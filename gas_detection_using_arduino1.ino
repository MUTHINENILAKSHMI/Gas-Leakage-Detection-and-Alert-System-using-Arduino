#include <LiquidCrystal.h>
// LCD pins: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(5, 6, 8, 9, 10, 11);

int redLed = 3;
int greenLed = 2;
int buzzer = 4;
int sensor = A0;

int sensorThreshold = 400; 

void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(sensor, INPUT);  

  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("System Ready");
  delay(2000);
  lcd.clear();
}

void loop() {
  int analogValue = analogRead(sensor);
  Serial.print("Sensor Reading: ");
  Serial.println(analogValue);

  if (analogValue > sensorThreshold) {
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    tone(buzzer, 1000);  // Tone ON

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("!! ALERT !!");
    lcd.setCursor(0, 1);
    lcd.print("EVACUATE NOW");
    delay(1000);
  } else {
    digitalWrite(greenLed, HIGH);
    digitalWrite(redLed, LOW);
    noTone(buzzer);  // Tone OFF

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Status: SAFE");
    lcd.setCursor(0, 1);
    lcd.print("All Clear");
    delay(1000);
  }
}

    