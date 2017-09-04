//SMART_Bin
// This code is written in arduino ide by Pulkit Singhal TidyBeings in HackfestISM 2016.
// This code helps android application Blueooth RC Controller to communicate as a wireless platform with arduino.

#define fwd 'F'      //When upward arrow is pressed in android application it returns 'F' value.
#define back 'B'     //When Downward arrow is pressed in android application it returns 'B' value.
#define right 'R'    //When Right arrow is pressed in android application it returns 'R' value.
#define left 'L'     //When Left arrow is pressed in android application it returns 'L' value.
#define st 'S'       //To Abort operation using android application, it returns 'S' value.
#define trigPin 11   //trigger pin of ultrasonic sensor is assigned to 11 pin of arduino.
#define echoPin 12   //echo pin of ultrasonic sensor is assigned to 12 pin of arduino.

void setup() {
 Serial.begin(9600); //Baud rate
 Serial.println("ADVANCED_CLEANING_SYSTEM_BY_T!dyBe!ngs_HACKFESTISM(2k16)");
 Serial.flush();
pinMode(trigPin,OUTPUT);             //To set the configuration of all pins to be used
pinMode(echoPin,INPUT);
pinMode(13,OUTPUT);
pinMode(10,OUTPUT);
pinMode(9,OUTPUT);

pinMode(5,OUTPUT);
 pinMode(6,OUTPUT);
 pinMode(7,OUTPUT);
 pinMode(8,OUTPUT);
}

void loop() {
  digitalWrite(13,HIGH);            //supply of ultrasonic sensor
  
if(Serial.available()>0)
{
  char r = Serial.read();           //gets the character given by android application via bluetooth.
  
  if(r==fwd)
  
  {
    digitalWrite(5,HIGH);           //SMART_Bin moves forward
    digitalWrite(6,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    
    Serial.println("FORWARD");
    
  }
  else if(r==back)
  {
    digitalWrite(5,LOW);            //SMART_Bin moves Backward
    digitalWrite(6,HIGH);         
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    
    Serial.println("BACK");
    
   
  }
 else if(r==right)
  {
    digitalWrite(5,HIGH);          //SMART_Bin turns right using Differential Drive.
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    
    Serial.println("RIGHT");
    
    
  }
 else if(r==left)
  {
    digitalWrite(5,LOW);          //SMART_Bin turns left using Differential Drive.
    digitalWrite(6,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    
    Serial.println("LEFT");
    
   
  }
  else if(r==st)
  {
    digitalWrite(5,LOW);          //To abort all processes of SMART_Bin.
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    
    Serial.println("STOP");
    
   
  }
  
  
}
 long distance,duration;
digitalWrite(trigPin,LOW);             //Set configurations of ultrasonic sensor.
delayMicroseconds(2);
digitalWrite(trigPin,HIGH);
delayMicroseconds(10);
digitalWrite(trigPin,LOW);
duration=pulseIn(echoPin,HIGH);
distance=(duration/2)/29.1;           //calculation of distance in cm.
if(distance<8){                       //if distance is less than 8 cm dustbin is full sound the BUZZER alarm.
  Serial.print(distance);
  Serial.println("cm");
  digitalWrite(10,LOW);
  digitalWrite(9,HIGH);
  delay(50);
  digitalWrite(10,LOW);
  digitalWrite(9,LOW);               //Stop the Buzzer after certain duration.
} 

}
