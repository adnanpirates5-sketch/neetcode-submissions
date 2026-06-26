class Solution {
public:
    bool isAnagram(string s, string t) {

        vector<char>string_1;
        vector<char>string_2;

        for(int i=0;i<s.size();i++)
        {
            string_1.push_back(s[i]);
        }

        sort(string_1.begin(),string_1.end());

        for(int i=0;i<t.size();i++)
        {
            string_2.push_back(t[i]);
        }

        sort(string_2.begin(),string_2.end());


        if(string_1.size()!=string_2.size() || string_1 != string_2)
        {
            return false;
        }

        return true;
        


}
};

/*
==========================
Logic:
==========================

১. প্রথমে দুটি খালি vector<char> তৈরি করা হয়েছে।
   - string_1 -> প্রথম string (s)-এর সব character সংরক্ষণ করবে।
   - string_2 -> দ্বিতীয় string (t)-এর সব character সংরক্ষণ করবে।

২. প্রথম for loop দিয়ে s-এর প্রতিটি character
   string_1 vector-এ push_back() করা হয়েছে।

৩. এরপর string_1 কে sort() করা হয়েছে।
   এতে character গুলো alphabetical order-এ সাজানো হয়।

৪. একইভাবে দ্বিতীয় for loop দিয়ে t-এর প্রতিটি character
   string_2 vector-এ push_back() করা হয়েছে।

৫. এরপর string_2-কেও sort() করা হয়েছে।

৬. এখন দুটি vector compare করা হয়।
   - যদি size আলাদা হয়,
     তাহলে দুটি string কখনোই anagram হতে পারে না।
   - অথবা sort করার পর যদি দুটি vector সমান না হয়,
     তাহলে character গুলোর frequency মিলছে না।
     তাই false return করা হয়।

৭. যদি size একই হয় এবং sort করার পর
   দুটি vector পুরোপুরি সমান হয়,
   তাহলে string দুটি anagram।
   তাই true return করা হয়।

উদাহরণ:

s = "listen"
t = "silent"

sort করার পর

string_1 = "eilnst"
string_2 = "eilnst"

দুটি vector সমান,
তাই answer = true.


==========================
Time Complexity:
==========================

ধরি, string-এর দৈর্ঘ্য n।

১. প্রথম for loop = O(n)
   (s-এর প্রতিটি character একবার করে vector-এ রাখা হচ্ছে)

২. sort(string_1) = O(n log n)

৩. দ্বিতীয় for loop = O(n)

৪. sort(string_2) = O(n log n)

৫. vector compare = O(n)
   (সব element একবার করে compare করতে হতে পারে)

সুতরাং,

O(n) + O(n log n) + O(n) + O(n log n) + O(n)

= O(3n + 2n log n)

Big-O তে ছোট term বাদ দিলে,

Final Time Complexity = O(n log n)


==========================
Space Complexity:
==========================

string_1 vector = O(n)

string_2 vector = O(n)

মোট extra memory = O(2n)

Constant বাদ দিলে,

Final Space Complexity = O(n)

*/
