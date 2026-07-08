# Ordered Set (PBDS)

Policy Based Data Structure (PBDS) is an extension of the C++ STL.

It works like a `std::set` but also supports **Order Statistics**, making it easy to find the k-th smallest element or count elements smaller than a given value.

---

## Time Complexity

| Operation | Complexity |
|-----------|------------|
| Insert | O(log N) |
| Erase | O(log N) |
| Find | O(log N) |
| order_of_key() | O(log N) |
| find_by_order() | O(log N) |

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
st.find(x) != st.end();
```

Returns whether `x` exists in the set.

---

## Count Elements Smaller than x

```cpp
st.order_of_key(x);
```

Returns the number of elements **strictly smaller** than `x`.

---

## Count Elements Smaller than or Equal to x

```cpp
st.order_of_key(x + 1);
```

---

## Count Elements Greater than x

```cpp
st.size() - st.order_of_key(x + 1);
```

---

## Count Elements Greater than or Equal to x

```cpp
st.size() - st.order_of_key(x);
```

---

## k-th Smallest Element

```cpp
*st.find_by_order(k);
```

Uses **0-based indexing**.

```text
k = 0 -> Smallest
k = 1 -> Second Smallest
k = 2 -> Third Smallest
```

---

## k-th Largest Element

```cpp
*st.find_by_order(st.size() - k);
```

```text
k = 1 -> Largest
k = 2 -> Second Largest
```

---

## Example

```text
Set = {1, 3, 5, 7, 9}

order_of_key(6) = 3
order_of_key(5) = 2

find_by_order(0) = 1
find_by_order(2) = 5
find_by_order(4) = 9
```

---

## Notes

- Stores only **unique** values.
- Duplicate values are **not allowed**.
- For duplicates, use `pair<int, int>` or an Ordered Multiset implementation.

---

## When to Use PBDS

- Find the k-th smallest/largest element.
- Count elements smaller or greater than a value.
- Dynamic order statistics with insertion and deletion in `O(log N)`.