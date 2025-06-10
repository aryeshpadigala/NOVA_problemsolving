
# 🚗 Automobile Maintenance Library

> A C++ console application to manage and track maintenance tasks for electric, gas, and diesel vehicles.

## 📖 Table of Contents

- [Motivation](#motivation)
- [Project Description](#project-description)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Technologies Used](#technologies-used)
- [Challenges and Learnings](#challenges-and-learnings)
- [Future Improvements](#future-improvements)
- [License](#license)
- [Acknowledgements](#acknowledgements)

## 🧠 Motivation

This project was created as part of an academic assignment to apply object-oriented programming (OOP) in a real-world context. The domain of automobile maintenance was chosen for its practicality and its natural fit for OOP principles such as inheritance, polymorphism, and encapsulation.

Our goal was to build a user-friendly, realistic C++ system where users can manage vehicle records, assign service tasks, and ensure that task applicability aligns with the vehicle's type. This project strengthened our design skills, modular thinking, and C++17 proficiency.

## 📦 Project Description

The **Automobile Maintenance Library** is a modular, extensible C++ console application for managing vehicle data and maintenance history.

Users can:
- Add vehicles (electric, gas, diesel)
- Assign tasks validated by vehicle type
- Remove and list maintenance tasks
- View task history and suggestions

It's built using modern C++ features like `std::shared_ptr`, STL containers, and class inheritance.

## 🌟 Features

- 🚗 Add and remove vehicles
- 🔧 Assign tasks based on vehicle type
- ❌ Prevent tasks that don't apply (e.g., oil change for electric cars)
- 📝 Create custom tasks (Other)
- 📋 List vehicle records
- 📈 Suggest tasks based on odometer reading
- 💬 Clean, user-friendly prompts
- 🧪 Unit tests with Google Test

## 💻 Installation

### 🔧 Prerequisites

- C++17 compiler (e.g., g++, clang++)
- CMake
- Google Test (auto-downloaded via CMake)

### 🛠️ To Build the Project

```bash
mkdir build
cd build
cmake ..
make
```

### ▶️ To Run the Application

```bash
./AutomobileApp
```

### 🧪 To Run the Unit Tests

```bash
ctest
# or directly
./AutomobileTests
```

## 🧰 Technologies Used

- **C++17** – Core language
- **STL (Standard Template Library)** – `vector`, `map`, `shared_ptr`
- **OOP** – Inheritance, encapsulation, polymorphism
- **CMake** – Build system
- **Google Test** – Unit testing framework
- **Console UI** – Input/output interactions

## 🤯 Challenges and Learnings

### 🔄 Challenges

- Building an OOP model with flexible maintenance logic
- Handling invalid input (type mismatches, year/odometer errors)
- Using smart pointers correctly for dynamic memory
- Ensuring clean separation of concerns between logic and UI
- Integrating a test suite for all core components

### 📘 Learnings

- Practiced inheritance and abstraction in a practical context
- Built safe, leak-free memory handling with `shared_ptr`
- Gained fluency in writing CMake scripts and Google Test cases
- Enhanced user experience with clear console messaging
- Learned the importance of validation and edge-case handling

## 🚀 Future Improvements

- Add motorcycles, trucks, and hybrid types
- Implement GUI (e.g., using Qt or a web front-end)
- Enable file/database storage for record persistence
- Add maintenance scheduling with time/mileage alerts
- Improve test coverage and input edge-case handling
- Add localization for multiple languages

## 📜 License

This project is for educational use. You may adapt and reuse the code with appropriate credit.

## 🙌 Acknowledgements

- Thanks to Google Test and the C++ Standard Library community
- Inspired by real-world service tracking software and tutorials

---

🚘 *Track your maintenance with confidence. Built with C++ and care.*
