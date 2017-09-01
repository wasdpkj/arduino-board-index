/*
  [head,2byte,0xAA 0xBB] [type,1byte,TYPE_NUM] [data,16byte] [body,1byte,getChecksum()]
  Example:
  AA BB C8 DC 05 DC 05 D0 07 EF 03 DC 05 DC 05 DC 05 DC 05 E3
*/

#include <Microduino_Protocol.h>

SoftwareSerial mySerial(4, 5);

ProtocolSer protocolA(&Serial1, 16);	//采用Serial1，数据长度为16个字节
ProtocolSer protocolB(&mySerial, 16);   //mySerial，数据长度为16个字节

uint16_t sendData[8] = {1500, 1500, 1500, 1500, 1000, 1000, 1000, 1000};
uint16_t recData[8];
uint8_t recCmd;
uint32_t sendTime;

void setup() {
  Serial.begin(9600);
  protocolA.begin(9600);  //9600/19200/38400
  protocolB.begin(9600);  //9600/19200/38400
  sendTime = millis();
}

void loop() {
	
  if(millis() - sendTime > 1000)
  {
	  sendTime = millis();
	  protocolA.write(0x01, (uint8_t *)sendData, 16);
    Serial.println("protocolA send !");
  }
  
  if(protocolB.available())
  {
	  protocolB.readWords(&recCmd, recData, 8);
	  Serial.println("protocolB Received !");
	  Serial.print("recCmd: ");
	  Serial.print(recCmd);
	  Serial.print("  Data:");
	  for(uint8_t i=0; i<8; i++)
	  {
		  Serial.print(" ");
		  Serial.print(recData[i]);
	  }
    Serial.println();
  }
 
  delay(10);
}