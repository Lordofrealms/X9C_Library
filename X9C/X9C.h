#ifndef X9C_H
#define X9C_H

#if defined(ARDUINO) && (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

class X9C
{
private:
	int CS_PIN; //CS Pin - used to turn module on and off
	int UD_PIN;	//U/D Pin - used to select the increment mode either up or down
	int INC_PIN; //INC Pin - used to increment the digipot
	int counter; //counter used for increment and decrement step counting
	int init_counter = 0; //current number of steps down on init we have done
	int init_counter_ticks = 0; //how many steps down to take on init
	void init(int CS_PIN, int UD_PIN, int INC_PIN); //used to initialize a new instance of the digipot with the given pins
	public:
	X9C(int CS_PIN, int UD_PIN, int INC_PIN); //X9C declarator, initializes on declaration, and decrements the number of initialize steps set by init_counter_ticks
	void decrement(int steps); //decrement the digipot by steps number of steps
	void decrement(); //decrement the digipot once
	void increment(int steps); //increment the digipot by steps number of steps
	void increment(); //increment the digipot once
	void store(); //store the current digipot value to NVRAM, requires a 30ms delay to ensure stored
	void sleep(); //sleep the digipot (does not store), this is to prevent multiple similar functions. Store first then sleep if desired.
	void wake(); //wake the digipot
};

#include "X9C.h"

#endif