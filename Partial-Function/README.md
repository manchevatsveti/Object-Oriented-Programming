
# Partial Function System

**Course**: Object-Oriented Programming   
**Program**: Software Engineering, Faculty of Mathematics and Informatics (FMI)  
**Year**: 2023/2024

## Task Description

This project involves designing and implementing a system for handling partial functions over 32-bit integers. The system should work with an abstract base class and its concrete subclasses, which perform various operations on partial functions. 

### Abstract Base Class: Partial Function

The base class **PartialFunction** must provide:
- A method to check if the function is defined at a given point.
- A method to compute the result of the function for a given integer `x`.

### Concrete Subclasses

1. **Partial Function by Criterion**: 
   - Constructor: Takes a function (or callable object) that, given an integer, returns a pair indicating whether the function is defined at that point and, if so, the result.

2. **Maximum of Partial Functions**:
   - Constructor: Takes several partial functions. The resulting function is defined at a point if and only if all the provided functions are defined at that point. The result for a given `x` will be the maximum of the results from all the functions at the same `x`.

3. **Minimum of Partial Functions**:
   - Constructor: Takes several partial functions. The resulting function is defined at a point if and only if all the provided functions are defined at that point. The result for a given `x` will be the minimum of the results from all the functions at the same `x`.

### File Input Specification

The program reads from a binary file `func.dat` to construct the appropriate partial function. The file begins with two non-negative 16-bit integers, `N` and `T`, where:

- `N` indicates the number of elements.
- `T` specifies the type of partial function to construct. The possible values for `T` and their corresponding construction rules are:

  - **0**: Followed by `2N` 32-bit integers defining a function with `N` arguments and results. The function is defined only at the provided arguments.
  - **1**: Followed by `N` 32-bit integers defining a function not defined at any of these numbers. For all other `x`, the function returns `x`.
  - **2**: Followed by `N` 32-bit integers defining a function that returns `1` for these numbers and `0` otherwise. The function is defined for all integers.
  - **3**: Followed by `N` strings, each terminated by `0`, describing paths to binary files. The resulting function is the maximum of the functions described in the referenced binary files.
  - **4**: Followed by `N` strings, each terminated by `0`, describing paths to binary files. The resulting function is the minimum of the functions described in the referenced binary files.

### Program Modes

The program operates in two modes:

1. **Range Query Mode**: 
   - Takes two integers `a` and `b` from standard input and outputs the results of the function for all integers in the interval `[a; b]`.

2. **Interactive Query Mode**:
   - Allows sequential querying of results for defined points, with each subsequent result generated upon user request.

### Example

**Input File `func.dat`**:
```
3 3
first.dat
second.dat
third.dat
7 0
0 1 2 3 5 6 7
0 3 3 3 4 4 0
2 1
3 5
4 2
0 5 6 7
```

**Commands**:
```
a = 0
b = 10
```

**Expected Output**:
```
f(0) = 1   f(1) = 3   f(2) = 3   f(6) = 6   f(7) = 7
```

**Note**: The contents of the binary files are shown as text for convenience in this example. The files themselves must be binary.
