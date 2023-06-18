class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double mx;
    double sum=0;

    for(int i=0; i<k; i++)sum += nums[i];

    mx=sum;

    for(int i=1; i<=nums.size()-k; i++)
    {
        sum=sum-nums[i-1]+nums[i+k-1];
        mx = max(mx,sum);
    }

    return mx/k;
    }
};
