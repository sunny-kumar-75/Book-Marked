<div align="center">
  <h1>📚 BookMarked</h1>
  <p><i>A C++ Command-Line Library Management System</i></p>
</div>

---

**BookMarked** is a C++ command-line library management system. The application features a fully functional role-based login system for librarians and members, and manages book inventory, borrowing, and returns. It uses object-oriented programming principles and handles data persistence through CSV files, ensuring that all records are saved dynamically between sessions.

---

## ✨ Key Features

- 🔐 **Role-Based Logins:** Secure and separate menus for Librarians (Admins) and regular Members.
- 💾 **File-Based Storage:** Utilizes CSV files for reading and writing records, ensuring the library's data remains intact after the program exits.
- 🔍 **Flexible Searching:** Look up books by entering partial titles or author names, fully ignoring uppercase and lowercase differences.
- ⏱️ **Due Dates & Fines:** Automatically assigns 1-month due dates when a book is issued. Returning a book late triggers a calculated fine of ₹10 per day.
- 🛡️ **Robust Input Handling:** Built-in safeguards clear memory buffers if users type invalid data, preventing common infinite loops and program crashes.
- 📅 **Custom Calendar Engine:** Implements a from-scratch `Date` class that accurately tracks calendar logic—including leap year math and month-end clamping—without relying entirely on heavy external time libraries.
- 🧾 **Transaction Tracking:** Generates unique Transaction IDs to safely link borrowed books to specific members, keeping a perfect historical ledger of exactly who has which book and when it is due.
## 🛠️ How to Compile & Run

### 1. Open Terminal
Navigate to the project folder in your command line.

### 2. Compile the Code
Use the `g++` compiler to build the executable:
```bash
g++ *.cpp -o BookMarked.exe
```

### 3. Run the Program
```bash
./BookMarked.exe
```

## 👤 Default Admin Account
When running the program for the very first time, use these credentials to log in as the Librarian:
- **User ID:** `admin`
- **Password:** `admin123`

---
<div align="center">
  <p>Built with C++</p>
</div>
