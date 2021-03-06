# Home-Security-System-with-Ultrasonic-Sensor
Simple home security application that detects anomalies using HC-SR04 Ultrasonic Sensor. If the sensor is triggered, the system uses a seven segment display and active buzzer to produce a 10-second countdown that ends with an emergency siren.

# Hardware:
* Arduino Uno or equivalent (Elegoo UNO R3)
* HC-SR04 Ultrasonic Sensor
* Active Buzzer
* 7 Segment Display
* Resistor (1K Ohm)
* Jumper Wires

# Procedure:
1. Ultrasonic Sensor begins calibration phase in order to detect average uniterrupted distance. The active buzzer will alert with two "beeps" once the calibration phase has been completed. 

2. The Ultrasonic Sensor is now armed. Any anomaly that disturbs the sensor's current maximum range will initiate the alert process.
3. Once alert process has been triggered, the Seven Segment Display will begin a 10 second countdown.
4. At the conclusion of the 10 second countdown, the active buzzer outputs an emergency siren.
5. Restarting the system can be achieved by pressing red code reset button on the arduino. 

Circuit Layout: ![layout](https://github.com/burnettcj1966/Home-Security-System-with-Ultrasonic-Sensor/blob/main/sensorCircuit.jpg)


