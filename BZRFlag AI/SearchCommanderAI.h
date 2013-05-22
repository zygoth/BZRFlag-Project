/* 
 * File:   SearchCommander.h
 * Author: zygoth
 *
 * Created on May 22, 2013, 3:12 PM
 */

#ifndef SEARCHCOMMANDER_H
#define	SEARCHCOMMANDER_H

#include "CommanderAI.h"
#include "470bot.h"
#include "f9.h"

class SearchCommanderAI : CommanderAI
{
public:
    SearchCommanderAI(BZRC* connection);
    void controlTeam();
    virtual ~SearchCommanderAI();
private:
    void fixOffByOneErrors();

};

#endif	/* SEARCHCOMMANDER_H */

