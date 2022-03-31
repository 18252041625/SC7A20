#include <Arduino.h>
#include "SC7A20.h"

SC7A20_Class SC7A20;

void setup() 
{
  Serial.begin(9600);
	if(!SC7A20.begin())
	{	
    while (1);
  }
}

void loop() 
{  
	SC7A20.measure();
	Serial.printf("X:%d Y:%d Z:%d\r\n",SC7A20.accel_X,SC7A20.accel_Y,SC7A20.accel_Z);
	delay(1000);
}