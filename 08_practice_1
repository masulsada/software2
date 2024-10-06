void setup() {
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
  digitalWrite(PIN_TRIG, LOW);
  
  Serial.begin(57600);
}

void loop() {
  float distance;

  if (millis() < (last_sampling_time + INTERVAL))
    return;

  distance = USS_measure(PIN_TRIG, PIN_ECHO);

  int brightness;

  if (distance > _DIST_MAX) {
    brightness = 0;
  } else if (distance < _DIST_MIN) {
    brightness = 0;
  } else if (distance <= 200) {
    brightness = map((int)distance, 100, 200, 0, 255); // Increasing brightness from 100 to 200 mm
  } else {
    brightness = map((int)distance, 200, 300, 255, 0); // Decreasing brightness from 200 to 300 mm
  }
  
  analogWrite(PIN_LED, brightness);

  if (distance != 0 && !isinf(distance)) {
    Serial.print("Min:");
    Serial.print(_DIST_MIN);
    Serial.print(", Distance:");
    Serial.print(distance);
    Serial.print(", Max:");
    Serial.print(_DIST_MAX);
    Serial.println("");
  } else {
    Serial.println("Error: Distance calculation out of range.");
  }

  last_sampling_time += INTERVAL;
}

float USS_measure(int TRIG, int ECHO) {
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(PULSE_DURATION);
  digitalWrite(TRIG, LOW);

  return pulseIn(ECHO, HIGH, TIMEOUT) * SCALE;
}
