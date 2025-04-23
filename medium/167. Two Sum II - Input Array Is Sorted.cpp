class Solution {
public:
    vector<int> twoSum(vector<int>& a, int k) {
        vector<int> res;
        int n = a.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; ++i) {
            int need = k - a[i];
            if(mp.count(need)) {
                res.emplace_back(mp[need]);
                res.push_back(i + 1);
            }
            else mp[a[i]] = i + 1;
        }
        return res;
    }
};
