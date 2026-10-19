#include <IRremote.h>

const int LED_PIN = 8; 
bool ledState = false;

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(11, ENABLE_LED_FEEDBACK);
   // Pin 2 is IR signal input
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW); 
}
void loop() {
  if (IrReceiver.decode()) {
    IrReceiver.printIRResultShort(&Serial);
    if (IrReceiver.decodedIRData.command == 0x18) {
        // do something here
        ledState = !ledState; // عكس حالة الـ LED (إذا كان مطفأ يُضاء، والعكس)
      digitalWrite(LED_PIN, ledState);
     
      if (ledState) {
        Serial.println("LED ON");
      } else {
        Serial.println("LED OFF");
      }

    }
    IrReceiver.resume(); // Enable receiving of the next IR frame
  }
}
