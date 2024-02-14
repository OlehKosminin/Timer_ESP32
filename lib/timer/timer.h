#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "timeConverter.h"
class Timer
{
private:
    unsigned long long workTime;
    unsigned long long relaxTime;
    unsigned long long startTime;
    unsigned long long elapsedTime;
    bool timerRunning;
    bool isWorkTime;

    LiquidCrystal_I2C &lcd; // посилання на об'єкт LCD екрану
    void isWorkTimeCheck();
    void printMessage();

public:
    Timer(long long relaxTime, long long workTime, LiquidCrystal_I2C &lcd);
    void TimerLoop();
    void Start();
    void Pause();
    void Clear();
};
