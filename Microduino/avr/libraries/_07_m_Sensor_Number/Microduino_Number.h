#ifndef __NUMBER_H__
#define __NUMBER_H__

#include <SoftwareSerial.h>

#define HEADA 0x7A  
#define HEADB 0x7B 
#define SHOWC 0x7C

#define POSITIVE 0
#define NEGATIVE 1
#define ALL   -1

//0,1,2,3,4,5,6,7,8,9
const byte Positive_data[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};

//0,1,2,3,4,5,6,7,8,9
const byte Negative_data[10] = {0x3f, 0x30, 0x5b, 0x79, 0x74, 0x6d, 0x6f, 0x38, 0x7f, 0x7d};

class Number{
public:
  Number(uint8_t n,SoftwareSerial *ser);
  Number(uint8_t n,HardwareSerial *ser);
  
  void begin();
  void Serial_Send(u8* Data,u8 len);
  void setNumber(uint8_t _num, uint8_t _data,byte _light);
  void setSeg(uint8_t _num, byte _data,byte _light);
  void direction(uint8_t n);
  void setPoint(uint8_t _num,boolean _point);
  void show();
  void turnOff(int8_t _num);

  byte getCheckBcc(byte length, byte mydata[]);

private:
  uint8_t numLED;
  uint8_t numLEDDir;
  uint8_t *numData;

  SoftwareSerial *numSwSerial;
  HardwareSerial *numHwSerial;

  void common_init(void);
};

#endif