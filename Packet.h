#pragma once
#include "Utils.h"
#include <iostream>
using namespace std;

// -----------------------------
// Packet and queue (Member 1)
// -----------------------------
struct Packet {
    string sourceIP;
    string destIP;
    string protocol;
    int severity;
    time_t timestamp;
    string message;
};

struct QNode {
    Packet data;
    QNode* next;
};

class PacketQueue {
private:
    QNode* front;
    QNode* rear;

public:
    PacketQueue();
    bool isEmpty();
    void enqueue(const Packet& p);
    Packet dequeueReturn();
    void dequeuePrint();
    void displayQueue();
    bool queueEmpty();
};

string generateMessageForPacket(const Packet& p);
Packet generatePacket();
