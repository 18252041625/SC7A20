#include "SC7A20.h"

bool SC7A20_Class::begin( uint8_t address, TwoWire &wirePort)
{
	_address = address;
  	_i2cPort = &wirePort;

	_i2cPort->begin();
  	if(!IsExist())
	  return false;
	IIC_Write_Byte(CTRL_REG1,0x27); //正常模式 10HZ
	return true;
}

void SC7A20_Class::IIC_Write_Byte(uint8_t reg,uint8_t data)
{
	_i2cPort->beginTransmission(_address);
	_i2cPort->write(reg);
	_i2cPort->write(data);
	_i2cPort->endTransmission();
}

void SC7A20_Class::IIC_Read_Byte(uint8_t reg,uint8_t* buf,int lenght)
{

    uint8_t i=0;
	_i2cPort->beginTransmission(_address);
	reg |= 0x80; //turn auto-increment bit on
	_i2cPort->write(reg);
	_i2cPort->endTransmission(false);
	_i2cPort->requestFrom(_address, lenght);

	while (_i2cPort->available() && i<lenght)
	{
		*buf= _i2cPort->read();
		buf++;
		i++;
	}
}

bool SC7A20_Class::IsExist()
{
  uint8_t config; 
  IIC_Read_Byte(WHO_AM_I_REG,&config,1);

  if (config == CHIP_ID) 
    return true;
  else 
    return false;
}
int16_t SC7A20_Class::_12bitComplement(uint8_t msb,uint8_t lsb)
{

	int16_t temp;
	temp=msb<<8|lsb;
	temp=temp>>4;   //只有高12位有效
	temp=temp & 0x0fff;
	if(temp&0x0800) //负数 补码==>原码
	{
		temp=temp&0x07ff; //屏弊最高位      
		temp=~temp;
		temp=temp+1;
		temp=temp&0x07ff;
		temp=-temp;       //还原最高位
	}	
	return temp;
}

void SC7A20_Class::measure(void)
{
	uint8_t buff[6];
	IIC_Read_Byte(0x28,buff,6);
	accel_X=_12bitComplement(buff[1],buff[0]); 
	accel_Y=_12bitComplement(buff[3],buff[2]); 
	accel_Z=_12bitComplement(buff[5],buff[4]); 
}