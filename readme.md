# Menu-Driven Program for Dynamic Array Operations

This C++ program demonstrates the use of dynamic memory allocation and resizing in an interactive, menu-driven environment. The program creates a dynamic array, allows the user to perform operations such as adding new numbers, deleting numbers, printing the array, and printing the sum of the array. The user can perform operations repeatedly until they choose to exit.

## How It Works

1. **Dynamic Array Creation**: 
   - A dynamic array of size 5 is created initially with random values between 0 and 10.
   
2. **Menu Options**: 
   - The program offers five operations:
     1. Add a new number.
     2. Delete a number.
     3. Print the array.
     4. Print the sum of the array.
     5. Exit the program.
   
3. **Dynamic Resizing**: 
   - When a new number is added, the array size increases by one using the `ResizeArray` function, and when a number is deleted, the size decreases accordingly.
   
4. **Interactive Menu**: 
   - The user can interact with the program through a menu-driven system, repeating actions until they decide to exit.

## Features

- **Dynamic Memory Management**: 
   - The array size is dynamically managed based on user input.
   
- **Add/Delete Numbers**: 
   - Users can add new numbers to the array, automatically increasing its size, and delete numbers, decreasing the array size.
   
- **Array Manipulation**: 
   - The program prints the current state of the array and computes the sum of all elements.

## Functions Description

### `Resize_array()`
```cpp
void Resize_array(int *&ptr, int &size_of_array);
void Add_new_number(int *&ptr, int &size_of_array);
void Delete_a_number(int *&ptr, int &size_of_array);
void Print_the_array(int *ptr, int size_of_array);
void Print_sum_of_array(int *ptr, int size_of_array);
*********************
Press [1] to Add a Number: 
Press [2] to Delete a Number:
Press [3] to Print the Array:
Press [4] to Print Sum of Array:
Press [5] to Exit:

Enter your choice (1-5): 1
Enter number: 7
Number added successfully.

Enter your choice:
[1] Main Menu
[0] Exit: 1

Press [1] to Add a Number: 
Press [2] to Delete a Number:
Press [3] to Print the Array:
Press [4] to Print Sum of Array:
Press [5] to Exit:

Enter your choice (1-5): 3
Array is: 1 2 3 4 5 7 

Enter your choice:
[1] Main Menu
[0] Exit: 1

Press [1] to Add a Number: 
Press [2] to Delete a Number:
Press [3] to Print the Array:
Press [4] to Print Sum of Array:
Press [5] to Exit:

Enter your choice (1-5): 4
Sum of Array is: 22
