/*
 * PotentialFieldCalculator.cpp
 *
 *  Created on: May 6, 2013
 *      Author: zygoth
 */

#include "PotentialFieldCalculator.h"
#include <iostream>
#include <unistd.h>

using namespace std;

PotentialFieldCalculator::PotentialFieldCalculator(BZRC* constructor) {
    socket = constructor;
}

PotentialFieldCalculator::~PotentialFieldCalculator() {
}

TankVector* PotentialFieldCalculator::calculateVector(int x, int y, TeamColor team) {
    xVector = 0.0; 
    yVector = 0.0;
    TankVector* result;
    
    calculateObjectVector(x, y);
    calculateShotVector(x,y);
    calculateFriendlyTanks(x,y);
    calculateEnemyTanks(x,y);
    calculateTargetVector(x,y,team);
    
    result = new TankVector(xVector, yVector);
    
    return result;
}

void PotentialFieldCalculator::calculateObjectVector(int x, int y) {
    int range = 15;
    int x1, y1, x2, y2, firstX, firstY;
    int xCheck, yCheck, calcX, calcY, count;
    double rise, run, xUpdate, yUpdate;
    obstacle_t temp;
    
    vector<obstacle_t> *objects;
    socket->get_obstacles(objects);
    
    for(int i = 0; i < objects->size(); i++) {
        temp = objects->at(i);
        
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
            
            xVector += xUpdate;
            yVector += xUpdate;
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
            
        xVector += xUpdate;
        yVector += xUpdate;
    }

    objects->clear();
}

void PotentialFieldCalculator::calculateShotVector(int x, int y) {
    
}
   
void PotentialFieldCalculator::calculateFriendlyTanks(int x, int y) {
    int tankX, tankY, calcX, calcY;
    double rise, run;
    
    vector<tank_t> *tanks;
    socket->get_mytanks(tanks);
    
    for(int i = 0; i < tanks->size(); i++) {
        tankX = (int)tanks->at(i).pos[0];
        tankY = (int)tanks->at(i).pos[1];
        
        calcX = x - tankX;
        calcY = y - tankY;
        
        if(abs(calcX) < 10 || abs(calcY) < 10) {
            if(abs(calcX) < abs(calcY)) {
                run = (double)(calcX * (10 - abs(calcX)));
                rise = (double)(calcY * (10 - abs(calcX)));
            }
            else {
                run = (double)(calcX * (10 - abs(calcY)));
                rise = (double)(calcY * (10 - abs(calcY)));
                
            }
        }
        else
        {
            run = 0.0;
            rise = 0.0;
        }
        
        xVector += run;
        yVector += rise;
    }
    
    tanks->clear();
}
        
void PotentialFieldCalculator::calculateEnemyTanks(int x, int y) {
    int tankX, tankY, calcX, calcY;
    double rise, run;
    
    vector<otank_t> *tanks;
    socket->get_othertanks(tanks);
    
    for(int i = 0; i < tanks->size(); i++) {
        tankX = (int)tanks->at(i).pos[0];
        tankY = (int)tanks->at(i).pos[1];
        
        calcX = x - tankX;
        calcY = y - tankY;
        
        if(abs(calcX) < 10 || abs(calcY) < 10) {
            if(abs(calcX) < abs(calcY)) {
                run = (double)(calcX * (10 - abs(calcX)));
                rise = (double)(calcY * (10 - abs(calcX)));
            }
            else {
                run = (double)(calcX * (10 - abs(calcY)));
                rise = (double)(calcY * (10 - abs(calcY)));
                
            }
        }
        else
        {
            run = 0.0;
            rise = 0.0;
        }
        
        xVector += run;
        yVector += rise;
    }
   
    tanks->clear();
}
        
void PotentialFieldCalculator::calculateTargetVector(int x, int y, TeamColor teams) {
    int flagX, flagY, calcX, calcY;
    double rise, run;
    
    vector<flag_t> *flags;
    socket->get_flags(flags);
    
    for(int i = 0; i <  flags->size(); i++) {
        switch(teams) {
            case PURPLE:
                if(flags->at(i).color.compare("purple")) {
                    flagX = (int)(flags->at(i).pos[0]);
                    flagY = (int)(flags->at(i).pos[1]);
                }
                break;
            case BLUE:
                if(flags->at(i).color.compare("blue")) {
                    flagX = (int)(flags->at(i).pos[0]);
                    flagY = (int)(flags->at(i).pos[1]);                    
                }
                break;
            case GREEN:
                if(flags->at(i).color.compare("green")) {
                    flagX = (int)(flags->at(i).pos[0]);
                    flagY = (int)(flags->at(i).pos[1]);                    
                }
                break;
            case RED:
                if(flags->at(i).color.compare("red")) {
                    flagX = (int)(flags->at(i).pos[0]);
                    flagY = (int)(flags->at(i).pos[1]);                    
                }
                break;
        }
    }
    
    flags->clear();
    
    calcX = flagX - x;
    calcY = flagY - y;
    
    if(abs(calcX) > abs(calcX)) {
        run = (double)calcX/(double)abs(calcX) * 2.0;
        rise = (double)calcX/(double)abs(calcX) * 2.0;
    }
    else {
        run = (double)calcX/(double)abs(calcX) * 2.0;
        rise = (double)calcX/(double)abs(calcX) * 2.0;        
    }
        
    xVector += run;
    yVector += rise;
}
        
