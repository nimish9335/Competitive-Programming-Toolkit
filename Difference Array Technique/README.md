# Difference Array Technique

## Overview

The Difference Array is a powerful optimization technique used to perform multiple **range update operations** in constant time.

Instead of updating every element inside a range `[L, R]`, we only update two positions in a helper array.

After processing all updates, a single prefix sum reconstructs the final array.

This reduces the complexity from **O(N × Q)** to **O(N + Q)**.

---

# When to Use

Difference Array should immediately come to mind whenever a problem contains statements such as:

- Add `x` to every element from `L` to `R`
- Increment all elements in a range
- Perform many range updates
- Print the final array after all updates
- Offline range updates

If updates are performed first and the final values are required only once, Difference Array is usually the correct solution.

---

# Core Idea

Suppose we need to perform

```
Add x to every element from L to R
```

Instead of

```
for(i=L;i<=R;i++)
    a[i]+=x;
```

we simply perform

```
diff[L] += x;
diff[R+1] -= x;
```

After processing every query,

```
Prefix Sum(diff)
```

produces the final updated array.

---

# Why Does It Work?

The difference array stores **changes**, not values.

When taking the prefix sum,

- `+x` starts affecting the array from index `L`
- the effect continues automatically
- at `R+1`, `-x` cancels the effect

Therefore only two updates are sufficient.

Visualization

```
L               R
|---------------|

+5              -5

Prefix Sum

0 0 5 5 5 5 0 0
```

---

# Mathematical Definition

For an array

```
a[1...n]
```

Difference array is defined as

```
diff[1] = a[1]

diff[i] = a[i] - a[i-1]
```

Original array can always be recovered by

```
a[i] = a[i-1] + diff[i]
```

In other words,

> Prefix Sum of Difference Array = Original Array

---

# Algorithm

### Step 1

Construct Difference Array.

```
diff[1]=a[1]

for(i=2;i<=n;i++)
    diff[i]=a[i]-a[i-1];
```

---

### Step 2

For every query

```
L R X
```

perform

```
diff[L]+=X;

diff[R+1]-=X;
```

---

### Step 3

Take prefix sum

```
a[1]=diff[1];

for(i=2;i<=n;i++)
    a[i]=a[i-1]+diff[i];
```

Now `a` contains the final updated values.

---

# Complexity

Naive

```
Every Update = O(N)

Total = O(N × Q)
```

Difference Array

```
Each Update = O(1)

All Updates = O(Q)

Reconstruction = O(N)

Total = O(N + Q)
```

---

# Example

Initial Array

```
1 2 3 4 5
```

Queries

```
1 3 +2

2 5 +4
```

Difference Array

```
1 1 1 1 1
```

After Updates

```
diff[1]+=2
diff[4]-=2

diff[2]+=4
diff[6]-=4
```

Take Prefix Sum

```
3 8 9 8 9
```

which is exactly the final array.

---

# Recognizing Difference Array Problems

Look for phrases like

- Perform Q range updates
- Add value to every element in a segment
- Increment all indices between L and R
- Apply operations and print final array
- Offline range updates

These are strong indicators that Difference Array may be applicable.

---

# When NOT to Use

Difference Array is **not suitable** when

- queries ask for intermediate results
- updates and queries are mixed
- range sum is required after every update
- range minimum/maximum after each operation

In such situations use

- Fenwick Tree (BIT)
- Segment Tree
- Lazy Propagation

---

# Common Mistakes

### Forgetting `R + 1`

Wrong

```
diff[R] -= X;
```

Correct

```
diff[R+1] -= X;
```

---

### Not allocating extra space

Always create

```
vector<long long> diff(n+2);
```

because `R` may be equal to `N`.

---

### Forgetting prefix sum

Difference array itself is **not** the answer.

Always reconstruct the final array using prefix sums.

---

### Wrong indexing

Be careful about

- 0-based indexing
- 1-based indexing

The update formula changes accordingly.

---

# Relationship with Prefix Sum

Prefix Sum

```
Range Query
```

Difference Array

```
Range Update
```

A useful way to remember this is

```
Prefix Sum
    ↓
Fast Queries

Difference Array
    ↓
Fast Updates
```

---

# Advanced Applications

Difference Array is frequently combined with

- Prefix Sum
- Binary Search
- Sweep Line Algorithm
- Coordinate Compression
- Interval Problems
- Two-Dimensional Difference Array
- Difference Array on Operations (Difference on Queries)

Many Codeforces problems apply Difference Array **twice**:

1. Determine how many times each operation is executed.
2. Apply those operations efficiently to the original array.

---

# Template

```
Build Difference Array

↓

Apply all updates in O(1)

↓

Take Prefix Sum

↓

Final Array
```

---

# Key Formula

```
Range Update

diff[L] += X
diff[R+1] -= X
```

```
Recover Array

a[i] = a[i-1] + diff[i]
```

---

# Takeaway

Difference Array converts expensive range updates into constant-time operations by storing only the **start** and **end** of each update.

Whenever a problem asks for **many range updates but only the final array**, Difference Array should be one of the first techniques you consider.