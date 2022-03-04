#include "CMPS14.h"
#include "Wire.h"

#define CMPS14_BEARING_HIGH	0x02
#define CMPS14_BEARING_LOW	0x03
#define CMPS14_PITCH		0x04
#define CMPS14_ROLL			0x05

#define CMPS14_MAGNETOMETER_X_HIGH	0x06
#define CMPS14_MAGNETOMETER_X_LOW	0x07
#define CMPS14_MAGNETOMETER_Y_HIGH	0x08
#define CMPS14_MAGNETOMETER_Y_LOW	0x09
#define CMPS14_MAGNETOMETER_Z_HIGH	0x0A
#define CMPS14_MAGNETOMETER_Z_LOW	0x0B

#define CMPS14_ACCELEROMETER_X_HIGH	0x0C
#define CMPS14_ACCELEROMETER_X_LOW	0x0D
#define CMPS14_ACCELEROMETER_Y_HIGH	0x0E
#define CMPS14_ACCELEROMETER_Y_LOW	0x0F
#define CMPS14_ACCELEROMETER_Z_HIGH	0x10
#define CMPS14_ACCELEROMETER_Z_LOW	0x11

#define CMPS14_GYROSCOPE_X_HIGH		0x12
#define CMPS14_GYROSCOPE_X_LOW		0x13
#define CMPS14_GYROSCOPE_Y_HIGH		0x14
#define CMPS14_GYROSCOPE_Y_LOW		0x15
#define CMPS14_GYROSCOPE_Z_HIGH		0x16
#define CMPS14_GYROSCOPE_Z_LOW		0x17

#define CMPS14_ROLL_HIGH	0x1C
#define CMPS14_ROLL_LOW		0x1D


CMPS14::CMPS14(int16_t compassAddress)
{
	m_compassAddress = compassAddress;
}

void CMPS14::begin()
{
	Wire.begin();
	m_pitchOffset	= 0;
	m_rollOffest	= 0;
	m_pitchOffset	= readPitch();
	m_rollOffest	= readRoll();
}

int8_t CMPS14::readInt8(int16_t address)
{
	Wire.beginTransmission(m_compassAddress);
	Wire.write(address);
	Wire.endTransmission();
	Wire.requestFrom(m_compassAddress, 1);
	return Wire.read();	
}

int16_t CMPS14::readInt16(int16_t highAddress, int16_t lowAddress)
{
	int8_t highByte = readInt8(highAddress);
	int8_t lowByte = readInt8(lowAddress);	

	return (((int16_t) highByte) << 8) + lowByte;
}


int16_t CMPS14::readBearing()
{
	m_bearing = readInt16(CMPS14_BEARING_HIGH, CMPS14_BEARING_LOW);
	return m_bearing;
}
int8_t CMPS14::readPitch()
{
	m_pitch = readInt8(CMPS14_PITCH) - m_pitchOffset;
	return m_pitch;
}
int16_t CMPS14::readRoll()
{
	m_roll = readInt16(CMPS14_ROLL_HIGH, CMPS14_ROLL_LOW) - m_rollOffest;
	return m_roll;
}
int16_t CMPS14::readGyroX()
{
	m_gyroX = readInt16(CMPS14_GYROSCOPE_X_HIGH, CMPS14_GYROSCOPE_X_LOW);
	return m_gyroX;
}
int16_t CMPS14::readGyroY()
{
	m_gyroY = readInt16(CMPS14_GYROSCOPE_Y_HIGH, CMPS14_GYROSCOPE_Y_LOW);
	return m_gyroY;
}
int16_t CMPS14::readGyroZ()
{
	m_gyroZ = readInt16(CMPS14_GYROSCOPE_Z_HIGH, CMPS14_GYROSCOPE_Z_LOW);
	return m_gyroZ;
}


int16_t CMPS14::getBearing()
{
	return m_bearing;
}
int8_t CMPS14::getPitch()
{
	return m_pitch;
}
int16_t CMPS14::getRoll()
{
	return m_roll;
}
int16_t CMPS14::getGyroX()
{
	return m_gyroX;
}
int16_t CMPS14::getGyroY()
{
	return m_gyroY;
}
int16_t CMPS14::getGyroZ()
{
	return m_gyroZ;
}
