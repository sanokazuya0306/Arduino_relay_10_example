/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://www.arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */


// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  
  // initialize digital pin 4-13 as an output.
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  int i=0;

//  //1つずつ順番に点灯
//  singleOn();
//  
//  //2つずつ順番に点灯
//  doubleOn();
//  
//  //1つずつ増やして減らす
//  wave();
//
//  //3つずつ光らせる
//  tripleOn();
//  tripleOn();
//  tripleOn();
//
//  //半分ずつ光らせる
//  halfOn();

  //全体点滅
  blinkAll(1000);

//  //caution!
//  blinkAll(500);
//  blinkAll(500);
//
//  //danger!
//  blinkAll(250);
//  blinkAll(250);
//  blinkAll(250);
//  blinkAll(250);
//
//  blinkAll(125);
//  blinkAll(125);
//  blinkAll(125);
//  blinkAll(125);
//  
//  blinkAll(50);
//  blinkAll(50);
//  blinkAll(50);
//  blinkAll(50);
  
}


void singleOn() {
  for(int i=4;i<14;i++){
    if(i>4){
      digitalWrite(i-1, LOW);
    }
    digitalWrite(i, HIGH);
    Serial.println(i);
    delay(1000);
  }
  digitalWrite(13, LOW);
}

void doubleOn() {
  for(int i=4;i<14-1;i+=2){
    if(i>5){
      digitalWrite(i-1, LOW);
      digitalWrite(i-2, LOW);
    }
    digitalWrite(i, HIGH);
    digitalWrite(i+1, HIGH);
    Serial.print(i);
    Serial.print(",");
    Serial.println(i+1);
    delay(1000);
  }
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
}

void tripleOn(){
  for(int i=4;i<14-2;i+=3){
    if(i>6){
      digitalWrite(i-1, LOW);
      digitalWrite(i-2, LOW);
      digitalWrite(i-3, LOW);
    }
    digitalWrite(i, HIGH);
    digitalWrite(i+1, HIGH);
    digitalWrite(i+2, HIGH);
    Serial.print(i);
    Serial.print(",");
    Serial.print(i+1);
    Serial.print(",");
    Serial.println(i+2);
    delay(1000);
  }
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
}

void wave() {
  for(int i=4;i<14;i++){
    digitalWrite(i, HIGH);
    Serial.print(i);
    if(i<13){
      Serial.print(",");
    } else {
      Serial.println("");
    }
    delay(1000);
  }
  for(int i=4;i<14;i++){
    digitalWrite(i, LOW);
    Serial.print(i);
    if(i<13){
      Serial.print(",");
    } else {
      Serial.println("");
    }
    delay(1000);
  }
}

void halfOn() {
  for(int i=0; i<5; i++){
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    Serial.println("left");
    delay(1000);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);

    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(13, HIGH);
    Serial.println("right");
    delay(1000);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
  }
}

void blinkAll(int delayTime){
  for(int i=0; i<5; i++){
    for(int j=4; j<14; j++){
      digitalWrite(j, HIGH);
    }
    Serial.println("All on");
    delay(delayTime);
    for(int j=4; j<14; j++){
      digitalWrite(j, LOW);
    }
    Serial.println("All off");
    delay(delayTime);
  }
}

