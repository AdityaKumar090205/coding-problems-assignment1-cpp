#include <bits/stdc++.h>
using namespace std;
int maxCyclicSubstringSum(string s) {
    int n = s.size();
    string temp = s + s;
    vector<int> freq(26, 0);

    int left = 0;
    int currSum = 0;
    int maxSum = 0;

    for (int right = 0; right < 2 * n; right++) {
        int ch = temp[right] - 'a';
        currSum += (ch + 1);
        freq[ch]++;

        while (freq[ch] > 1 || (right - left + 1) > n) {
            int leftChar = temp[left] - 'a';
            currSum -= (leftChar + 1);
            freq[leftChar]--;
            left++;
        }
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}

int main() {
    string s;
    cin >> s;
    cout << maxCyclicSubstringSum(s) << endl;
    return 0;
}
