#pragma once
#include <string>
#include <vector>
using namespace std;

struct Trainer {
    int id;
    string name;
    string specialization;
    int maxMembers;
    vector<int> assignedMemberIds;
};