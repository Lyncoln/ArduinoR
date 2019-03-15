#include <dht.h>  // Biblioteca dos sensores de temperatura
#include "EmonLib.h" // Biblioteca do sensor de corrente

// Definindo objetos 


dht DHT; 
EnergyMonitor emon1;

//<===================================================>


//Definindo Pinos 


#define TEMP2 2
#define TEMP3 3
#define TEMP4 4
#define TEMP5 5
#define TEMP6 6
#define TEMP7 7
#define BUZ 8
#define CORRENTE A1
#define MQ2 A2
#define MQ6 A3

//<===================================================>

//Preparando os pinos e serial

void setup() {
  Serial.begin(9600);
  pinMode(TEMP2, INPUT);
  pinMode(TEMP3, INPUT);
  pinMode(TEMP4, INPUT);
  pinMode(TEMP5, INPUT);
  pinMode(TEMP6, INPUT);
  pinMode(TEMP7, INPUT);
  emon1.current(CORRENTE,60.6);
  pinMode(MQ2,INPUT);
  pinMode(MQ6,INPUT);
  pinMode(BUZ,OUTPUT);

}

//<===================================================>

//Programa 

void loop() {

  //Lendo temperaturas dos sensores
  
  int temp2 = temperatura(TEMP2),
  temp3 = temperatura(TEMP3),
  temp4 = temperatura(TEMP4),
  temp5 = temperatura(TEMP5),
  temp6 = temperatura(TEMP6),
  temp7 = temperatura(TEMP7);
  
  //<===================================================>

  //Lendo corrente do sensor
  double Irms = emon1.calcIrms(1480);

  //<===================================================>

  //Lendo sensores de gas

  int sensorMQ2 = SensorGAS(MQ2),
      sensorMQ6 = SensorGAS(MQ6);

  //Mostrando sinais lidos 
  Serial.println("Sensores de temperatura : ");
  Serial.print(temp2);
  Serial.print("  ");
  Serial.print(temp3);
  Serial.print("  ");
  Serial.print(temp4);
  Serial.print("  ");
  Serial.print(temp5);
  Serial.print("  ");
  Serial.print(temp6);
  Serial.print("  ");
  Serial.println(temp7);
  Serial.print("Corrente : ");
  Serial.println(Irms);
  Serial.println("Sensores de gas");
  Serial.print("MQ2 : ");
  Serial.println(sensorMQ2);
  Serial.print("MQ6 : ");
  Serial.println(sensorMQ6);
  

  
  
  

  if(temp2 > 36 || temp3 > 36 ||temp4 > 36 ||temp5 > 36 ||temp6 > 36 ||temp7 > 36){
    digitalWrite(BUZ,HIGH);
  }
  else{
    digitalWrite(BUZ,LOW);
  }

  delay(2000);
  
  

}

int temperatura(char pino){
  DHT.read11(pino);
  int t = DHT.temperature;
  return(t);
}

int SensorGAS(char pino) {
  int leitura = analogRead(pino);
  Serial.println(leitura);  
}
