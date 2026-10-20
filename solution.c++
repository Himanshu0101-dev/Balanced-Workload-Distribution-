#include <bits/stdc++.h>
using namespace std;

int balancedWorkload(vector<int>& projects) {
    int total = accumulate(projects.begin(), projects.end(), 0);
    int target = total / 2;
    vector<bool> dp(target + 1, false);
    dp[0] = true;

    for (int hours : projects) {
        for (int j = target; j >= hours; j--) {
            if (dp[j - hours]) dp[j] = true;
        }
    }

    for (int i = target; i >= 0; i--) {
        if (dp[i]) return total - 2 * i;
    }
    return total; // fallback
}

int main() {
    vector<int> projects = {10, 20, 15, 5};
    cout << balancedWorkload(projects) << endl; // Output: 0
    return 0;
}
