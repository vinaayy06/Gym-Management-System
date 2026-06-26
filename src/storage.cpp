#include "member.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;
extern vector<Member> members;
extern int nextMemberId;

void saveMembers() {
    ofstream file("data/members.txt");
    for (auto& m : members) {
        file << m.id << "|" << m.name << "|" << m.age << "|"
             << m.membershipType << "|" << m.expiryDate << "|"
             << m.assignedTrainerId << "|" << m.isExpired << "\n";
    }
    cout << "Members saved.\n";
}

void loadMembers() {
    ifstream file("data/members.txt");
    if (!file.is_open()) return;
    members.clear();
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        Member m;
        string tmp;
        getline(ss, tmp, '|'); m.id = std::stoi(tmp);
        getline(ss, m.name, '|');
        getline(ss, tmp, '|'); m.age = std::stoi(tmp);
        getline(ss, m.membershipType, '|');
        getline(ss, m.expiryDate, '|');
        getline(ss, tmp, '|'); m.assignedTrainerId = std::stoi(tmp);
        getline(ss, tmp, '|'); m.isExpired = std::stoi(tmp);
        members.push_back(m);
        if (m.id >= nextMemberId) nextMemberId = m.id + 1;
    }
}
