#ifndef CMPS14_H
#define CMPS14_H

#include "Arduino.h"

/*
 * For more information about the CMPS14 refer to the datasheet:
 * https://www.robot-electronics.co.uk/files/cmps14.pdf
 * 
 */

#define CMPS14_DEFAULT_ADDRESS 0x60

class CMPS14
{
public:
	CMPS14(int16_t compassAddress = CMPS14_DEFAULT_ADDRESS);
	
	void begin();

	int16_t readBearing();
	int8_t readPitch();
	int16_t readRoll();
	int16_t readGyroX();
	int16_t readGyroY();
	int16_t readGyroZ();
	

	int16_t getBearing();
	int8_t getPitch();
	int16_t getRoll();
	int16_t getGyroX();
	int16_t getGyroY();
	int16_t getGyroZ();
	
private:
	int8_t  readInt8(int16_t address);
	int16_t readInt16(int16_t highAddress, int16_t lowAddress);
	
	int8_t m_pitchOffset = 0;
	int16_t m_rollOffest = 0;

	int16_t m_compassAddress;
	int16_t m_bearing;
	int8_t m_pitch;
	int16_t m_roll;

	int16_t m_gyroX;
	int16_t m_gyroY;
	int16_t m_gyroZ;
};

#endif
