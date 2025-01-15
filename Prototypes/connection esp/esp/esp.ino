#define RXp2 1
#define TXp2 3
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial2.begin(9600, SERIAL_8N1, RXp2, TXp2);
}
void loop() {
    Serial.println("Message Received: ");
    Serial.println(Serial2.readString());
}