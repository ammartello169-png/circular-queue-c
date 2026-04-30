# circular-queue-c
Simple circular queue implementation in C using arrays.
🔄 Circular Queue in C

📌 Description

This project demonstrates the implementation of a Circular Queue using an array in C.

The program:

- Takes a user's name as input
- Appends ""CE-ESY""
- Stores each character in a circular queue
- Prints the result after dequeue operations

---

🧠 Concept: What is a Circular Queue?

A Circular Queue is a linear data structure that connects the end back to the beginning.

Instead of wasting space like a normal queue, it reuses empty positions.

---

🔁 Queue Visualization

Step Example (Input: Ammar)

After adding ""CE-ESY"" → "AmmarCE-ESY"

Index:   0   1   2   3   4   5   6   7   8   9   10   11
        -----------------------------------------------
Data:   | A | m | m | a | r | C | E | - | E | S | Y |
        -----------------------------------------------
           ↑                               ↑
         read                            write

---

🔄 Circular Behavior

When the queue reaches the end:

(write_index + 1) % CAPACITY

Example:

Index:   18  19   0   1   2
        ---------------------
Data:   | X | Y | A | B | C |
        ---------------------
               ↑
             write (wrapped around)

---

⚙️ Operations

➕ Enqueue (Insert)

- Adds element at "write_index"
- Moves forward circularly

➖ Dequeue (Remove)

- Removes element from "read_index"
- Moves forward circularly

---

🧱 Data Structure

typedef struct {
    char data[CAPACITY];
    int write_index;
    int read_index;
    int current_size;
} CircularQueue;

---

🚀 How to Run

Compile:

gcc main.c -o queue

Run:

./queue

---

🖥️ Example

Input:

Ammar

Output:

AmmarCE-ESY

---

⚠️ Notes

- Max capacity = 20
- Overflow if full
- Underflow if empty

---

📊 UML Diagram (Simplified)

+----------------------+
|    CircularQueue     |
+----------------------+
| data[20]             |
| write_index          |
| read_index           |
| current_size         |
+----------------------+
| setupQueue()         |
| addToQueue()         |
| removeFromQueue()    |
| queueIsEmpty()       |
| queueIsFull()        |
+----------------------+

---

🎯 Key Idea

The magic line:

(write_index + 1) % CAPACITY

This makes the queue circular instead of linear.

---

👨‍💻 Author

Ammar

---
