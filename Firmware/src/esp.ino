//-------------------------------------------------------------
//--    Controlling an OmniBoard over sockets creating an AP
//--------------------------------------------------------------
//--    BQ
//--------------------------------------------------------------
//--    Example created by
//--        Alvaro Ferran Cifuentes (alvaroferran)
//--------------------------------------------------------------
//--    Released on March 2016
//--    under the GPL v3
//--------------------------------------------------------------

#include <ESP8266WiFi.h>
#include <WiFiClient.h>

WiFiServer server(80);

//Wifi AP credentials
const char *ssid = "OmniBoard-Wifi-AP";
const char *password = "1234567890";

String input;
boolean stringComplete = false;


int motL1=D1, motL2=D2, motR1=D3, motR2=D4;


void setup() {
    WiFi.softAP(ssid, password);
    server.begin();

    pinMode(motL1, OUTPUT);
    pinMode(motL2, OUTPUT);
    pinMode(motR1, OUTPUT);
    pinMode(motR2, OUTPUT);
}





void front() {
    analogWrite(motL1, 1024*0.9);
    analogWrite(motL2, 1024*0);
    analogWrite(motR1, 1024*0.9);
    analogWrite(motR2, 1024*0);
}

void back() {
    analogWrite(motL1, 1024*0);
    analogWrite(motL2, 1024*0.9);
    analogWrite(motR1, 1024*0);
    analogWrite(motR2, 1024*0.9);
}

void right() {
    analogWrite(motL1, 1024*0.7);
    analogWrite(motL2, 1024*0);
    analogWrite(motR1, 1024*0);
    analogWrite(motR2, 1024*0);
}

void left() {
    analogWrite(motL1, 1024*0);
    analogWrite(motL2, 1024*0);
    analogWrite(motR1, 1024*0.7);
    analogWrite(motR2, 1024*0);
}

void halt() {
    analogWrite(motL1, 1024*0);
    analogWrite(motL2, 1024*0);
    analogWrite(motR1, 1024*0);
    analogWrite(motR2, 1024*0);
}

void heart(){}
void flame(){}
void skull(){}
void plus(){}
void punch(){}
void mask(){}


void parseData(String data){
    int plusIndex = data.indexOf('+');

    if(data.substring(0,plusIndex).toInt()==1)
    front();
    else if(data.substring(0,plusIndex).toInt()==2)
    back();
    else if(data.substring(0,plusIndex).toInt()==3)
    left();
    else if(data.substring(0,plusIndex).toInt()==4)
    right();
    else if(data.substring(0,plusIndex).toInt()==5)
    halt();
    else if(data.substring(0,plusIndex).toInt()==6)
    heart();
    else if(data.substring(0,plusIndex).toInt()==7)
    flame();
    else if(data.substring(0,plusIndex).toInt()==8)
    skull();
    else if(data.substring(0,plusIndex).toInt()==9)
    plus();
    else if(data.substring(0,plusIndex).toInt()==10)
    punch();
    else if(data.substring(0,plusIndex).toInt()==11)
    mask();
}




void loop() {
    WiFi.mode(WIFI_AP);

    WiFiClient client = server.available();
    if (!client) {
        Serial.println(WiFi.localIP());
        delay(1000);
    }
    while (client.connected()) {
        while (client.available()) {
            input = client.readStringUntil('+');
            stringComplete = true;
        }
        if (stringComplete) {
            parseData(input);
            stringComplete = false;
        }
    }
}
