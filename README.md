
# 📁 FileFlow Automator

**FileFlow Automator** is a Linux-based automated file management system written in **C and Bash**.
It continuously monitors a directory and automatically sorts files into appropriate folders based on their file extensions.

This project demonstrates core **Operating System concepts** such as directory traversal, file permissions, process automation, and logging.

---

## 🚀 Features

* 📂 Automatic file sorting
* 🔁 Continuous directory monitoring
* 🧹 Zero-byte (empty) file removal
* 🔐 Permission checking (read/write)
* 🧾 Logging to log file
* ⚙️ Simple Bash-based automation

---

## 🗂️ File Sorting Rules

| File Type      | Destination Folder |
| -------------- | ------------------ |
| `.cpp`, `.c`, `.sh` | `Code/`       |
| `.txt`, `.pdf` | `Documents/`       |
| `.jpg`, `.png` | `Images/`          |
| Other files    | `Misc/`            |
| Empty files    | Deleted            |

---

## 📂 Required Folder Structure

Before running the program, make sure the following structure exists:

```
FileFlowAutomator/
│
├── watch_folder/
│
├── Code/
├── Images/
├── Misc/
├── Videos/
├── Documents/
│
├── fileflow.c
├── fileflow.sh
├── fileflow.log
```

📌 **Important:**
All files to be sorted must be placed inside the `watch_folder` directory.

---

## 🛠️ How to Compile

Make sure you are on **Linux (Ubuntu)** and have `gcc` installed.

```bash
gcc fileflow.c -o fileflow
```

---

## ▶️ How to Run

1. Make the Bash script executable:

```bash
chmod +x fileflow.sh
```

2. Start the FileFlow Automator:

```bash
./fileflow.sh
```

You will see:

```
FileFlow Automator Started
To end press 1
```

3. Add files to the `watch_folder`
   They will be automatically sorted every 5 seconds.

4. Press **`1`** to stop the program.

---

## 🧾 Logging

* All actions are logged in:

  * 📜 `fileflow.log'

### Example Log Entry:

```
[Fri Jan 16 00:10:43 2026] File: calculator.sh -> Moved to ./Code
```

---

## 🧠 Technologies Used

* **Language:** C, Bash
* **OS:** Linux (Ubuntu)
* **System Calls & Functions:**

  * `opendir()`, `readdir()`
  * `stat()`
  * `access()`
  * `rename()`
  * `remove()`

---

## 🎓 Academic Relevance

This project is suitable for:

* Operating Systems Lab
* File System Management demonstrations
* Process automation examples
* Viva and practical examinations

---

## 📌 Summary

FileFlow Automator simplifies file organization by automatically managing files in real time, showcasing practical operating system concepts through a lightweight and efficient design.

---
