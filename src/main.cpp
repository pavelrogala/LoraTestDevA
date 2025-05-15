#include <SPI.h>
#include <LoRa.h>

#define ss   5   // Chip select pin for LoRa
#define rst  14  // Reset pin for LoRa
#define dio0 2   // Interrupt pin for LoRa

void setup() {
  // Initialize Serial Monitor
  Serial.begin(115200);
  while (!Serial);
  Serial.println("LoRa Sender");

  // Setup LoRa transceiver module
  LoRa.setPins(ss, rst, dio0);

  // Try to initialize LoRa
  while (!LoRa.begin(433E6)) {
    Serial.println(".");
    delay(500);  // Wait and keep trying to initialize LoRa
  }

  // Set sync word to ensure you're not receiving messages from other LoRa modules
  LoRa.setSyncWord(0xF3);

  Serial.println("LoRa Initializing OK!");
}

void loop() {
  LoRa.beginPacket();
  LoRa.print("HIGH");
  LoRa.endPacket();
      
  Serial.println("Button Pressed, Sent Message");
  delay(1000);

  LoRa.beginPacket();
  LoRa.print("LOW");
  LoRa.endPacket();

  Serial.println("Button Pressed, Sent Message");
  delay(1000);
}