

// AIRPAD
/* ############################################################ 
 
 *  By: Gianluca Pugliese 
 *  BQlabs
 *  Android App for Controller:  https://play.google.com/store/apps/details?id=com.br3.udpctl&hl=th
 *  Hardware Micro Controller: BQ Zum board or compatible Arduino/Genuino BT board
  
 *########################################################### */

#include <Servo.h>

Servo myservo1;  // create servo object to control a servo

Servo myservo2;  // create servo object to control a servo

Servo myservo3;  // create servo object to control a servo

Servo myservo4;  // create servo object to control a servo



int state;

void setup() 
{

  Serial.begin(19200);

  
  myservo1.attach(6);  // rigth ext pin 6
  myservo2.attach(7);  // right int pin 7
  myservo3.attach(8);  // left int pin 8
  myservo4.attach(9);  // left int pin 9
}

void loop() {


  //Save income data to variable 'state'
    if(Serial.available() > 0){    
      state = Serial.read();  
    }

/*****MOVEMENTS BASED ON A BRIAN ROBOT (https://github.com/bqlabs/Brian) THAT USE 2 CONTINUAL ROTATION SERVO FOR EACH SIDE****/
 /*****FELL FREE TO CUSTOMIZE MOVEMENTS :)  ****/


  /***********************Forward****************************/
  //If state is equal with letter 'A', go forward!
    if (state == 'A') {
      
    myservo1.write(180);              
    myservo4.write(0);             
   delay(500);                       // waits 1/2 sec to async the second servo
    myservo2.write(180);             
    myservo3.write(0);            
   delay(500); 
    }

    
  /**********************Left************************/
  //If state is equal with letter 'D',go left
  
    else if (state == 'D') {
      //Motor
      myservo1.write(180);              
    myservo4.write(0);             
   delay(500);                       // waits 1/2 sec to async the second servo
    myservo2.write(0);             
    myservo3.write(180);            
   delay(500); 
    }

    
  /**********************Forward Right************************/
  //If state is equal with letter 'B',  go forward right
    else if (state == 'B') {
      //Motor
         myservo1.write(0);              
    myservo4.write(180);             
   delay(500);                       // waits 1/2 sec to async the second servo
    myservo2.write(180);             
    myservo3.write(0);            
   delay(500); 
    }

    
  /***********************Backward****************************/
  //If state is equal with letter 'C',  go backward
    else if (state == 'C') {
      //Motor
        myservo1.write(0);              
    myservo4.write(180);             
   delay(500);                       // waits 1/2 sec to async the second servo
    myservo2.write(0);             
    myservo3.write(180);            
   delay(500); 
    }


 /***********************STOP****************************/
  //If state is equal with letter 'S', stop
    else if (state == 'S') {
      //Motor
         myservo1.write(90);              
    myservo4.write(90);             
   delay(500);                       // waits 1/2 sec to async the second servo
    myservo2.write(90);             
    myservo3.write(90);            
   delay(500); 
    }


  
 /***********************LOVE****************************/
  //If state is equal with letter 'E', LOVE BUTTON
    else if (state == 'E') {
     
      //PUT HERE YOUR MOVEMENTS
  
    }


 /***********************FIRE****************************/
  //If state is equal with letter 'F', FIRE BUTTON
    else if (state == 'F') {
     
      //PUT HERE YOUR MOVEMENTS
  
    }


 /***********************SKULL****************************/
  //If state is equal with letter 'G', SKULL BUTTON
    else if (state == 'G') {
     
      //PUT HERE YOUR MOVEMENTS
  
    }


 /***********************PLUS****************************/
  //If state is equal with letter 'H', PLUS BUTTON
    else if (state == 'H') {
     
      //PUT HERE YOUR MOVEMENTS
  
    }


 /***********************PUNCH****************************/
  //If state is equal with letter 'I', PUNCH BUTTON
    else if (state == 'I') {
     
      //PUT HERE YOUR MOVEMENTS
  
    }


 /***********************MASK****************************/
  //If state is equal with letter 'J', MASK BUTTON
    else if (state == 'J') {
     
      //PUT HERE YOUR MOVEMENTS
  
    }



  

   
 }
  

