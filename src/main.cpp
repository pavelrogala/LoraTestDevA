#include <SPI.h>
#include <LoRa.h>

#define ss   5   // Chip select pin for LoRa
#define rst  14  // Reset pin for LoRa
#define dio0 2   // Interrupt pin for LoRa

#define LED_PIN_1 13  // LED on pin 13 (turn on during LoRa initialization)
#define LED_PIN_2 12  // LED on pin 12 (turn on after successful LoRa initialization)

void setup() {
  // Initialize Serial Monitor
  Serial.begin(115200);
  while (!Serial);
  Serial.println("LoRa Sender");

  // Setup LED pins
  pinMode(LED_PIN_1, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);

  // Setup LoRa transceiver module
  LoRa.setPins(ss, rst, dio0);

  // Replace the LoRa.begin(---E-) argument with your location's frequency
  // 433E6 for Asia
  // 866E6 for Europe
  // 915E6 for North America
  
  // Turn on LED on pin 13 to indicate LoRa initialization is happening
  digitalWrite(LED_PIN_1, HIGH);
  digitalWrite(LED_PIN_2, LOW); // Make sure LED on pin 12 is off initially

  // Try to initialize LoRa
  while (!LoRa.begin(433E6)) {
    Serial.println(".");
    delay(500);  // Wait and keep trying to initialize LoRa
  }

  // LoRa initialized successfully
  // Turn off the LED on pin 13 and turn on LED on pin 12
  digitalWrite(LED_PIN_1, LOW);
  digitalWrite(LED_PIN_2, HIGH);

  // Set sync word to ensure you're not receiving messages from other LoRa modules
  LoRa.setSyncWord(0xF3);

  Serial.println("LoRa Initializing OK!");
}

void loop() {
  //Send LoRa packet to receiver
  LoRa.beginPacket();
  //LoRa.print("Temperature: ");
  LoRa.print("10");
  LoRa.print(",");
  LoRa.print("20");
//  LoRa.print(" Humidity: ");
//  LoRa.print(h);
  LoRa.endPacket();

  counter++;

  delay(50);
}