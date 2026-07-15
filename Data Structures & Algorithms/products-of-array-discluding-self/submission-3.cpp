class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    

    int n=nums.size();

    vector<int>ans(n);
    vector<int>prefix(n);
    vector<int>suffix(n);

    prefix[0]=1;

    for(int i=1;i<n;i++)
    {
        prefix[i]=prefix[i-1] * nums[i-1];
    }


    suffix[n-1]=1;

    for(int i=n-2; i>=0; i--)
    {
        suffix[i]=suffix[i+1] * nums[i+1];
    }

    for(int i=0;i<n;i++)
    {
        ans[i]=prefix[i] * suffix[i];
    }

    return ans;
    }
};







/*
=========================================================
Approach: Prefix Product + Suffix Product
=========================================================

Problem:
প্রতিটি index-এর জন্য নিজের element ছাড়া বাকি সব element-এর
product বের করতে হবে।
Division ব্যবহার করা যাবে না, তাই Prefix এবং Suffix Product
technique ব্যবহার করা হয়েছে।

=========================================================
How My Logic Works
=========================================================

Step-1: Create Prefix Product Array

prefix[i] = index i-এর বাম পাশের সব element-এর product।

Initially,
prefix[0] = 1

কারণ প্রথম element-এর বামে কোনো element নেই।

তারপর,

prefix[i] = prefix[i-1] * nums[i-1]

অর্থাৎ,
আগের prefix product-এর সাথে আগের element গুণ করে
বর্তমান index-এর left product বের করা হয়েছে।

---------------------------------------------------------

Step-2: Create Suffix Product Array

suffix[i] = index i-এর ডান পাশের সব element-এর product।

Initially,
suffix[n-1] = 1

কারণ শেষ element-এর ডানে কোনো element নেই।

তারপর reverse direction-এ,

suffix[i] = suffix[i+1] * nums[i+1]

অর্থাৎ,
পরের suffix product-এর সাথে পরের element গুণ করে
বর্তমান index-এর right product বের করা হয়েছে।

---------------------------------------------------------

Step-3: Build Final Answer

প্রতিটি index-এর জন্য,

answer[i] = prefix[i] * suffix[i]

কারণ,

prefix[i]  -> Left side product
suffix[i]  -> Right side product

দুইটিকে গুণ করলে নিজের element ছাড়া
বাকি সব element-এর product পাওয়া যায়।

=========================================================
Dry Run
=========================================================

Input:

nums = [1,2,3,4]

n = 4

---------------------------------------------------------
Step-1: Build Prefix Array
---------------------------------------------------------

Initially:

prefix = [1,0,0,0]

i = 1
prefix[1] = prefix[0] * nums[0]
          = 1 * 1
          = 1

prefix = [1,1,0,0]

---------------------

i = 2

prefix[2] = prefix[1] * nums[1]
          = 1 * 2
          = 2

prefix = [1,1,2,0]

---------------------

i = 3

prefix[3] = prefix[2] * nums[2]
          = 2 * 3
          = 6

Final Prefix:

prefix = [1,1,2,6]

=========================================================

Step-2: Build Suffix Array
=========================================================

Initially:

suffix = [0,0,0,1]

i = 2

suffix[2] = suffix[3] * nums[3]
          = 1 * 4
          = 4

suffix = [0,0,4,1]

---------------------

i = 1

suffix[1] = suffix[2] * nums[2]
          = 4 * 3
          = 12

suffix = [0,12,4,1]

---------------------

i = 0

suffix[0] = suffix[1] * nums[1]
          = 12 * 2
          = 24

Final Suffix:

suffix = [24,12,4,1]

=========================================================

Step-3: Build Answer Array
=========================================================

answer[0] = prefix[0] * suffix[0]
          = 1 * 24
          = 24

answer = [24,_,_,_]

---------------------

answer[1] = 1 * 12
          = 12

answer = [24,12,_,_]

---------------------

answer[2] = 2 * 4
          = 8

answer = [24,12,8,_]

---------------------

answer[3] = 6 * 1
          = 6

answer = [24,12,8,6]

Final Output:

[24,12,8,6]

=========================================================
Time Complexity
=========================================================

Building Prefix Array  -> O(n)

Building Suffix Array  -> O(n)

Building Answer Array  -> O(n)

Total:

O(n + n + n)

= O(3n)

Ignoring constant factor,

Overall Time Complexity = O(n)

=========================================================
Space Complexity
=========================================================

Extra Arrays:

prefix -> O(n)

suffix -> O(n)

Output Array:

answer -> O(n)

LeetCode-তে output array-কে extra space হিসেবে ধরা হয় না।

Therefore,

Auxiliary Space = O(2n)

Ignoring constant factor,

Overall Auxiliary Space = O(n)

=========================================================
*/
