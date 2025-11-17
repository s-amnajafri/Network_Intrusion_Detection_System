#include "Packet.h"

PacketQueue::PacketQueue() : front(NULL), rear(NULL) {}

bool PacketQueue::isEmpty() { return front == NULL; }

void PacketQueue::enqueue(const Packet& p) {
    QNode* temp = new QNode;
    temp->data = p;
    temp->next = NULL;
    if (isEmpty()) {
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
    cout << GREEN << "\nPacket stored in queue." <<RESET;
}

Packet PacketQueue::dequeueReturn() {
    Packet pkt;
    if (isEmpty()) {
        cout << "Queue is empty.\n";
        pkt.severity = -1;
        return pkt;
    }
    QNode* temp = front;
    front = front->next;
    pkt = temp->data;
    delete temp;
    if (front == NULL) rear = NULL;
    return pkt;
}

void PacketQueue::dequeuePrint() {
    if (isEmpty()) {
        cout << "Queue is empty. Cannot dequeue.\n";
        return;
    }
    QNode* temp = front;
    front = front->next;

    string timeStr = timeTToString(temp->data.timestamp);

    cout << "Dequeued Packet: ["
        << temp->data.sourceIP << " => " << temp->data.destIP
        << " | " << temp->data.protocol
        << " | Severity: " << temp->data.severity
        << " | Time: " << timeStr << "]\n"
        << " Message: " << temp->data.message << "\n";

    delete temp;
    if (front == NULL) rear = NULL;
}

void PacketQueue::displayQueue() {
    if (isEmpty()) {
        cout << "Queue is empty.\n";
        return;
    }

    cout << YELLOW<< "\n--- Packet Queue Contents ---" <<RESET<<endl;
    QNode* temp = front;
    while (temp != NULL) {
        string timeStr = timeTToString(temp->data.timestamp);
        cout << "[" << temp->data.sourceIP
            << " => " << temp->data.destIP
            << " | " << temp->data.protocol
            << " | Severity: " << temp->data.severity
            << " | Time: " << timeStr << "]"
            << " Message: " << temp->data.message << "\n";
        temp = temp->next;
    }
}

bool PacketQueue::queueEmpty() { return isEmpty(); }

string generateMessageForPacket(const Packet& p) {
    if (p.protocol == "ICMP") {
        return "High-ICMP activity";
    } else if (p.protocol == "TCP") {
        if (p.severity >= 8) return "Multiple failed logins";
        return "Normal TCP request";
    } else { // UDP
        if (p.severity >= 7) return "Unusual UDP spikes";
        return "DNS/resolved query";
    }
}

Packet generatePacket() {
    Packet p;
    p.sourceIP = generateRandomIP();
    p.destIP = generateRandomIP();
    p.protocol = randomProtocol();
    p.timestamp = time(NULL);

    if (p.protocol == "ICMP") {
        p.severity = randInt(7, 10);
    }
    else if (p.protocol == "TCP") {
        p.severity = randInt(4, 7);
    }
    else {
        p.severity = randInt(1, 4);
    }

    p.message = generateMessageForPacket(p);
    return p;
}
