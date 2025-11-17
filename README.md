# **Network Intrusion Detection System (IDS)**

**Network Intrusion Detection System (IDS)** is an interactive C++ project designed to simulate basic network monitoring. It generates random network packets, stores them in efficient data structures, and analyzes them for suspicious activity using blacklist/whitelist rules and severity scoring. This project demonstrates the use of **queues, BSTs, and anomaly detection logic** in a practical way.

---

## **Features**

### 1️⃣ Packet Generation & Queue Handling

* Generates random packets with timestamps and source IP addresses.
* FIFO queue to manage incoming packets.
* Simulates realistic network traffic for analysis.

### 2️⃣ Logging System (BST)

* Stores network packets in a Binary Search Tree.
* Supports searching, inserting, and traversing logs.
* Efficiently handles packet history for anomaly detection.

### 3️⃣ Anomaly Detection

* Checks packet frequency per IP.
* Flags suspicious activity based on thresholds.
* Uses blacklist/whitelist rules to prioritize alerts.

### 4️⃣ Whitelist & Blacklist

* Trusted IPs → ignored for severity checks.
* Malicious IPs → auto high-severity alerts.
* Demonstrates practical filtering logic.

### 5️⃣ Console UI & Visual Alerts

* Colored console output: green for safe, red for alerts.
* Easy-to-read logs and severity messages.

---

## **Project Structure**

```
main.cpp
Utils.cpp / Utils.h
PacketQueue.cpp / PacketQueue.h
BST.cpp / BST.h
AnomalyDetection.cpp / AnomalyDetection.h
README.md
.gitignore
```

---

## **Compilation & Running**

**Compile using g++:**

```bash
g++ main.cpp Utils.cpp PacketQueue.cpp BST.cpp AnomalyDetection.cpp -o IDS
```

**Run the program:**

```bash
./IDS
```

> Note: Works on Windows / Linux (requires g++ compiler).

---

## **Prerequisites**

* Basic C++ knowledge
* g++ compiler or any C++ IDE
* Optional: terminal supporting ANSI colors for better output

---

## **How it Works**

1. **Packet Generation:** Simulates network traffic with random IPs and timestamps.
2. **Queue Handling:** Incoming packets are stored in a FIFO queue.
3. **BST Logging:** Packets are logged in a BST for efficient searching/traversal.
4. **Anomaly Detection:** Checks each packet for suspicious patterns.
5. **Severity Alerts:** Console highlights alerts and logs severity.

---

## 👨‍💻 Team Members

- Syeda Amna Jafri
- Amna Gul
- Sana Zehra
- Fatima Hasan



