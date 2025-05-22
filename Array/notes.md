
# MyArray: Static Array Implementation

## Overview

- A simple static array class with fixed capacity.
- Manages insertion, access, and display of elements.


### Key Features:

- **Fixed Capacity**: Size determined at initialization.
- **Basic Operations**: `push()`, `set()`, `get()`, `display()`, `size()`.


### Public Methods:

- **`push(int value)`**: Adds element to the end if space exists.
- **`set(int index, int value)`**: Updates element at `index`.
- **`get(int index)`**: Returns element at `index` (bounds-checked).
- **`display()`**: Prints all elements.
- **`size()`**: Returns current number of elements.


### Usage Example:

```cpp
MyArray arr(5);
arr.push(10);
arr.set(0, 99);
cout << arr.get(0); // Output: 99
arr.display();      // Output: Array elements: 99 
```


---

# MyVector: Dynamic Array Implementation

## Overview

- A dynamic array class with automatic resizing (similar to `std::vector`).
- Grows/shrinks capacity as needed for efficient memory usage.


### Key Concepts:

- **Capacity**: Total allocated memory (doubles when full).
- **Length**: Current number of elements in use.
- **Resizing**: Uses `resize()` to manage capacity dynamically.


### Public Methods:

- **`push_back(int val)`**: Adds element to the end (resizes if full).
- **`prepend(int val)`**: Inserts element at the start (shifts elements right).
- **`pop()`**: Removes and returns last element (optionally shrinks capacity).
- **`delete_index(int idx)`**: Deletes element at `idx` and shifts left.
- **`delete_val(int val)`**: Removes all occurrences of `val` (two-pointer method).
- **`find(int val)`**: Returns first index of `val` (returns -1 if not found).
- **`print()`**: Displays all elements.


### Key Implementation Details:

- **Resizing Logic**:
    - **Growth**: Doubles capacity when `length == capacity`.
    - **Shrink**: Reduces capacity by half if `capacity > 4 * length` (min capacity: 16).
- **Pointer Arithmetic**: Uses `*(arr + i)` instead of `arr[i]` for element access.


### Usage Example:

```cpp
MyVector vec;
vec.push_back(10);
vec.prepend(5);
vec.pop(); // Returns 10
vec.print(); // Output: MyVector: 5 
```

## **Time Complexity**

1.  **Access by Index**:  **O(1)**: Direct access using `arr[i]` due to contiguous memory layout.

2.  **Search**: **O(n)**: Linear search required for unsorted arrays (worst case).

3.  **Insertion**:

-  **End (Dynamic Array)**:**Amortized O(1)**: If capacity allows. Resizing (doubling capacity) takes O(n) but averages to O(1) over many insertions.

-  **Beginning/Middle**: **O(n)**: Requires shifting all subsequent elements.

4.  **Deletion**:

-  **End**: **O(1)**: No shifting needed (dynamic arrays may shrink capacity).

-  **Beginning/Middle**:**O(n)**: Requires shifting elements to fill the gap.

5.  **Resizing (Dynamic Arrays)**: **O(n)**: Copying elements to a new array when capacity changes.

## **Space Complexity**

-  **Static Arrays**: **O(n)**: Fixed size; unused space if underfilled.

-  **Dynamic Arrays**:**O(n)**: Allocates memory for elements + extra capacity (typically 2x current size).