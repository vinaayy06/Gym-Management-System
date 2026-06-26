#include "member.h"
#include <vector>
#include <iostream>
#include <ctime>
#include <sstream>
using namespace std;

extern vector<Member> members;

string getCurrentDate() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    char buf[11];
    sprintf(buf, "%04d-%02d-%02d", 1900 + ltm->tm_year, 1 + ltm->tm_mon, ltm->tm_mday);
    return string(buf);
}

void checkExpiry() {
    string today = getCurrentDate();
    int count = 0;
    for (auto& m : members) {
        if (m.expiryDate <= today) {
            m.isExpired = true;
            count++;
            cout << "[EXPIRED] ID: " << m.id << " | " << m.name
                 << " | Expired: " << m.expiryDate << "\n";
        }
    }
    if (count == 0) cout << "No expired memberships.\n";
}

