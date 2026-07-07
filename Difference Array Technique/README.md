# Difference Array — Quick Notes

## Kya hai?
Range updates (`add x to a[L..R]`) ko **O(1) per query** mein karne ki trick.
Naive: O(N) per update → O(N×Q) total.
Diff array: O(1) per update + O(N) final reconstruction → **O(N + Q)**.

## Kab use karo?
- Bahut saari range updates deni hain (`add x from L to R`)
- Sirf **final array** chahiye, beech-beech mein query nahi
- "Offline" type problems (pehle sab updates, phir answer)

⚠️ **Use mat karo** agar har update ke baad turant query chahiye (range sum/min/max) — wahan Segment Tree / BIT + Lazy Propagation use karo.

## Core Formula

**Diff array banane ka tarika:**
```
diff[1] = a[1]
diff[i] = a[i] - a[i-1]      // for i = 2..n
```

**Range update `[L, R] += X`:**
```
diff[L]   += X
diff[R+1] -= X
```

**Original array wapas paane ke liye (prefix sum):**
```
a[i] = a[i-1] + diff[i]
```

## Kyun kaam karta hai?
`diff[L] += X` prefix sum lene par index `L` se aage sabko `+X` de deta hai.
`diff[R+1] -= X` us effect ko `R+1` se cancel kar deta hai.
Isliye poore range mein sirf 2 point-updates kaafi hain.

## In-place Version (extra array ki zaroorat nahi)

```cpp
void rangeUpdate(vector<long long>& a, vector<vector<long long>>& queries) {
    int n = a.size() - 1;   // 1-indexed, a[1..n]

    // Step 1: array ko khud diff bana do (right→left)
    for (int i = n; i >= 2; i--)
        a[i] -= a[i - 1];

    // Step 2: queries seedhe isi array par apply
    for (auto &q : queries) {
        long long l = q[0], r = q[1], val = q[2];
        a[l] += val;
        if (r + 1 <= n) a[r + 1] -= val;
    }

    // Step 3: prefix sum se original wapas banao (left→right)
    for (int i = 2; i <= n; i++)
        a[i] += a[i - 1];
}
```

## Example

Array: `1 2 3 4 5`
Queries: `(1,3,+2)`, `(2,5,+4)`

```
diff → 1 1 1 1 1
apply → diff[1]+=2, diff[4]-=2, diff[2]+=4, diff[6]-=4
prefix sum → 3 8 9 8 9   ✅ final array
```

## Common Mistakes
- `diff[R] -= X` likhna instead of `diff[R+1] -= X`
- Array size `n+2` na rakhna (kyunki `R` = `N` ho sakta hai)
- Prefix sum lena bhool jaana (diff array khud answer nahi hai)
- 0-indexed vs 1-indexed mix kar dena

## Yaad rakhne ka tarika
```
Prefix Sum       → Fast Range QUERY
Difference Array → Fast Range UPDATE
```

## Advanced (agar aage padhna ho)
- 2D Difference Array (grid range updates)
- Sweep Line + Difference Array
- "Diff on diff" — pehle count karo har operation kitni baar chalega, phir usko array par apply karo
