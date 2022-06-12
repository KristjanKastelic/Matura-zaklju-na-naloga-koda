#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define trigPin 12
#define echoPin 11
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
const int LED1 = 2;
const int LED2 = 3;
const int LED3 = 4;
const int LED4 = 5;
const int LED5 = 6;
const int LED6 = 7;
const int LED7 = 8;
float duration;
float distance;
void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
}   
 
  display.display();
  delay(200);
  display.clearDisplay();
   pinMode(trigPin , OUTPUT);
  pinMode(echoPin , INPUT);
  
  
  pinMode(LED1 , OUTPUT);
  pinMode(LED2 , OUTPUT);
  pinMode(LED3 , OUTPUT);
  pinMode(LED4 , OUTPUT);
  pinMode(LED5 , OUTPUT);
  pinMode(LED6 , OUTPUT);
  pinMode(LED7 , OUTPUT);  
  int duration = 0;
  int distance = 0;
}
void loop(){
  display.clearDisplay(); 
  drawGraph();
  drawText();
  LED();
 display.display();
 delay(200);
}

void drawGraph(){
  float graph = distanceInCM();
  if (graph >= 70){
    graph = 70;  
  }
  display.drawRect(29,43,70,10,WHITE);
  display.fillRect(29,43,graph,10,WHITE);
  display.drawLine(64,42,64,54,WHITE);
  display.setTextSize(1);
  display.setCursor(29,56);
  display.println("0");
  display.setCursor(64,56);
  display.println("35");
  display.setCursor(99,56);
  display.println("70");
  
  
}
float distanceInCM(){
  float distance_cm;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance_cm = (duration/2) / 29.1;
return(distance_cm);

}  
 void drawText(){
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(5,10);
  display.println(distanceInCM());
  display.setCursor(113,24);
  display.setTextSize(1);
  display.println("cm");
}

void LED(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);  
  duration = pulseIn(echoPin, HIGH);
  distance = duration/58.2;
  if ( distance <= 10 )
  {
    digitalWrite(LED1, HIGH);
  }
  else
  {
    digitalWrite(LED1, LOW);
  }
  if ( distance <= 20 )
  {
    digitalWrite(LED2, HIGH);
  }
  else
  {
    digitalWrite(LED2, LOW);
  }
  if ( distance <= 30 )
  {
    digitalWrite(LED3, HIGH);
  }
  else
  {
    digitalWrite(LED3, LOW);
  }
  if ( distance <= 40 )
  {
    digitalWrite(LED4, HIGH);
  }
  else
  {
    digitalWrite(LED4, LOW);
  }
  if ( distance <= 50 )
  {
    digitalWrite(LED5, HIGH);
  }
  else
  {
    digitalWrite(LED5, LOW);
  }
  if ( distance <= 60 )
  {
    digitalWrite(LED6, HIGH);
  }
  else
  {
    digitalWrite(LED6, LOW);
  }
  if ( distance <= 70 )
  {
    digitalWrite(LED7, HIGH);
  }
  else
  {
    digitalWrite(LED7, LOW);
  }
  delay(200);
}
