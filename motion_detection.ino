const int TRIG_PIN = 7;
const int ECHO_PIN = 8;
const int RED_LED = 2;
const int GREEN_LED = 3;
const int BLUE_LED = 4;

const int DETECTION_LIMIT = 20;
const int CLOSE_LIMIT = 10;

unsigned long lastReport = 0;
const unsigned long REPORT_INTERVAL = 1000;

bool redState = false, greenState = false, blueState = false;
unsigned long redLast = 0, greenLast = 0, blueLast = 0;

float getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  unsigned long duration = pulseIn(ECHO_PIN, HIGH, 30000);
  if (duration == 0) return -1;
  return duration * 0.0343 / 2.0;
}

void blinkLed(int pin, bool &state, unsigned long &lastChange,
              unsigned long onTime, unsigned long offTime) {
  unsigned long now = millis();
  unsigned long interval = state ? onTime : offTime;

  if (now - lastChange >= interval) {
    state = !state;
    digitalWrite(pin, state ? HIGH : LOW);
    lastChange = now;
  }
}

void offLed(int pin, bool &state) {
  state = false;
  digitalWrite(pin, LOW);
}

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  float distance = getDistance();

  if (distance >= 0 && distance <= DETECTION_LIMIT) {
    blinkLed(RED_LED, redState, redLast, 200, 150);
    blinkLed(GREEN_LED, greenState, greenLast, 250, 350);

    if (distance <= CLOSE_LIMIT) {
      blinkLed(BLUE_LED, blueState, blueLast, 300, 450);
    } else {
      offLed(BLUE_LED, blueState);
    }

    if (millis() - lastReport >= REPORT_INTERVAL) {
      Serial.print(distance, 1);
      Serial.println(",1");
      lastReport = millis();
    }
  } else {
    offLed(RED_LED, redState);
    offLed(GREEN_LED, greenState);
    offLed(BLUE_LED, blueState);

    if (millis() - lastReport >= REPORT_INTERVAL) {
      Serial.println("0,0");
      lastReport = millis();
    }
  }

  delay(20);
}
