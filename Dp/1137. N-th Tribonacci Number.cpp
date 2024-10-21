#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9, inf = 1e9;
class Solution {
public:
    int dp[10009];  
    Solution() {
        memset(dp, -1, sizeof(dp)); 
    }

    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n <= 2) return 1; 
        int &ans = dp[n];
        if(ans != -1) return ans;
        return ans = (tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3));
        }
};

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string s, w; cin >> s >> w;
  Solution sln; 
  cout << sln.maxRepeating(s, w) << '\n';
  return 0;
}
