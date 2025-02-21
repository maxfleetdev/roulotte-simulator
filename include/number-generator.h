#ifndef NUMBER_GENERATOR_H
#define NUMBER_GENERATOR_H

#include <iostream>
#include <random>

class Generator {
public:
	int roll_ball();
	int get_last_number();

protected:
	int random_number();
	
	int m_last_number = 0;
	int m_numbers[37] = 
	{
		0,32,15,19,4,21,2,25,17,34,6,27,13,
		36,11,30,8,23,10,5,24,16,33,1,20,14,
		31,9,22,18,29,7,28,12,35,3,26
	};
};

#endif