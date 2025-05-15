#include <SPI.h>
#include <LoRa.h>

#define BUTTON_PIN 13
#define LORA_CS    5
#define LORA_RST   14
#define LORA_IRQ   4

unsigned long lastPressTime = 0;  // To track button press time
const long debounceDelay = 500;    // 500 ms debounce delay

void setup() {
  Serial.begin(115200);
  while (!Serial);

  pinMode(BUTTON_PIN, INPUT_PULLDOWN);

  LoRa.setPins(LORA_CS, LORA_RST, LORA_IRQ);
  
  // Initialize LoRa
  if (!LoRa.begin(433E6)) {  // Set LoRa frequency (e.g., 433 MHz)
    Serial.println("Starting LoRa failed!");
    while (1);  // Hang here indefinitely if LoRa fails to initialize
  }
  delay(1000);
  Serial.println("1");
  delay(5000);
  Serial.println("LoRa Transmitter Initialized!");
}

void loop() {
  // Read the button state
  if (digitalRead(BUTTON_PIN) == HIGH) {
    Serial.println("Button Pressed, Sent Message");
    //unsigned long currentMillis = millis();
    
    // Check if enough time has passed for debounce (500ms)
    //if (currentMillis - lastPressTime >= debounceDelay) {
      //lastPressTime = currentMillis;
      
      //LoRa.beginPacket();
      //LoRa.print("BUTTON_PRESSED");
      //LoRa.endPacket();
      
      
    //}
  }
}
