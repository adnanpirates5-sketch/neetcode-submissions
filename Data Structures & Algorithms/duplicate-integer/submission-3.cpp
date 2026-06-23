class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int>sets(nums.begin(),nums.end());

        return sets.size()<nums.size();
        
    }
};