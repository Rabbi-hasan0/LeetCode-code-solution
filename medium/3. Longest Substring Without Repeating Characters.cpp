class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int n = s.size(), ans = 0, back = 0, j = 0;
        for(int i = 0; i < n; ++i) {
            if(mp[s[i]] == 0) {
                int lngth = i - back + 1;
                ans = max(ans, lngth);
                mp[s[i]] = i + 1;
            } else {
                back = mp[s[i]];
                while(j < back) mp[s[j++]] = 0;
                mp[s[i]] = i + 1;
            }
        }
        return ans;
    }
};
