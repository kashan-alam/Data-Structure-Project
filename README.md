# Online Bookstore Management System

## Overview
This C++ application implements a comprehensive online bookstore management system using various data structures. The system allows users to browse books, search for specific titles, manage a shopping cart, and complete purchases with payment details.

## Features

### Customer Features
- **Book Browsing**: View books sorted by:
  - Price (high to low)
  - Price (low to high)
  - Title (high to low) 
  - Title (low to high)
- **Book Search**: Find specific books by title
- **Shopping Cart Management**:
  - Add books to cart
  - View cart contents
  - Remove items from cart
  - Checkout

### Admin Features
- Admin login with authentication
- Add new books to the inventory

## Data Structures Used

1. **Binary Search Trees (BST)**: 
   - Two BSTs to organize books by price and title
   - Enables efficient searching and sorted traversal

2. **Linked List**:
   - Manages the shopping cart
   - Tracks order quantity and references original inventory

3. **Stack**:
   - Implements high-to-low ordering of books by price and title

4. **Priority Queue**:
   - Manages customer support requests based on priority levels

5. **Struct and Class Implementation**:
   - Structured data organization for books, requests, and user information

## Technical Implementation

### Key Classes
- `node`: Basic structure for book information
- `linked_list`: Implementation for shopping cart management
- `book`: Core class with BST implementations for inventory management
- `Payment`: Handles payment processing and customer information
- `Login_admin`: Administrator authentication and inventory management
- `Request`: Support ticket structure with priority handling

### Algorithms
- BST insertion and traversal algorithms
- Stack-based sorting implementations
- Priority queue implementation for customer support

## How to Use

### Main Menu Options
1. **Book List**: Browse all available books with sorting options
2. **Search**: Find specific books by title
3. **Cart**: Manage shopping cart and checkout process
4. **Login**: Administrator access for inventory management
5. **Customer Support**: Access priority-based support system
6. **Store Information**: View bookstore details
7. **Exit**: Close the application

### Admin Access
- Admin credentials are required for administrative functions
- Default credentials:
  - Username: 22k-4561 or 22k-4164
  - Password: rayyan or kashan

## Build Instructions
The project can be built with Visual Studio using the included solution (.sln) and project files (.vcxproj).

1. Open the solution file in Visual Studio
2. Build the solution (F7 or Build > Build Solution)
3. Run the application (F5 or Debug > Start Debugging)

## Dependencies
- Standard C++ libraries
## Contributors
- Project implementation by the Data Structures course team

---

*This application was developed as a data structures project to demonstrate the practical implementation of various data structures in a real-world application scenario.*
