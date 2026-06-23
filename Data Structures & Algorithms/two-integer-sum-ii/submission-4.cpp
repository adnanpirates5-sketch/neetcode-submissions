class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i=0;i<numbers.size();i++)
        {
            int required=target-numbers[i];

            int left=i+1;
            int right=numbers.size()-1;

            while(left<=right)
            {

                int mid=(left+right)/2;
                if(numbers[mid]==required)
                {
                    return {i+1,mid+1};
                }
                else if(numbers[mid]<required)
                {
                    left=mid+1;
                }
                else
                {
                    right=mid-1;
                }


            }
        }
        return {};
        
    }
};

/*
2. Binary Search
Intuition
Because the array is already sorted, we don’t need to check every pair.
For each number at index i, we know exactly what value we need to find:
target - numbers[i].
Since the array is sorted, we can efficiently search for this value using binary search instead of scanning linearly.
This reduces the inner search from O(n) to O(log n), making the solution much faster.

Algorithm
Loop through each index i from 0 to n - 1.
For each number numbers[i], compute the needed complement:
tmp = target - numbers[i]
Perform binary search on the subarray from i + 1 to the end:
If numbers[mid] == tmp, return [i + 1, mid + 1]
If numbers[mid] < tmp, search the right half
Otherwise, search the left half
If no pair is found after checking all indices, return an empty list.
Time & Space Complexity
Time complexity: 
O
(
n
log
⁡
n
)
O(nlogn)
Space complexity: 
O
(
1
)
O(1) */

