#include "BST.h"
#include <ctime>

LogNode::LogNode(const Packet& p) : data(p), left(NULL), right(NULL) {
    timestampStr = timeTToString(p.timestamp);
}

BST::BST() : root(NULL) {}

LogNode* BST::insertRec(LogNode* node, const Packet& p) {
    if (!node) {
        cout << "Inserted packet with severity " << p.severity << " into BST.\n";
        return new LogNode(p);
    }

    if (p.severity < node->data.severity)
        node->left = insertRec(node->left, p);
    else
        node->right = insertRec(node->right, p);

    return node;
}

void BST::inorderRec(LogNode* node) {
    if (!node) return;
    inorderRec(node->left);

    cout << "[Severity: " << node->data.severity << "] "
        << node->data.protocol << " packet from "
        << node->data.sourceIP << " => " << node->data.destIP
        << " at " << node->timestampStr
        << " | Message: " << node->data.message
        << endl;

    inorderRec(node->right);
}

void BST::insertBST(const Packet& p) { root = insertRec(root, p); }

void BST::inorderTraversal() {
    if (!root) {
        cout << "No logs in IDS yet.\n";
        return;
    }
    cout << "\n--- IDS Logs (Sorted by Severity) ---\n";
    inorderRec(root);
}

LogNode* BST::getRoot() { return root; }

void processPackets(PacketQueue& pq, BST& bst) {
    if (pq.queueEmpty()) {
        cout << "Queue empty. No packets to process.\n";
        return;
    }

    cout << CYAN <<"\nProcessing packets..." <<RESET <<endl;

    while (!pq.queueEmpty()) {
        Packet p = pq.dequeueReturn();
        if (p.message.empty()) p.message = generateMessageForPacket(p);
        bst.insertBST(p);
    }
    cout << "All packets moved to IDS (BST).\n";
}
