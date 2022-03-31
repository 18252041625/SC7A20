#ifndef _SC7A20_H
#define _SC7A20_H
#include "Wire.h"
#include "Arduino.h"

#define SC7A20_I2C_ADDR		    0x18

//Reg Table
#define WHO_AM_I_REG			0x0F

#define CTRL_REG1			    0x20
#define CTRL_REG2			  	0x21
#define CTRL_REG3			  	0x22
#define ADDR_STATUS_REG         0x27
#define OUT_X_L_REG				0x28
#define OUT_X_H_REG				0x29
#define OUT_Y_L_REG				0x2A
#define OUT_Y_H_REG				0x2B
#define OUT_Z_L_REG				0x2C
#define OUT_Z_H_REG				0x2D

// For CHIP_ID_REG
#define CHIP_ID					0x11


class SC7A20_Class
{
public:
    int accel_X;
    int accel_Y;
    int accel_Z;
    bool begin( uint8_t address=SC7A20_I2C_ADDR, TwoWire &wirePort=Wire);
    void measure(void);

private:
    uint8_t _address;
    TwoWire *_i2cPort;
    void IIC_Write_Byte(uint8_t reg,uint8_t data);
    void IIC_Read_Byte(uint8_t reg,uint8_t* buf,int lenght);
    bool IsExist();
    int16_t _12bitComplement(uint8_t msb,uint8_t lsb);
};
#endif
