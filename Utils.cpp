#include "Utils.h"

int randInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

string intToString(int n) {
    ostringstream ss;
    ss << n;
    return ss.str();
}

string timeTToString(time_t t) {
    char* raw = ctime(&t);
    if (!raw) return string("");
    string s(raw);
    size_t pos = s.find_last_not_of('\n');
    if (pos != string::npos) s = s.substr(0, pos + 1);
    return s;
}

string extractMinute(const string &timeStr) {
    for (size_t i = 0; i + 4 < timeStr.size(); ++i) {
        if (isdigit((unsigned char)timeStr[i]) && isdigit((unsigned char)timeStr[i+1])
            && timeStr[i+2]==':' && isdigit((unsigned char)timeStr[i+3]) && isdigit((unsigned char)timeStr[i+4])) {
            return timeStr.substr(i, 5);
        }
    }
    if (timeStr.size() >= 5) return timeStr.substr(0,5);
    return timeStr;
}

string generateRandomIP() {
    int block = randInt(1, 3);
    if (block == 1)
        return "10." + intToString(randInt(0, 255)) + "." + intToString(randInt(0, 255)) + "." + intToString(randInt(1, 254));
    if (block == 2)
        return "172." + intToString(randInt(16, 31)) + "." + intToString(randInt(0, 255)) + "." + intToString(randInt(1, 254));
    return "192.168." + intToString(randInt(0, 255)) + "." + intToString(randInt(1, 254));
}

string randomProtocol() {
    int p = randInt(1, 3);
    if (p == 1) return "TCP";
    if (p == 2) return "UDP";
    return "ICMP";
}
