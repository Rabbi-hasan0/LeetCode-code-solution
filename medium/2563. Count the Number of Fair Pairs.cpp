
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
