#include "Battery.h"

Battery::Battery(int ledStart, int ledEnd, int id){
  this->ledStart = ledStart;
  this->ledEnd = ledEnd;
  this->id = id;
}
int Battery::getStart(){
  return ledStart;
}

int Battery::getEnd(){
  return ledEnd;
}
float Battery::getCurrent(){
  return current;
}
float Battery::getVoltage(){
  return voltage;
}
void Battery::setCurrent(float c){
  this->current = c;
}
void Battery::setVoltage(float v){
  this->voltage = v;
}
int Battery::getHue(){
  return hue;
}
void Battery::setHue(int h){
  this->hue = h;
}
int Battery::getID(){
  return id;
}
