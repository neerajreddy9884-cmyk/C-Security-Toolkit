# 🔐 C Security Toolkit

### Random Password Generator & Caesar Cipher Text Decoder

A menu-driven security utility developed using the C programming language. This project combines two functionalities: generating random passwords and decoding Caesar cipher encrypted text.

## 🚀 Features

### 1. Random Password Generator
- Generates passwords with lengths between 8 and 32 characters.
- Includes uppercase and lowercase letters.
- Includes numerical digits.
- Includes special characters.
- Guarantees at least one character from each category.
- Randomizes character positions using a shuffling algorithm.

### 2. Caesar Cipher Text Decoder
- Decodes Caesar cipher encrypted messages.
- Supports uppercase and lowercase alphabets.
- Accepts positive and negative shift values.
- Preserves spaces, numbers and special characters.
- Supports multiword messages.

### 3. Input Validation
- Validates numerical inputs.
- Handles invalid entries.
- Checks input ranges.
- Prevents integer overflow issues during input conversion.

## 🛠️ Technologies Used

- Programming Language: C
- Standard Libraries:
  - `stdio.h`
  - `stdlib.h`
  - `time.h`
  - `errno.h`
  - `limits.h`
  - `string.h`

## 📚 Concepts Implemented

- Functions and modular programming
- Arrays and strings
- Pointers
- Random number generation
- String manipulation
- Input validation
- Loops and conditional statements
- Switch-case statements
- Caesar cipher algorithm

## ⚙️ How to Run

### Step 1: Clone the repository

```bash
git clone https://github.com/YOUR-USERNAME/C-Security-Toolkit.git
```

### Step 2: Navigate to the project directory

```bash
cd C-Security-Toolkit
```

### Step 3: Compile the program

```bash
gcc main.c -o security_toolkit
```

### Step 4: Execute the program

Windows:

```bash
security_toolkit.exe
```

Linux/macOS:

```bash
./security_toolkit
```

## 📸 Project Demonstration

Screenshots of the program's menu, password generation and Caesar cipher decoding will be added here.

## 🎯 Learning Outcomes

Through this project, I strengthened my understanding of C programming, modular programming, string manipulation, random number generation and input validation.

## ⚠️ Disclaimer

This project is developed for educational purposes. The password generator uses the standard C `rand()` function and should not be used to generate passwords for real-world security applications.

## 👨‍💻 Developer

**S. Neeraj Reddy**

B.Tech – Electronics and Communication Engineering (ECE)

## 📜 License

This project is available under the MIT License.
