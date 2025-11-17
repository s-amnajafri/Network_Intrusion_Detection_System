#pragma once
#include "Packet.h"
#include <iostream>
using namespace std;

// -----------------------------
// Hybrid BST (Member 2)
// -----------------------------
struct LogNode {
    Packet data;
    string timestampStr;
    LogNode* left;
    LogNode* right;
    LogNode(const Packet& p);
};

class BST {
private:
    LogNode* root;
    LogNode* insertRec(LogNode* node, const Packet& p);
    void inorderRec(LogNode* node);

public:
    BST();
    void insertBST(const Packet& p);
    void inorderTraversal();
    LogNode* getRoot();
};

// Process packets from queue -> BST
void processPackets(PacketQueue& pq, BST& bst);
