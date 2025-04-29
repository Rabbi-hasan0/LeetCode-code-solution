class Solution {
public:
    int maxArea(vector<int>& a) {
        int n = a.size();
        int i = 0, j = n - 1;
        int ans = 0;
        while(i < j and i < n and j > -1) {
            int width = j - i;
            int height = min(a[i], a[j]);
            int area = width * height;
            ans = max(ans, area);
            if(a[i] == mn) {
                ++i;
            } else --j;
        }
        return ans;
    }
};
