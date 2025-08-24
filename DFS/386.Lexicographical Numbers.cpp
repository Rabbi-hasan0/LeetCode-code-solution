class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> v;
        int num = 1;
        for(int i = 1; i <= n; ++i) {
            v.push_back(num);
            if (num * 10 <= n) {
                num *= 10;
            } else {
                while(num == n or num % 10 == 9) {
                    num /= 10;
                }
                ++num;
            }
        }
        return v;
    }
};
