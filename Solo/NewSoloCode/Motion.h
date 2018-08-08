#include<Arduino.h>
#include<phys253.h>
#include <EEPROM.h>
#ifndef MOTION_H
#define MOTION_H

class Motion {
  private:
    uint16_t onTape, overCliff, turningTime;
    double regularPowerMult, slowPowerMult, backupPowerMult;
    
    int currentError, lastError, lastState, lastOn;
    uint16_t count;
    
    boolean isOnWhite(uint8_t);
    boolean isOverCliff(uint8_t);
    void pidControl(uint8_t, uint8_t, double);

  public:
    Motion(int);
    void setConstants();
    void reset(uint8_t);
    
    void followTape(double);
    void followRightEdge(double);
    void driveMotors(double, double);
    void stopMotors();

    bool findTapeLeft(uint16_t);
    bool findTapeRight(uint16_t);
    bool findRightEdge(double, double, unsigned int);
};

#endif
