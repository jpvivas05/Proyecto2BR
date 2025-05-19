#include <Servo.h>
const int l1 = 11;
const int l2 = 10;
const int l3 = 4;
const int l4 = 12;
const int lposes = 8;
const int lmanual = 7;
const int anterior = A4;
const int siguiente = 13;
const int poten1 = A0;
const int poten2 = A1;
const int poten3 = A2;
const int poten4 = A3;
const int ks = 2;
int servo1 = 0;
int servo2 = 0;
int servo3 = 0;
int servo4 = 0;
int contador = 0;
int donomar = 0;
int num1 = 0;
int num2 = 0;
int num3 = 0;
int num4 = 0;
bool cambio;
bool regreso;
bool adelante;
Servo t1;
Servo t2;
Servo t3;
Servo t4;
long val1;
long val2;
long val3;
long val4;
void pose(int r1, int r2, int r3, int r4){
    t1.write(r1);
    t2.write(r2);
    t3.write(r3);
    t4.write(r4);
}
void tipo(){
  if (cambio == HIGH){
  contador=0;
    }
    if (cambio==LOW){
      contador=1;
    }
}
void setup() {
  // put your setup code here, to run once:
pinMode(l1, OUTPUT);
pinMode(l2, OUTPUT);
pinMode(l3, OUTPUT);
pinMode(l4, OUTPUT);
pinMode(lposes, OUTPUT);
pinMode(lmanual, OUTPUT); 
pinMode(poten1, INPUT); 
pinMode(poten2, INPUT); 
pinMode(poten3, INPUT);
pinMode(poten4, INPUT);
pinMode(ks, INPUT);
pinMode(anterior, INPUT);
pinMode(siguiente, INPUT);
Serial.begin(9600);
t1.attach(9);
t2.attach(6);
t3.attach(5);
t4.attach(3);
}

void loop() {
  // put your main code here, to run repeatedly:
regreso = digitalRead(anterior);
adelante = digitalRead(siguiente);
cambio = digitalRead(ks);
switch (contador){
case 0:
digitalWrite(l1, LOW);
digitalWrite(l2, LOW);
digitalWrite(l3, LOW);
digitalWrite(l4, LOW);
digitalWrite(lposes, HIGH);
digitalWrite(lmanual, LOW);
if (cambio == HIGH){
  contador=0;
}
if (cambio == LOW){
  contador=1;
}
  switch (donomar){
    case 0:
    digitalWrite(l1, HIGH);
    digitalWrite(l2, LOW);
    digitalWrite(l3, LOW);
    digitalWrite(l4, LOW);
    pose(0, 90, 45, 15);
    Serial.print("Ángulos de posición:");
    Serial.println(r1, r2, r3, r4);
    tipo();
    if (regreso == HIGH){
      donomar = 3;
      delay(500);
    }
    if (adelante == HIGH){
      donomar = 1;
      delay(500);
    }
    break;
    case 1:
    digitalWrite(l1, HIGH);
    digitalWrite(l2, HIGH);
    digitalWrite(l3, LOW);
    digitalWrite(l4, LOW);
    pose(15, 90, 0, 45);
    Serial.print("Ángulos de posición:");
    Serial.println(r1, r2, r3, r4);
    tipo();
    if (regreso == HIGH){
      donomar = 0;
      delay(500);
    }
    if (adelante == HIGH){
      donomar = 2;
      delay(500);
    }
    break;
    case 2:
    digitalWrite(l1, HIGH);
    digitalWrite(l2, HIGH);
    digitalWrite(l3, HIGH);
    digitalWrite(l4, LOW);
    pose(0, 90, 45, 15);
    tipo();
    if (regreso == HIGH){
      donomar = 1;
      delay(500);
    }
    if (adelante == HIGH){
      donomar = 3;
      delay(500);
    }
    break;
    case 3:
    digitalWrite(l1, HIGH);
    digitalWrite(l2, HIGH);
    digitalWrite(l3, HIGH);
    digitalWrite(l4, HIGH);
    pose(45, 15, 90, 0);
    Serial.print("Ángulos de posición:");
    Serial.println(r1, r2, r3, r4);
    tipo();
    if (regreso == HIGH){
      donomar = 2;
      delay(500);
    }
    if (adelante == HIGH){
      donomar = 0;
      delay(500);
    }
    break;
  }
break;
case 1:
digitalWrite(l1, LOW);
digitalWrite(l2, LOW);
digitalWrite(l3, LOW);
digitalWrite(l4, LOW);
digitalWrite(lmanual, HIGH);
digitalWrite(lposes, LOW);
num1 = analogRead(poten1);
num2 = analogRead(poten2);
num3 = analogRead(poten3);
num4 = analogRead(poten4);
val1 = map(num1, 0, 1023, 0, 180);
val2 = map(num2, 0, 1023, 0, 180);
val3 = map(num3, 0, 1023, 0, 180);
val4 = map(num4, 0, 1023, 0, 180);
t1.write(val1);
t2.write(val2);
t3.write(val3);
t4.write(val4);
Serial.print("Ángulos de posición:");
Serial.println(val1, val2, val3, val4);
if (cambio == HIGH){
  contador=0;
}
else if (cambio ==LOW){
  contador=1;
}
break;
}
delay(1);
}
