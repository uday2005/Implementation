# Revision Checklist: Sorting Algorithms

For effective revision, re-implement the following key components and patterns from scratch:

---

## 1. **Selection Sort**
- Write the full sort function (find min, swap).
- Practice both with and without helper functions.

## 2. **Insertion Sort**
- Implement the classic insertion sort.
- Try both ascending and descending order.
- Practice with nearly sorted arrays.

## 3. **Shell Sort**
- Implement with the 3*h+1 gap sequence.
- Practice reducing the gap and inner insertion sort.

## 4. **Bubble Sort**
- Implement with early exit optimization.
- Practice both standard and optimized versions.

## 5. **Shuffling**
- Implement Fisher-Yates (Knuth) shuffle.
- Optionally, try the "sort by random key" method.

## 6. **Merge Sort**
- Implement recursive (top-down) merge sort.
- Write the merge function from scratch.
- Implement iterative (bottom-up) merge sort.

## 7. **Quick Sort**
- Implement recursive quick sort with 2-way partitioning.
- Write the partition function yourself.
- Add random shuffling before sorting.
- Implement three-way partitioning for duplicates.
- Implement quick select for kth smallest element.
- Implement quick select for kth largest element.

---

## General Patterns to Practice

- **Stable vs Unstable Sorts:** Know which is which and why.
- **In-place vs Not In-place:** Implement both types.
- **Switching to Insertion Sort for Small Subarrays:** Practice hybrid approaches.
- **Edge Cases:** Empty arrays, single element, all elements equal, already sorted, reverse sorted.

---

## Recommended Practice

- Implement each algorithm from scratch without looking at notes.
- Test with various input cases (random, sorted, reverse, duplicates).
- Time your implementations and compare performance.
- Write a main function to call and test each sort.
- Try to explain each step in comments or to yourself.

---

# Notes: Index & Key Points for `elementary_sorting_algo.cpp`

## Index

1. **SelectionSort**
    - Constructor
    - `sort()` method
    - `print()` method

2. **InsertionSort**
    - Constructor
    - `sort()` method
    - `print()` method

3. **ShellShort** (Shell Sort)
    - Constructor
    - `sort()` method

4. **Shuffling**
    - Constructor
    - `shuffle_1()` method (Sort by random key)
    - `shuffle_2()` method (Knuth/Fisher-Yates shuffle)

5. **BubbleSort**
    - Constructor
    - `sort()` method

---

## What to Remember

### 1. Selection Sort
- Finds the minimum element in the unsorted part and swaps it with the first unsorted element.
- Time Complexity: O(n²)
- In-place, not stable.

### 2. Insertion Sort
- Builds the sorted array one item at a time by inserting elements into their correct position.
- Time Complexity: O(n²) worst, O(n) best (already sorted).
- Stable, in-place.

### 3. Shell Sort
- Generalization of insertion sort that allows the exchange of items far apart.
- Uses gap sequence (here: 3*h+1).
- Time Complexity: Depends on gap sequence, better than O(n²) for practical cases.

### 4. Shuffling
- `shuffle_1()`: Assigns random keys and sorts (not efficient).
- `shuffle_2()`: Knuth/Fisher-Yates shuffle, optimal O(n).

### 5. Bubble Sort
- Repeatedly steps through the list, compares adjacent elements, and swaps them if out of order.
- Time Complexity: O(n²)
- Stable, in-place.
- Optimized with early exit if already sorted.

---

## General Tips

- Know the difference between stable and unstable sorts.
- Understand when to use each algorithm (small arrays, nearly sorted, etc.).
- Remember the best, average, and worst-case complexities.
- For shuffling, always use Fisher-Yates for unbiased results.


# Notes: Merge Sort (`merge_sort.cpp`)

## Index

1. **MergeSort Class**
    - Constructor
    - `merge()` method
    - `sort()` method (recursive/top-down)
    - `bottom_up_sort()` method (iterative/bottom-up)

---

## What to Remember

### Merge Sort (Top-Down)
- **Divide and Conquer** algorithm: splits the array into halves, sorts each half, then merges.
- **Stable** sort (preserves order of equal elements).
- **Time Complexity:** O(n log n) in all cases.
- **Space Complexity:** O(n) (needs extra space for merging).
- **Not in-place** (uses extra memory).
- Can stop early if the biggest item in the first half is less than the smallest in the second half (already sorted).

### Merge Function
- Merges two sorted subarrays into one sorted array.
- Uses a temporary array to store merged result.
- After merging, copies back to the original array.

### Bottom-Up Merge Sort
- Iterative approach: merges subarrays of size 1, then 2, then 4, etc.
- Avoids recursion (no stack overflow risk).
- Useful for linked lists or when recursion depth is a concern.

---

## General Tips

- Merge Sort is preferred for **large datasets** and when stability is required.
- Not in-place: requires O(n) extra space.
- Good for sorting linked lists (can be made in-place for lists).
- Bottom-up version is useful for iterative implementations.
- For arrays that are already nearly sorted, Merge Sort still runs in O(n log n).


# Notes: Quick Sort (`quick_sort.cpp`)

## Index

1. **quick_sort Class**
    - Constructor
    - `partition()` method (2-way partitioning)
    - `shuffle()` method
    - `sort()` method (recursive)
    - `quick_select()` method (for kth smallest)
    - `three_way_partionining()` method (3-way partitioning for duplicates)

---

## What to Remember

### Quick Sort (Standard/2-way)
- **Divide and Conquer** algorithm: picks a pivot, partitions array into elements less than and greater than pivot, then sorts subarrays.
- **Time Complexity:**  
  - Average: O(n log n)  
  - Worst: O(n²) (rare, if pivot choices are poor)
- **Space Complexity:** O(log n) (due to recursion stack)
- **Not stable** (does not preserve order of equal elements).
- **In-place** (no extra array needed).
- Random shuffling before sorting helps avoid worst-case.

### Partition Function
- Rearranges array so that all elements less than pivot are on the left, greater on the right.
- Returns the final position of the pivot.

### Three-way Partitioning
- Useful when array has many duplicate elements.
- Divides array into three parts: less than, equal to, and greater than the pivot.
- Improves performance for arrays with many duplicates.

### Quick Select
- Finds the kth smallest element in O(n) average time.
- Uses partitioning logic similar to Quick Sort.

---

## General Tips

- Always shuffle the array before sorting to avoid worst-case performance.
- Use three-way partitioning for arrays with many duplicate keys.
- Quick Sort is not stable, but is very fast for in-memory sorting.
- Quick Select is efficient for finding order statistics (like median).
- For small subarrays, consider switching to insertion sort for better performance.

---

