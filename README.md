# 📘 Social Network Backend System in C

A console-based Social Networking Backend System implemented in C using Graph and Linked List data structures.

This project simulates core functionalities of a social media platform such as account creation, authentication, friend management, post sharing, reactions, and messaging — all implemented using low-level data structures.

---

## 🚀 Features

- 🔐 User Account Creation & Login Authentication
- 👥 Friend Request & Two-Way Friendship System
- 🧵 Graph-Based User Storage (A–Z Bucketing)
- 📝 Post Creation & Sharing
- ❤️ Post Reactions (Like, Love, Dislike)
- 💬 Messaging Between Friends
- 📊 Display Followers & Following Count
- 🧠 Dynamic Memory Allocation using `malloc`

---

## 🏗 Data Structures Used

| Feature | Data Structure Used |
|----------|----------------------|
| User Storage | Graph (Adjacency List) |
| Friend List | Linked List |
| Posts | Linked List |
| Messages | Linked List |
| Bucketing Users | A–Z Alphabet Hashing |

---

## 📂 Project Structure

Social-Network-Graph-C/
│
├── src/
│ ├── main.c
│ └── social_network.c
│
├── include/
│ └── social_network.h
│
├── README.md
├── .gitignore
└── Makefile


---

## 🧠 How It Works

- Users are stored in a graph using 26 buckets (A–Z).
- Each bucket represents the first letter of the username.
- Every user node contains:
  - Friend list
  - Post list
  - Message list
  - Login credentials
- Posts propagate to friends.
- Reactions update post counters.
- Messaging system allows communication between connected users.

---

## 🎯 Learning Objectives

This project demonstrates:

- Implementation of Graph using Adjacency List
- Multi-level Linked Lists
- Dynamic Memory Management
- Struct-Based Data Modeling
- Basic Authentication Logic
- Console-Based Application Design
- Social Network Simulation

---

## 💡 Key Concepts Practiced

- Pointers
- Memory allocation (`malloc`)
- String handling
- Nested data structures
- Modular programming
- Graph traversal

---

## 👨‍💻 Author

**Manav Dhaye**  
Computer Science Student  
Passionate about Data Structures & System Design  

---

## ⭐ Future Improvements (Optional Enhancements)

- File storage (persistent data)
- Memory deallocation handling
- Improved UI
- Convert to C++ (OOP)
- Add database integration

## ⚙️ How to Compile & Run

### 🔹 On Windows (MinGW / GCC)

gcc src/main.c src/social_network.c -o social_network.exe
social_network.exe
