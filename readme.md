# BC 301A: Design and Analysis of Algorithms
## Detailed Study Notes (full explanations)

These notes expand your class notes (6 Jul to 5 Oct 2026). Each topic has the definition, the reasoning behind it, worked examples traced step by step, and the exam points. Where your handwritten pages left a question open (homework, assignments, blank sections), I've answered it in a section marked **Extra**.

**Contents**
1. Introduction to algorithms
2. Analysing algorithms
3. Asymptotic notations
4. Growth rates of functions
5. Divide and Conquer
6. Solving recurrences
7. Max/Min by Divide and Conquer
8. Quick Sort
9. Greedy method (Huffman, Activity selection)
10. Heap and Heap Sort
11. Answers to open questions from the notes

---

# 1. Introduction to Algorithms

## 1.1 Definition
An **algorithm** is any well-defined computational procedure that takes some value (or set of values) as **input** and produces some value (or set of values) as **output**. In other words, it is a finite sequence of computational steps that transforms the input into the output.

**Everyday analogy: making tea**

| Step | Action | Role |
|---|---|---|
| 1 | Turn on the stove | |
| 2 | Boil some water | input |
| 3 | Put in the tea leaves | input |
| 4 | Let it boil | processing |
| 5 | Get the tea (liquor) | output |

This is an algorithm because the steps are clear, ordered, finite, and produce a result.

## 1.2 Algorithms and the sorting problem
Sorting is a fundamental operation in computer science (searching, databases and many other algorithms depend on sorted data), so many good sorting algorithms exist.

**Correctness.** An algorithm is **correct** if, for *every* input instance, it **halts** with the **correct output**. An incorrect algorithm might:
- never halt on some inputs, or
- halt with a wrong answer.

**Formal sorting problem**
- **Input:** a sequence of n numbers ⟨a₁, a₂, …, aₙ⟩
- **Output:** a permutation (reordering) ⟨a₁', a₂', …, aₙ'⟩ of the input such that a₁' ≤ a₂' ≤ … ≤ aₙ'

For example, input ⟨31, 41, 59, 26, 41, 58⟩ gives output ⟨26, 31, 41, 41, 58, 59⟩.

Each concrete input (like the sequence above) is called an **instance** of the problem. An algorithm must work for *all* instances.

## 1.3 Environment of an algorithm
An **agent** (a human or a machine) supplies a **valid input** to the algorithm. The algorithm processes it and returns the **output**. "Valid" matters because an algorithm is only guaranteed to work for legal inputs.

## 1.4 Types of problems
**Computational problem:** one that a computer can solve. It is characterised by:
- (a) a formulation of all **legal inputs** and the **expected outputs**, and
- (b) a characterisation of the **relationship** between output and input.

**Non-computational problem:** one that cannot be solved by computers.

### Categories of computational problems
1. **Structuring problems:** arrange data, e.g. sort a list in ascending/descending order.
2. **Search problems:** look for a target among all possibilities, e.g. find a roll number in a list.
3. **Construction problems:** build a solution that satisfies the problem's constraints, e.g. build a timetable.
4. **Decision problems:** the answer is Yes or No, e.g. "is this number prime?"
5. **Optimisation problems:** find the best solution under constraints. They have an objective function that is maximised or minimised (e.g. minimise effort, find the shortest path).

### Worked example A: factorial
N! = N × (N−1) × (N−2) × … × 1, for a positive integer N. For N = 5: 5 × 4 × 3 × 2 × 1 = 120.

### Worked example B: counting pass/fail students
Pass mark = 50. Data:

| Reg. No. | Name | Marks |
|---|---|---|
| 1 | AD | 80 |
| 2 | BD | 30 |
| 3 | CD | 83 |
| 4 | DD | 23 |
| 5 | ED | 90 |
| 6 | FD | 78 |

**Version 1 (descriptive)**
1. Analyse the marks obtained by each student.
2. There are 6 students in total.
3. Pass criterion is 50, so AD, CD, ED, FD passed.
4. BD and DD failed to reach the minimum.
5. Stop.

**Version 2 (loop-based, closer to code)**
```
Step 1: counter = 1, no_of_students = 6, pass_count = 0, fail_count = 0
Step 2: while (counter <= no_of_students)
    2.1 read the marks of the current student
    2.2 compare the marks with 50
    2.3 if marks >= 50 then pass_count = pass_count + 1
        else fail_count = fail_count + 1
    2.4 counter = counter + 1
Step 3: print pass_count and fail_count
Step 4: exit
```

**Dry run**

| counter | marks | marks ≥ 50? | pass_count | fail_count |
|---|---|---|---|---|
| 1 | 80 | yes | 1 | 0 |
| 2 | 30 | no | 1 | 1 |
| 3 | 83 | yes | 2 | 1 |
| 4 | 23 | no | 2 | 2 |
| 5 | 90 | yes | 3 | 2 |
| 6 | 78 | yes | 4 | 2 |

Output: **pass = 4, fail = 2**.

(Initialising pass_count and fail_count to 0 is essential. The handwritten steps don't show it, but the counts must start at zero.)

## 1.5 Characteristics of a good algorithm
| # | Property | Explanation |
|---|---|---|
| 1 | **Input** | Takes zero or more inputs (zero when it generates values on its own, e.g. print the first 10 squares). |
| 2 | **Output** | Produces at least one output. An algorithm with no result is pointless. |
| 3 | **Definiteness** | Each instruction is precise and unambiguous. "Add a little salt" is not definite; "add 5 g of salt" is. |
| 4 | **Uniqueness** | The result of each step is uniquely defined and depends only on the input and the previous steps. |
| 5 | **Correctness** | Gives the correct output for every valid input. |
| 6 | **Effectiveness** | Every instruction is basic enough to be carried out in finite time. Overly complex steps may not work well. |
| 7 | **Finiteness** | Terminates after a finite number of steps for all inputs. |
| 8 | **Simplicity** | Based on the task, the steps and terms should be as simple as possible. |
| 9 | **Generality** | Solves all instances of the problem, not just one. |
| 10 | **Efficiency** | Uses minimum time and memory. |

## 1.6 Algorithm vs Program

| Point | Algorithm | Program |
|---|---|---|
| Phase | Written in the **design** phase | Written in the **implementation** phase |
| Knowledge needed | **Domain** knowledge (understanding the problem) | **Programming** knowledge |
| Language | Any language (English, pseudocode, flowchart) | A specific programming language |
| Dependence | Independent of hardware and software | Software-based; depends on the language and platform |
| Verification | **Analysed** for time and space | **Checked for faults** (testing and debugging) |

---

# 2. Analysing Algorithms

## 2.1 Parameters to consider
1. **Time:** how long it takes to run
2. **Space:** how much memory it needs
3. **Bandwidth:** data transferred (important in networks)
4. **Registers:** number of CPU registers used
5. **Battery power:** energy consumed (mobile and embedded devices)

Of these, **time** and **space** matter most, and **time** is generally the most important.

## 2.2 The problem-solving cycle
1. **Problem definition:** understand clearly what is to be solved.
2. **Constraints and conditions:** limits on input size, time, memory, etc.
3. **Design strategies:** choose an approach (divide and conquer, greedy, etc.).
4. **Express and develop the algorithm:** write it in pseudocode or a flowchart.
5. **Validation (dry run):** trace the algorithm by hand on sample inputs.
6. **Analysis:** study its space and time requirements.
7. **Coding:** translate it into a programming language.
8. **Testing and debugging:** run it and fix errors.
9. **Installation:** deploy it.
10. **Maintenance:** update and fix it over time.

## 2.3 Two ways of analysing an algorithm
| | Experimental (a posteriori / relative) | A priori (independent / absolute) |
|---|---|---|
| When | After the algorithm is converted to code | Before coding |
| How | Implement both algorithms, run them on a computer with various inputs, measure which takes less time | Use asymptotic notation and mathematical tools to find the **order of magnitude** of the number of steps |
| Depends on | Hardware, language, compiler, current system load | Only the algorithm itself |
| Result | Actual seconds | A growth function like n² or n log n |

The a priori method is preferred because the result does not change from machine to machine.

## 2.4 Asymptotic analysis
**Asymptotic analysis** evaluates the performance of an algorithm in terms of **input size**. We calculate how the time (or space) taken grows as the input size grows, treating the running time as a function of n.

**Example:** suppose insertion sort takes T(n) = c·n² + k and merge sort takes T'(n) = c'·n·log₂n + k'. For small n the two may be close, but as n grows (lakhs of data items) the n² curve rises far above the n log n curve.

We typically **ignore small values of n** because we want to know how slow the program will be on very large inputs.

**Rule of thumb:** *the slower the asymptotic growth rate, the better the algorithm.*

Running time is studied in three scenarios:
- **Best case:** the most favourable input
- **Average case:** a typical input
- **Worst case:** the least favourable input (the guarantee we usually care about)

---

# 3. Asymptotic Notations

Execution time depends on the instruction set, processor speed, disk I/O speed and so on. So instead of measuring seconds, we express efficiency asymptotically with a time function **T(n)**, where n is the input size.

| Symbol | Name | Idea | Typical use |
|---|---|---|---|
| **O** | Big O | Upper bound (never worse than) | Worst case |
| **Ω** | Big Omega | Lower bound (never better than) | Best case |
| **Θ** | Big Theta | Tight bound (both upper and lower) | Exact growth / average |
| **o** | Little o | Strict upper bound | |
| **ω** | Little omega | Strict lower bound | |

**Analogy: buying a house.** Budget planned is 1 crore (including interiors); offers might cost 90 lakhs or 80 lakhs. "At most 1 crore" is the upper bound (O); "at least 80 lakhs" is a lower bound (Ω); knowing a house costs about 90 lakhs is a tight estimate (Θ).

## 3.1 Big O notation (worst case)
**Meaning:** g(n) is an **upper bound** on f(n) for large n.

**Definition:** f(n) = O(g(n)) if there exist positive constants **c** and **n₀** such that

0 ≤ f(n) ≤ c·g(n) for all n ≥ n₀

**In words:** beyond some point n₀, the curve c·g(n) stays on or above f(n). For any input size, the running time does not cross the time given by c·g(n). Since it gives the worst-case running time, Big O is the most widely used notation.

## 3.2 Omega notation (best case)
**Definition:** f(n) = Ω(g(n)) if there exist positive constants **c** and **n₀** such that

0 ≤ c·g(n) ≤ f(n) for all n ≥ n₀

f(n) lies on or **above** c·g(n) for large n. It gives a **lower bound**.

## 3.3 Theta notation (tight bound)
**Definition:** f(n) = Θ(g(n)) if there exist positive constants **c₁, c₂, n₀** such that

0 ≤ c₁·g(n) ≤ f(n) ≤ c₂·g(n) for all n ≥ n₀

f(n) is **sandwiched** between c₁g(n) and c₂g(n). A function that is both O(g) and Ω(g) is Θ(g).

## 3.4 Comparison with real numbers
Treat f(n) as "a" and g(n) as "b":

| Statement | Like |
|---|---|
| f(n) = O(g(n)) | a ≤ b |
| f(n) = Ω(g(n)) | a ≥ b |
| f(n) = Θ(g(n)) | a = b |
| f(n) = o(g(n)) | a < b |
| f(n) = ω(g(n)) | a > b |

## 3.5 Time complexity analysis (class example)
| Case | Order of growth | Reasoning |
|---|---|---|
| Best | Constant | Input n is assumed even (the favourable case) |
| Average | Linear | Even and odd inputs are equally likely |
| Worst | Linear | Input n is always odd |

## 3.6 Worked problems

### Problem 1: Is 5n + 50 = O(n)?
We need c and n₀ with 5n + 50 ≤ c·n for all n ≥ n₀.

Try **c = 6**: 5n + 50 ≤ 6n ⇔ 50 ≤ n.

| n | f(n) = 5n + 50 | c·g(n) = 6n | f ≤ cg? |
|---|---|---|---|
| 10 | 100 | 60 | no |
| 20 | 150 | 120 | no |
| 50 | 300 | 300 | yes (equal), so n₀ = 50 |
| 51 | 305 | 306 | yes |

So **5n + 50 = O(n)** with c = 6, n₀ = 50. (Small n values may fail; only n ≥ n₀ matters.)

### Problem 2: Is 5n + 50 = O(log₁₀ n)?
Try c = 1000: compare 5n + 50 with 1000·log₁₀ n.

| n | 5n + 50 | 1000·log₁₀ n |
|---|---|---|
| 10 | 100 | 1,000 |
| 100 | 550 | 2,000 |
| 500 | 2,550 | ≈ 2,699 |
| 1,000 | 5,050 | 3,000 |

At small n the log side wins, but from about n = 1000 onward f(n) is larger and the gap keeps growing. Linear growth always eventually beats logarithmic growth, so no constant c works. **Hence f(n) ≠ O(log n):** log n is **not** an upper bound of 5n + 50.

(The values written in the handwritten table are too large, but the conclusion is the same.)

### Problem 3: upper bound of f(n) = 300
1. Dominant term = 300.
2. So g(n) = 1.
3. Check f(n) ≤ c·g(n): take c = 300, then 300 ≤ 300 · 1 = 300 ✔.

So **f(n) = O(1)** for c = 300, n₀ = 1. A constant function is bounded by a constant.

## 3.7 Common Big O runtimes
Big O describes how an algorithm's execution time scales as input size grows. Instead of exact seconds (which depend on hardware), it counts the growth rate of operations.

| Class | Name | Example |
|---|---|---|
| O(log n) | Logarithmic | Binary search |
| O(n) | Linear | Linear search |
| O(n log n) | Linearithmic | Merge sort, Quick sort (average) |
| O(n²) | Quadratic (polynomial) | Selection sort |
| O(n!) | Factorial (worse than exponential) | Travelling salesman (brute force) |

### Comparative study (in ms, assuming 1 ms per basic step)

| n | log n | n | n log n | n² | n! |
|---|---|---|---|---|---|
| 10 | 1 ms | 10 ms | 10 ms | 100 ms | 3,628,800 ms ≈ 1 hour |
| 20 | 1.3 ms | 20 ms | 26 ms | 400 ms | ≈ 2.43 × 10¹⁸ ms ≈ 7.7 × 10⁷ years |
| 100 | 2 ms | 100 ms | 200 ms | 10,000 ms = 10 s | ≈ 9.33 × 10¹⁵⁷ ms (astronomical) |

**Lesson:** polynomial algorithms stay practical; factorial/exponential algorithms become impossible even for modest n.

## 3.8 Applications of asymptotic notation
1. **Algorithm comparison:** decide which of two algorithms scales better.
2. **Worst-case planning:** make sure the system copes with the heaviest load.
3. **Best-case planning:** know the minimum work required.
4. **Exact growth bound:** use Θ to pin down the growth precisely.

---

# 4. Growth Rates of Functions

Order from slowest-growing to fastest-growing:

**decrement < constant < logarithmic < polynomial < exponential**

## 4.1 Decrement functions
A function whose **denominator is bigger than the numerator**, such as c/n, n/n², n/2ⁿ, n²/3ⁿ. As the input size increases, the value **decreases and approaches 0**.

### Example: arrange in order of decrease from slowest to fastest
Functions: 100/n, n/2ⁿ, n/n², n²/3ⁿ, n³/3ⁿ

**Step 1: simplify.** n/n² = 1/n. List: 100/n, n/2ⁿ, 1/n, n²/3ⁿ, n³/3ⁿ.

**Step 2: compare denominators.** The function with the smaller denominator decreases slowest; the larger the denominator, the faster it shrinks. Ordering denominators: n < 2ⁿ < 3ⁿ. Among those over 3ⁿ the denominators are equal, so go to numerators.

**Step 3: compare numerators.** For the same denominator, the smaller the numerator, the smaller the value. Since n² < n³ for n > 1, n²/3ⁿ < n³/3ⁿ in value.

**Result (slowest → fastest decrease):**
100/n, 1/n, n/2ⁿ, n³/3ⁿ, n²/3ⁿ

**Check:** substitute various values of n. The ones with bigger values are slower to decrease and the ones with smaller values are faster.

## 4.2 Constant functions
A function parallel to the x-axis: f(n) = c (e.g. 100, 200, 5000). It is **asymptotically bigger** than any decrement function, since those tend to 0.

## 4.3 Logarithmic functions
Functions that grow positively but with a slower growth rate: log n, (log n)¹⁰, log log n, log log log n, etc. A logarithmic function is **asymptotically bigger than a constant**.

**Question:** f(n) = 100 and g(n) = log₁₀ n. Is f(n) = O(g(n))?
- By Big O: need f(n) ≤ c·g(n).
- Take c = 1: 100 ≤ log₁₀ n.
- log₁₀ n is only 1 at n = 10, 100 at n = 10¹⁰⁰.

| f(n) | log₁₀ n |
|---|---|
| 100 | 1 (n = 10) |
| 100 | 100 (n = 10¹⁰⁰) |
| 100 | 1000 (n = 10¹⁰⁰⁰) |

For all large enough n, log n exceeds 100, so **f(n) = O(log n)**. Thus g(n) is asymptotically bigger than f(n).

## 4.4 Polynomial functions
Growth rate increases polynomially: n⁰·¹, √n, n², n log n, nᵏ. A polynomial function is **asymptotically bigger than a logarithmic function**.

## 4.5 Exponential functions
Growth rate increases very rapidly: 2ⁿ, 3ⁿ, n!, nⁿ, aⁿ. An exponential function is **asymptotically bigger than a polynomial function**.

---

# 5. Divide and Conquer (DAC)

## 5.1 Idea
Divide and Conquer is one of the most important algorithm design techniques in DAA. To solve a large problem (size n):
1. **Divide:** break it into two or more smaller sub-problems (of the same type).
2. **Conquer:** solve each sub-problem **recursively**. If a sub-problem is small enough (the **base case**), solve it directly.
3. **Combine:** merge the sub-solutions into the solution of the original problem.

### General template
```
DAC(P)
{
    if (small(P))
        return S(P);          // solve directly (base case)
    else
    {
        divide P into P1, P2, ..., Pk
        apply DAC(P1), DAC(P2), ..., DAC(Pk)
        combine the sub-solutions S1, S2, ..., Sk into S
        return S
    }
}
```

## 5.2 Base case and recursion tree
- **Base case:** the smallest problem, solved directly. Every recursive DAC algorithm needs one because it specifies when recursion should **stop**. Without it, recursion continues indefinitely.
- **Recursion tree:** all the recursive calls together form a tree. The root is the original problem, the leaves are base cases.

## 5.3 Recurrence relation for DAC
If a problem of size n is divided into **a** sub-problems each of size about **n/b**, the running time is

**T(n) = a·T(n/b) + f(n)**

| Symbol | Meaning |
|---|---|
| T(n) | Time to solve a problem of size n |
| a | Number of sub-problems |
| n/b | Size of each sub-problem |
| f(n) | Cost of the work done *outside* the recursive calls (dividing and combining) |

This relation is used to analyse the efficiency of a DAC algorithm.

## 5.4 Examples of DAC algorithms
Binary search, Quick sort, Merge sort, Strassen's matrix multiplication, Closest pair of points, Karatsuba multiplication.

## 5.5 Binary search (simplest DAC example)
Array must be **sorted**: [10, 20, 30, 40, 50, 60, 70, 80, 90]. Search for **70**.

| Step | Current range | Middle | Decision |
|---|---|---|---|
| 1 | [10 … 90] (9 elements) | 50 | 70 > 50, discard left half and 50 |
| 2 | [60, 70, 80, 90] | 70 (or 60 by floor) | With middle = 60: 70 > 60, discard 60 |
| 3 | [70, 80, 90] | 80 | 70 < 80, go left |
| 4 | [70] | 70 | **Found** (base case) |

Each step halves the search range, so the recurrence is T(n) = T(n/2) + c, which gives **O(log n)**.

## 5.6 Merge sort
**Idea:** sort the array by dividing it into smaller sub-arrays, sorting those, then **merging** the sorted sub-arrays to get the sorted original.

### The three phases
**Divide:** break the original problem into smaller sub-problems. Each sub-problem should represent a part of the overall problem. Keep dividing until no further division is possible (single elements). In merge sort, the input array is divided into two halves.

**Conquer:** solve each smaller sub-problem independently. If it is a base case, solve directly with no further recursion. In merge sort, the conquer step sorts the two halves individually (a single element is already sorted).

**Merge (combine):** combine solved sub-problems to form the solution of the whole problem, recursively building larger solutions from smaller ones. In merge sort, this step merges two sorted halves into one sorted array.

### Full trace
Unsorted array: **[70, 20, 30, 50, 60, 10, 40]**

```
                    [70 20 30 50 60 10 40]
                   /                      \
          [70 20 30 50]                [60 10 40]
           /        \                   /       \
      [70 20]     [30 50]          [60 10]     [40]
      /   \        /   \           /    \         |
    [70] [20]    [30] [50]       [60]  [10]      [40]      <- DIVIDE ends
      \   /        \   /           \    /         |
     [20 70]      [30 50]         [10 60]        [40]      <- first merges
          \        /                     \       /
       [20 30 50 70]                  [10 40 60]
                 \                    /
            [10 20 30 40 50 60 70]                         <- final merge
```

### How merging two sorted lists works
Merge [20 30 50 70] and [10 40 60]:
- Compare the fronts: 20 vs 10 → take 10
- 20 vs 40 → take 20
- 30 vs 40 → take 30
- 50 vs 40 → take 40
- 50 vs 60 → take 50
- 70 vs 60 → take 60
- Left over: 70
- Result: [10, 20, 30, 40, 50, 60, 70]

Merging n elements costs about n steps, so f(n) = n.

### Recurrence for merge sort
T(n) = 2T(n/2) + n, which gives **Θ(n log n)** (shown in section 6.2).

---

# 6. Solving Recurrence Relations

Three methods: **substitution**, **recursion tree**, **master theorem**. (Other methods exist and can be studied further.)

## 6.1 Substitution method
**Steps**
1. Write the recurrence relation of the algorithm.
2. Solve it by repeated substitution.
3. Express the result with asymptotic notation.

### Step 1: writing the recurrence (factorial)
A recurrence relation is a mathematical expression that describes the overall cost of a problem in terms of the cost of solving its smaller sub-problems. (Here **cost = time**.)

```
Algo fact(n) {
    if (n == 1)               // base case, takes constant time: T(1) = c
        return 1;
    else
        return n * fact(n-1); // recursive case
}
```
- For n = 1, it takes a constant time: **T(1) = c**.
- For n > 1, we solve the smaller problem fact(n−1), taking **T(n−1)**, then do a multiplication and a return, taking a constant **c**.

**Recurrence relation:**
```
T(n) = T(n-1) + c    if n > 1
T(n) = c             if n = 1
```

### Step 2: solving by substitution
Write the relation for successive values:

```
T(n)   = T(n-1) + c      (1)
T(n-1) = T(n-2) + c      (2)
T(n-2) = T(n-3) + c      (3)
T(n-3) = T(n-4) + c      (4)
```
Substitute (2) into (1): T(n) = [T(n−2) + c] + c = T(n−2) + **2c**
Substitute (3): T(n) = [T(n−3) + c] + 2c = T(n−3) + **3c**
Substitute (4): T(n) = T(n−4) + **4c**

**Pattern:** T(n) = T(n−k) + k·c

The recursion stops at the base case n = 1. Set **n − k = 1**, so **k = n − 1**:

T(n) = T(n − (n−1)) + (n−1)·c = T(1) + (n−1)·c = c + (n−1)c = c + cn − c = **c·n**

### Step 3: asymptotic form
T(n) = c·n, so **T(n) = O(n)** (linear).

### Recurrence of the *return value*
Here we find what the function returns. Let R(n) be the return value.

```
R(n) = R(n-1) * n    if n > 1
R(n) = 1             if n = 1
```
Expand:
- R(n) = R(n−1) · n
- = R(n−2) · (n−1) · n
- = R(n−3) · (n−2) · (n−1) · n
- = R(n−k) · (n−(k−1)) · … · (n−1) · n

With n − k = 1, k = n − 1: R(n) = R(1) · 2 · 3 · … · n = 1 · 2 · 3 · … · n = **n!**

So the return value of the recurrence is **n!** (which confirms the algorithm computes the factorial).

### Recurrence of the number of multiplications
Let M(n) = number of multiplications.
```
M(n) = M(n-1) + 1    if n > 1     (one multiplication n * fact(n-1))
M(n) = 0             if n = 1     (just returns 1)
```
Expand: M(n) = M(n−1) + 1 = M(n−2) + 2 = M(n−3) + 3 = … = M(n−k) + k.

With k = n − 1: M(n) = M(1) + (n−1) = 0 + n − 1 = **n − 1**, so **M(n) = O(n)**.

## 6.2 Recursion tree method
Solve a recurrence by **expanding its terms in a tree-like manner**, to obtain an asymptotic bound.

**Steps**
1. Formulate the recurrence by visualising the calls as a tree.
2. Collect information from the tree:
   - **Level:** the length of the path from the root to the node. The root is at level 0. The level (depth) of the tree is the longest root-to-leaf path. A **leaf** has no children.
   - **Cost per level:** compute for every level using the number of nodes and the work per node.
   - **Total cost:** sum of the costs of all levels.
3. Express the complexity in terms of the total cost.
4. Verify the sum using the substitution method or another method if necessary.

### Example: merge sort, T(n) = 2T(n/2) + n

```
Level 0:                  n                       cost = n
                        /   \
Level 1:            n/2       n/2                 cost = n/2 + n/2 = n
                    / \       / \
Level 2:         n/4  n/4  n/4  n/4               cost = 4 × n/4 = n
                  .    .    .    .
Level k:       (2^k nodes, each of size n/2^k)    cost = n
                  .
Last level:    1  1  1  ...  1  (n leaves)        cost = n × T(1) = n
```

| Level | No. of problems | Problem size | Work done |
|---|---|---|---|
| 0 | 1 | n | 1 × n = n |
| 1 | 2 | n/2 | 2 × (n/2) = n |
| 2 | 4 | n/4 | 4 × (n/4) = n |
| … | … | … | … |
| k | 2ᵏ | n/2ᵏ | 2ᵏ × (n/2ᵏ) = n |
| log n | 2^(log n) = n | 1 | n × T(1) = n |

**Reading the table**
- At level **log n** the problem size is reduced to 1, which is the base condition. Each leaf does T(1), a constant. There are 2^(log₂ n) = n leaves, so the last level costs n.
- Every level does the same work: **n**.
- Levels start at 0, so the number of levels is **1 + log₂ n**.

**Total cost** = (cost per level) × (number of levels) = n × (1 + log₂ n) = n log n + n

Ignoring the lower-order term: **T(n) = Θ(n log n)**.

**Exam format:** topic explanation (10 marks) + equation or problem solving (10 marks) = 20 marks.

## 6.3 Simplified Master Theorem
Used to solve DAC recurrences quickly.

**Form.** Let T(n) be positive and eventually non-decreasing, with

```
T(n) = a·T(n/b) + c·nᵏ     (A)
T(1) = a                    (B)
```
where a, b, c, k are constants, **b ≥ 2, k ≥ 0, a > 0, c > 0**.

**Solution**

| Case | Condition | Result | Meaning |
|---|---|---|---|
| 1 | a < bᵏ | T(n) = Θ(nᵏ) | Top-level work dominates |
| 2 | a = bᵏ | T(n) = Θ(nᵏ log n) | Every level contributes equally |
| 3 | a > bᵏ | T(n) = Θ(n^(log_b a)) | Leaves dominate |

### Proof (using the recursion tree)
The problem is divided into **a** sub-problems at every level, each of size **n/b**.

- Level 0: one problem of size n, cost c·nᵏ.
- Level 1: a problems of size n/b, cost a · c(n/b)ᵏ = c·nᵏ · (a/bᵏ).
- Level 2: a² problems of size n/b², cost c·nᵏ · (a/bᵏ)².
- Level i: cost c·nᵏ · (a/bᵏ)ⁱ.
- The tree has log_b n levels (below the root).

Let **d = a/bᵏ**. The total cost is

T(n) = c·nᵏ [1 + d + d² + d³ + … + d^(log_b n)]   (C)

**Case 1: d < 1 (a < bᵏ).** The series converges even if infinite, so it reduces to a constant:
1 + d + d² + … = 1/(1 − d).
T(n) = c·nᵏ/(1 − d) = **Θ(nᵏ)**.

**Case 2: d = 1 (a = bᵏ).** Each term equals 1, and there are (1 + log_b n) terms:
T(n) = c·nᵏ [1 + log_b n] = c·nᵏ + c·nᵏ log_b n = **Θ(nᵏ log n)**.

**Case 3: d > 1 (a > bᵏ).** The series is dominated by its last (largest) term. The sum is a geometric series with ratio > 1, so it is Θ(d^(log_b n)):
T(n) = c·nᵏ · a^(log_b n) / bᵏ^(log_b n) = c·nᵏ · a^(log_b n)/nᵏ = c · a^(log_b n)

Since a^(log_b n) = n^(log_b a), **T(n) = Θ(n^(log_b a))**.

### Worked examples
**Example 1:** T(n) = 8T(n/2) + n²
- Compare with aT(n/b) + c·nᵏ: a = 8, b = 2, c = 1, k = 2.
- bᵏ = 2² = 4. Since 8 > 4, this is **Case 3** (a > bᵏ).
- T(n) = Θ(n^(log₂ 8)) = **Θ(n³)**.

**Example 2 (homework):** T(n) = 2T(n/2) + n
- a = 2, b = 2, c = 1, k = 1. bᵏ = 2, so a = bᵏ: **Case 2**.
- T(n) = Θ(nᵏ log n) = Θ(n¹ log n) = **Θ(n log n)**.
- Same as merge sort, which matches the recursion tree result.

### When the Master Theorem fails
1. **T(n) = 3ⁿ T(n/2) + n³:** a = 3ⁿ is not a constant; it depends on n.
2. **T(n) = 0.3 T(n/2) + n:** a < 1. The theorem needs a ≥ 1 (a positive count of sub-problems).
3. **T(n) = T(n/2) − n⁴:** f(n) is **negative**. The theorem requires f(n) to be positive.
4. **T(n) = 4T(n/4) + n/log n:** comparing f(n) with n^(log_b a), the two are neither polynomially smaller nor larger. They fall in a "**gap**", and even the generalised master theorem doesn't work.

---

# 7. Finding Maximum and Minimum using Divide and Conquer

**Setup:** array A[0 … n−1]. Two variables: **min** stores the smallest element, **max** stores the largest.

**Algorithm**
1. **If n = 1:** min = max = A[0]. Stop.
2. **If n = 2:** compare A[0] < A[1]. If true: min = A[0], max = A[1]; else min = A[1], max = A[0]. This needs just **one comparison**.
3. **If n > 2:** compute mid = (low + high)/2 and divide into
   - LH = A[low … mid]
   - RH = A[mid+1 … high]
4. Find min₁, max₁ of the left half (recursively).
5. Find min₂, max₂ of the right half (recursively).
6. **Combine:** max = max(max₁, max₂), min = min(min₁, min₂). This takes **two comparisons**.
7. Final values: Minimum = min, Maximum = max.

## Example 1: A = {13, 14, 16, 20, 8, 4, 7, 45}

**Finding the minimum**
```
[13 14 16 20 | 8 4 7 45]
 [13 14] [16 20]   [8 4] [7 45]
 min: 13   16        4     7        <- base cases (pairs)
   min(13,16) = 13    min(4,7) = 4
              min(13,4) = 4
```
**Minimum = 4**

**Finding the maximum**
```
 [13 14] [16 20]   [8 4] [7 45]
 max: 14   20        8     45
   max(14,20) = 20    max(8,45) = 45
              max(20,45) = 45
```
**Maximum = 45**

## Example 2 (practice): A = {12, 5, 18, 7, 3, 15, 9}
Split: [12, 5, 18, 7] and [3, 15, 9]
- Min: left half → min(5, 7) = 5; right half → min(3, 9) = 3; final **min = 3**
- Max: left half → max(12, 18) = 18; right half → max(15, 9) = 15; final **max = 18**

## Number of comparisons
Recurrence: T(n) = 2T(n/2) + 2, with T(2) = 1.

Expanding (n a power of 2): T(n) = 2ᵏ⁻¹·T(2) + (2 + 4 + … + 2ᵏ⁻¹) = n/2 + (n − 2) = **3n/2 − 2**.

| n | Comparisons |
|---|---|
| Even | 3n/2 − 2 |
| Odd | 3(n − 1)/2 |

A simple linear scan would need about 2(n − 1) comparisons, so DAC saves roughly 25%.

*Assignment: Strassen's matrix multiplication.*

---

# 8. Quick Sort

## 8.1 Overview
Quick sort uses the **DAC** strategy to sort the elements of an array. Unlike merge sort, it does **not** divide the array into equal halves. Instead it chooses a **pivot** element and uses it to divide the elements into two parts.

Quick sort has two stages:
1. The array is **partitioned** around a pivot.
2. The two resulting sub-arrays (array₁ and array₂) are **sorted recursively**.

| | Merge sort | Quick sort |
|---|---|---|
| Hard part | Merging | **Partitioning** |
| Division | Always equal halves | Depends on the pivot |
| Combine step | Real work (merge) | Trivial (already in place) |

## 8.2 Choosing the pivot
The pivot may be: (1) the first element, (2) the last element, (3) the middle element, (4) a random element, (5) the median of three.

## 8.3 Partitioning definition
Let the pivot be **v** and the array **A**. Partition into:
- array₁ = { x ∈ A − {v} | x ≤ v }
- array₂ = { x ∈ A − {v} | x ≥ v }

## 8.4 Steps of Quick Sort
1. Pick an element as the pivot v.
2. Partition the array: sub-array 1 has elements ≤ v, sub-array 2 has elements ≥ v.
3. Sort sub-array 1 and sub-array 2 recursively.
4. Combine the arrays: [sub-array 1] v [sub-array 2].

## 8.5 Formal algorithm
```
Algorithm quicksort(A, first, last)
%% Input : unsorted array A[first ... last]
%% Output: sorted array A
Begin
    if (first < last) then
        v = partition(A, first, last)     %% v is the final position of the pivot
        quicksort(A, first, v - 1)
        quicksort(A, v + 1, last)
    end if
End
```

## 8.6 Hoare partition algorithm
Introduced by **C.A.R. Hoare**. It uses **two scans**: one from left to right (pointer i) and one from right to left (pointer j).

**Informal steps**
1. Choose the pivot (generally the first element).
2. Scan **left to right** for an element **greater** than the pivot.
3. Scan **right to left** for an element **smaller** than the pivot.
4. When both are found, **exchange** them.
5. When the pointers **cross**, exchange the pivot with A[j] so it lands in its final place.
6. Return that position.

**Formal algorithm**
```
Algorithm Hoare_partition(A, first, last)
Begin
    pivot = A[first]
    i = first + 1
    j = last
    while (true) do
        while (i <= j and A[i] <= pivot) do  i = i + 1
        while (A[j] >= pivot and j >= i) do  j = j - 1
        if (j < i) then break
        else swap A[i] <-> A[j]
    end while
    swap A[first] <-> A[j]
    return j
End
```

**Trace** on A = [50, 30, 10, 90, 40, 80, 60], pivot = 50:

| Action | Array |
|---|---|
| Start: i → 30, j → 60 | [50, 30, 10, 90, 40, 80, 60] |
| i moves past 30, 10; stops at 90 (> 50) | i = 3 |
| j moves past 60, 80; stops at 40 (< 50) | j = 4 |
| i < j, swap A[3] ↔ A[4] | [50, 30, 10, **40, 90**, 80, 60] |
| i moves past 40; stops at 90 (i = 4) | |
| j moves left past 90; stops at 40 (j = 3) | j < i, break |
| Swap pivot A[0] ↔ A[3] | [**40, 30, 10, 50**, 90, 80, 60] |
| Return 3 | pivot 50 is in its final place |

Left part [40, 30, 10] holds values ≤ 50 and right part [90, 80, 60] holds values ≥ 50. These are then sorted recursively.

## 8.7 Lomuto partition algorithm
Designed by **Nico Lomuto**. It uses only **one-direction scan**.
- The **last** element is the pivot.
- A pointer scans from the first element.
- If the element is **≤ pivot**, add it to the **prefix list** (the list of elements that are smaller than/equal to the pivot) by swapping it to the end of that list.
- If the element is **greater** than the pivot, the pointer simply moves on without any operation.

**Informal steps**
1. Pick the last element as the pivot.
2. Initialise a pointer to the first element.
3. Scan left to right and compare with the pivot.
4. If the element is ≤ pivot, increase the length of the prefix list (and swap it in); else just increment the pointer.
5. Rearrange so that the pivot is in its correct location.
6. Return the pivot's position.

**Standard formal version**
```
Algorithm Lomuto(A, first, last)
Begin
    pivot = A[last]
    next  = first - 1               %% last index of the prefix list
    for k = first to last - 1 do
        if (A[k] <= pivot) then
            next = next + 1
            swap A[next] <-> A[k]
        end if
    end for
    swap A[next + 1] <-> A[last]    %% put pivot in place
    return next + 1
End
```

**Trace** on A = [10, 80, 30, 90, 40, 50, 70], pivot = 70, next = −1:

| k | A[k] | ≤ 70? | Action | Array |
|---|---|---|---|---|
| 0 | 10 | yes | next = 0, swap A[0],A[0] | [10, 80, 30, 90, 40, 50, 70] |
| 1 | 80 | no | none | same |
| 2 | 30 | yes | next = 1, swap A[1],A[2] | [10, 30, 80, 90, 40, 50, 70] |
| 3 | 90 | no | none | same |
| 4 | 40 | yes | next = 2, swap A[2],A[4] | [10, 30, 40, 90, 80, 50, 70] |
| 5 | 50 | yes | next = 3, swap A[3],A[5] | [10, 30, 40, 50, 80, 90, 70] |
| end | | | swap A[4],A[6] | [10, 30, 40, 50, **70**, 90, 80] |

Return **4**: pivot 70 is at its final index.

## 8.8 Complexity analysis
- **Partition cost:** one pass over the elements, so **O(n)**.
- **Best case:** the pivot splits the array into two equal halves each time.
  T(n) = 2T(n/2) + n → **O(n log n)** (Master Theorem Case 2).
- **Worst case:** the pivot is the smallest or largest element each time (e.g. already sorted array with first/last pivot). Splits are n−1 and 0.
  T(n) = T(n−1) + n → n + (n−1) + … + 1 = n(n+1)/2 → **O(n²)**.
- **Average case:** random splits, about 1.39 n log₂ n comparisons → **O(n log n)**.

Using a random pivot or median-of-three makes the worst case unlikely.

---

# 9. The Greedy Method

## 9.1 Huffman coding
**Purpose:** assign **variable-length binary codewords** to symbols so that frequent symbols get **short codes** and rare symbols get **long codes**, minimising the average code length (data compression). Huffman coding is a greedy algorithm: at each step it merges the two **least probable** symbols.

**Procedure**
1. List the source symbols in **decreasing probability** order. The two symbols with the lowest probability are assigned a 0 or 1.
2. **Combine** the probabilities of the two lowest-probability symbols, then **reorder** the resulting probabilities.
3. **Repeat** until only two ordered probabilities remain.
4. Start encoding from the **last reduction** (exactly two probabilities): assign **0** as the first digit for the symbols of the first probability and **1** for the second.
5. Go back to the previous reduction step. The two probabilities that were combined get **0 and 1 as the next digit**, while retaining all earlier assignments.
6. Continue backwards until the **first column** is reached.

### Example 1: S = {0.4, 0.2, 0.2, 0.1, 0.1}

**Reduction**
```
Sym   Prob   Stage 1        Stage 2        Stage 3
S0    0.4    0.4            0.4            0.6
S1    0.2    0.2            0.4            0.4
S2    0.2    0.2            0.2
S3    0.1    0.2 (S3+S4)
S4    0.1
```
- Stage 1: combine S3 + S4 (0.1 + 0.1 = 0.2).
- Stage 2: combine the two lowest 0.2's → 0.4.
- Stage 3: combine 0.2 + 0.4 → 0.6, leaving 0.6 and 0.4.

**Resulting codewords (from your table)**

| Symbol | Probability | Codeword | Length |
|---|---|---|---|
| S₀ | 0.4 | 00 | 2 |
| S₁ | 0.2 | 10 | 2 |
| S₂ | 0.2 | 11 | 2 |
| S₃ | 0.1 | 010 | 3 |
| S₄ | 0.1 | 011 | 3 |

**Average length** = Σ pᵢ × lᵢ = 0.4×2 + 0.2×2 + 0.2×2 + 0.1×3 + 0.1×3 = 0.8 + 0.4 + 0.4 + 0.3 + 0.3 = **2.2 bits/symbol**.

(Different tie-breaks can give different codewords, but the average length stays the same.)

### Example 2: five symbols x₁ … x₅
Question probabilities: 0.2, 0.15, 0.05, 0.3, 0.5. These add up to 1.2, which is impossible. The working table uses x₅ = 0.5, x₁ = 0.2, x₂ = 0.15, x₄ = 0.1, x₃ = 0.05 (total 1.0), so that is what's solved here.

**Reduction**
1. Sorted: 0.5 (x₅), 0.2 (x₁), 0.15 (x₂), 0.1 (x₄), 0.05 (x₃)
2. Merge 0.1 + 0.05 = 0.15 → list: 0.5, 0.2, 0.15, 0.15
3. Merge 0.15 + 0.15 = 0.3 → list: 0.5, 0.3, 0.2
4. Merge 0.3 + 0.2 = 0.5 → list: 0.5, 0.5

**Backward assignment**
- Last two: x₅ (0.5) → **1**; merged group (0.5) → **0**
- Merged group splits into 0.3 → **00** and x₁ (0.2) → **01**
- The 0.3 group splits into x₂ (0.15) → **001** and merged 0.15 → **000**
- The 0.15 group splits into x₄ (0.1) → **0000** and x₃ (0.05) → **0001**

| Symbol | Probability | Codeword | Length |
|---|---|---|---|
| x₅ | 0.5 | 1 | 1 |
| x₁ | 0.2 | 01 | 2 |
| x₂ | 0.15 | 001 | 3 |
| x₄ | 0.1 | 0000 | 4 |
| x₃ | 0.05 | 0001 | 4 |

**Average length** = 0.5×1 + 0.2×2 + 0.15×3 + 0.1×4 + 0.05×4 = 0.5 + 0.4 + 0.45 + 0.4 + 0.2 = **1.95 bits/symbol**.

**Prefix property:** no codeword is the beginning of another, so decoding is unambiguous.

## 9.2 Basics of the greedy method
The **greedy method** is an algorithmic technique used to solve **optimisation problems** by making the **best possible choice at each step**, hoping that these locally best choices will lead to a **globally optimal solution**.

### General structure
1. Start with an **empty solution**.
2. **Identify** the available choices.
3. **Select** the best choice according to a greedy criterion.
4. **Check** whether the choice is feasible.
5. **Add** it to the solution if feasible.
6. **Repeat** until the solution is complete.

### General pseudocode
```
GreedyAlgorithm(problem)
{
    solution = empty
    while (solution is not complete)
    {
        select the best available choice
        if (choice is feasible)
            add choice to solution
    }
    return solution
}
```
**Flow:** Select → Check → Accept / Reject → Repeat.

```
Available choices
      ↓
 Select best case
      ↓
 Is it feasible? ──No──→ Reject ──┐
      │Yes                        │
      ↓                           │
   Accept                         │
      ↓                           │
   Repeat ←───────────────────────┘
```

**Caution:** a greedy choice is never reconsidered, so greedy algorithms are correct only for problems where local optimum leads to global optimum (activity selection and Huffman are such problems).

## 9.3 Example: Activity selection problem
**Objective:** select the **maximum number of activities** such that **no two selected activities overlap**.

| Activity | Start | Finish |
|---|---|---|
| A1 | 1 | 2 |
| A2 | 3 | 4 |
| A3 | 0 | 6 |
| A4 | 5 | 7 |
| A5 | 8 | 9 |
| A6 | 5 | 9 |

**Greedy criterion:** always choose the activity that **finishes earliest** among those compatible with what has been chosen (this leaves the most room for later activities).

**Step 1:** Sort the activities by finish time: A1 (2), A2 (4), A3 (6), A4 (7), A5 (9), A6 (9).

**Step 2:** Select the first activity A1 (1–2). Current solution {A1}; last finishing time = 2.

**Step 3:** Examine A2 (3–4). Start(A2) = 3 ≥ Finish(A1) = 2 → compatible. Solution {A1, A2}; last finish = 4.

**Step 4:** Examine A3 (0–6). Start(A3) = 0 < Finish(A2) = 4 → overlaps → **reject**. Solution {A1, A2}.

**Step 5:** Examine A4 (5–7). Start(A4) = 5 ≥ Finish(A2) = 4 → accept. Solution {A1, A2, A4}; last finish = 7.

**Step 6:** Examine A5 (8–9). Start(A5) = 8 ≥ Finish(A4) = 7 → accept. Solution {A1, A2, A4, A5}; last finish = 9.

**Step 7:** Examine A6 (5–9). Start(A6) = 5 < Finish(A5) = 9 → overlaps → **reject**.

**Answer: {A1, A2, A4, A5}**: 4 activities.

**Complexity:** sorting dominates, so O(n log n); the selection pass is O(n).

*(The mid-semester syllabus ends here.)*

---

# 10. Heap and Heap Sort (05.10.26)

## 10.1 Heap
A **heap** is a **complete binary tree** (all levels full except possibly the last, which is filled left to right) that satisfies the heap property:
- **Max heap:** every parent node is **greater than or equal to** its children. The root is the largest.
- **Min heap:** every parent node is **smaller than or equal to** its children. The root is the smallest.

**Example of a max heap**
```
          50
        /    \
      30      40
     /  \    /
   10   20  35
```
Here 50 ≥ 30, 40; 30 ≥ 10, 20; 40 ≥ 35. ✔

A tree like 10 → (20, 15) → (30, 25, 40) is **not** a max heap, because children are larger than their parents.

**Array representation** (0-indexed): for the node at index i,
- left child = 2i + 1, right child = 2i + 2
- parent = floor((i − 1)/2)

## 10.2 Basic operations on a heap
1. **Build heap:** turn an arbitrary array into a heap.
2. **Heapify:** repair a sub-tree so it satisfies the heap property.
3. **Insert:** add a new element and restore the heap.
4. **Delete / extract root:** remove the root (max or min) and restore the heap.

## 10.3 Heapify
**Heapify** adjusts a sub-tree so that it satisfies the heap property. For a max heap: compare the node with its children, and if a child is larger, swap with the **largest child**, then continue down.

**Example:** node 20 with children 50 and 30 is not a max heap. Largest child is 50, so swap 20 ↔ 50 giving 50 with children 20, 30. ✔

*Heapify fixes only the sub-tree it is called on (a max-heap fix), not the entire tree.*

## 10.4 Building a max heap
Let **A = [4, 10, 3, 5, 1]** (n = 5).
```
        4
      /   \
    10     3
   /  \
  5    1
```
Because heapify assumes the sub-trees below are already heaps, we start from the **last non-leaf node** and work backwards to the root.

**Step 1: find the last non-leaf node.** For array size n, the last non-leaf index is floor(n/2) − 1.
For n = 5: floor(5/2) − 1 = 2 − 1 = **1**. So start at index 1.

**Step 2: heapify index 1** (value 10). Children: 5 and 1. 10 ≥ 5 and 10 ≥ 1 → **no change**. Array: [4, 10, 3, 5, 1].

**Step 3: heapify index 0** (value 4). Children: 10 and 3. The largest is 10, so swap 4 ↔ 10. Array: [10, 4, 3, 5, 1].

**Step 4:** The value 4 is now at index 1 with children 5 and 1. The largest child is 5 > 4, so swap 4 ↔ 5. Array: **[10, 5, 3, 4, 1]**.

```
        10
       /   \
      5     3
     / \
    4   1
```
Check: 10 ≥ 5, 3; 5 ≥ 4, 1. ✔ Valid max heap.

## 10.5 Heap Sort (completing the picture)
The notes introduce heaps as the basis of heap sort. The sort works like this:
1. **Build a max heap** from the array.
2. **Swap** the root (largest) with the last element of the heap. That element is now in its final sorted position.
3. **Reduce the heap size by 1** and **heapify the root**.
4. **Repeat** steps 2 and 3 until the heap size is 1.

**Trace** from the heap [10, 5, 3, 4, 1]:

| Step | Action | Array (sorted part on the right) |
|---|---|---|
| 1 | Swap 10 ↔ 1, heap size 4, heapify root (1 swaps with 5, then with 4) | [5, 4, 3, 1 \| 10] |
| 2 | Swap 5 ↔ 1, heap size 3, heapify root (1 swaps with 4) | [4, 1, 3 \| 5, 10] |
| 3 | Swap 4 ↔ 3, heap size 2, heapify root (3 ≥ 1, no change) | [3, 1 \| 4, 5, 10] |
| 4 | Swap 3 ↔ 1, heap size 1 | [1 \| 3, 4, 5, 10] |
| Done | | **[1, 3, 4, 5, 10]** |

**Complexity:** building the heap is O(n); each of the n−1 extractions costs O(log n). Total = **O(n log n)** in best, average and worst cases, with O(1) extra space.

---

# 11. Answers to Open Questions from the Notes

## Q1. Why is algorithm analysis important? (assignment)
- To predict **resource needs** (time, memory) before writing code.
- To **compare** competing algorithms independent of hardware or language.
- To judge **scalability**: how performance behaves as input grows.
- To avoid choosing an algorithm that works on small tests but fails at real sizes (e.g. n² vs n log n).
- To save **cost and energy** (cloud bills, battery).
- To identify **bottlenecks** and optimise.
- To give guarantees (worst case) for real-time or critical systems.

## Q2. Fundamental stages of problem solving (7 stages, from the hint)
1. **Understanding** the problem
2. **Planning** the solution approach
3. **Designing** the algorithm
4. **Validating / verifying** correctness (dry run, proofs)
5. **Analysing** time and space
6. **Implementing** (coding)
7. **Performing empirical analysis** if necessary (running and measuring)

## Q3. What is meant by time and space complexity?
- **Time complexity:** the amount of time an algorithm takes as a function of input size n, i.e. the number of basic operations executed, written T(n) and expressed asymptotically (O, Ω, Θ).
- **Space complexity:** the amount of memory an algorithm needs as a function of input size n. It includes the input, extra variables and the recursion stack.

Example: linear search has time O(n), space O(1); merge sort has time O(n log n), space O(n).

## Q4. Classification of algorithms (4 classes)
1. **Based on implementation:** recursive vs iterative; serial vs parallel; deterministic vs non-deterministic; exact vs approximate.
2. **Based on design:** divide and conquer, greedy, dynamic programming, backtracking, branch and bound, brute force, randomised.
3. **Based on area of specialisation:** sorting, searching, graph, string, geometric, numerical, cryptographic algorithms, etc.
4. **Based on tractability:** *tractable* (solvable in polynomial time, class P) vs *intractable* (needs exponential time, e.g. NP-hard problems).

## Q5. Steps of an algorithm analysis framework
1. Understand the problem and decide the **input size** parameter (n).
2. Identify the **basic operation** (the most time-consuming step, usually in the innermost loop).
3. Check whether the number of times the basic operation runs depends only on n, or also on the type of input (**best / average / worst case**).
4. Set up a **sum or recurrence relation** for the count of basic operations.
5. **Solve** it (summation formulas, substitution, recursion tree, master theorem) to get the order of growth.
6. Express the result in **asymptotic notation**.

## Q6. Fundamental algorithm design approaches
- **Brute force:** try all possibilities.
- **Divide and conquer:** split, solve, combine (merge sort, quick sort).
- **Decrease and conquer:** reduce the problem by a constant or factor (binary search, insertion sort).
- **Transform and conquer:** convert to a simpler or different form (heap sort, presorting).
- **Greedy:** locally optimal choices (Huffman, activity selection).
- **Dynamic programming:** store solutions of overlapping sub-problems.
- **Backtracking and branch-and-bound:** systematic search with pruning.

## Q7. General template of an algorithm
```
Algorithm <Name>(<inputs>)
// Description: what the algorithm does
// Input : <valid inputs and their constraints>
// Output: <what is produced>
Begin
    1. Initialise variables
    2. Process the input (decisions, loops, recursion)
    3. Produce the output
End
```
Typical parts: **name, description, input, output, body (steps), termination.** Steps use sequence, selection (if/else) and iteration (loops).

## Q8. Convert a Fahrenheit temperature to Celsius and Kelvin

**Normal maths**
- C = (F − 32) × 5/9
- K = C + 273.15

Example: F = 98.6 → C = (98.6 − 32) × 5/9 = 66.6 × 5/9 = 37.0 → K = 37.0 + 273.15 = 310.15.

**Algorithm**
```
Step 1: Start
Step 2: Read F
Step 3: C = (F - 32) * 5 / 9
Step 4: K = C + 273.15
Step 5: Print C and K
Step 6: Stop
```

**Flowchart (text form)**
```
 ( Start )
     ↓
 [ Input F ]
     ↓
 [ C = (F - 32) * 5 / 9 ]
     ↓
 [ K = C + 273.15 ]
     ↓
 [ Output C, K ]
     ↓
 ( Stop )
```

**Program (Python)**
```python
F = float(input("Enter temperature in Fahrenheit: "))
C = (F - 32) * 5 / 9
K = C + 273.15
print("Celsius :", round(C, 2))
print("Kelvin  :", round(K, 2))
```

---

# Quick Revision Sheet

| Topic | Remember |
|---|---|
| Algorithm | Finite, definite, effective, with input/output and correctness |
| Big O / Ω / Θ | Upper / lower / tight bound with constants c, n₀ |
| Growth order | decrement < constant < log < polynomial < exponential |
| DAC | Divide → Conquer → Combine; T(n) = aT(n/b) + f(n) |
| Merge sort | Θ(n log n) all cases, needs O(n) extra space |
| Substitution | Expand, find pattern T(n−k) + kc, set n − k = base |
| Recursion tree | Cost per level × number of levels |
| Master theorem | Compare a with bᵏ: <, =, > → Θ(nᵏ), Θ(nᵏ log n), Θ(n^(log_b a)) |
| Max/min DAC | 3n/2 − 2 comparisons (even n) |
| Quick sort | Best/avg O(n log n), worst O(n²); Hoare (2 scans), Lomuto (1 scan) |
| Huffman | Merge two smallest repeatedly; frequent symbols get shorter codes |
| Activity selection | Sort by finish time, pick compatible activities |
| Heap | Complete binary tree; last non-leaf = floor(n/2) − 1; heap sort O(n log n) |
