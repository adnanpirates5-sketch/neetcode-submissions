class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<pair<int,int>>pairs;

        for(int i=0;i<numbers.size();i++)
        {
            pairs.push_back({numbers[i],i});
        }
        //sort(pairs.begin(),pairs.end()); lagbe ne jehetu sort kora ase

        int left=0;
        int right=pairs.size()-1;

        while(left<right)
        {
            int current=pairs[left].first+pairs[right].first;

            if(current==target)
            {
                return {min(pairs[left].second+1 , pairs[right].second+1),max(pairs[left].second+1,pairs[right].second+1)} ;
            }

            else if(current>target)
            {
                right--;
            }
            else
            {
                left++;
            }
        }
        return {};
        
    }
        
    
};
