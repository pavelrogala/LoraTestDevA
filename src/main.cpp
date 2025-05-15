#include <SPI.h>
#include <LoRa.h>

#define BUTTON_PIN 13
#define LORA_CS    5
#define LORA_RST   14
#define LORA_IRQ   4

void setup() {
  Serial.begin(115200);
  while (!Serial);
  
  pinMode(BUTTON_PIN, INPUT_PULLDOWN);
  
  // Initialize LoRa
  if (!LoRa.begin(433E6)) {  // Set LoRa frequency (e.g., 868 MHz)
    Serial.println("Starting LoRa failed!");
    while (1);
  }
  
  LoRa.setPins(LORA_CS, LORA_RST, LORA_IRQ);
  
  Serial.println("LoRa Transmitter Initialized!");
}

void loop() {
  if (digitalRead(BUTTON_PIN) == HIGH) {
    LoRa.beginPacket();
    LoRa.print("BUTTON_PRESSED");
    LoRa.endPacket();
    Serial.println("Button Pressed, Sent Message");
    delay(500); // Debounce delay
  }
}