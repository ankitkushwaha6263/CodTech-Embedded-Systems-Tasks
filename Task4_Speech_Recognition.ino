String voiceCommand = "";
const int relayDevice = 8;
void setup() {
  Serial.begin(9600);
  pinMode(relayDevice, OUTPUT);
  Serial.println("Speech Recognition Ready...");
  Serial.println("Type 'light on' or 'light off'");
}
void loop() {
  if (Serial.available() > 0) {
    voiceCommand = Serial.readStringUntil('\n'); 
    voiceCommand.trim(); 
    voiceCommand.toLowerCase(); 

    Serial.print("Recognized: ");
    Serial.println(voiceCommand);

    if (voiceCommand == "light on" || voiceCommand == "turn on light")
    {
      digitalWrite(relayDevice, HIGH);
      Serial.println(">> Device ON");
    } 
    else if (voiceCommand == "light off" || voiceCommand == "turn off light")
    {
      digitalWrite(relayDevice, LOW);
      Serial.println(">> Device OFF");
    }
  }
}
