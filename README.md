Making of a Smart Dustbin project utlising different resources.
Addition of various codes ranging from simple blink to final product using ESP8266, Node MCU.
![image](https://github.com/user-attachments/assets/a45f9845-0013-4d9f-9903-9abd1d422119)

Used Thingspeak, mathworks product to visualize data.

1. Choosing sensors? VL53L0X or VL53L1X
![image](https://github.com/user-attachments/assets/d9f4c134-e257-4128-88f9-7706c0561aa6)
2. Which to Choose?
Choose VL53L0X if:
Your application is cost-sensitive.
You only need short-range sensing.
Ambient light or accuracy isn’t a major concern.
Choose VL53L1X if:
You need longer-range measurements.
High accuracy is essential.
You require adjustable FoV or multi-zone detection.

Learnt about Watchdog timer. is a hardware or software timer used in embedded systems to detect and recover from system malfunctions. It ensures that the system continues operating correctly, especially inscenarios where the program gets stuck in an infinite loop, crashes, or hangs.

How It Works
  
  
  Setup: The watchdog timer is configured to count down from a predefined value (timeout period).
  
  Feeding the Dog: During normal operation, the program must reset the watchdog timer (commonly called "feeding" or "kicking" the watchdog) within the timeout period.
  
  Timeout: If the watchdog timer is not reset within this time, it assumes the system is malfunctioning and performs a corrective action, usually restarting the system (a watchdog reset).

yield(): Resets the watchdog timer in ESP8266 to prevent it from triggering during long tasks.

Checked library comparison for VL53L0X for "pololu" and "Adafruit".
![image](https://github.com/user-attachments/assets/445fcdd9-cfc6-4083-9a85-a432c77526d5)

Moved onto using Node red, started with making simple turn on turn off program.

Finding Potenial Use for GPS module. Tried with different modules and different ways.
Use NEO6m and SIM28ML module to find the location.
Found the location using both on different platforms.
Trying to upload this data on any website.
