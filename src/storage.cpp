#include "member.h"
#include "trainer.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

extern vector<Member> members;
extern int nextMemberId;
extern vector<Trainer> trainers;

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
        getline(ss, tmp, '|'); m.id = stoi(tmp);
        getline(ss, m.name, '|');
        getline(ss, tmp, '|'); m.age = stoi(tmp);
        getline(ss, m.membershipType, '|');
        getline(ss, m.expiryDate, '|');
        getline(ss, tmp, '|'); m.assignedTrainerId = stoi(tmp);
        getline(ss, tmp, '|'); m.isExpired = stoi(tmp);
        members.push_back(m);
        if (m.id >= nextMemberId) nextMemberId = m.id + 1;
    }
}

void saveTrainers() {
    ofstream file("data/trainers.txt");
    for (auto& t : trainers) {
        file << t.id << "|" << t.name << "|" << t.specialization << "|" << t.maxMembers << "|";
        for (int i = 0; i < (int)t.assignedMemberIds.size(); i++) {
            file << t.assignedMemberIds[i];
            if (i < (int)t.assignedMemberIds.size() - 1) file << ",";
        }
        file << "\n";
    }
}

void loadTrainers() {
    ifstream file("data/trainers.txt");
    if (!file.is_open()) return;
    trainers.clear();
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        Trainer t;
        string tmp;
        getline(ss, tmp, '|'); t.id = stoi(tmp);
        getline(ss, t.name, '|');
        getline(ss, t.specialization, '|');
        getline(ss, tmp, '|'); t.maxMembers = stoi(tmp);
        getline(ss, tmp, '|');
        if (!tmp.empty()) {
            stringstream ids(tmp);
            string id;
            while (getline(ids, id, ',')) {
                t.assignedMemberIds.push_back(stoi(id));
            }
        }
        trainers.push_back(t);
    }
}
