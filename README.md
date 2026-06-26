# Gym Management System

A CLI-based gym management system built in C++ with file-persistent member records, automated membership expiry detection, and a trainer scheduling algorithm.

## Features

- **Member management** — add, remove, and view gym members
- **Attendance marking** — track daily member attendance
- **Membership expiry tracking** — automatically flags expired memberships on startup
- **Trainer scheduling** — assigns members to trainers based on availability and capacity
- **Persistent trainer assignments** — trainer data saved and loaded across sessions
- **File-based storage** — all data persists using plain text files (no database)

## Project Structure

```
Gym-Management-System/
├── src/
│   ├── main.cpp        # Entry point and menu loop
│   ├── member.h        # Member struct definition
│   ├── member.cpp      # Member operations (add, remove, view, attendance)
│   ├── trainer.h       # Trainer struct definition
│   ├── trainer.cpp     # Trainer scheduling algorithm
│   ├── storage.cpp     # File I/O for member and trainer persistence
│   └── expiry.cpp      # Membership expiry detection
├── data/
│   ├── members.txt     # Persistent member records
│   └── trainers.txt    # Persistent trainer records
└── README.md
```

## Installation

**Requirements:** macOS or Linux, g++ with C++17 support

```bash
# Clone the repo
git clone https://github.com/vinaayy06/Gym-Management-System.git
cd Gym-Management-System

# Build
g++ -std=c++17 src/main.cpp src/member.cpp src/storage.cpp src/trainer.cpp src/expiry.cpp -o gym

# Run
./gym
```

## Usage

```
=== Gym Management System ===
1. Add Member
2. View Members
3. Remove Member
4. Mark Attendance
5. Assign Trainer
6. View Trainers
7. Check Expired Memberships
8. Exit
```

```bash
# Add a member
> Enter name: Vinay
> Enter age: 20
> Membership type (basic/premium): premium
> Expiry date (YYYY-MM-DD): 2026-12-31
Member added! ID: 1

# Assign trainer (greedy scheduling by availability)
> Enter member ID: 1
Assigned trainer Kartik to member Vinay

# View trainers with capacity
ID: 1 | Kartik | Strength | Members: 1/3
ID: 2 | Jatin  | Cardio   | Members: 0/3
ID: 3 | Yugam  | Yoga     | Members: 0/3

# Expired memberships flagged automatically on startup
[EXPIRED] ID: 3 | Yugam | Expired: 2025-01-01
```

## Technical Details

- Data structures: `std::vector` with iterator-based deletion for member removal
- Scheduling: greedy algorithm assigns members to trainers with available capacity
- Expiry detection: compares stored date strings against system date on load
- Storage: pipe-delimited text files for simple, human-readable persistence
- Trainer persistence: comma-separated member ID lists saved to `data/trainers.txt`

## Language

C++ 100%
