class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();

        vector<int>ans(n,1);



        for(int i=1;i<n;i++)
        {
            ans[i]=ans[i-1]*nums[i-1];
        }

        int suffix=1;

        for(int i=n-2;i>=0;i--)
        {
            suffix=suffix*nums[i+1];
            ans[i]=ans[i]*suffix;
        }

        return ans;


    }
};


/*
=========================================================
LeetCode 238 - Product of Array Except Self
Approach: Prefix Product + Running Suffix Product (Optimal)
=========================================================

Problem:
প্রতিটি index-এর জন্য নিজের element বাদে
বাকি সব element-এর product বের করতে হবে।

Condition:
1. Division ব্যবহার করা যাবে না।
2. O(n) Time Complexity.
3. O(1) Extra Space (Output array বাদ দিয়ে).

=========================================================
Intuition
=========================================================

যদি প্রতিটি index-এর জন্য

Left Product × Right Product

জানা থাকে, তাহলে নিজের element বাদে
বাকি সব element-এর product সহজেই পাওয়া যায়।

Example:

nums = [1,2,3,4]

Index 2-এর জন্য,

Left Product = 1 × 2 = 2

Right Product = 4

Answer = 2 × 4 = 8

এই ধারণার উপর ভিত্তি করেই solutionটি তৈরি করা হয়েছে।

=========================================================
How My Logic Works
=========================================================

Step-1:
প্রথমে answer array-কে সব জায়গায় 1 দিয়ে initialize করেছি।

vector<int> ans(n,1);

কারণ,
প্রথম element-এর বামে কিছু নেই,
তাই Left Product = 1.

---------------------------------------------------------

Step-2:
একটি loop চালিয়ে answer array-এর মধ্যে
Prefix Product store করেছি।

Formula:

ans[i] = ans[i-1] * nums[i-1]

অর্থাৎ,

ans[i] = index i-এর বাম পাশের
সব element-এর product।

এই loop শেষে,

ans array-তেই Prefix Product সংরক্ষিত থাকে।

---------------------------------------------------------

Step-3:
এবার আলাদা suffix array না বানিয়ে

একটি variable নিয়েছি।

int suffix = 1;

এই variable সবসময় বর্তমান index-এর
ডান পাশের product সংরক্ষণ করে।

Reverse direction-এ চলতে চলতে,

suffix = suffix * nums[i+1];

এরপর,

ans[i] = ans[i] * suffix;

এখানে,

ans[i] = Left Product

suffix = Right Product

দুইটিকে গুণ করলে Final Answer পাওয়া যায়।

এভাবেই extra suffix array ব্যবহার না করেই
solutionটি সম্পন্ন হয়েছে।

=========================================================
Complete Dry Run
=========================================================

Input:

nums = [1,2,3,4]

n = 4

---------------------------------------------------------
Step-1:

Initially,

ans = [1,1,1,1]

---------------------------------------------------------
Step-2: Build Prefix Product

i = 1

ans[1] = ans[0] * nums[0]
       = 1 * 1
       = 1

ans = [1,1,1,1]

-------------------------

i = 2

ans[2] = ans[1] * nums[1]
       = 1 * 2
       = 2

ans = [1,1,2,1]

-------------------------

i = 3

ans[3] = ans[2] * nums[2]
       = 2 * 3
       = 6

ans = [1,1,2,6]

এখন ans array-তে শুধু Prefix Product রয়েছে।

---------------------------------------------------------
Step-3: Running Suffix Product

Initially,

suffix = 1

-------------------------

i = 2

suffix = 1 * nums[3]
       = 4

ans[2] = 2 * 4
       = 8

ans = [1,1,8,6]

-------------------------

i = 1

suffix = 4 * nums[2]
       = 12

ans[1] = 1 * 12
       = 12

ans = [1,12,8,6]

-------------------------

i = 0

suffix = 12 * nums[1]
       = 24

ans[0] = 1 * 24
       = 24

Final Answer:

ans = [24,12,8,6]

=========================================================
Why This Solution Is Optimal?
=========================================================

সাধারণ solution-এ

Prefix Array -> O(n)

Suffix Array -> O(n)

দুইটি extra array লাগে।

কিন্তু এখানে,

Prefix Product সরাসরি answer array-তে store করা হয়েছে।

এবং

Suffix Product শুধুমাত্র একটি variable দিয়ে
calculate করা হয়েছে।

ফলে extra suffix array-এর প্রয়োজন হয়নি।

=========================================================
Time Complexity
=========================================================

1st Loop (Build Prefix Product)
= O(n)

2nd Loop (Multiply Running Suffix Product)
= O(n)

Total

O(n + n)

= O(2n)

Ignoring constant factor,

Overall Time Complexity = O(n)

=========================================================
Space Complexity
=========================================================

Extra Variable:

suffix = O(1)

Output Array:

ans = O(n)

LeetCode-তে output array-কে extra space হিসেবে
গণনা করা হয় না।

Therefore,

Auxiliary Space = O(1)

Overall Extra Space Complexity = O(1)

=========================================================
*/
