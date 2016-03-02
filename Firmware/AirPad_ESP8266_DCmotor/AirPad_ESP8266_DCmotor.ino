

// AIRPAD
/* ############################################################ 
 *  By: Gianluca Pugliese 
 *  BQlabs
 *  Android App for Controller:  http://ai2.appinventor.mit.edu/#5583264621789184
 *  Hardware Micro Controller: NodeMCU V2 (ESP8266-12)
  
 *  Based on the awesome job of Vittaysak Rujivorakul
 *########################################################### */


 
#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

/* Set SSID and Password of your AP . */


const char *ssid = "AirPad";
const char *password = "";

ESP8266WebServer server(80);


int pin1_motor_R = D1;   ///E2
int pin2_motor_R = D2;
int pin1_motor_L = D3;   // E1
int pin2_motor_L = D4;

//Is possible to add more actuators, refer to your board
//int pin1_motor_C = D7;   // E1
//int pin2_motor_C = D8;
 


String cmd="1";

//  http://192.168.4.1 in a web browser


void handleRoot() {
  cmd=server.arg("cmd");

  
  // get cmd parameter from url :  http://192.168.4.1/?cmd=1

  
  checkcommand();

  server.send(200, "text/html", "<h1>AirPad connected</h1>" + cmd);
}



void setup() {
  delay(1000);
  Serial.begin(9600);

   pinMode(pin1_motor_R , OUTPUT);
   pinMode(pin2_motor_R, OUTPUT);
   pinMode(pin1_motor_L, OUTPUT);
   pinMode(pin2_motor_L, OUTPUT);

 
  Serial.println();
  Serial.print("Configuring access point...");
  /* You can remove the password parameter if you want the AP to be open. */
  WiFi.softAP(ssid, password);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.on("/", handleRoot);

  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
   
  server.handleClient();
}



void forward()
 {
   delay(10);
 //  Serial.println("forward");
   
 
   digitalWrite(pin1_motor_R, HIGH);
   digitalWrite(pin2_motor_R, LOW);
   
   digitalWrite(pin1_motor_L, HIGH);
   digitalWrite(pin2_motor_L, LOW);
   
 }


 void back()
 {
   delay(10);
  // Serial.println("back");
 
   digitalWrite(pin1_motor_R, LOW);
   digitalWrite(pin2_motor_R, HIGH);
   
   digitalWrite(pin1_motor_L, LOW);
   digitalWrite(pin2_motor_L, HIGH);
 }



 void left()
 {
  delay(10);
 // Serial.println("left");
 
  digitalWrite(pin1_motor_R, LOW);
  digitalWrite(pin2_motor_R, LOW);
   
   digitalWrite(pin1_motor_L, HIGH);
   digitalWrite(pin2_motor_L, LOW);
 }

 
 void right()
 {
  delay(10);
 // Serial.println("Right");
 
   digitalWrite(pin1_motor_R, HIGH);
  digitalWrite(pin2_motor_R, LOW);
   
   digitalWrite(pin1_motor_L, LOW);
   digitalWrite(pin2_motor_L, LOW);
 }

void Stop()
 {
  delay(10);
 // Serial.println("Stop");
 
   digitalWrite(pin1_motor_R, LOW);
  digitalWrite(pin2_motor_R, LOW);
   
   digitalWrite(pin1_motor_L, LOW);
   digitalWrite(pin2_motor_L, LOW);
 }


void love()
 {
  delay(10);
 // Serial.println("love");
 
/*
**************************
- PUT YOUR MOVEMENT HERE -
**************************
*/
 
 }


void fire()
 {
  delay(10);
 // Serial.println("fire");
 
/*
**************************
- PUT YOUR MOVEMENT HERE -
**************************
*/
 
 }


void skull()
 {
  delay(10);
 // Serial.println("skull");
 
/*
**************************
- PUT YOUR MOVEMENT HERE -
**************************
*/
 
 }


void plus()
 {
  delay(10);
 // Serial.println("plus");
 
/*
**************************
- PUT YOUR MOVEMENT HERE -
**************************
*/
 
 }


void punch()
 {
  delay(10);
 // Serial.println("punch");
 
/*
**************************
- PUT YOUR MOVEMENT HERE -
**************************
*/
 
 }


void mask()
 {
  delay(10);
 // Serial.println("mask");
 
/*
**************************
- PUT YOUR MOVEMENT HERE -
**************************
*/
 
 }






 void checkcommand()
 {
    
   int cm = cmd.toInt();
   switch(cm){
    
    
//UP
    case 1:     forward();      
    break;
    
//DOWN
    case 2:      back();      
    break;


//STOP
    case 5:  Stop();                              
    break;


//LEFT
    case 3:  left();    
    break;


//RIGH
    case 4:  right();   
    break;


//HEART
    case 6:  love();   
    break;


//FIRE
    case 7:  fire();   
    break;


//SKULL
    case 8:  skull();   
    break;


//PLUS
    case 9:  plus();   
    break;

//PUNCH
    case 10:  punch();   
    break;


//MASK
    case 11:  mask();   
    break;

    }

 }
