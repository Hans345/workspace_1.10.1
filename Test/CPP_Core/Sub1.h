/*
 * Sub1.h
 *
 *  Created on: Feb 6, 2023
 *      Author: raphael.baumeler
 */

#ifndef SUB1_H_
#define SUB1_H_

#include "Base1.h"
#include "Base2.h"

class Sub1: public base1, public base2 {
public:
	Sub1();
	virtual ~Sub1();

};

#endif /* SUB1_H_ */
