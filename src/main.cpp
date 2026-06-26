#include <iostream>
#include "member.h"
using namespace std;

extern void addMember();
extern void viewMembers();
extern void removeMember(int id);
extern void markAttendance(int id);
extern void saveMembers();
extern void loadMembers();
extern void initTrainers();
extern void assignTrainer(int memberId);
extern void viewTrainers();
extern void checkExpiry();
extern void saveTrainers();
extern void loadTrainers();

int main() {
    loadMembers();
    loadTrainers();
    if (trainers.empty()) initTrainers();
    checkExpiry();
    while (true) {
        cout << "\n=== Gym Management System ===\n";
        cout << "1. Add Member\n";
        cout << "2. View Members\n";
        cout << "3. Remove Member\n";
        cout << "4. Mark Attendance\n";
        cout << "5. Assign Trainer\n";
        cout << "6. View Trainers\n";
        cout << "7. Check Expired Memberships\n";
        cout << "8. Exit\n";
        cout << "Choice: ";

        int choice;
        cin >> choice;

        if (choice == 1) { addMember(); saveMembers(); }
        else if (choice == 2) viewMembers();
        else if (choice == 3) {
            int id;
            cout << "Enter member ID to remove: ";
            cin >> id;
            removeMember(id);
            saveMembers();
        }
        else if (choice == 4) {
            int id;
            cout << "Enter member ID: ";
            cin >> id;
            markAttendance(id);
        }
        else if (choice == 5) {
            int id;
            cout << "Enter member ID: ";
            cin >> id;
            assignTrainer(id);
            saveMembers();
            saveTrainers();
        }
        else if (choice == 6) viewTrainers();
        else if (choice == 7) checkExpiry();
        else if (choice == 8) break;
    }
    return 0;
}
