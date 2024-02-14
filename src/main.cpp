#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <string>

#include "Timer.h"
#include "timeConverter.h"

#define BUZZER_PIN 18

#define BTN_START_PIN 15
#define BTN_STOP_PIN 4
#define BTN_CLEAR_TIME_PIN 16

// time in miliseconds
long long workTime = timeStringToMilliseconds("01:00:00");
long long relaxTime = timeStringToMilliseconds("00:10:00");

LiquidCrystal_I2C lcd(0x27, 16, 2);
Timer MyTimer(relaxTime, workTime, lcd);

void setup()
{
  Serial.begin(115200);
  // lcd init
  lcd.init();
  lcd.clear();
  lcd.backlight();

  lcd.setCursor(0, 1);
  lcd.print("Press BTN start");

  pinMode(BUZZER_PIN, OUTPUT);

  pinMode(BTN_START_PIN, INPUT_PULLUP);
  pinMode(BTN_STOP_PIN, INPUT_PULLUP);
  pinMode(BTN_CLEAR_TIME_PIN, INPUT_PULLUP);
}

void loop()
{
  // loop for time work
  MyTimer.TimerLoop();

  if (digitalRead(BTN_CLEAR_TIME_PIN) == LOW)
    MyTimer.Clear();

  // start
  if (digitalRead(BTN_START_PIN) == LOW)
    MyTimer.Start();

  // stop
  if (digitalRead(BTN_STOP_PIN) == LOW)
    MyTimer.Pause();

  delay(500);
}