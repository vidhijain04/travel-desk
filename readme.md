# Travel Desk

> This is a Transportation Management System (TMS), designed to efficiently handle the operations of a transport service. This system manages trips, vehicles, and bookings using a combination of object-oriented programming and data structures like binary search trees.

## Table of Contents

- [Features](#Features)
- [Technologies Used](#technologies-used)
- [Class Descriptions](#class-descriptions)
- [Installation and Usage](#installation-and-usage)
    - [Requirements](#requirements)
    - [Installation](#installation)
- [Future Improvements](#future-improvements)
- [License](#license)

## Features

- **Add Trips:** Easily add new trips, associating them with vehicles and locations.

- **Show Trips:** Retrieve trips within a specified time range, with optional destination filtering.

- **Book Trips:** Book seats on a trip, updating the number of booked seats and managing availability.

- **Efficient Data Management:** Use binary search trees for efficient trip management based on departure times.

## Technologies Used

![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c++&logoColor=white)

## Class Descriptions

1. **Vehicle:** Represents a vehicle with a unique number and seating capacity. Manages multiple trips associated with the vehicle.

2. **Trip:** Represents a trip with details like vehicle, pick-up location, drop-off location, departure time, and booked seats.

3. **TransportService:** Manages trips using a binary search tree for efficient search and retrieval based on departure times.

4. **BinaryTreeNode:** A node in the binary tree storing a trip and pointers to left, right, and parent nodes.

5. **BinaryTree:** Provides basic binary tree functionalities such as calculating the height and the number of nodes.

6. **BinarySearchTree:** Extends BinaryTree with binary search tree functionalities, including node insertion, deletion, and searching for nodes by key.

7. **Location:** Represents a location managing transport services to various drop-off locations.

8. **TravelDesk** Manages the entire transportation service, including adding trips, showing trips within a time range, booking trips, and managing locations.

## Installation and Usage

### Requirements

- c++ 11.4.0
- g++ 11.4.0

### Installation

1. Clone the repository

```bash
git clone https://github.com/vidhijain04/travel-desk.git
cd travel-desk
```

2. Compile the code

```bash
cd source
g++ -o tms main.cpp
```

3. Run the Application

```bash
./tms
```

> You can find unit testcases for the travel-desk in the `unit_testcases` directory. You can compile them to check its functioning as follows:

4. Go to the `unit_testcases` directory.

```bash
cd ../unit_testcases
```

5. Compile the test case files.

```bash
g++ -o tc_0 testcase.cpp
g++ -o tc_1 testcase_1.cpp
```

6. Run the Test Cases

```bash
./tc_0
./tc_1
```

## Future Improvements

 - **Memory Management:** Use smart pointers for automatic memory management.

- **Error Handling:** Implement robust error handling for invalid inputs and edge cases.

- **Optimization:** Optimize tree traversal and modification functions for better performance.

- **Documentation:** Add detailed comments and documentation for improved readability and maintainability.

## License

This project is licensed under the MIT License. See the `license.md` file for details.