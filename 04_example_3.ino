#define PIN_LED 13
unsigned int count, toggle;

void setup() {
  pinMode(PIN_LED, OUTPUT);
  Serial.begin(115200);
  while (!Serial){
    ;
  }
  Serial.println("Hello World!");
  count = toggle = 0;
  digitalWrite(PIN_LED, toggle);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(toggle++);
  toggle = toggle_state(toggle);
  digitalWrite(PIN_LED, toggle%2);
  delay(1000);
}

int toggle_state(int toggle){
  return toggle;
}
