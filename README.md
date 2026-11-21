# Empirical Analysis of Sorting Algorithms

From-scratch C++17 implementation and empirical time-complexity benchmarking of **Bubble Sort**, **Selection Sort**, **Insertion Sort**, and **Merge Sort** across input sizes $N \in \{5, 10, 50, 100\}$ using given ascending arrays (`Arr1`–`Arr4`) and reverse-sorted worst-case arrays.

## Student & Repository Details
* **Student Name:** Ali Haider
* **SAP ID:** 65333
* **Language:** C++17 (`std::chrono::high_resolution_clock` timing in microseconds, $\mu\text{s}$)
* **Trials per Size:** 10 timed runs per input size (after 1 warmup pass), averaged for analysis
* **Repository:** `https://github.com/ALIHAIDER101259/assignment3-analysis-of-algorithm-`

## Algorithms Implemented (From Scratch)
* **Bubble Sort:** Adjacent comparisons and swaps with an early-exit flag when a pass makes no swaps.
* **Selection Sort:** Repeatedly selects the minimum element from the unsorted portion and swaps once per outer pass.
* **Insertion Sort:** Inserts each element into its sorted position in the prefix by shifting larger elements right.
* **Merge Sort:** Divide-and-conquer recursive sort merging sorted subarrays using temporary left and right vectors.

## Test Cases
* **Given Ascending Arrays:** `Arr1` ($N=5$), `Arr2` ($N=10$), `Arr3` ($N=50$), and `Arr4` ($N=100$).
* **Reverse-Sorted Worst Case:** Descending sequences of sizes $N = 5, 10, 50, 100$.

## How to Compile and Run

### Using `g++` (Terminal / VS Code)
```bash
g++ -O2 sorting_benchmark_n.cpp -o sorting_benchmark_n
./sorting_benchmark_n
