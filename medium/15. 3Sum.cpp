class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        vector<vector<int>> ans;
        set<vector<int>> res;
        int n = a.size();
        sort(a.begin(), a.end());

        int offset = 1e5;
        int max_val = 2 * offset + 1;
        vector<int> mp(max_val, 0), used(max_val, 0);
        int current_time = 1;

        for(int i = 0; i < n; ++i) {
            ++current_time;
            for(int j = i + 1; j < n; ++j) {
                int need = -(a[i] + a[j]);
                int idx = need + offset;
                if(idx >= 0 && idx < max_val && used[idx] == current_time && mp[idx] > 0) {
                    vector<int> temp = {a[i], need, a[j]};
                    sort(temp.begin(), temp.end());
                    res.insert(temp);
                    mp[idx]--;
                } else {
                    int add_idx = a[j] + offset;
                    if(add_idx >= 0 && add_idx < max_val) {
                        used[add_idx] = current_time;
                        mp[add_idx]++;
                    }
                }
            }
        }

        for(auto i: res) {
            ans.emplace_back(i);
        }

        return ans;
    }
};
