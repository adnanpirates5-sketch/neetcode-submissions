class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>res;
        // Set is used to store only unique triplets.
        // If the same triplet is found multiple times,
        // the set automatically removes duplicates.


        sort(nums.begin(),nums.end());

        // Sort the array so every triplet is generated
        // in sorted order (e.g., [-1,0,1] instead of [1,-1,0]).
        // This helps the set identify duplicate triplets.

        for(int i=0;i<nums.size();i++) // Pick the first element of the triplet.
        {
            for(int j=i+1;j<nums.size();j++)
            // Pick the second element.
            // Start from i + 1 so we don't reuse the same element.
            {
                for(int k=j+1;k<nums.size();k++)
                 // Pick the third element.
                // Start from j + 1 to ensure all three indices are different.
                {
                    if(nums[i]+nums[j]+nums[k]==0)
                     // If the sum of the three numbers is 0,
                    // we have found a valid triplet.

                    // Insert the triplet into the set.
                        // Since the array is already sorted,
                        // the triplet is also sorted.
                        // Duplicate triplets are automatically ignored.
                    {
                        res.insert({nums[i],nums[j],nums[k]});
                    }
                }
            }
        }
       // Convert the set into a vector because
        // the function's return type is vector<vector<int>>.
        return vector<vector<int>>(res.begin(),res.end());
        
    }
};
