#include "X9C.h"

X9C::X9C(int CS_PIN, int UD_PIN, int INC_PIN) {
	init(CS_PIN,UD_PIN,INC_PIN);
}

void X9C::init(int CS_PIN, int UD_PIN, int INC_PIN) {
	this->CS_PIN = CS_PIN;
	this->UD_PIN = UD_PIN;
	this->INC_PIN = INC_PIN;
	pinMode(CS_PIN,OUTPUT);
  	pinMode(UD_PIN,OUTPUT);
  	pinMode(INC_PIN,OUTPUT);
  	digitalWrite(INC_PIN,HIGH);
	digitalWrite(UD_PIN,LOW);
	digitalWrite(CS_PIN,LOW);
	while(init_counter<init_counter_ticks)
		{
			digitalWrite(INC_PIN,LOW);
			digitalWrite(INC_PIN,HIGH);
			init_counter++;
		}
}

void X9C::decrement(int steps) 
	{
		digitalWrite(UD_PIN,LOW);
		counter = 0;
		while(counter<steps)
			{
				digitalWrite(INC_PIN,LOW);
				digitalWrite(INC_PIN,HIGH);
				counter++;
			}
	}
	
void X9C::decrement()
	{
		digitalWrite(UD_PIN,LOW);
		digitalWrite(INC_PIN,LOW);
		digitalWrite(INC_PIN,HIGH);
	}
	
void X9C::increment(int steps)
	{
		digitalWrite(UD_PIN,HIGH);
		counter = 0;
		while(counter<steps)
			{
				digitalWrite(INC_PIN,LOW);
				digitalWrite(INC_PIN,HIGH);
				counter++;
			}
	}
	
void X9C::increment()
	{
		digitalWrite(UD_PIN,HIGH);
		digitalWrite(INC_PIN,LOW);
		digitalWrite(INC_PIN,HIGH);
	}

void X9C::store()
	{
		digitalWrite(INC_PIN,HIGH);
		digitalWrite(CS_PIN,HIGH);
		delay(30);
		digitalWrite(CS_PIN,LOW);
	}
	
void X9C::sleep()
	{
		digitalWrite(UD_PIN,HIGH);
		digitalWrite(INC_PIN,LOW);
		digitalWrite(CS_PIN,HIGH);
	}
	
void X9C::wake()
	{
		digitalWrite(INC_PIN,HIGH);
		digitalWrite(CS_PIN,LOW);
		delay(5);
		digitalWrite(UD_PIN,LOW);
		digitalWrite(INC_PIN,LOW);
		digitalWrite(INC_PIN,HIGH);
	}