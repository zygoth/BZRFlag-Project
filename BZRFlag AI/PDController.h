/*
 * PDController.h
 *
 *  Created on: May 6, 2013
 *      Author: zygoth
 */

#ifndef PDCONTROLLER_H_
#define PDCONTROLLER_H_

class PDController {
    double pi, maxTurnAng;
public:
	PDController();
	virtual ~PDController();
        double calculateIntermediateAngle (double, double);
};

#endif /* PDCONTROLLER_H_ */