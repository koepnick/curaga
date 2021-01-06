// #include <Stepper.h>
// #include "bitmap.h"
// #define STEPS 2038 // the number of steps in one revolution of your motor (28BYJ-48)
// // D2-D5
// uint8_t p1 = 3; // D3
// uint8_t p2 = 4; // D4
// uint8_t p3 = 5; // D5
// uint8_t p4 = 6; // D6

// int controlPin = A0;
// int pwmPin = 7;
// int rotationalValue = 0;

// /*
//    The slider potentiometer goes from 0 to 910-ish
//    The rotational potentiometer goes from 0 to 900
//    Both on USB

//    But using 3v3 as a range of 0-705 for both
// */



// #include <SPI.h>
// #include <Wire.h>
// #include <Adafruit_GFX.h>
// #include <Adafruit_SSD1306.h>
// #include <Stepper.h>

// #define SCREEN_WIDTH 128 // OLED display width, in pixels
// #define SCREEN_HEIGHT 64 // OLED display height, in pixels

// // Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// #define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
// Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// const int stepsPerRevolution = 200;
// Stepper myStepper(stepsPerRevolution, p1, p3, p2, p4);


// void drawText() {
//   display.setTextSize(1);             // Normal 1:1 pixel scale
//   display.setTextColor(SSD1306_WHITE);        // Draw white text
//   display.setCursor(0, 0);            // Start at top-left corner
//   //  display.println(F("Hello, world!"));
//   //
//   //  display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Draw 'inverse' text
//   //  display.println(3.141592);

//   display.setTextSize(2);             // Draw 2X-scale text
//   display.setTextColor(SSD1306_WHITE);
//   display.print(F("Curaga"));
//   //display.print(F("0x")); display.println(0xDEADBEEF, HEX);

//   display.setTextSize(1);
//   display.setCursor(0, 40);
//   display.print("Built on:");
//   display.setCursor(0, 50);
//   display.print(__DATE__);


//   display.drawBitmap(
//     (display.width()  - imageWidth ) / 2,
//     (display.height() - imageHeight) / 2,
//     bitmap, imageWidth, imageHeight, 1);

//   display.display();
//   delay(2000);
// }

// Stepper stepper(STEPS, p1, p2, p3, p4);
// void setup() {
//   // nothing to do
//   Serial.begin(115200);
//   pinMode(controlPin, INPUT);
//   pinMode(pwmPin, OUTPUT);
//   //  digitalWrite(p1, HIGH);
//   //  digitalWrite(p2, HIGH);
//   //  digitalWrite(p3, HIGH);
//   //  digitalWrite(p4, HIGH);

//   if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
//     Serial.println(F("SSD1306 allocation failed"));
//     for (;;); // Don't proceed, loop forever
//   }
//   else {
//     Serial.println(F("SSD1306 allocation succeeded"));
//   }
//   display.clearDisplay();
//   drawText();
//   delay(1000);
//   //  display.clearDisplay();
//   //  display.display();

// }

// int prevValue = 0;
// int prevPct = 0;

// void loop() {
//   rotationalValue = analogRead(controlPin);
//   (float)rotationalValue;
//   int delta = abs(rotationalValue - prevValue);
//   int pct = rotationalValue / 700.0 * 100.0;

//   // Fix that annoying flicker
//   //  if(abs(pct - prevPct) > 1){
//   //  display.clearDisplay();
//   //  display.setCursor(10, 10);
//   //  display.print(pct);
//   //  display.print("%");
//   //  display.setCursor(10, 30);
//   //  display.print(rotationalValue);
//   //  display.setCursor(10, 50);
//   //
//   //  }
//   prevPct = pct;

//   int sensorReading = analogRead(A0);
//   // map it to a range from 0 to 100:
//   int motorSpeed = map(sensorReading, 0, 1023, 0, 100);
//   // set the motor speed:
//   if (motorSpeed > 0) {
//     myStepper.setSpeed(motorSpeed);
//     // step 1/100 of a revolution:
//     myStepper.step(stepsPerRevolution / 100);
//   }

//   // My own debuggery

//   //  digitalWrite(p1, LOW);
//   //  digitalWrite(p2, LOW);
//   //  digitalWrite(p3, LOW);
//   //  digitalWrite(p4, LOW);
//   //
//   //  if(pct < 25){
//   //    //digitalWrite(p1, HIGH);
//   //    //display.print("p1 is high");
//   //    myStepper.setSpeed(100);
//   //    myStepper.step(10);
//   //    display.display();
//   //  } else if(pct < 50){
//   //    myStepper.setSpeed(0);
//   //    //digitalWrite(p2, HIGH);
//   //    display.print("p2 is high");
//   //    display.display();
//   //  }
//   //   else if(pct < 75){
//   //    //digitalWrite(p3, HIGH);
//   //    display.print("p3 is high");
//   //    display.display();
//   //  }
//   //   else{
//   //    //digitalWrite(p4, HIGH);
//   //    display.print("p4 is high");
//   //    display.display();
//   //  }


//   //  if (delta > 100){
//   //    display.setTextSize(1);
//   //    display.print(F("Linear: "));
//   //    display.println(delta);
//   //    display.display();
//   //    prevValue = rotationalValue;
//   //  }
//   //Serial.println(rotationalValue);
//   //delay(100);

//   //  analogWrite(pwmPin, 0);
//   //  Serial.println("0");
//   //  delay(5000);
//   //  analogWrite(pwmPin, 128);
//   //  Serial.println("128");
//   //  delay(5000);
//   //  analogWrite(pwmPin, 255);
//   //  Serial.println("255");
//   //  delay(5000);
//   //stepper.setSpeed(4); // 1 rpm
//   //stepper.step(2038); // do 2038 steps -- corresponds to one revolution in one minute
//   //delay(1000); // wait for one second
//   //stepper.setSpeed(6); // 6 rpm
//   //stepper.step(-2038); // do 2038 steps in the other direction with faster speed -- corresponds to one revolution in 10 seconds
// }
