#include <Adafruit_NeoPixel.h>
#include <SoftwareServo.h>

#define SERVO_PIN 1
#define BLANK 0
#define FILLED 45
#define LED_PIN 2
#define LED_COUNT 1

// int r, g, b;
Adafruit_NeoPixel leds = Adafruit_NeoPixel(LED_COUNT, LED_PIN, NEO_RGB + NEO_KHZ800);
SoftwareServo eyes;


void setup() {
  // put your setup code here, to run once:
  eyes.attach(SERVO_PIN);
  
}

// RGB is from 0 to 1
void setState(int state) {
  leds.begin();
  leds.setPixelColor(0, 0, 0, 0);
  leds.show();   
  for (int n = 0; n<100; n++){
    eyes.write(state);
    delay(10);
    SoftwareServo::refresh();
  }
  leds.setPixelColor(0, 0, 0, 0);
  leds.show();   
}

// RGB is from 0 to 1
void pulseLED(float r, float g, float b) {
  for (int n = 0; n<=200; n++){
    leds.setPixelColor(0, (int)(r*n), (int)(g*n), (int)(b*n));
    leds.show();
    delay(10);
  }
  for (int n = 200; n>=0; n--){
    leds.setPixelColor(0, (int)(r*n), (int)(g*n), (int)(b*n));
    leds.show();
    delay(10);
  }
}

void pulseRandomColor() {
  float multR = (float)(random(100))/(float)(100);
  float multG = (float)(random(100))/(float)(100);
  float multB = (float)(random(100))/(float)(100);
  pulseLED(multR, multG, multB);
}

void loop() {
  setState(BLANK);
  pulseLED(0.6, 0.6, 0.6);
  setState(FILLED);
  pulseRandomColor();
}
