# Network Intrusion Detection System (NIDS)
---

## Project Report

**Project Statement:**
Develop a network intrusion detection mechanism that stores packet logs, analyzes traffic patterns, and detects malicious behavior through anomaly-based methods and predefined rule conditions, including protocol severity thresholds and blacklist verification.

---

## Problem Description

In modern networks, monitoring traffic and identifying malicious activity has become a critical challenge. Network administrators often struggle to manually analyze large volumes of incoming packets, track suspicious IP addresses, and detect abnormal traffic spikes. Performing these tasks manually is time-consuming and error-prone. Without an automated system, administrators may overlook high-severity packets, repeated intrusion attempts, or unusual behavior patterns. Traditional log-checking methods also make it difficult to identify traffic floods, protocol misuse, or blacklist violations in real time. Networks become vulnerable to attacks such as flooding, unauthorized access attempts, and abnormal protocol behavior.

---

## Proposed Solution

To address these challenges, we designed a Network Intrusion Detection System (NIDS) that:

* Logs packets automatically, including source IP, destination IP, protocol type, timestamp, and severity.
* Stores packets efficiently using a Binary Search Tree (BST).
* Performs automated anomaly detection by monitoring per-minute traffic counts, identifying flooding attempts, and highlighting sudden spikes or unusual IP activity.
* Applies rule-based checks such as protocol-based severity evaluation and blacklist monitoring.
* Provides an organized, automated, and error-free approach to packet analysis.

---

## Project Features

1. **Packet Logging**

   * Stores packet details (source IP, destination IP, protocol, severity, timestamp) in a BST.
   * Maintains an organized history of all network activity.

2. **Severity Classification**

   * Assigns severity scores depending on protocol type (TCP, UDP, ICMP, DNS, HTTP).
   * Highlights high-risk packets for immediate review.

3. **Traffic Frequency Analysis**

   * Counts packets per minute.
   * Detects flooding attacks when activity exceeds a threshold.

4. **Blacklist Checking**

   * Maintains a list of known malicious IPs.
   * Flags packets originating from blacklisted sources.

5. **Anomaly Detection**

   * Identifies unusual spikes in traffic.
   * Highlights IPs sending abnormal numbers of packets.
   * Detects high-severity outliers.

6. **BST-Based Searching**

   * Quickly finds logs, displays packet history, and performs sorting operations.

7. **Alerts and Notifications**

   * Generates warning messages to indicate suspicious or dangerous network behavior.

---

## Function Descriptions

* `generatePacket()` — Creates a packet with random IPs, random protocol, assigned severity, and a timestamp.
* `insertLog()` — Inserts a packet into the BST based on timestamp ordering.
* `inorderTraversal()` — Displays stored packet logs in sorted order.
* `analyzeSeverity()` — Checks severity levels and produces warnings for dangerous packets.
* `detectAnomalies()` — Performs anomaly detection such as flooding, traffic spikes, repeated IP occurrences.
* `displayCurrentTime()` — Prints current system time to track real-time packet generation.
* `extractMinute()` — Extracts the minute from the timestamp to analyze per-minute traffic.
* `collectIPData()` — Counts packet frequency based on IP and minute.
* `searchLog()` — Allows the user to search for logs using keywords such as IP or protocol.

---

## Data Structures Used

1. **Struct: Packet**

   * Represents a single network packet with attributes: source IP, destination IP, protocol, severity, timestamp, and message.

2. **Queue (Linked List)**

   * Implements FIFO processing of packets using a linked list.

3. **BST (Binary Search Tree)**

   * Stores packet logs in an ordered fashion for efficient insertion and traversal.

4. **Maps and Sets**

   * `map<string,int>` — Counts packets per source IP and per minute.
   * `set<string>` — Stores blacklist and whitelist IPs.

5. **Strings and Utility Functions**

   * Used for IP addresses, protocol types, timestamps, and messages.

---

## Conclusion

The project demonstrates a functional, CLI-based network intrusion detection system. It effectively captures packets, logs them efficiently, identifies suspicious behavior, and detects anomalies in real time. The implementation highlights how fundamental data structures support real-world networking concepts, including traffic monitoring, alert generation, and log organization. The system provides a solid foundation for future enhancements and further exploration in cybersecurity-focused software design.

---



