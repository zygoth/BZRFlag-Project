/* 
 * File:   BehaviorCommanderAI.h
 * Author: zygoth
 *
 * Created on June 10, 2013, 1:59 PM
 */

#ifndef BEHAVIORCOMMANDERAI_H
#define	BEHAVIORCOMMANDERAI_H

#include "CommanderAI.h"
#include "TankTargeter.h"
#include "470bot.h"
#include <cmath>
#include "GNUPrinter.h"

class BehaviorCommanderAI : public CommanderAI
{
public:
	BehaviorCommanderAI(BZRC* connection);
        void controlTeam();
	virtual ~BehaviorCommanderAI();

private:
    void buildWorldOccgrid(vector <obstacle_t> *objects);
    void drawEdge(int x1, int y1, int x2, int y2);
    void fillObject(int x, int y);
    void objectFinished(bool* copy);
    
    GNUPrinter* printer;
    vector<TankAI*> tankAIs;
    vector<TankTargeter> tankTargeters;
    int worldSize;
    bool* worldMap;
};

#endif	/* BEHAVIORCOMMANDERAI_H */

