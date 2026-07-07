#include<bits/stdc++.h>
using namespace std;

void rangeUpdate(vector<long long>& a, vector<vector<long long>>& queries) {
    int n = a.size() - 1;
    vector<long long> diff(n + 2, 0);

    diff[1] = a[1];
    for (int i = 2; i <= n; i++)
        diff[i] = a[i] - a[i - 1];

    for (auto &q : queries) {
        long long l = q[0];
        long long r = q[1];
        long long val = q[2];

        diff[l] += val;
        diff[r + 1] -= val;
    }

    a[1] = diff[1];
    for (int i = 2; i <= n; i++)
        a[i] = a[i - 1] + diff[i];
}

int main(){
    
}