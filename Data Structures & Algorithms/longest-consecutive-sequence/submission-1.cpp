class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int>store(nums.begin(),nums.end());

        int res=0;
        for(int num:nums)
        {
            int streak=0; int curr=num;


            while(store.find(curr)!=store.end())
            {
                streak++;
                curr++;
            }

            res=max(res,streak);
        }

        return res;
        
    }
};

/*
===========================================================
Approach

১. প্রথমে array-এর সব element একটি unordered_set-এ store করা হয়েছে।
   কারণ unordered_set-এ কোনো element search করতে Average O(1) সময় লাগে।

২. এরপর array-এর প্রতিটি element-কে consecutive sequence-এর starting
   point ধরে check করা হয়েছে।

৩. একটি current variable দিয়ে বর্তমান number track করা হয়েছে এবং
   যতক্ষণ current number set-এ পাওয়া যাচ্ছে ততক্ষণ sequence চালানো হয়েছে।

৪. প্রতিবার current number পাওয়া গেলে
      - streak (sequence length) ১ বৃদ্ধি করা হয়েছে।
      - current number ১ বাড়িয়ে next number check করা হয়েছে।

৫. যখন next consecutive number পাওয়া যায় না,
   তখন সেই sequence শেষ হয়।

৬. প্রতিটি sequence-এর length-এর সাথে previous maximum compare করে
   সর্বোচ্চ length update করা হয়েছে।

৭. সব iteration শেষ হলে longest consecutive sequence-এর length return করা হয়েছে।

===========================================================
Dry Run

Example:

nums = [100,4,200,1,3,2]

unordered_set:

{
100,
4,
200,
1,
3,
2
}

-----------------------------------------------------------
Iteration 1

num = 100

100 পাওয়া গেছে
streak = 1

101 পাওয়া যায়নি

Maximum Length = 1

-----------------------------------------------------------
Iteration 2

num = 4

4 পাওয়া গেছে
streak = 1

5 পাওয়া যায়নি

Maximum Length = 1

-----------------------------------------------------------
Iteration 3

num = 200

200 পাওয়া গেছে
streak = 1

201 পাওয়া যায়নি

Maximum Length = 1

-----------------------------------------------------------
Iteration 4

num = 1

1 পাওয়া গেছে
streak = 1

2 পাওয়া গেছে
streak = 2

3 পাওয়া গেছে
streak = 3

4 পাওয়া গেছে
streak = 4

5 পাওয়া যায়নি

Maximum Length = 4

-----------------------------------------------------------
Iteration 5

num = 3

3 পাওয়া গেছে
streak = 1

4 পাওয়া গেছে
streak = 2

5 পাওয়া যায়নি

Maximum Length = 4

-----------------------------------------------------------
Iteration 6

num = 2

2 পাওয়া গেছে
streak = 1

3 পাওয়া গেছে
streak = 2

4 পাওয়া গেছে
streak = 3

5 পাওয়া যায়নি

Maximum Length = 4

-----------------------------------------------------------

Final Answer = 4

===========================================================
Time Complexity

unordered_set তৈরি করতে লাগে O(n)।

এরপর for loop n বার চলে।

Worst Case-এ while loop একই consecutive sequence বারবার scan করে।

Example:

nums = [1,2,3,4,5]

Iteration from 1:
5 checks

Iteration from 2:
4 checks

Iteration from 3:
3 checks

Iteration from 4:
2 checks

Iteration from 5:
1 check

Total Operations

= 5 + 4 + 3 + 2 + 1
= n(n+1)/2

Worst Case Time Complexity = O(n²)

===========================================================
Space Complexity

unordered_set-এ array-এর সব unique element store করা হয়েছে।

Extra Space = O(n)

অন্যান্য variable (res, streak, curr) শুধুমাত্র constant memory ব্যবহার করে।

Total Space Complexity = O(n)

===========================================================
Drawback

এই approach-এ একই consecutive sequence একাধিকবার scan করা হয়।

Example:

1 2 3 4

Starting from 1:
1 → 2 → 3 → 4

Starting from 2:
2 → 3 → 4

Starting from 3:
3 → 4

Starting from 4:
4

এই repeated scanning-এর কারণেই Worst Case Time Complexity O(n²) হয়।

Optimal Solution-এ শুধুমাত্র sequence-এর starting element থেকে scan করা হয়,
ফলে Time Complexity O(n) হয়ে যায়।

===========================================================
*/
