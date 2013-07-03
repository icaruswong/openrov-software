#include "Device.h"
#include "Settings.h"
Device::Device(){
  DeviceManager::registerDevice(this);
}

void Device::device_loop(Command cmd){
  
}

void Device::device_setup(){
  
}

void DeviceManager::registerDevice(Device *device){
  devices[device_count] = device;
  device_count++;
}

void DeviceManager::doDeviceLoops(Command cmd){
  for(int i=0;i<device_count;i++) {
    devices[i]->device_loop(cmd);
  }
}

void DeviceManager::doDeviceSetups(){
  for(int i=0;i<device_count;i++) {
    devices[i]->device_setup();
  }
}

void OutputSharedData(){

    Serial.print(F("motorAttached:"));
    Serial.print(thrusterdata::MATC);
    Serial.println(';');
    
    Serial.print(F("servo:"));
    Serial.print(cameraMountdata::CMNT);
    Serial.print(';');
    Serial.print(F("starg:"));
    Serial.print(cameraMountdata::CMTG);
    Serial.println(';');
    
    Serial.print(F("fmem:"));
    Serial.print(capedata::FMEM);
    Serial.print(';');
    Serial.print(F("vout:"));
    Serial.print(capedata::VOUT);
    Serial.print(';');    
    Serial.print(F("iout:"));
    Serial.print(capedata::IOUT);
    Serial.print(';');
    Serial.print(F("atmp:"));
    Serial.print(capedata::ATMP);
    Serial.print(';');    
    Serial.print(F("ver:"));
    Serial.print(capedata::VER);
    Serial.print(';');
    Serial.print(F("time:"));
    Serial.print(capedata::UTIM);
    Serial.println(';'); 
    
    Serial.print(F("hdgd:"));
    Serial.print(navdata::HDGD);
    Serial.println(';');         
}

int DeviceManager::device_count = 0;
Device *DeviceManager::devices[MAX_DEVICES];

// Initialize all of the shared data types
double navdata::HDGD = 0;

double capedata::FMEM = 0;
double capedata::VOUT = 0;
double capedata::IOUT = 0;
double capedata::ATMP = 0;
String capedata::VER = "";
int capedata::UTIM = 0;

boolean thrusterdata::MATC = true;

int cameraMountdata::CMNT = MIDPOINT;
int cameraMountdata::CMTG = MIDPOINT;

