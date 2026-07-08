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

void insertElement(ordered_set &st, int x){
    st.insert(x);
}

void eraseElement(ordered_set &st, int x){
    st.erase(x);
}

bool contains(ordered_set &st, int x){
    return st.find(x) != st.end();
}

int countSmaller(ordered_set &st, int x){
    return st.order_of_key(x);
}

int countSmallerOrEqual(ordered_set &st, int x){
    return st.order_of_key(x + 1);
}

int countGreater(ordered_set &st, int x){
    return st.size() - st.order_of_key(x + 1);
}

int countGreaterOrEqual(ordered_set &st, int x){
    return st.size() - st.order_of_key(x);
}

int kthSmallest(ordered_set &st, int k){
    return *st.find_by_order(k);
}

int kthLargest(ordered_set &st, int k){
    return *st.find_by_order(st.size() - k);
}

int size(ordered_set &st){
    return st.size();
}

bool empty(ordered_set &st){
    return st.empty();
}

int smallestElement(ordered_set &st){
    return *st.begin();
}

int largestElement(ordered_set &st){
    return *st.rbegin();
}

int main(){

    ordered_set st;

    insertElement(st, 10);
    insertElement(st, 30);
    insertElement(st, 20);
    insertElement(st, 50);
    insertElement(st, 40);

    cout << countSmaller(st, 30) << '\n';
    cout << countSmallerOrEqual(st, 30) << '\n';
    cout << countGreater(st, 30) << '\n';
    cout << countGreaterOrEqual(st, 30) << '\n';

    cout << kthSmallest(st, 0) << '\n';
    cout << kthSmallest(st, 2) << '\n';

    cout << kthLargest(st, 1) << '\n';
    cout << kthLargest(st, 3) << '\n';

    cout << smallestElement(st) << '\n';
    cout << largestElement(st) << '\n';

    cout << contains(st, 20) << '\n';
    cout << contains(st, 100) << '\n';

    eraseElement(st, 20);

    cout << size(st) << '\n';

    return 0;
}