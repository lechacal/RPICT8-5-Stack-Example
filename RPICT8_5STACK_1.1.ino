// RPICT8 - 5 Stack
// Version 1.1

// Required Libraries:
// RPICTlib 1.2.0
// http://lechacal.com/RPICT/RPICTlib/RPICTlib_v1.2.0.zip

#include "RPICTlib.h"

// Some mandatory definitions for RPICT board first
uint8_t ADC_BITS = 12;
uint16_t ADC_COUNTS (1 << ADC_BITS);
uint16_t ADC_REF = 4096; // USE 3300 instead if using RPICT8 version 3

// Some user definitions. Modify as required.

uint8_t N_cycles = 10;     // How many cycles we want to compute rms on.
uint8_t xpFREQ = 50;       // Frequency of the measured signal 50Hz here.
const int sInterval = 300; // 300usec is 3.3kHz sampling interval
const uint16_t NUMBER_OF_SAMPLES = (uint16_t) (N_cycles * 1000000 / xpFREQ / sInterval);
const float ICAL = 74.074; // Using 100A rated with SCT-013-000
const uint8_t N_CT = 40;   // Number of CT to compute

// The big array for CT node computation is defined here below.

SignalNode_mcp3208 CTS[N_CT];

// Let's give a meaningful name to the pin setup

const uint8_t master = 10;
const uint8_t slave_1 = 6;
const uint8_t slave_2 = 7;
const uint8_t slave_3 = 8;
const uint8_t slave_4 = 9;

const uint8_t ct1 = 7;
const uint8_t ct2 = 6;
const uint8_t ct3 = 5;
const uint8_t ct4 = 4;
const uint8_t ct5 = 3;
const uint8_t ct6 = 2;
const uint8_t ct7 = 1;
const uint8_t ct8 = 0;


void setup() {

  pinMode(slave_1, OUTPUT);
  digitalWrite(slave_1, HIGH);
  pinMode(slave_2, OUTPUT);
  digitalWrite(slave_2, HIGH);
  pinMode(slave_3, OUTPUT);
  digitalWrite(slave_3, HIGH);
  pinMode(slave_4, OUTPUT);
  digitalWrite(slave_4, HIGH);
  pinMode(master, OUTPUT);
  digitalWrite(master, HIGH);

  Serial.begin(38400);
  Serial.println(F("# RPICT8 5 boards stack v1.1"));

  SPI.begin();

  CTS[0].begin(ct1, master, ICAL);
  CTS[1].begin(ct2, master, ICAL);
  CTS[2].begin(ct3, master, ICAL);
  CTS[3].begin(ct4, master, ICAL);
  CTS[4].begin(ct5, master, ICAL);
  CTS[5].begin(ct6, master, ICAL);
  CTS[6].begin(ct7, master, ICAL);
  CTS[7].begin(ct8, master, ICAL);
  CTS[8].begin(ct1, slave_1, ICAL);
  CTS[9].begin(ct2, slave_1, ICAL);
  CTS[10].begin(ct3, slave_1, ICAL);
  CTS[11].begin(ct4, slave_1, ICAL);
  CTS[12].begin(ct5, slave_1, ICAL);
  CTS[13].begin(ct6, slave_1, ICAL);
  CTS[14].begin(ct7, slave_1, ICAL);
  CTS[15].begin(ct8, slave_1, ICAL);
  CTS[16].begin(ct1, slave_2, ICAL);
  CTS[17].begin(ct2, slave_2, ICAL);
  CTS[18].begin(ct3, slave_2, ICAL);
  CTS[19].begin(ct4, slave_2, ICAL);
  CTS[20].begin(ct5, slave_2, ICAL);
  CTS[21].begin(ct6, slave_2, ICAL);
  CTS[22].begin(ct7, slave_2, ICAL);
  CTS[23].begin(ct8, slave_2, ICAL);
  CTS[24].begin(ct1, slave_3, ICAL);
  CTS[25].begin(ct2, slave_3, ICAL);
  CTS[26].begin(ct3, slave_3, ICAL);
  CTS[27].begin(ct4, slave_3, ICAL);
  CTS[28].begin(ct5, slave_3, ICAL);
  CTS[29].begin(ct6, slave_3, ICAL);
  CTS[30].begin(ct7, slave_3, ICAL);
  CTS[31].begin(ct8, slave_3, ICAL);
  CTS[32].begin(ct1, slave_4, ICAL);
  CTS[33].begin(ct2, slave_4, ICAL);
  CTS[34].begin(ct3, slave_4, ICAL);
  CTS[35].begin(ct4, slave_4, ICAL);
  CTS[36].begin(ct5, slave_4, ICAL);
  CTS[37].begin(ct6, slave_4, ICAL);
  CTS[38].begin(ct7, slave_4, ICAL);
  CTS[39].begin(ct8, slave_4, ICAL);
}

void loop() {

  for (uint8_t i = 0; i < N_CT; i++) {
    CTS[i].calcRMS(NUMBER_OF_SAMPLES, sInterval);

    Serial.print(CTS[i].inPin);
    Serial.print(" ");
    Serial.print(CTS[i].mcp);
    Serial.print(" ");

    if (!CTS[i].err) {
      Serial.println(CTS[i].RMS);
    }
    else {
      Serial.print("err ");
      Serial.println(CTS[i].err);

    }
  }
}
