// cd "C:\Users\abeer\cpp programs\DSA\DSA PROJECT"
// g++ main.cpp Utils.cpp Packet.cpp BST.cpp Anomaly.cpp -o main 
// .\main

#include "Packet.h"
#include "BST.h"
#include "Anomaly.h"
#include "Utils.h"
#include <limits>
#include <iostream>
using namespace std;

int main() {
    srand((unsigned)time(NULL));

    // Example blacklist / whitelist
    blacklist.insert("192.168.0.8");
    blacklist.insert("10.0.0.99");
    blacklist.insert("172.16.0.15");

    whitelist.insert("192.168.0.1");
    whitelist.insert("192.168.0.100");

    PacketQueue pq;
    BST bst;

    while (true) {
    	cout << CYAN << "\n\n--- IDS Main Menu ---" <<RESET <<endl;
        cout << "1. Generate & Enqueue Packet" <<endl;
        cout << "2. Dequeue & Print Packet"<<endl;
        cout << "3. Display Queue"<<endl;
        cout << "4. Process Packets (Queue -> BST)" <<endl;
        cout << "5. Display IDS Logs (BST - inorder by severity)" <<endl;
        cout << "6. Run Anomaly Detection (on current BST)" <<endl;
        cout << "7. Insert a Manual Packet to Queue (custom fields)" <<endl;
        cout << "8. Save IDS Logs to File " <<endl;
        cout << "9. Exit" <<endl;
        cout << MAGENTA <<"Enter choice: " <<RESET;

        int ch;
        if (!(cin >> ch)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');   
            string dummy; getline(cin, dummy);
            cout << "Please enter a valid number.\n";
            continue;
        }

        switch (ch) {
        case 1: {
            Packet p = generatePacket();
            cout << CYAN << "\nCaptured Packet: " <<RESET "[" << p.sourceIP <<RESET
                << " => " << p.destIP
                << " | " << p.protocol
                << " | Severity: " << p.severity
                << " | Time: " << timeTToString(p.timestamp) << "]\n";
            cout << YELLOW << "Message: " <<RESET << p.message << endl;
            pq.enqueue(p);
            break;
        }

        case 2:
            pq.dequeuePrint();
            break;

        case 3:
            pq.displayQueue();
            break;

        case 4:
            processPackets(pq, bst);
            break;

        case 5:
            bst.inorderTraversal();
            break;

        case 6: {
            LogNode* root = bst.getRoot();
            if (!root) {
                cout << "No logs in BST to analyze. Process packets first or insert logs.\n";
            } else {
                detectAnomalies(root);
            }
            break;
        }

        case 7: {
            Packet p;
            cout << "Enter source IP: "; cin >> p.sourceIP;
            cout << "Enter dest IP: "; cin >> p.destIP;
            cout << "Enter protocol (TCP/UDP/ICMP): "; cin >> p.protocol;
            cout << "Enter severity (1-10): "; cin >> p.severity;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter message: ";
            getline(cin, p.message);
            p.timestamp = time(NULL);
            pq.enqueue(p);
            break;
        }
        
        case 8: {
            LogNode* root = bst.getRoot();
            if (!root) {
                cout << RED << "No logs to save yet! Process packets first.\n" << RESET;
            } else {
                saveLogsToFile(root);
            }
            break;
        }

        case 9:
            cout << RED <<"Exiting program..\n" <<RESET;
            return 0;

        default:
            cout << RED <<"Invalid option! Try again.\n" <<RESET;
        }
    }

    return 0;
}
