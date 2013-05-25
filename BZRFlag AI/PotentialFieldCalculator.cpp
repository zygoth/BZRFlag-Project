/*
 * PotentialFieldCalculator.cpp
 *
 *  Created on: May 6, 2013
 *      Author: zygoth
 */

#include "PotentialFieldCalculator.h"
#include <iostream>
#include <unistd.h>
#include "PDController.h"

using namespace std;

PotentialFieldCalculator::PotentialFieldCalculator(BZRC* constructor) {
    socket = constructor;
}

PotentialFieldCalculator::~PotentialFieldCalculator() {
}

TankVector* PotentialFieldCalculator::calculateVector(int x, int y, TeamColor targetTeam, int tankIndex) {
    xVector = 0.0;
    yVector = 0.0;
    TankVector* result;
    
    calculateObjectVector(x, y);
    calculateShotVector(x,y);
    calculateFriendlyTanks(x,y);
    calculateEnemyTanks(x,y);
    calculateTargetVector(x,y,targetTeam, tankIndex);
    
    result = new TankVector(xVector, yVector);
    
    return result;
}

TankVector* PotentialFieldCalculator::calculateSearcherVector(int x, int y, int index)
{
    TankVector* result;
    
    vector<tank_t> myTanks;
    socket->get_mytanks(&myTanks);
    tank_t myTank = myTanks.at(index);
    
    // Get the vector for the target point
    xVector = (double)(x - myTank.pos[0]);
    yVector = (double)(y - myTank.pos[1]);
    
    if(abs(xVector) > abs(yVector))
    {
        yVector = yVector/abs(xVector) *2;
        xVector = xVector/abs(xVector) *2;
    }
    else
    {
        xVector = xVector/abs(yVector) *2;
        yVector = yVector/abs(yVector) *2;        
    }
    
    vector<grid_t> tankMap;
    socket->get_occgrid(&tankMap, index);
    
    // adjust vectors to deal with objects
    avoidObjects(myTank, tankMap.at(0));
    
    result = new TankVector(xVector, yVector);
    
    myTanks.clear();
    tankMap.clear();
    
    return result;
}

void PotentialFieldCalculator::avoidObjects(tank_t tank, grid_t visible)
{
    // range away from the tank it will look for an object
    int objectRange = 20;
    int gridX = tank.pos[0] - visible.x;
    int gridY = tank.pos[1] - visible.y;
    int rise, run;
    double angle, newAngle, newXVector, newYVector;
    
    for(int i = objectRange * -1; i < objectRange; i++)
    {
        for(int k = objectRange * -1; i < objectRange; i++)
        {
            run = gridX + k;
            rise = gridY + i;
            if(run > 0 && run < visible.xdim &&
               rise > 0 && rise < visible.ydim)
            {
                
                angle = atan2(i,k);
                
                // get difference between angle to an object and the tanks
                // current angle
                newAngle = getAngleBetween(angle, tank.angle);

                if(visible.grid[rise*visible.xdim + run]  && newAngle > PI/-4.0 
                                                          && newAngle < PI/4.0)
                {
                    // get the angle of the new vector
                    if(newAngle > 0)
                        newAngle = angle - PI/2.0;
                    else 
                        newAngle = angle + PI/2.0;
                    
                    newAngle = getAngleBetween(newAngle, 0.0);
                    
                    if(newAngle == PI/2 || newAngle == PI/-2)
                    {
                        newYVector = 1.0;
                        newXVector = 0.0;
                    }
                    else
                    {
                        newXVector = tan(newAngle);
                        
                        newYVector = abs(newXVector);
                        newXVector = newXVector/abs(newXVector);
                    }
                    
                    if(newAngle < 0){
                        newYVector = newYVector * -1;
                        newXVector = newXVector * -1;
                    }
                    
                    if(abs(newXVector) > abs(newYVector))
                    {
                        newYVector = newYVector/abs(newXVector) *.1;
                        newXVector = newXVector/abs(newXVector) *.1;
                    }
                    else
                    {
                        newXVector = newXVector/abs(newYVector) *.1;
                        newYVector = newYVector/abs(newYVector) *.1;        
                    }

                    xVector += newXVector;
                    yVector += newYVector;
                }
            }
        }
    }
}

double PotentialFieldCalculator::getAngleBetween(double target, double start)
{
    double result = target - start;
    
    if(result > PI)
	result = result - (2 * PI);
    if(result < -1*PI)
	result = result + (2 * PI);
     
    return result;
}

void PotentialFieldCalculator::calculateObjectVector(int x, int y) {
    int range = 10;
    double amount = 10.0;
    int x1, y1, x2, y2, firstX, firstY;
    int xCheck, yCheck, calcX, calcY, count;
    double rise, run, xUpdate, yUpdate;
    obstacle_t temp;
    
    vector<obstacle_t> objects;
    socket->get_obstacles(&objects);
    
    for(int i = 0; i < objects.size(); i++) {
        temp = objects.at(i);
        
        firstX = (int)temp.o_corner[0][0];
        firstY = (int)temp.o_corner[0][1];
        
        x2 = firstX;
        y2 = firstY;
        
        for(int z = 1; z < temp.courner_count; z++) {
            xUpdate = 0.0;
            yUpdate = 0.0;

            x1 = x2;
            y1 = y2;
            
            x2 = (int)temp.o_corner[z][0];
            y2 = (int)temp.o_corner[z][1];
            
            calcX = x2 - x1;
            calcY = y2 - y1;

            if(abs(calcX) > abs(calcY)) {
                run = (double)calcX/(double)abs(calcX);
                rise = (double)calcY/(double)abs(calcX);
                count = abs(calcX);
            }
            else {
                run = (double)calcX/(double)abs(calcY);
                rise = (double)calcY/(double)abs(calcY);                
                count = abs(calcY);
            }
            
            for(int k = 0; k < count; k++) {
                xCheck = x1 + (int)(k * run + 0.5);
                yCheck = y1 + (int)(k * rise + 0.5);

                if(xCheck < x+range && 
                   xCheck > x-range && 
                   yCheck < y+range && 
                   yCheck > y-range) {
                    
                    xUpdate = run;
                    yUpdate = rise;
                }
            }
            
            xVector += xUpdate * amount;
            yVector += yUpdate * amount;
        }
        
        xUpdate = 0.0;
        yUpdate = 0.0;

        x1 = x2;
        y1 = y2;
            
        x2 = firstX;
        y2 = firstY;
            
        calcX = x2 - x1;
        calcY = y2 - y1;

        if(abs(calcX) > abs(calcY)) {
            run = (double)calcX/(double)abs(calcX);
            rise = (double)calcY/(double)abs(calcX);
            count = abs(calcX);
        }
        else {
            run = (double)calcX/(double)abs(calcY);
            rise = (double)calcY/(double)abs(calcY);                
            count = abs(calcX);
        }
            
        for(int k = 0; k < count; k++) {
            xCheck = x1 + (int)(k * run + 0.5);
            yCheck = y1 + (int)(k * rise + 0.5);

            if(xCheck < x+range && 
               xCheck > x-range && 
               yCheck < y+range && 
               yCheck > y-range) {
                
                xUpdate = run;
                yUpdate = rise;
            }
        }
            
        xVector += xUpdate * amount;
        yVector += yUpdate * amount;
    }

    objects.clear();
}

void PotentialFieldCalculator::calculateShotVector(int x, int y) {
    
}
   
void PotentialFieldCalculator::calculateFriendlyTanks(int x, int y) {
    int tankX, tankY, calcX, calcY;
    double rise, run;
    int range = 5;
    double amount = 0.5;
    
    vector<tank_t> tanks;
    socket->get_mytanks(&tanks);
    
    for(int i = 0; i < tanks.size(); i++) {
        tankX = (int)tanks.at(i).pos[0];
        tankY = (int)tanks.at(i).pos[1];
        
        calcX = x - tankX;
        calcY = y - tankY;
        
        if(abs(calcX) < range && abs(calcY) < range && 
               (calcX != 0 || calcY != 0)) {
            if(abs(calcX) < abs(calcY)) {
                run = (double)calcX/(double)abs(calcY);
                rise = (double)calcY/(double)abs(calcY);
            }
            else {
                run = (double)calcX/(double)abs(calcX);
                rise = (double)calcY/(double)abs(calcX);
                
            }
        }
        else
        {
            run = 0.0;
            rise = 0.0;
        }
        
        xVector += run * amount;
        yVector += rise * amount;
    }
    
    tanks.clear();
}
        
void PotentialFieldCalculator::calculateEnemyTanks(int x, int y) {
    int tankX, tankY, calcX, calcY;
    double rise, run;
    int range = 5;
    double amount = 0.5;
    
    vector<otank_t> tanks;
    socket->get_othertanks(&tanks);
    
    for(int i = 0; i < tanks.size(); i++) {
        tankX = (int)tanks.at(i).pos[0];
        tankY = (int)tanks.at(i).pos[1];
        
        calcX = x - tankX;
        calcY = y - tankY;
        
        if(abs(calcX) < range && abs(calcY) < range && 
               calcX != 0 && calcY != 0) {
            if(abs(calcX) < abs(calcY)) {
                run = (double)calcX/(double)abs(calcY);
                rise = (double)calcY/(double)abs(calcY);
            }
            else {
                run = (double)calcX/(double)abs(calcX);
                rise = (double)calcY/(double)abs(calcX);
                
            }
        }
        else
        {
            run = 0.0;
            rise = 0.0;
        }
        
        xVector += run * amount;
        yVector += rise * amount;
    }
   
    tanks.clear();
}
        
void PotentialFieldCalculator::calculateTargetVector(int x, int y, TeamColor targetTeam, int tankIndex) {
    int flagX, flagY, calcX, calcY, baseX, baseY;
    double rise, run;
    TeamColor myTeam, base;
    string flag;
    
    vector<flag_t> flags;
    socket->get_flags(&flags);
    
    vector<tank_t> tanks;
    socket->get_mytanks(&tanks);
    
    vector<base_t> teams;
    socket->get_bases(&teams);
    
    if(tanks.size() == 0)
    {
        throw "My team has no tanks.  Terminating.\n";
    }

    tank_t myTank = tanks.front();
    string callSign = myTank.callsign;
    
    myTeam = stringToTeamColor(callSign);
    
    for(int i = 0; i < teams.size(); i++) {
        base = stringToTeamColor(teams.at(i).color);
        
        if(base == myTeam){
            baseX = teams.at(i).base_corner[0][0]
                  - teams.at(i).base_corner[2][0];
            baseY = teams.at(i).base_corner[0][1]
                  - teams.at(i).base_corner[2][1];
            
            baseX = teams.at(i).base_corner[2][0]
                    + baseX/2;
            baseY = teams.at(i).base_corner[2][1]
                    + baseY/2;
        }
    }
    
    teams.clear();
    
    for(int i = 0; i <  flags.size(); i++) {
        switch(targetTeam) {
            case PURPLE:
                if(flags.at(i).color.compare("purple") == 0) {
                    flagX = (int)(flags.at(i).pos[0]);
                    flagY = (int)(flags.at(i).pos[1]);
                }
                break;
            case BLUE:
                if(flags.at(i).color.compare("blue") == 0) {
                    flagX = (int)(flags.at(i).pos[0]);
                    flagY = (int)(flags.at(i).pos[1]);                    
                }
                break;
            case GREEN:
                if(flags.at(i).color.compare("green") == 0) {
                    flagX = (int)(flags.at(i).pos[0]);
                    flagY = (int)(flags.at(i).pos[1]);                    
                }
                break;
            case RED:
                if(flags.at(i).color.compare("red") == 0) {
                    flagX = (int)(flags.at(i).pos[0]);
                    flagY = (int)(flags.at(i).pos[1]);                    
                }
                break;
        }
    }
    
    flags.clear();
    
    myTank = tanks.at(tankIndex);
    flag = myTank.flag;
    
    if(flag.compare("-") != 0) {
        flagX = baseX;
        flagY = baseY;
    }
    
            

    
    calcX = flagX - x;
    calcY = flagY - y;
    
    if(abs(calcX) > abs(calcX)) {
        run = (double)calcX/(double)abs(calcX);
        rise = (double)calcY/(double)abs(calcX);
    }
    else {
        run = (double)calcX/(double)abs(calcY);
        rise = (double)calcY/(double)abs(calcY);        
    }
        
    xVector += run;
    yVector += rise;
    
}
/*
TeamColor CommanderAI::determineMyColor()
{
    vector<tank_t> myTanks;
    connection->get_mytanks(&myTanks);
    
    if(myTanks.size() == 0)
    {
        throw "My team has no tanks.  Terminating.\n";
    }
    
    tank_t myTank = myTanks.front();
    string callSign = myTank.callsign;
    
    TeamColor myColor = stringToTeamColor(callSign);
        
    return myColor;
}
*/
/**
 * This should be moved to a file with the TeamColor Enum.
 * @param colorString
 * @return 
 */
TeamColor stringToTeamColor(string colorString)
{
    TeamColor returnedColor;
    
    if(colorString.rfind("red") != colorString.npos) // red is in the callsign
    {
        returnedColor = RED;
    }
    else
    if(colorString.rfind("blue") != colorString.npos) // blue is in the callsign
    {
        returnedColor = BLUE;
    }
    else
    if(colorString.rfind("green") != colorString.npos) // green is in the callsign
    {
        returnedColor = GREEN;
    }
    else
    if(colorString.rfind("purple") != colorString.npos) // purple is in the callsign
    {
        returnedColor = PURPLE;
    }
    else
    {
        throw "The color could not be determined from the string.";
    }
    
    return returnedColor;
}
