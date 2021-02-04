// Day 4
// Question : Longest Harmonious Subsequence

class Solution
{
public:
    int findLHS(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        int res = 0;
        for (auto x : mp)
        {
            auto it = mp.find(x.first + 1);
            if (it != mp.end())
            {
                res = max(res, x.second + mp[x.first + 1]);
            }
        }
        return res;
    }
};
