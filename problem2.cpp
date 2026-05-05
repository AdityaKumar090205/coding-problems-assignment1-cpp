#include <bits/stdc++.h>
using namespace std;

long long minimumOperations(vector<int>& A, int K) {
    int n = A.size();
    for (int i = 1; i < n; i++) {
        if (abs(A[i] - A[0]) % K != 0) {
            return -1;
        }
    }
    vector<int> normal;
    int base = A[0];

    for (int x : A) {
        normal.push_back((x - base) / K);
    }
    sort(normal.begin(), normal.end());
    int median = normal[n / 2];
    long long operations = 0;

    for (int x : normal) {
        operations += abs(x - median);
    }
    return operations;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int K;
    cin >> K;
    cout << minimumOperations(A, K) << endl;
    return 0;
}
