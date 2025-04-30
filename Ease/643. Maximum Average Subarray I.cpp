class Solution {
public:
double findMaxAverage(vector<int>& a, int k) {

  int sum = accumulate(a.begin(), a.begin() + k, 0);

  int mx_sum = sum;
  for(int i = 1; i <= a.size() - k; i++) {
       sum -= a[i - 1];
       sum += a[i + k - 1];
       mx_sum = max(mx_sum, sum);
  } 
  double ans = (double)mx_sum / k;
  return ans;
}
};
