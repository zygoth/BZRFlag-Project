/* 
 * File:   BehaviorCommanderAI.cpp
 * Author: zygoth
 * 
 * Created on June 10, 2013, 1:59 PM
 */

#include "BehaviorCommanderAI.h"
#include "BehaviorTankAI.h"

BehaviorCommanderAI::BehaviorCommanderAI(BZRC* connection) : CommanderAI(connection)
{
    //* Create enemy tank targeters
    vector<otank_t> otherTanks;
    connection->get_othertanks(&otherTanks);
    
    for(int i = 0; i < otherTanks.size(); i++)
    {
        TankTargeter t(connection, i);
        tankTargeters.push_back(t);
    }
    
    //* Create tank AIs
    vector<tank_t> myTanks;
    connection->get_mytanks(&myTanks);
    
    for(int i = 0; i < myTanks.size(); i++)
    {
        tankAIs.push_back(new BehaviorTankAI(connection, i, myColor, &tankTargeters));
    }    
    
    //* Get constants from server
    
    vector<constant_t> constants;
    connection->get_constants(&constants);
         
    for(int i = 0; i < constants.size(); i++)
    {
        if(constants.at(i).name.compare("worldsize") == 0)
            worldSize = atoi(constants.at(i).value.c_str());
    }
    
    //* Build world occgrid
    
    worldMap = new bool[worldSize * worldSize];
    
    vector<obstacle_t> objects;
    connection->get_obstacles(&objects);
    
    buildWorldOccgrid(&objects);
    
    otherTanks.clear();
    myTanks.clear();
    constants.clear();
    objects.clear();
}

void BehaviorCommanderAI::buildWorldOccgrid(vector <obstacle_t> *objects)
{
    int x, y, x2, y2;
    int thisX, thisY, lastX, lastY;
    obstacle_t temp;
    
    bool mapCopy[worldSize * worldSize];
    
    for(int i = 0; i < objects->size(); i++)
    {
        temp = objects->at(i);
        x = temp.o_corner[0][0];
        y = temp.o_corner[0][1];
        
        x += worldSize/2;
        y += worldSize/2;
        
        thisX = x;
        thisY = y;
                
        for(int corner = 1; corner < temp.courner_count; corner++)
        {
            lastX = thisX;
            lastY = thisY;
            
            thisX = temp.o_corner[corner][0];
            thisY = temp.o_corner[corner][1];
            
            thisX += worldSize/2;
            thisY += worldSize/2;
            
            drawEdge(lastX, lastY, thisX, thisY);
            
            if(corner == 3)
            {
                if(x != lastX)
                {
                    x2 = lastX + (x - lastX)/abs(x - lastX);
                    y2 = lastY + (thisY - lastY)/abs(thisY - lastY);
                }
                else
                {
                    x2 = lastX + (thisX - lastX)/abs(thisX - lastX);
                    y2 = lastY + (y - lastY)/abs(y - lastY);        
                }
            }
        }
        
        drawEdge(thisX, thisY, x, y);
        
        fillObject(x2, y2);
        objectFinished(mapCopy);
    }
    
    for(int i = 0; i < worldSize*worldSize; i++)
        worldMap[i] = mapCopy[i];
}

void BehaviorCommanderAI::drawEdge(int x1, int y1, int x2, int y2)
{
    int width = x1 - x2;
    int height = y1 - y2;
    
    if(width == 0)
    {
        for(int i = 0; i < abs(height); i++)
            worldMap[(y2 + height/abs(height))*worldSize + x2] = 1;
    }
    else if(height == 0)
    {
        for(int i = 0; i < abs(width); i++)
            worldMap[y2*worldSize + (x2 + width/abs(width))] = 1;
    }
    else
        cout << "Object has Diagonal Line!" << endl;
    
}

void BehaviorCommanderAI::fillObject(int x, int y)
{
    if(worldMap[y*worldSize + x] == 1)
        return;
    
    worldMap[y*worldSize + x] = 1;
    
    if(x > 0)
        fillObject(x-1, y);
    
    if(x < worldSize - 1)
        fillObject(x+1, y);
    
    if(y > 0)
        fillObject(x, y-1);
    
    if(y < worldSize - 1)
        fillObject(x, y+1);
}

void BehaviorCommanderAI::objectFinished(bool* copy)
{
    bool currentValue;
    
    for(int i = 0; i < worldSize*worldSize; i++)
    {
        currentValue = worldMap[i];
        copy[i] = currentValue;
        if(currentValue)
            worldMap[i] = false;
    }
}

void BehaviorCommanderAI::controlTeam()
{    
    /**
     * Update enemy positions
     */
    for(int i = 0; i < tankTargeters.size(); i++)
    {
        tankTargeters[i].update();
    }
    
    /**
     * Control the individual tanks
     */
    for(int i = 0; i < tankAIs.size(); i++)
    {
        tankAIs[i]->controlTank();
    }
}

BehaviorCommanderAI::~BehaviorCommanderAI() 
{
    for(int i = 0; i < tankAIs.size(); i++)
    {
        delete tankAIs[i];
    }
}

