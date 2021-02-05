# Home-Security-System-with-Ultrasonic-Sensor
Simple home security application that detects anomalies using HC-SR04 Ultrasonic Sensor. Initializes 10 second countdown to seven segment display, resulting in sounding of active buzzer.

# Hardware:
* Item Arduino Uno or equivalent (Elegoo UNO R3)
* Item HC-SRO4 Ultrasonic Sensor
* Item Active Buzzer
* Item 7 Segment Display
* Resistor (1K Ohm)

# Procedure:
1. Item Ultrasonic Sensor begins calibration phase in order to detect average uniterrupted distance. The active buzzer will alert with two "beeps" once the calibration phase has been completed.
2. Item The Ultrasonic Sensor is armed. Any anomaly that disturbs the sensor current maximum range will intiate the alert process.
3. Item Once triggered, the Seven Segment Display will begin a 10 second countdown.
4. Item At the conclusion of the 10 second countdown, the active buzzer outputs loud noise.
5. Item Restarting the system can be achieved by pressing code reset on the arduino. 

Circuit Layout: [!


