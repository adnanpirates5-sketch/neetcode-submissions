class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int>s;

        for(int num:nums)
        {
            s.insert(num);
        }

        return nums.size()>s.size();
    }
};