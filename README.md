# RSSI-Based Localization Dataset

This repository contains a dataset of Received Signal Strength Indicator (RSSI) measurements acquired through a proof-of-concept testbed using IoT-compliant devices with LoRa communication. The dataset is intended for research on wireless localization, signal propagation analysis, and the performance evaluation of RSS-based algorithms in realistic outdoor settings. This work is carried out as part of the POSIDONIA project, funded under the third open call of the NGI Sargasso initiative.
---

## 📦 Dataset Overview

The dataset was collected using a Raspberry Pi 5 as the **target device** and multiple Adafruit Feather 32u4 RFM95 nodes as **anchors**. All devices operate at the 868.0 MHz frequency. RSSI readings were gathered across three distinct outdoor scenarios, with varying distances and placements between nodes to simulate different propagation conditions.

---

## 🛠️ Hardware Setup

- **Target Device**  
  - Raspberry Pi 5  
  - Adafruit RFM95W LoRa module (connected via serial interface)  
  - Mounted on a tripod at 1.3 meters height

- **Anchor Nodes**  
  - Adafruit Feather 32u4 with RFM95  
  - Mounted on tripods at 1.3 meters height  
  - Transmit packets periodically (random interval between 2 and 3 seconds)

---

## 💻 Software Stack

- **Target Side**
  - Python script using the `adafruit_rfm9x` library
  - Tasks:
    - Receive and filter packets from anchors
    - Extract RSSI values and anchor IDs
    - Store data in structured CSV format

- **Anchor Side**
  - Arduino sketches with the `RH_RF95` library
  - Tasks:
    - Periodically transmit packets with unique identifiers

---

## 🧪 Scenarios & Data Collection

Data was collected on a football field at the *Centro Universitario Sportivo (CUS)*, "Sa Duchessa", University of Cagliari, Italy.

### 📍 Scenario A – Linear Distance Test
- Goal: Analyze the RSSI-distance relationship.
- Setup: One anchor moved linearly from 10 to 40 meters in 10-meter steps while the target remains stationary.
![Scenario A](img/ScenarioA.png)

### 📍 Scenario B – Grid-Based Deployment
- Goal: RSSI measurement with fixed anchors and varied target positions.
- Setup: Four anchors around a 23.5×44 m² rectangle. The target is placed at five positions (T1–T5).
![Scenario B](img/ScenarioB.png)

> ℹ️ Additional scenarios and conditions will be added in future dataset updates.
