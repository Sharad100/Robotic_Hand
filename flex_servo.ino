//Define sensors and servos

#include <Servo.h> //Includes servo library


Servo myservo_1;//pinki
Servo myservo_2;//middle
Servo myservo_3;//index
Servo myservo_4;//ring
int flexPin_1 = A1;//pinki
int flexPin_2 = A2;//ring
int flexPin_3 = A3;//middle
int flexPin_4 = A4;//index


void setup()
{
 
  Serial.begin(9600);
  
 
   pinMode(flexPin_1, INPUT);
   pinMode(flexPin_2, INPUT);
   pinMode(flexPin_3, INPUT);
   pinMode(flexPin_4, INPUT);

  myservo_1.attach(10);//pinki
  myservo_1.write(0);
  myservo_2.attach(6);//middle
  myservo_2.write(0);
  myservo_3.attach(5);//index
  myservo_3.write(180);
  myservo_4.attach(9);//ring
  myservo_4.write(0);  
 }

void loop()
{
  //Defines analog input variables
  int flex_1 = analogRead(flexPin_1);
  int flex_2 = analogRead(flexPin_2);
  int flex_3 = analogRead(flexPin_3);
  int flex_4 = analogRead(flexPin_4);
  
  
  Serial.println(flex_1);
  
  int pos_1;
  int pos_2;
  int pos_3;
  int pos_4;

  //maps analog signal to finger position
  pos_1 = map(flex_1, 613, 510, 180, 0);
  pos_1 = constrain(pos_1, 1, 180);

  pos_2 = map(flex_2, 640, 500, 180, 0);
  pos_2 = constrain(pos_2, 0, 180);

  pos_3 = map(flex_3, 580, 390, 180, 0);
  pos_3 = constrain(pos_3, 0, 180);

  pos_4 = map(flex_4, 650, 550, 180, 0);
  pos_4 = constrain(pos_4, 0, 180);



  //moves finger to position
  myservo_1.write(pos_1);
  myservo_2.write(pos_3);
  myservo_3.write(pos_4);
  myservo_4.write(pos_2);

  delay(50); 
  
}
