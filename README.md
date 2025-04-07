C++ Grocery Store System
A console-based grocery store application developed as part of the ITDEV-185 course. This project demonstrates object-oriented programming principles in C++.
Features

Shopping Cart Management: Add items, update prices, apply discounts
Object-Oriented Design: Utilizes inheritance and polymorphism
Item Classes: Base class Item with specialized FreshProduce and MeasuredProduct classes
Discount System: Apply percentage-based discounts to cart items
Checkout System: Calculate totals with optional tip

Project Structure

Item.h/cpp: Base class for all store items
FreshProduce.h/cpp: Specialized class for produce items
MeasuredProduct.h/cpp: Class for items sold by unit quantity
main.cpp: Contains the user interface and main program logic

How It Works

Users are presented with a menu to interact with the system
They can add items to their cart, specifying name, price, and quantity
Items can be updated (price changes, discounts)
At checkout, a receipt is generated with item details and total

Technical Highlights

Inheritance: Demonstrates IS-A relationships between classes
Virtual Functions: Uses polymorphism for price calculation and printing
Memory Management: Proper handling of dynamically allocated objects
Input Validation: Guards against invalid user inputs
Formatting: Professional output formatting using iostream manipulators

Skills Demonstrated

Object-oriented programming
C++ language features
Console application development
Software design principles
User input handling and validation

Author:
Domeneak Addison
