# Real-Time Vehicle GPS Tracking System 

![System Demo](https://cdn.phototourl.com/free/2026-06-08-da25d2ff-ff0c-4acf-8eee-309cab3a9db2.jpg)

## Overview
An end-to-end Full-stack IoT solution for real-time vehicle tracking. This system captures raw NMEA telemetry data using edge hardware, syncs it continuously to the cloud via REST APIs, and visualizes the live routing trajectory on a cross-platform mobile application.

##System Architecture
1. **Hardware Node:** An ESP32 microcontroller processes coordinate data from a NEO-6M GPS module via UART.
2. **Cloud Middleware:** Firebase Realtime Database acts as a low-latency broker to store and sync telemetry data.
3. **Client App:** A Flutter-based mobile application listens to database changes and dynamically renders the vehicle's location and routing path.

##Tech Stack & Components
* **Hardware:** ESP32 DOIT DevKit V1, GY-NEO6MV2 GPS Module.
* **Firmware:** C++, Arduino Framework, `TinyGPS++`, `Firebase_ESP_Client`.
* **Cloud:** Google Firebase Realtime Database.
* **Mobile App:** Flutter, Dart, `flutter_map` (OpenStreetMap), `firebase_database`.

## Key Features
* **Live Telemetry Parsing:** Accurate extraction of latitude/longitude from raw satellite data.
* **Real-time Synchronization:** Sub-second latency data transmission using Firebase.
* **Dynamic Polyline Routing:** Advanced rendering algorithm that draws the vehicle's trajectory on OpenStreetMap.
* **Memory Optimization:** Smart data-filtering logic built into the app to bypass redundant stationary coordinates, ensuring smooth UI performance.

##Getting Started

### Hardware Setup
1. Connect NEO-6M GPS `TX` to ESP32 `RX2 (GPIO 16)`.
2. Connect NEO-6M GPS `RX` to ESP32 `TX2 (GPIO 17)`.
3. Flash the firmware located in the `GPS TRACKING` folder using PlatformIO or Arduino IDE.

### Software Setup
1. Clone this repository.
2. Create a Firebase RTDB project and update the `DATABASE_URL` in the ESP32 code.
3. Replace the `google-services.json` in the Flutter project with your own Firebase credentials.
4. Run `flutter pub get` followed by `flutter run`.

## 👨‍💻 Author
**Pham Quoc Thang**
* Telecommunications & Integrated Circuit Design Student at Ho Chi Minh City University of Technology and Education (HCMUTE).
* Reach out via [thangpham29y5@gmail.com] or connect with me on [linkedin.com/in/thang-pham-quoc-238663332/].
