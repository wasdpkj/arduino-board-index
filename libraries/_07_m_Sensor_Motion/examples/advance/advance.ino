// LICENSE: GPL v3 (http://www.gnu.org/licenses/gpl.html)
// ==============

// 版权所有：
// @Machine  maxing@microduino.cc
// ==============
#include <Sensor_Motion.h>

SoftwareSerial mySerial(4, 5);   // RX, TX
sensorMotion motion(&mySerial);  //使用软串口

//sensorMotion motion(&Serial1); //使用硬串口0，1

float ypr[3];//用来存放三轴姿态角

void setup() {
  Serial.begin(115200);
  motion.begin();
  motion.setFullScaleGyroRange(GYRO_FS_1000);
  motion.setFullScaleAccelRange(ACCEL_FS_8);
}

void loop() {
  //如果成功接收数据，则串口输出三轴姿态角
  if (motion.getData(MOTION_3, ypr)) {
    Serial.print(ypr[0]);
    Serial.print("  ");
    Serial.print(ypr[1]);
    Serial.print("  ");
    Serial.println(ypr[2]);
  }
  delay(10);
}
