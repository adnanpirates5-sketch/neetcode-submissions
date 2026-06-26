class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.length() != t.length())
        {
            return false;
        }

        unordered_map<char,int>counts;
        unordered_map<char,int>countS;

        for(int i=0;i<s.length();i++)
        {
            counts[s[i]]++;
            countS[t[i]]++;

        }

        return counts == countS;
        
    }
};

/*
==========================
Algorithm (Hash Map)
==========================

১. প্রথমে দুটি string-এর length check করি।
   - যদি length ভিন্ন হয়, তাহলে তারা কখনোই anagram হতে পারে না।
   - তাই সঙ্গে সঙ্গে false return করি।

২. দুটি hash map তৈরি করি।
   - map1 -> প্রথম string (s)-এর character frequency সংরক্ষণ করবে।
   - map2 -> দ্বিতীয় string (t)-এর character frequency সংরক্ষণ করবে।

৩. একটি loop চালিয়ে একই সাথে দুটি string traverse করি।
   - map1[s[i]]++ করে s-এর প্রতিটি character-এর count বাড়াই।
   - map2[t[i]]++ করে t-এর প্রতিটি character-এর count বাড়াই।

৪. Loop শেষ হলে দুটি hash map compare করি।
   - যদি map1 == map2 হয়,
     তাহলে প্রতিটি character-এর frequency একই।
     অর্থাৎ string দুটি anagram।
     তাই true return করি।

   - অন্যথায়,
     character frequency মিলছে না।
     তাই false return করি।

উদাহরণ:

s = "listen"
t = "silent"

map1:
l -> 1
i -> 1
s -> 1
t -> 1
e -> 1
n -> 1

map2:
s -> 1
i -> 1
l -> 1
e -> 1
n -> 1
t -> 1

দুটি map-এর character frequency একই,
তাই answer = true.
*/
/*
Time Complexity:

ধরি, string-এর দৈর্ঘ্য = n

১. Length check = O(1)

২. Loop = O(n)
   - প্রতিটি iteration-এ
     map1[s[i]]++
     map2[t[i]]++
   Average case-এ unordered_map-এর insert/update = O(1)

৩. দুটি hash map compare = O(k)

এখানে,
k = unique character-এর সংখ্যা।

যদি character set সীমিত হয় (যেমন English lowercase ২৬টি),
তাহলে k ≤ 26, অর্থাৎ O(1)।

সাধারণভাবে k ≤ n,
তাই worst case-এ comparison = O(n)।

মোট Time Complexity:

O(1) + O(n) + O(n)
= O(n)
*/
/*
Space Complexity:

দুটি hash map ব্যবহার করা হয়েছে।

প্রতিটি unique character-এর জন্য একটি entry রাখা হয়।

যদি k = unique character-এর সংখ্যা হয়,

Space = O(k)

Worst case-এ,
সব character ভিন্ন হলে

k = n

তাই Space Complexity = O(n)

যদি শুধুমাত্র lowercase English letter থাকে,
তাহলে সর্বোচ্চ ২৬টি entry থাকবে।

সেক্ষেত্রে Space Complexity = O(1)
*/

