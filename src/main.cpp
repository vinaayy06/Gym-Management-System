#include <iostream>
#include "member.h"
using namespace std;

extern void addMember();
extern void viewMembers();
extern void saveMembers();
extern void loadMembers();
extern void initTrainers();
extern void assignTrainer(int memberId);
extern void viewTrainers();
extern void checkExpiry();

int main() {
    loadMembers();
    checkExpiry();
    initTrainers();
    while (true) {
        cout << "\n=== Gym Management System ===\n";
        cout << "1. Add Member\n";
        cout << "2. View Members\n";
        cout << "3. Assign Trainer\n";
        cout << "4. View Trainers\n";
        cout << "5. Check Expired Memberships\n";
        cout << "6. Exit\n";
        cout << "Choice: ";

        int choice;
        cin >> choice;

        if (choice == 1) { addMember(); saveMembers(); }
        else if (choice == 2) viewMembers();
        else if (choice == 3) {
            int id;
            cout << "Enter member ID: ";
            cin >> id;
            assignTrainer(id);
            saveMembers();
        }
        else if (choice == 4) viewTrainers();
        else if (choice == 5) checkExpiry();
        else if (choice == 6) break;
    }
    return 0;
}




