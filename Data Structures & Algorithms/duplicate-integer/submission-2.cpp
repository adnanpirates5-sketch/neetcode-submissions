class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int>sets;

        for(int number:nums)
        {
            if(sets.count(number)>0)
            {
                return true;
            }
            else
            {
                sets.insert(number);
            }
        }
        return false;
        
    }
};