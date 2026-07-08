#include<bits/stdc++.h>
using namespace std;

void rangeUpdate(vector<long long>& a, vector<vector<long long>>& queries) {
    int n = a.size() - 1;   // 1-indexed array, a[1..n] valid

    // Step 1: array ko khud "difference array" bana do (in-place)
    for (int i = n; i >= 2; i--)
        a[i] = a[i] - a[i - 1];
    // a[1] already apna diff hai (kyunki diff[1] = a[1])

    // Step 2: saari range updates directly isi array par lagao
    for (auto &q : queries) {
        long long l = q[0];
        long long r = q[1];
        long long val = q[2];

        a[l] += val;
        if (r + 1 <= n)
            a[r + 1] -= val;
    }

    // Step 3: prefix sum karke wapas original array reconstruct karo (in-place)
    for (int i = 2; i <= n; i++)
        a[i] = a[i - 1] + a[i];
}

int main(){
    vector<long long> a = {0, 10, 20, 30, 40, 50}; // index 0 unused, 1-indexed
    vector<vector<long long>> queries = {
        {2, 4, 5},   // index 2 se 4 tak +5
        {1, 3, 2}    // index 1 se 3 tak +2
    };

    rangeUpdate(a, queries);

    for (int i = 1; i < (int)a.size(); i++)
        cout << a[i] << " ";
    cout << endl;
}