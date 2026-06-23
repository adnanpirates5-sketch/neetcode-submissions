class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>>pairs;

        for(int i=0;i<nums.size();i++)
        {
            pairs.push_back({nums[i],i});
        }
        sort(pairs.begin(),pairs.end());

        int left=0;
        int right=pairs.size()-1;

        while(left<right)
        {
            int current=pairs[left].first+pairs[right].first;

            if(current==target)
            {
                return {min(pairs[left].second , pairs[right].second),max(pairs[left].second,pairs[right].second)} ;
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
/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        // প্রতিটি number এর সাথে তার index রাখার জন্য pair বানানো হচ্ছে
        vector<pair<int,int>> pairs;

        for(int i = 0; i < nums.size(); i++)
        {
            // {value, index} আকারে store করা হচ্ছে
            pairs.push_back({nums[i], i});
        }

        // value অনুযায়ী sort করা হচ্ছে (pair এর first element অনুযায়ী)
        sort(pairs.begin(), pairs.end());

        // দুইটা pointer নেওয়া হচ্ছে
        int left = 0;
        int right = pairs.size() - 1;

        // দুই দিক থেকে check করা হচ্ছে
        while(left < right)
        {
            // দুই pointer এর value যোগ করা হচ্ছে
            int current = pairs[left].first + pairs[right].first;

            // যদি target পাওয়া যায়
            if(current == target)
            {
                // original index return করতে হবে
                return {
                    min(pairs[left].second, pairs[right].second),
                    max(pairs[left].second, pairs[right].second)
                };
            }

            // যদি sum বড় হয়, তাহলে right কমাতে হবে (কারণ array sorted)
            else if(current > target)
            {
                right--;
            }

            // যদি sum ছোট হয়, তাহলে left বাড়াতে হবে
            else
            {
                left++;
            }
        }

        // যদি কিছু না পাওয়া যায়
        return {};
    }
};
*/
