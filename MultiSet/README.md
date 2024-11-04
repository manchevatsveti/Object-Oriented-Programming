
# MultiSet Class

**Course**: Object-Oriented Programming   
**Program**: Software Engineering, Faculty of Mathematics and Informatics (FMI)  
**Year**: 2023/2024

## Task Description

Implement a class named `MultiSet` that represents a multiset of numbers in the range from 0 to `n`, where `n` is specified in the constructor. The constructor takes two parameters: `n` (the maximum number in the set) and `k` (the maximum number of bits needed to store the count of occurrences of a number, where `1 <= k <= 8`). This means each number can occur in the multiset at most `2^k - 1` times.

The class should be optimized for memory usage and must support the following functionalities:

### Functionalities

1. **Add a Number**: 
   - Add a number to the multiset.

2. **Count Occurrences**: 
   - Check how many times a number occurs in the multiset.

3. **Print All Numbers**: 
   - Print all numbers present in the multiset.

4. **Print Memory Representation**: 
   - Print how the multiset is represented in memory.

5. **Serialization/Deserialization**: 
   - Serialize and deserialize the multiset to/from a binary file.

6. **Intersection/Difference**: 
   - Compute the intersection and difference of two multisets.

7. **Complement**: 
   - Compute the complement of the multiset. If a number `x` appears `p` times in the multiset, it appears `2^k - 1 - p` times in the complement.

### Example Usage

```python
# Create a MultiSet with numbers ranging from 0 to 10, and up to 3 bits for counting occurrences
ms = MultiSet(n=10, k=3)

# Add numbers
ms.add(1)
ms.add(1)
ms.add(2)

# Check occurrences
print(ms.count(1))  # Output: 2

# Print all numbers in the multiset
ms.print_all()  # Output: 1, 2

# Print memory representation
ms.print_memory()

# Serialize to a binary file
ms.serialize("multiset.dat")

# Deserialize from a binary file
ms2 = MultiSet.deserialize("multiset.dat")

# Compute the complement of the multiset
ms_complement = ms.complement()

# Compute the intersection and difference with another multiset
ms_intersection = ms.intersection(ms2)
ms_difference = ms.difference(ms2)
```
