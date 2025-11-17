#pragma once
#include "BST.h"
#include <map>
#include <set>
using namespace std;

// -----------------------------
// Anomaly Detection (Member 3)
// -----------------------------
extern map<string,int> ipCount;
extern map<string,int> timeCount;
extern set<string> blacklist;
extern set<string> whitelist;
extern int criticalCount;
extern int totalPackets;
extern bool floodDetected;

void collectIPData(LogNode *root);
void analyzeSeverity(LogNode *root);
void detectTrafficFlooding();
void generateSummaryReport();
void detectAnomalies(LogNode *root);
void saveLogsToFile(LogNode *root);
