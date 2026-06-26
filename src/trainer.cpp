#include "trainer.h"
#include "member.h"
#include <vector>
#include <iostream>
using namespace std;
vector<Trainer> trainers;
int nextTrainerId = 1;

extern vector<Member> members;

void initTrainers() {
    if (!trainers.empty()) return;
    trainers.push_back({nextTrainerId++, "Kartik", "Strength", 3, {}});
    trainers.push_back({nextTrainerId++, Jatin", "Cardio", 3, {}});
    trainers.push_back({nextTrainerId++, "Yugam", "Yoga", 3, {}});
}

void assignTrainer(int memberId) {
    for (auto& m : members) {
        if (m.id == memberId) {
            for (auto& t : trainers) {
                if ((int)t.assignedMemberIds.size() < t.maxMembers) {
                    t.assignedMemberIds.push_back(memberId);
                    m.assignedTrainerId = t.id;
                    cout << "Assigned trainer " << t.name << " to member " << m.name << "\n";
                    return;
                }
            }
            cout << "No available trainers.\n";
            return;
        }
    }
    cout << "Member not found.\n";
}

void viewTrainers() {
    for (auto& t : trainers) {
        cout << "ID: " << t.id << " | " << t.name
                  << " | " << t.specialization
                  << " | Members: " << t.assignedMemberIds.size()
                  << "/" << t.maxMembers << "\n";
    }
}
