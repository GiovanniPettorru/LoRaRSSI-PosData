// Feather9x_RX - Adafruit code
#include <SPI.h>
#include <RH_RF95.h>
#include <avr/wdt.h>

// Feather 32u4:
#define RFM95_CS   8
#define RFM95_RST  4
#define RFM95_INT  7

// CIt must match RX's freq!
#define RF95_FREQ_1 434.0 
#define RF95_FREQ_2 868.0

int default_power = 13;
int anchorID = 1; 
String message = "{\"ID\": " + String(anchorID)}";

// Singleton instance of the radio driver
RH_RF95 rf95(RFM95_CS, RFM95_INT);

void setup() {
  wdt_disable();
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(RFM95_RST, OUTPUT);
  digitalWrite(RFM95_RST, HIGH);

  // manual reset
  digitalWrite(RFM95_RST, LOW);
  delay(10);
  digitalWrite(RFM95_RST, HIGH);
  delay(10);

  while (!rf95.init()) {
    while (1);
  }

  // Defaults: 434/868 MHz13dBm, Bw = 125 kHz, Cr = 4/5, Sf = 128chips/symbol, CRC on
  if (!rf95.setFrequency(RF95_FREQ_2)) {
    while (1);
  }

  rf95.setTxPower(default_power, false);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  rf95.send((uint8_t *)message.c_str(), message.length());
  rf95.waitPacketSent();
  digitalWrite(LED_BUILTIN, LOW);
  delay(random(9000, 11000));  // Random delay to avoid collision
}
