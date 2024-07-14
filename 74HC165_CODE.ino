const int REG165_CLK_pin = 33;
const int REG165_LTH_pin = 32;
const int REG165_DS_pin  = 35;

uint8_t REG165_value=0;

void REG165_read()
{
  digitalWrite(REG165_LTH_pin, 0);
  delayMicroseconds(5);
  digitalWrite(REG165_LTH_pin, 1);
  delayMicroseconds(5);
  
  digitalWrite(REG165_CLK_pin, 1);
  REG165_value = shiftIn(REG165_DS_pin, REG165_CLK_pin, LSBFIRST);
}
void setup() {
  Serial.begin(115200);

  pinMode(REG165_CLK_pin, OUTPUT);
  pinMode(REG165_LTH_pin, OUTPUT);
  pinMode(REG165_DS_pin,  INPUT);

  delay(200);
}
void loop() {
  REG165_read();
  Serial.printf("New value : %d\n", REG165_value);
  delay(500);
}
