#pragma once
#include <string>
using namespace std;

struct Member {
    int id;
    string name;
    int age;
    string membershipType;
    string expiryDate;
    int assignedTrainerId;
    bool isExpired;
};