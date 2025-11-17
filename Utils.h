#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <cctype>
using namespace std;

// ANSI colors 
#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define YELLOW  "\033[1;33m"
#define GREEN   "\033[1;32m"
#define CYAN    "\033[1;36m"
#define MAGENTA "\033[1;35m"

// -----------------------------
// Utility functions
// -----------------------------
int randInt(int min, int max);
string intToString(int n);
string timeTToString(time_t t);
string extractMinute(const string &timeStr);
string generateRandomIP();
string randomProtocol();
