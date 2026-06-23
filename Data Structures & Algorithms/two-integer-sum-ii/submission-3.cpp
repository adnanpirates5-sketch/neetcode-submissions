class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left=0;
        int right=numbers.size()-1;

        while(left<right)
        {
            int current=numbers[left]+numbers[right];
            if(current==target)
            {
                return {left+1,right+1};
            }
            else if(current>target)
            {
                right--;
            }
            else if(current<target)
            {
                left++;
            }
        }
        return {};
        
    }
};
/* 4. Two Pointers
Intuition
Because the array is sorted, we can use two pointers to adjust the sum efficiently.
If the current sum is too big, moving the right pointer left makes the sum smaller.
If the sum is too small, moving the left pointer right makes the sum larger.
This lets us quickly close in on the target without checking every pair.

Algorithm
Initialize two pointers:
l = 0 (start)
r = len(numbers) - 1 (end)
While l < r:
Compute curSum = numbers[l] + numbers[r].
If curSum > target, move r left to reduce the sum.
If curSum < target, move l right to increase the sum.
If curSum == target, return [l + 1, r + 1].
If no pair matches the target, return an empty list. */
