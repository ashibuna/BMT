//https://forum.arduino.cc/index.php?topic=395961.0
#include<Wire.h>
#include <avr/sleep.h>
#include <avr/power.h>
#include <Bounce2.h>

Bounce debouncerPower = Bounce();

int16_t accelX,accelY,accelZ,temperature,gyroX,gyroY,gyroZ,gyro_x_cal,gyro_y_cal,gyro_z_cal; //These will be the raw data from the MPU6050.
uint32_t timer; //it's a timer, saved as a big-ass unsigned int.  We use it to save times from the "micros()" command and subtract the present time in microseconds from the time stored in timer to calculate the time for each loop.
double roll, pitch ,yaw; //These are the angles in the complementary filter
float rollangle,pitchangle;
int cal_int;
float tau=0.075; // For testing th ecomplementory filter.
float a=0.0;



void setup() 
{
 pinMode(2, INPUT_PULLUP);

  debouncerPower.attach(2, INPUT_PULLUP);
  debouncerPower.interval(20); 
}

void loop() 
{
   debouncerPower.update();

  if (debouncerPower.read() == LOW)
  {sleepNow();
  }
 else if(debouncerPower.read() == HIGH)
 {
  //IDLE STATE
 } 
 


}


void wakeUpNow()
{
  
}

void sleepNow() {
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_enable();
  attachInterrupt(0, wakeUpNow, LOW);
    
  sleep_mode();
  
  sleep_disable();
  detachInterrupt(0);
}
