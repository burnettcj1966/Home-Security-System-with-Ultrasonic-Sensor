# Home-Security-System-with-Ultrasonic-Sensor
Simple home security application that detects anomalies using HC-SR04 Ultrasonic Sensor. Initializes 10 second countdown to seven segment display, resulting in sounding of active buzzer.

# Hardware:
* Arduino Uno or equivalent (Elegoo UNO R3)
* HC-SRO4 Ultrasonic Sensor
* Active Buzzer
* 7 Segment Display
* Resistor (1K Ohm)

# Procedure:
1.Ultrasonic Sensor begins calibration phase in order to detect average uniterrupted distance. The active buzzer will alert with two "beeps" once the calibration phase has been completed.
2. The Ultrasonic Sensor is armed. Any anomaly that disturbs the sensor current maximum range will intiate the alert process.
3. Once triggered, the Seven Segment Display will begin a 10 second countdown.
4. At the conclusion of the 10 second countdown, the active buzzer outputs loud noise.
5. Restarting the system can be achieved by pressing code reset on the arduino. 

Circuit Layout: ![layout](https://github.com/burnettcj1966/Home-Security-System-with-Ultrasonic-Sensor/blob/main/sensorCircuit.jpg)


