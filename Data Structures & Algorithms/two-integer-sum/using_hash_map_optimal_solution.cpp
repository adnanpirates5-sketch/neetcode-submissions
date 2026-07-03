class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>result;

        for(int i=0;i<nums.size();i++)
        {
            result[nums[i]]=i;
        }

        for(int i=0;i<nums.size();i++)
        {
            int difference=target-nums[i];

            if(result.count(difference) && result[difference]!=i)
            {
                return {i,result[difference]};
            }
        }


        return {};
    }
};

// Logic:
//
// একটি unordered_map ব্যবহার করা হয়েছে যেখানে
// Key = array-এর value
// Value = সেই value-এর index
//
// উদাহরণ:
// nums = {2, 7, 11, 15}
//
// প্রথম loop শেষে map হবে:
//
// 2  -> 0
// 7  -> 1
// 11 -> 2
// 15 -> 3
//
// এরপর আবার array traverse করি।
//
// প্রতিটি element-এর জন্য বের করি:
//
// diff = target - nums[i]
//
// অর্থাৎ বর্তমান সংখ্যার সাথে target পূরণ করতে আর কোন সংখ্যা প্রয়োজন।
//
// উদাহরণ:
// target = 9
// nums[i] = 2
//
// diff = 9 - 2 = 7
//
// এখন map-এ check করি 7 আছে কিনা।
//
// indices.count(diff)
// -> যদি 1 হয়, তাহলে diff map-এ আছে।
// -> যদি 0 হয়, তাহলে নেই।
//
// এরপর check করি:
//
// indices[diff] != i
//
// কারণ একই element দুইবার ব্যবহার করা যাবে না।
//
// যদি দুইটি condition-ই true হয়,
// তাহলে current index (i)
// এবং diff-এর index (indices[diff])
// return করি।

// Time Complexity:
//
// 1st loop:
// পুরো array একবার traverse করে map-এ insert করা হয়.
// Average insertion = O(1)
// তাই = O(n)
//
// 2nd loop:
// আবার পুরো array একবার traverse করা হয়.
// প্রতিবার map-এ lookup (count এবং []) = O(1) average
// তাই = O(n)
//
// মোট Time Complexity:
//
// O(n) + O(n)
// = O(n)
//
// Worst case:
// Hash collision হলে unordered_map-এর operation O(n) হতে পারে,
// তখন worst case = O(n²)



