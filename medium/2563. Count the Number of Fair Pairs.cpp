#include <bits/stdc++.h>
#define print(x) cout << x << '\n'
#define int long long
using namespace std;
const int N = 2e5;
const int mod = 1e9 + 7;
int dp[N], pref[N];

class Solution {
public:
    long long countFairPairs(vector<int>& a, int l, int r) {
        sort(a.begin(), a.end());
        long long ans = 0;
        for(int i = 0; i < a.size(); ++i) {
            int val = l - a[i];
            int lw = lower_bound(a.begin(), a.end(), val) - a.begin();
            val = r - a[i];
            int up = upper_bound(a.begin(), a.end(), val) - a.begin();
            if(lw >= a.size()) {
                continue;
            } 
            if(up == 0) up++;
            if(a[i] + a[lw] >= l and a[i] + a[up - 1] <= r) {
                ans += up - lw;
                if(lw <= i and i <= up - 1) {
                    ans--;
                }
            }
        }
        return ans / 2;
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // memset(dp, -1, sizeof dp);
    int t = 1; cin >> t;
    while(t--){
        int n, l, r; 
        cin >> n >> l >> r;
        vector<int> a(n);
        for(auto &i: a) cin >> i;
        Solution obj;
        cout << obj.countFairPairs(a, l, r) << '\n';
    }
    return 0;
}
