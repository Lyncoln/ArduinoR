#include <dht.h> 
dht DHT;

#define TEMP2 2
#define TEMP3 3
#define TEMP4 4
#define TEMP5 5
#define TEMP6 6
#define TEMP7 7
#define BUZ 8
char ports[6] = {'TEMP1','TEMP2','TEMP3','TEMP4','TEMP5','TEMP6'};

void setup() {
  pinMode(TEMP2, INPUT);
  pinMode(TEMP3, INPUT);
  pinMode(TEMP4, INPUT);
  pinMode(TEMP5, INPUT);
  pinMode(TEMP6, INPUT);
  pinMode(TEMP7, INPUT);
  pinMode(BUZ,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  int temp2 = temperatura(TEMP2),
  temp3 = temperatura(TEMP3),
  temp4 = temperatura(TEMP4),
  temp5 = temperatura(TEMP5),
  temp6 = temperatura(TEMP6),
  temp7 = temperatura(TEMP7);

  
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
