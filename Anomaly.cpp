#include "Anomaly.h"
#include <iostream>
#include <fstream>
#include "Utils.h"

map<string,int> ipCount;
map<string,int> timeCount;
set<string> blacklist;
set<string> whitelist;
int criticalCount = 0;
int totalPackets = 0;
bool floodDetected = false;

void collectIPData(LogNode *root) {
    if (root == NULL) return;

    collectIPData(root->left);

    string source = root->data.sourceIP;
    string minute = extractMinute(root->timestampStr);
    ipCount[source]++;
    timeCount[minute]++;
    totalPackets++;

    collectIPData(root->right);
}

void analyzeSeverity(LogNode *root) {
    if (root == NULL) return;

    analyzeSeverity(root->left);

    if (whitelist.find(root->data.sourceIP) != whitelist.end()) {
        cout << GREEN << "Whitelisted IP ignored: " << root->data.sourceIP << RESET << endl;
        analyzeSeverity(root->right);
        return;
    } else {
        if (blacklist.find(root->data.sourceIP) != blacklist.end()) {
            root->data.severity = 10;
            cout << RED << "BLACKLIST ALERT! " << root->data.sourceIP << " 's severity set to 10!" << RESET << endl;
        }
    }

    if (root->data.severity >= 8) {
        criticalCount++;
        cout << RED << "CRITICAL ALERT! " << root->data.sourceIP << " -> " << root->data.destIP
            << " | Severity: " << root->data.severity
            << " | Time: " << root->timestampStr << RESET << endl;
        cout << " Message: " << root->data.message << endl;
    }

    analyzeSeverity(root->right);
}

void detectTrafficFlooding(){
    cout << MAGENTA << "Checking for possible flooding..." << RESET << endl;
    for(map<string,int>::iterator it = timeCount.begin(); it != timeCount.end(); ++it) {
        if(it->second > 5) {
            floodDetected = true;
            cout << RED << "Possible Flooding Detected at minute: " << it->first << "; " << it->second << " packets captured!" << RESET << endl;
        }
    }
    if(!floodDetected) {
        cout << GREEN << "No flood-like activity detected!" << RESET << endl;
    }
}

void generateSummaryReport() {
    cout << CYAN << "\n----- IDS REPORT SUMMARY ----" << RESET << endl;
    cout << "Total Packets: " << totalPackets << endl;
    cout << "Total Unique IPs: " << ipCount.size() << endl;
    cout << "Total Critical Alerts: " << criticalCount << endl;

    int suspiciousIPs = 0;
    for (map<string,int>::iterator it = ipCount.begin(); it != ipCount.end(); ++it)
        if (it->second > 3) suspiciousIPs++;

    cout << "Total Suspicious IPs (>3 occurrences): " << suspiciousIPs << endl;
    cout << "Flood Alert Triggered: ";
    if(floodDetected)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    cout << CYAN << "-------------------------------" << RESET << endl;
}

void detectAnomalies(LogNode *root) {
    ipCount.clear();
    timeCount.clear();
    criticalCount = 0;
    totalPackets = 0;
    floodDetected = false;

    cout << CYAN << "\n--- Starting Anomaly Detection ---" << RESET << endl;

    collectIPData(root);

    cout << MAGENTA << "\nAnalyzing High-Severity Logs..." << RESET << endl;
    analyzeSeverity(root);

    cout << MAGENTA << "\nDetecting Suspicious IP Patterns..." << RESET << endl;
    for(map<string,int>::iterator it = ipCount.begin(); it != ipCount.end(); ++it) {
        if (it->second > 3) {
            cout << YELLOW << "  Suspicious IP Detected: "<< it->first << " appeared "<< it->second << " times." << RESET << endl;
        }
    }

    detectTrafficFlooding();
    generateSummaryReport();

    cout << CYAN << "\n--- End of Analysis ---\n" << RESET;
}

// -----------------------------
// Save Logs to File
// -----------------------------
void saveLogsToFileHelper(ofstream &file, LogNode *node) {
    if (!node) return;

    saveLogsToFileHelper(file, node->left);

    file << "[Severity: " << node->data.severity << "] "
         << node->data.protocol << " packet from "
         << node->data.sourceIP << " => " << node->data.destIP
         << " at " << node->timestampStr
         << " | Message: " << node->data.message << "\n";

    saveLogsToFileHelper(file, node->right);
}

void saveLogsToFile(LogNode *root) {
    ofstream file("IDS_Logs.txt");
    if (!file) {
        cout << RED << "Error opening file! Logs NOT saved." << RESET << endl;
        return;
    }

    saveLogsToFileHelper(file, root);

    file.close();
    cout << GREEN << "\nLogs saved successfully to IDS_Logs.txt!"<< RESET <<endl;
}
