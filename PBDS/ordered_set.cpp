#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update
> ordered_set;

// Count elements strictly smaller than x
int countSmaller(ordered_set &st, int x){
    return st.order_of_key(x);
}

// Count elements strictly greater than x
int countGreater(ordered_set &st, int x){
    return st.size() - st.order_of_key(x + 1);
}

// k-th smallest element (0-based)
int kthSmallest(ordered_set &st, int k){
    return *st.find_by_order(k);
}

// k-th largest element (1-based)
int kthLargest(ordered_set &st, int k){
    return *st.find_by_order(st.size() - k);
}