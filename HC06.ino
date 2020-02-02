#include <SoftwareSerial.h>
SoftwareSerial HC06(10, 11); //HC06-TX Pin 10, HC06-RX to Arduino Pin 11

int LED = 12; //Use whatever pins you want 
int LDR = A0; //Sensor Pin to Analog A0

void setup() {
  HC06.begin(9600); //Baudrate 9600 , Choose your own baudrate 
  pinMode(LED, OUTPUT);
  pinMode(LDR, INPUT);
}

void loop() {

  if(HC06.available() > 0) //When HC06 receive something
  {
    char receive = HC06.read(); //Read from Serial Communication
    if(receive == '1') //If received data is 1, turn on the LED and send back the sensor data
    {
      digitalWrite(12, HIGH); 
      int data = analogRead(LDR);
      HC06.println(data);
    }
    else digitalWrite(12, LOW);//If received other data, turn off LED
  }

}
