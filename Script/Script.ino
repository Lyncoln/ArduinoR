/* Definicao de macros*/

#define PRESENCA 3
#define TEMPERATURA_UMIDADE 2
#define GAS A0

/* Biblioteca do DHT11 (Sensor de temperatura) */
#include <dht.h> 
dht DHT;

void setup() {
  
  pinMode(PRESENCA, INPUT);
  pinMode(GAS,INPUT);
  Serial.begin(9600);
  
}

void loop() {
  SensorGas();
  delay(1000); 
}

/* Funcoes Auxiliares */

void SensorDht(void){
  DHT.read11(TEMPERATURA_UMIDADE); 
  float temperatura = DHT.temperature,
        umidade = DHT.humidity;  
  Serial.print(temperatura);
  Serial.print("   ");
  Serial.println(umidade); 
}

void SensorPresenca(void){
   if(digitalRead(PRESENCA)){
    Serial.println(1);
  }
  else {
    Serial.println(0);   
  } 
}

void SensorGas(void) {
  int leitura = analogRead(GAS);
  //float nivelGas = (leitura*100.0)/1023.0;
  Serial.println(leitura);
  
}
