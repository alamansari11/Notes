### Algorithms

**Algorithm:**
An algorithm is a step-by-step instruction to accomplish a specific task. It is a sequence of steps or rules to obtain the expected result from the given input.

**Characteristics of Algorithm:**
1. **Clear and Ambiguous:** The algorithm should be clear and should lead to only one meaning.
2. **Well-Defined Input:** The input should be well-defined and should have a clear meaning.
3. **Well-Defined Output:** The algorithm should define what output is to be yielded.
4. **Finiteness:** The algorithm should have finite steps.
5. **Feasible:** The algorithm should be implementable with the present technology, not anything that is in the future.
6. **Language Independent:** The algorithm should be language independent.

**Sorting Algorithm:**
Sorting algorithms are used to rearrange the given list or arrays followed by a particular pattern.

**Selection Sort:**
- It is an in-place sorting algorithm.
- Time Complexity: \(O(n^2)\)
- Inefficient for long inputs.
- It divides the input list into two parts: the left sorted sublist and the right unsorted list.
- Initially, the left sorted sublist is empty, and the right unsorted list is the whole input list.
- First, it takes the element at index \(i=0\) and stores it in the `minimum` variable. Then, it starts comparing it from \(j=i+1\) to \(n\).
- If `arr[j] < arr[minimum]`, it stores the index of `arr`.