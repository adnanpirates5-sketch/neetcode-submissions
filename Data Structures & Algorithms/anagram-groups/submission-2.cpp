class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>>mp;

        for( string s:strs)
        {
            vector<int>count(26,0);

            for(char c:s)
            {
                count[c-'a']++;
            }
            string key="";

            for(int i=0;i<26;i++)
            {
                key= key+to_string(count[i])+ ",";
            }
            mp[key].push_back(s);
        }

        vector<vector<string>>ans;

        for(auto &it:mp)
        {
            ans.push_back(it.second);
        }

        return ans;
    }
};


/*
======================================
LeetCode 49 : Group Anagrams
Time Complexity : O(n * k)
Space Complexity: O(n * k)

Explanation (Bangla)

Idea:
-------
দুটি string যদি anagram হয়, তাহলে তাদের character frequency
একই হবে।

Example:

"eat"
a = 1
e = 1
t = 1

"tea"
a = 1
e = 1
t = 1

দুটোর frequency একই, তাই এদের একই group-এ রাখতে হবে।

------------------------------------------------------------

Step 1:
একটি unordered_map তৈরি করি।

unordered_map<string, vector<string>> mp;

এখানে,

key   = character frequency কে string আকারে রাখা হবে।
value = যেসব string-এর frequency একই, সেগুলো।

Example:

key
"1,0,0,0,1,...,1,..."

value

["eat","tea","ate"]

------------------------------------------------------------

Step 2:
প্রতিটি string traverse করি।

for(string s : strs)

------------------------------------------------------------

Step 3:
২৬টি lowercase letter-এর frequency count করি।

vector<int> count(26,0);

index

0 -> a
1 -> b
2 -> c
...
25 -> z

এরপর

for(char c : s)
{
    count[c-'a']++;
}

Example:

s = "eat"

count হবে

a = 1
b = 0
c = 0
d = 0
e = 1
...
t = 1

------------------------------------------------------------

Step 4:
vector<int> কে unordered_map-এর key হিসেবে
ব্যবহার করা যায় না।

তাই frequency array-কে একটি string-এ convert করি।

string key = "";

for(int i=0;i<26;i++)
{
    key += to_string(count[i]) + ",";
}

এখানে,

count[i]
→ frequency বের করে।

to_string(count[i])
→ integer কে string-এ convert করে।

+ ","
→ comma যোগ করে।

key +=
→ key-এর শেষে append করে।

Example:

count

[1,0,0,0,1,0,0,...,1]

key

"1,0,0,0,1,0,0,...,1,"

Comma ব্যবহার করা হয়েছে ambiguity এড়ানোর জন্য।

Example

[1,11]
→ "1,11,"

[11,1]
→ "11,1,"

comma না থাকলে দুটোই

"111"

হয়ে যেত।

------------------------------------------------------------

Step 5:
এখন

mp[key].push_back(s);

এর মাধ্যমে

যদি key আগে থেকেই থাকে,
তাহলে সেই vector-এর শেষে string যোগ হবে।

যদি key নতুন হয়,
তাহলে unordered_map নতুন entry তৈরি করবে।

Example:

Input

["eat","tea","tan","ate","nat","bat"]

Iteration 1

eat

key

"1,0,0,0,1,...,1"

Map

{
 key1 : ["eat"]
}

Iteration 2

tea

same key

{
 key1 : ["eat","tea"]
}

Iteration 3

tan

different key

{
 key1 : ["eat","tea"]
 key2 : ["tan"]
}

Iteration 4

ate

same key

{
 key1 : ["eat","tea","ate"]
 key2 : ["tan"]
}

Iteration 5

nat

same as tan

{
 key1 : ["eat","tea","ate"]
 key2 : ["tan","nat"]
}

Iteration 6

bat

new key

{
 key1 : ["eat","tea","ate"]
 key2 : ["tan","nat"]
 key3 : ["bat"]
}

------------------------------------------------------------

Step 6:

শেষে unordered_map-এর প্রতিটি value
(answer groups) answer vector-এ push করি।

for(auto &it : mp)
{
    ans.push_back(it.second);
}

এবং ans return করি।

------------------------------------------------------------

Why does this work?

Anagram-এর character frequency সবসময় একই হয়।

তাই frequency থেকে তৈরি key-ও একই হবে।

একই key হওয়ার কারণে
unordered_map তাদের একই vector-এর মধ্যে store করবে।

------------------------------------------------------------

Complexity

n = number of strings
k = average length of each string

Character counting
= O(k)

Key তৈরি
= O(26)
= O(1)

সব string-এর জন্য

Time Complexity

O(n × k)

Space Complexity

O(n × k)

======================================
*/
