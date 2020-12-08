#include "CTBot.h"
CTBot myBot;

String ssid = "NYEH";     
String pass = "light gaia"; 
String token = "1342443857:AAHJqH1KaZJhZr30RDOQkQOxaJBHN7g0H5o";   
uint8_t redLed = D1;               
uint8_t greenLed = D2;                       
                                    

void setup() {
  Serial.begin(115200);
  Serial.println("Starting TelegramBot...");

  myBot.wifiConnect(ssid, pass);

  myBot.setTelegramToken(token);

  // check if all things are ok
  if (myBot.testConnection())
    Serial.println("\ntestConnection OK");
  else
    Serial.println("\ntestConnection NOK");

  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  digitalWrite(redLed, LOW); 
  digitalWrite(greenLed, LOW);

}

void loop() {
  TBMessage msg;

  if (myBot.getNewMessage(msg)) {

    if (msg.text.equalsIgnoreCase("Red Light on")) {              
      digitalWrite(redLed, HIGH);                               
      myBot.sendMessage(msg.sender.id, "Red Light is now ON");  
    }
    else if (msg.text.equalsIgnoreCase("Red Light off")) {        
      digitalWrite(redLed, LOW);                              
      myBot.sendMessage(msg.sender.id, "Red Light is now OFF"); 
    }
      if (msg.text.equalsIgnoreCase("Green Light on")) {              
      digitalWrite(greenLed, HIGH);                               
      myBot.sendMessage(msg.sender.id, "Green Light is now ON");  
    }
    else if (msg.text.equalsIgnoreCase("Green Light off")) {         
      digitalWrite(greenLed, LOW);                              
      myBot.sendMessage(msg.sender.id, "Green Light is now OFF"); 
    }
    else {                                                    
      
      String reply;
      reply = (String)"Welcome " + msg.sender.username + (String)". Try LIGHT ON or LIGHT OFF.";
      myBot.sendMessage(msg.sender.id, reply);             
    }
  }
  
  delay(50);
}
