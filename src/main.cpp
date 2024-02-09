#include <Arduino.h>

#define btnStart 22
#define btnStop 23
unsigned long startTime = 0;
unsigned long elapsedTime = 0;
bool timerRunning = false;

void setup()
{
  Serial.begin(115200);
  pinMode(btnStart, INPUT_PULLUP);
  pinMode(btnStop, INPUT_PULLUP);
  startTime = millis();
}

void loop()
{
  if (digitalRead(btnStart) == LOW)
  {
    timerRunning = true;
    Serial.print("Timer state changed to ");
    Serial.println("running");

    if (timerRunning)
    {
      startTime = millis() - elapsedTime;
    }
  }
  if (digitalRead(btnStop) == LOW)
  {
    timerRunning = false;
    Serial.print("Timer state changed to ");
    Serial.println("stopped");
  }
  delay(50);

  if (timerRunning)
  {
    unsigned long currentTime = millis();
    elapsedTime = currentTime - startTime;

    unsigned long hours = (elapsedTime / 3600000) % 24;
    unsigned long minutes = (elapsedTime / 60000) % 60;
    unsigned long seconds = (elapsedTime / 1000) % 60;

    Serial.print(hours < 10 ? "0" : "");
    Serial.print(hours);
    Serial.print(":");
    Serial.print(minutes < 10 ? "0" : "");
    Serial.print(minutes);
    Serial.print(":");
    Serial.print(seconds < 10 ? "0" : "");
    Serial.print(seconds);
    Serial.println("");
  }

  delay(1000);
}
