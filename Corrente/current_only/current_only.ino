#include "EmonLib.h"

EnergyMonitor emon1;

int rede = 120;

int pino_sct = A1;

void setup(){
  Serial.begin(9600);
  emon1.current(pino_sct,60.6);
  
}

void loop(){
  double Irms = emon1.calcIrms(1480);
  Serial.println("Corrente : ");
  Serial.println(Irms);
  delay(500);
  
}
