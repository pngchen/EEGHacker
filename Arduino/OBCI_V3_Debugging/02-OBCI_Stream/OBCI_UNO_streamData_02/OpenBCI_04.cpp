

#include "OpenBCI_04.h"

void OpenBCI::initialize(void){
  initialize_ads();
  initialize_accel();
}

void OpenBCI::initialize_ads(void) {
  ads.initialize(PIN_DRDY, PIN_RST, ADS_SS);  // adjust here to test daisy module!
}

void OpenBCI::initialize_accel(void) {
  accel.initialize();
}

void OpenBCI::enable_accel(void) {
  accel.enable_accel();
}

void OpenBCI::disable_accel(void){
  accel.disable_accel();
}

byte OpenBCI::getAccelID(void){
  return accel.getDeviceID();
}

boolean OpenBCI::LIS3DH_DataReady(void){
  return (accel.LIS3DH_DataReady());
}

void OpenBCI::getAccelData(void){
  accel.LIS3DH_updateAxisData();
}


int OpenBCI::getX(void){ return accel.getX(); }
int OpenBCI::getY(void){ return accel.getY(); }
int OpenBCI::getZ(void){ return accel.getZ(); }



// ADS FUNCTIONS
void OpenBCI::printAllRegisters(void) {
  Serial.println("\nADS Registers:");
  ads.printAllRegisters();
  delay(100);
  Serial.println("LIS3DH Registers:");
  delay(100);
  accel.readAllRegs();
}

byte OpenBCI::getADS_ID(void){
  return ads.getDeviceID();
}

void OpenBCI::activateChannel(int chan, byte gainCode, byte inputType){
  ads.activateChannel(chan, gainCode, inputType);
}

void OpenBCI::activateChannel(int chan, byte gainCode, byte inputType, boolean useInBias){
  ads.activateChannel(chan, gainCode, inputType, useInBias); 
}

void OpenBCI::deactivateChannel(int N){
  ads.deactivateChannel(N); 
}

void OpenBCI::startStreaming(void){
  ads.startADS();
  if(useAccel){accel.enable_accel();}
}

void OpenBCI::stopStreaming(void){
  ads.stopADS();
  accel.disable_accel();
}

void OpenBCI::reset_ads(void){
  ads.resetADS();
}

boolean OpenBCI::isDataAvailable(void){
  return ads.isDataAvailable();
}

void OpenBCI::updateChannelData(void){
  ads.updateChannelData();
}

void OpenBCI::setSRB1(boolean desired_state){
  ads.setSRB1(desired_state);
}

void OpenBCI::writeDataToDongle(byte sampleNumber){
  Serial.write(sampleNumber); // 1 byte
  ads.writeADSchannelData();  // 24 bytes
  accel.writeLIS3DHdata();    // 6 bytes
}

//Configure the test signals that can be inernally generated by the ADS1299
void OpenBCI::configureInternalTestSignal(byte amplitudeCode, byte freqCode)
{
  ads.configureInternalTestSignal(amplitudeCode, freqCode);
}

