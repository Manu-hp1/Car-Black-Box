/* 
 * File:   internal_eeprom.h
 * Author: Manu H P
 *
 * Created on April 21, 2026, 12:45 PM
 */

#ifndef INTERNAL_EEPROM_H
#define INTERNAL_EEPROM_H

void write_internal_eeprom(unsigned char addr,unsigned char data);
unsigned char read_internal_eeprom(unsigned char addr);

#endif	/* INTERNAL_EEPROM_H */

