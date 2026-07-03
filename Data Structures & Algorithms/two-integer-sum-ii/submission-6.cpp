class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
         unordered_map<int,int>result;

        for(int i=0;i<numbers.size();i++)
        {
            result[numbers[i]]=i;
        }

        for(int i=0;i<numbers.size();i++)
        {
            int difference=target-numbers[i];

            if(result.count(difference) && result[difference]!=i)
            {
                return {i + 1, result[difference] + 1};
            }
        }


        return {};
        
    }
};
