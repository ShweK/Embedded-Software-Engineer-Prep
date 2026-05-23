# Day 1 - Class, Constructor, Destructor

## Goal
Understand the basic structure of a C++ class.

## Notes
- A class is a user-defined type.
- A constructor runs when an object is created.
- A destructor runs when an object is destroyed.
- Destructor is useful for cleanup.
- This is the base idea behind RAII.

## Example
A constructor can initialize data.
A destructor can release resources or print cleanup logs.

## Why it matters for embedded/system roles
- Object lifetime matters
- Resource cleanup matters
- Safer design than scattered manual cleanup
