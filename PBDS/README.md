# Ordered Set (PBDS)

Policy Based Data Structure (PBDS) is an extension of the C++ STL.

It behaves like a `std::set` but also supports order statistics.

Time Complexity of all operations:

- Insert : O(log N)
- Erase : O(log N)
- Find : O(log N)
- order_of_key() : O(log N)
- find_by_order() : O(log N)

---

## Declaration

```cpp
typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update
> ordered_set;
```

---

## Create

```cpp
ordered_set st;
```

---

## Insert

```cpp
st.insert(x);
```

---

## Delete

```cpp
st.erase(x);
```

---

## Search

```cpp
st.find(x);
```

---

## Count Elements Smaller than x

```cpp
st.order_of_key(x);
```

Returns the number of elements strictly smaller than `x`.

Example

```
1 3 5 7 9

order_of_key(6) = 3
order_of_key(5) = 2
```

---

## Count Elements Greater than x

```cpp
st.size() - st.order_of_key(x + 1);
```

Example

```
1 3 5 7 9

Greater than 5 = 2
```

---

## k-th Smallest Element

```cpp
*st.find_by_order(k);
```

0-based indexing

Example

```
0 -> smallest
1 -> second smallest
2 -> third smallest
```

---

## k-th Largest Element

```cpp
*st.find_by_order(st.size() - k);
```

Example

```
k = 1 -> largest
k = 2 -> second largest
```

---

## Complexity

| Operation | Complexity |
|-----------|------------|
| insert | O(log N) |
| erase | O(log N) |
| find | O(log N) |
| order_of_key | O(log N) |
| find_by_order | O(log N) |

---

## Notes

- Stores only unique values.
- Duplicate values are not allowed.
- For duplicates, use `pair<int,int>` or an ordered multiset implementation.