# 🧮 Math Quiz Game (C++)

A simple **console-based Math Quiz Game** written in **C++** for Windows.  
Players can test their math skills with randomly generated questions, choose different operations, enable mixed mode, and even switch console themes.

---

## 🎮 Features

- ✅ Randomly generated math questions  
- ➕➖✖➗ Supports:
  - Addition  
  - Subtraction  
  - Multiplication  
  - Division  
  - Mixed mode (random operations)
- 🎯 Score tracking (correct & wrong answers)
- 🎨 Console themes (Dark / Light)
- 🎲 Random ASCII logo on startup
- 🔁 Play-again option

---

## 🖥️ Requirements

- **Windows OS**
- **C++ compiler** (MinGW, MSVC, etc.)
- Uses:
  - `<windows.h>`
  - `<iostream>`
  - `<ctime>`

> ⚠️ This program uses `system("cls")`, `system("color")`, and `Sleep()`  
> It is **Windows-only** and will not work properly on Linux/macOS without modification.

---

## ⚙️ How to Compile & Run

### Using g++ (MinGW)

```bash
g++ main.cpp -o math-quiz
math-quiz
