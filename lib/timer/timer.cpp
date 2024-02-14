#include <Arduino.h>
#include <string>
#include "Timer.h"
#include "buzzer.h"
// private

#define BUZZER_PIN 18

void Timer::isWorkTimeCheck()
{
    if (isWorkTime)
        if (elapsedTime >= workTime)
        {
            Serial.println("Work time over start relax ");
            isWorkTime = false;
            Clear();
            printMessage();
            melody1(BUZZER_PIN);
        }

    if (!isWorkTime)
        if (elapsedTime >= relaxTime)
        {
            Serial.println("Relax time over start work");
            isWorkTime = true;
            Clear();
            printMessage();
            melody1(BUZZER_PIN);
        }
};

void Timer::printMessage()
{
    lcd.setCursor(0, 1);
    lcd.print("                ");

    lcd.setCursor(0, 1);
    lcd.print("Start");

    lcd.setCursor(7, 1);
    lcd.print(isWorkTime ? "Work?" : "Relax?");
};

// public
Timer::Timer(long long relaxTime, long long workTime, LiquidCrystal_I2C &lcd) : relaxTime(relaxTime), workTime(workTime), startTime(0),
                                                                                elapsedTime(0),
                                                                                timerRunning(false),
                                                                                lcd(lcd),
                                                                                isWorkTime(true) {}

void Timer::Start()
{
    lcd.setCursor(0, 1);
    lcd.print("                ");

    timerRunning = true;

    startTime = millis() - elapsedTime;

    lcd.setCursor(0, 1);
    lcd.print(isWorkTime ? "Work time" : "Relax time");
};

void Timer::Pause()
{
    lcd.setCursor(0, 1);
    lcd.print("                ");

    if (!timerRunning)
    {
        Serial.println("if timer stoped you can't stop timer");
    }
    else
    {
        timerRunning = false;

        Serial.println("Timer paused");

        lcd.setCursor(0, 1);
        lcd.print("Timer paused");
    }
};
void Timer::Clear()
{
    lcd.clear();

    startTime = 0;
    elapsedTime = 0;
    timerRunning = false;

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Time: 00:00:00");
    lcd.setCursor(0, 1);
    lcd.print("Timer clear");
    delay(100);
}

void Timer::TimerLoop()
{

    if (timerRunning)
    {
        unsigned long currentTime = millis();
        elapsedTime = currentTime - startTime;
        unsigned long hours = (elapsedTime / 3600000) % 24;
        unsigned long minutes = (elapsedTime / 60000) % 60;
        unsigned long seconds = (elapsedTime / 1000) % 60;

        isWorkTimeCheck();

        lcd.setCursor(0, 0);
        lcd.print("Time: ");
        lcd.print(hours < 10 ? "0" : "");
        lcd.print(hours);
        lcd.print(":");
        lcd.print(minutes < 10 ? "0" : "");
        lcd.print(minutes);
        lcd.print(":");
        lcd.print(seconds < 10 ? "0" : "");
        lcd.print(seconds);
    }
}
