# Recursive Binary Search

This program implements a recursive binary search algorithm in C. The algorithm efficiently searches for a given value within a sorted array by dividing the search range in half at each step. If the value is found, it returns the index where the value is located in the array. Otherwise, it returns -1 to indicate that the value was not found within the specified range.

## How to Use

1. Ensure you have a C compiler installed on your system (e.g., GCC).
2. Clone the repository or download the source code files.
3. Compile the code using the C compiler. For example:

```C
gcc binary_search.c -o binary_search 
```

4. Prepare an input file (input.txt) containing the test cases. The input file should follow this format:

```C
<number_of_test_cases>
<array_size>
<array_elements>
...
```
Example:
```C
2
5
1 3 5 7 9
3
2 4 6
```

5. Run the compiled executable, passing the input file as input:
```C
./binary_search
```

6. The program will read the input file and perform binary search on each test case. The output will be displayed on the console, indicating whether the searched value exists in the array and its index if found.

## Implementation Details

The core binary search algorithm is implemented recursively using the following steps:

1. Check if the low index is greater than the high index. If true, the value is not found, so return -1.

2. Calculate the middle index as `(low + high) / 2`.

3. Compare the value at the middle index with the target value:
    
    - If they are equal, return the middle index.
    
    - If the value at the middle index is greater than the target value, perform binary search on the left half of the array by recursively calling the binary search function with `low` and `mid - 1`.
    
    - If the value at the middle index is less than the target value, perform binary search on the right half of the array by recursively calling the binary search function with `mid + 1` and `high`.

4. Repeat the above steps until the value is found or the search range is empty.

    The `search` function acts as a wrapper for the `binarySearch` function, providing the initial low and high indexes to search within the array.

## Acknowledgments

This program was developed as an example implementation of the recursive binary search algorithm in CS1.