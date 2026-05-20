const int appliance1 = 12; 
const int appliance2 = 13; 
char bluetoothData;              
void setup() {
  Serial.begin(9600); 
  pinMode(appliance1, OUTPUT);
  pinMode(appliance2, OUTPUT);
  Serial.println("Bluetooth Automation Ready!");
  Serial.println("Send 1 for ON, 0 for OFF");
}
void loop() {
  if (Serial.available() > 0) {
    bluetoothData = Serial.read(); 
    
    if (bluetoothData == '1') {
      digitalWrite(appliance1, HIGH);
      Serial.println("Appliance 1 ON");
    } 
    else if (bluetoothData == '0') {
      digitalWrite(appliance1, LOW);
      Serial.println("Appliance 1 OFF");
    } 
  }
}
