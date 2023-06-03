class Solution {
public:
    int singleNumber(vector<int>& a) {
        map<int,int>mp;
    for (int i = 0; i <a.size() ; i++)
    {
        mp[a[i]]++;
    }
    int ans=0;
    for (auto it: mp)
    {
        int x=it.first;
        int y=it.second;
        if(y==1)
           {
               ans=x;
               break;
           }
    }
return ans;
    }
};
