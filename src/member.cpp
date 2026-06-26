#include "member.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

vector<Member> members;
int nextMemberId = 1;

void addMember() {
    Member m;
    m.id = nextMemberId++;
    cout << "Enter name: ";
    cin >> m.name;
    cout << "Enter age: ";
    cin >> m.age;
    cout << "Membership type (basic/premium): ";
    cin >> m.membershipType;
    cout << "Expiry date (YYYY-MM-DD): ";
    cin >> m.expiryDate;
    m.assignedTrainerId = -1;
    m.isExpired = false;
    members.push_back(m);
    cout << "Member added! ID: " << m.id << "\n";
}

void viewMembers() {
    if (members.empty()) {
        cout << "No members found.\n";
        return;
    }
    for (auto& m : members) {
        cout << "ID: " << m.id
                  << " | " << m.name
                  << " | Age: " << m.age
                  << " | " << m.membershipType
                  << " | Expires: " << m.expiryDate
                  << (m.isExpired ? " [EXPIRED]" : "")
                  << "\n";
    }
}