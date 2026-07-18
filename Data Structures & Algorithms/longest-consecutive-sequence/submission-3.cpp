class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>numsets(nums.begin(),nums.end());

        int longest=0;

        for(int num:nums)
        {
            if(numsets.find(num-1)==numsets.end())
            {
                int length=1;

                while(numsets.find(num+length)!=numsets.end())
                {
                    length++;
                }
                 longest=max(longest,length);
            }

            
        }

        return longest;
        
    }
};
/*
=========================================
Approach (বাংলা)
=========================================

১. প্রথমে array-এর সব element একটি unordered_set-এ রাখি।
   কারণ unordered_set-এ কোনো element খুঁজতে average O(1) time লাগে।

২. এরপর array-এর প্রতিটি element-এর জন্য check করি,
   এটি কোনো consecutive sequence-এর শুরু কিনা।

   Condition:
   if(numsets.find(num-1) == numsets.end())

   অর্থাৎ যদি (num-1) set-এ না থাকে,
   তাহলে বুঝব বর্তমান num-ই sequence-এর প্রথম element।

৩. এরপর while loop ব্যবহার করে
   num+1, num+2, num+3 ... এভাবে পরপর element আছে কিনা check করি।

৪. যতক্ষণ consecutive element পাওয়া যায়,
   length বাড়াই।

৫. প্রতিটি sequence-এর length বের করে
   longest-এর সাথে compare করে maximum value রাখি।

৬. সব element check শেষ হলে longest return করি।


=========================================
Dry Run
=========================================

Input:
nums = [100,4,200,1,3,2]

unordered_set =
{
100,4,200,1,3,2
}

Iteration:

num = 100
99 নেই
=> নতুন sequence শুরু
100
length = 1
longest = 1

-----------------------

num = 4
3 আছে
=> Skip

-----------------------

num = 200
199 নেই
=> নতুন sequence শুরু
200
length = 1
longest = 1

-----------------------

num = 1
0 নেই
=> নতুন sequence শুরু

Sequence:
1 -> 2 -> 3 -> 4

length = 4

longest = max(1,4)
        = 4

-----------------------

num = 3
2 আছে
=> Skip

-----------------------

num = 2
1 আছে
=> Skip

Final Answer = 4


=========================================
কেন num-1 check করি?
=========================================

যদি num-1 থাকে,
তাহলে বুঝব current number sequence-এর মাঝখানে আছে।

যেমন:

1 2 3 4

এখানে

2-এর আগে 1 আছে
3-এর আগে 2 আছে
4-এর আগে 3 আছে

তাই শুধুমাত্র 1 থেকেই sequence count করা হবে।

এর ফলে একই sequence বারবার count হয় না।


=========================================
Time Complexity
=========================================

unordered_set তৈরি = O(n)

for loop = O(n)

while loop nested হলেও,
প্রতিটি element পুরো program-এ সর্বোচ্চ একবারই consecutive sequence-এর অংশ হিসেবে visit হয়।

তাই while loop-এর মোট কাজ = O(n)

Total Time Complexity:

O(n)


=========================================
Space Complexity
=========================================

unordered_set-এ n টি element রাখা হচ্ছে।

Space Complexity:

O(n)

*/

/*
=========================================
Dry Run Example
=========================================

Input:
nums = [100,4,200,1,3,2,6,5,9,8]

unordered_set:
{100,4,200,1,3,2,6,5,9,8}

longest = 0

--------------------------------------------------

num = 100

Check:
100 - 1 = 99

99 নেই
=> নতুন sequence শুরু

length = 1

100 + 1 = 101 ❌

Sequence:
100

longest = max(0,1) = 1

--------------------------------------------------

num = 4

Check:
4 - 1 = 3

3 আছে
=> Skip

--------------------------------------------------

num = 200

Check:
200 - 1 = 199

199 নেই
=> নতুন sequence শুরু

length = 1

200 + 1 = 201 ❌

Sequence:
200

longest = max(1,1) = 1

--------------------------------------------------

num = 1

Check:
1 - 1 = 0

0 নেই
=> নতুন sequence শুরু

length = 1

while loop:

1 + 1 = 2 ✅
length = 2

1 + 2 = 3 ✅
length = 3

1 + 3 = 4 ✅
length = 4

1 + 4 = 5 ✅
length = 5

1 + 5 = 6 ✅
length = 6

1 + 6 = 7 ❌

Loop শেষ

Sequence:
1 -> 2 -> 3 -> 4 -> 5 -> 6

longest = max(1,6) = 6

--------------------------------------------------

num = 3

2 আছে
=> Skip

--------------------------------------------------

num = 2

1 আছে
=> Skip

--------------------------------------------------

num = 6

5 আছে
=> Skip

--------------------------------------------------

num = 5

4 আছে
=> Skip

--------------------------------------------------

num = 9

8 আছে
=> Skip

--------------------------------------------------

num = 8

Check:
8 - 1 = 7

7 নেই
=> নতুন sequence শুরু

length = 1

8 + 1 = 9 ✅
length = 2

8 + 2 = 10 ❌

Sequence:
8 -> 9

longest = max(6,2) = 6

--------------------------------------------------

Final Answer:

Longest Consecutive Sequence = 6

Sequence:
1 -> 2 -> 3 -> 4 -> 5 -> 6
*/