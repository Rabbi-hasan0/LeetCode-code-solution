#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9, inf = 1e9;
int dp[N];

class Solution {
public:
    int maxRepeating(string s, string w) { // unsing dp and complexity: O(n)
        int n = s.size(), m = w.size();
        int dp[n];
        fill(dp, dp + n, 0);
        int ans = 0;
        for(int i = m - 1; i < n; i++) {
            // here, using [string.substr(start, length);]
            // --> s is original string
            // --> in bracket given starting point and length
            // --> after == then given w, which I found..
            if(s.substr(i - m + 1, m) == w) {
                dp[i] = 1;
                if (i >= m) dp[i] += dp[i - m];
                ans = max(ans, dp[i]);
            }
        }
        return ans;
    }
    int MaxRepeating(string s, string w) { // bruthforce approach and complexity: O(n * n)
        int m = w.size(), ans = 0;
        for(int i = 0; i < s.size(); i++) {
            int k = 0, cnt = 0;
            for(int j = i; j < s.size(); j++) {
                if(s[j] == w[k]) {
                    k++;
                    if(k >= m) {
                        k = 0;
                        cnt++;
                    }
                } else break;
            }
            ans = max(ans, cnt);
        }
        return ans;
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
