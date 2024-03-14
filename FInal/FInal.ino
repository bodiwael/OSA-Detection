#include <Wire.h> //to connect the esp with sensor
#include "MAX30102_PulseOximeter.h"//import to library sensor

#include <WiFi.h>//import to wifi
#include <IOXhop_FirebaseESP32.h>//import to firebaseESP32

// Set these to run example.
#define FIREBASE_HOST "https://osa-detection-default-rtdb.firebaseio.com/"
#define FIREBASE_AUTH "YpWu2tlvxKxwG6qjF3wptNBSic6YmkYWYNIwLqUt"
#define WIFI_SSID "tidata_35g"
#define WIFI_PASSWORD "87654321"

#define REPORTING_PERIOD_MS     1000 //READ FROM SENSOR EVERY SECOND

// PulseOximeter is the higher level interface to the sensor
// it offers:
//  * beat detection reporting
//  * heart rate calculation
//  * SpO2 (oxidation level) calculation
PulseOximeter pox;

uint32_t tsLastReport = 0;

// Callback (registered below) fired when a pulse is detected
void onBeatDetected()
{
  Serial.println("Beat!");
}

void setup()
{
  Serial.begin(115200);

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Serial.print("Initializing pulse oximeter..");

  // Initialize the PulseOximeter instance
  // Failures are generally due to an improper I2C wiring, missing power supply
  // or wrong target chip
  if (!pox.begin()) {
    Serial.println("FAILED");
    for (;;);
  } else {
    Serial.println("SUCCESS");
  }

  // The default current for the IR LED is 50mA and it could be changed
  //   by uncommenting the following line. Check MAX30102_Registers.h for all the
  //   available options.
  // pox.setIRLedCurrent(MAX30102_LED_CURR_7_6MA);

  // Register a callback for the beat detection
  pox.setOnBeatDetectedCallback(onBeatDetected);
}

int n = 0;


void loop()
{
  // Make sure to call update as fast as possible
  pox.update();

  // Asynchronously dump heart rate and oxidation levels to the serial
  // For both, a value of 0 means "invalid"
  if (millis() - tsLastReport > REPORTING_PERIOD_MS) {
    Serial.print("Heart rate:");
    Serial.print(pox.getHeartRate() / 3);
    Serial.print("bpm / SpO2:");
    Serial.print(pox.getSpO2());
    Serial.println("%");

    pox.shutdown();
    
    Firebase.setFloat("/Data/SPO2", pox.getSpO2());
    Firebase.setFloat("/Data/HR", pox.getHeartRate() / 3);
    
    pox.resume();
    
    tsLastReport = millis();
  }

  //  delay(400);
}
