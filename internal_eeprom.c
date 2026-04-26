/*
 * File:   internal_eeprom.c
 * Author: Manu H P
 *
 * Created on April 21, 2026, 12:50 PM
 */

#include <xc.h>

#include "internal_eeprom.h"

void write_internal_eeprom(unsigned char addr,unsigned char data)
{
    //Write the address
	EEADR = addr;

	//Write the data
	EEDATA = data;

	//Point to data memory
	EECON1bits.EEPGD = 0;

	//Access data EEPROM memory
	EECON1bits.CFGS = 0;

	//Data write enable bit
	EECON1bits.WREN = 1;

	//Global interrupt disable 
	GIE = 0;

	//Write protection sequence
	EECON2 = 0x55;
	EECON2 = 0xAA;

	//Initiate write
	EECON1bits.WR = 1;

	//Global interrupt enable
	GIE = 1;

	//Wait till write is complete
	while (!PIR2bits.EEIF);

	//Disable the flag
	PIR2bits.EEIF = 0;
}

unsigned char read_internal_eeprom(unsigned char addr)
{
    //Write the address, from where data has to be read
	EEADR = addr;

	//Inhibits write cycles to Flash program/data EEPROM
	EECON1bits.WREN = 0;

	//Point to data memory
	EECON1bits.EEPGD = 0;

	//Access data EEPROM memory
	EECON1bits.CFGS = 0;
	
	//Initiate read
	EECON1bits.RD = 1;

	//Data available in EEDATA register
	return EEDATA;
}
