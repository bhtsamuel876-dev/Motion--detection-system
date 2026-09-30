# Flowchart

START
|
Initialize Arduino pins and Serial
|
Read HC-SR04 distance
|
Is distance <= 20 cm?
|-- NO --> Turn LEDs OFF --> Repeat
|
YES
|
Blink RED (200 ms ON / 150 ms OFF)
|
Blink GREEN (250 ms ON / 350 ms OFF)
|
Is distance <= 10 cm?
|-- YES --> Blink BLUE (300 ms ON / 450 ms OFF)
|-- NO --> BLUE OFF
|
Send event through Serial
|
Repeat
