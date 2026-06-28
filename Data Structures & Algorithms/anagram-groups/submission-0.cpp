class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string,vector<string>>result;

        for(string s:strs)
        {
            string stored=s;

            sort(stored.begin(),stored.end());

            result[stored].push_back(s);
        }

        vector<vector<string>>ultimate_result;

        for(auto& pair:result )
        {
            ultimate_result.push_back(pair.second);
        }

        return ultimate_result;
        
    }
};





















/*
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        
        ===========================================================
        Problem:
        ===========================================================

        Given an array of strings, group all the anagrams together.

        Anagrams are words that contain the same characters with the
        same frequencies but possibly in a different order.

        Example:

        Input:
        ["eat","tea","tan","ate","nat","bat"]

        Output:
        [
            ["eat","tea","ate"],
            ["tan","nat"],
            ["bat"]
        ]

        ===========================================================
        Approach:
        ===========================================================

        Observation:

        Two strings are anagrams if their sorted versions are identical.

        Example:

        "eat" -> sort -> "aet"
        "tea" -> sort -> "aet"
        "ate" -> sort -> "aet"

        Since all three become "aet", they belong to the same group.

        We use an unordered_map where

            Key   = Sorted string
            Value = Vector of original strings

        Example:

        "aet" -> ["eat","tea","ate"]
        "ant" -> ["tan","nat"]
        "abt" -> ["bat"]

        Finally, we collect all map values into our answer.

        ===========================================================
        */

       // unordered_map<string, vector<string>> result;

        /*
        Traverse every string.

        Example:
        strs = ["eat","tea","tan","ate","nat","bat"]
        */

        //for (string s : strs)
       // {
            /*
            Make a copy because we need the original string later.
            */

           // string stored = s;

            /*
            Sort the copied string.

            "eat" -> "aet"
            "tea" -> "aet"
            "tan" -> "ant"
            */

         //   sort(stored.begin(), stored.end());

            /*
            Use the sorted string as the key.

            If key already exists,
            push current string into that vector.

            Otherwise unordered_map automatically creates
            a new empty vector.
            */

            //result[stored].push_back(s);
        //}

        /*
        Store final grouped anagrams.
        */

        //vector<vector<string>> ultimate_result;

        /*
        Copy every vector from the hashmap into answer.
        */

       // for (auto &pair : result)
       // {
           // ultimate_result.push_back(pair.second);
       // }

       // return ultimate_result;
   // }
//};

/*

====================================================================
Dry Run
====================================================================

Input:

strs =

[
"eat",
"tea",
"tan",
"ate",
"nat",
"bat"
]

Initially

result = { }

====================================================================
Iteration 1
====================================================================

Current string

s = "eat"

Copy

stored = "eat"

Sort

stored = "aet"

Insert into map

result

"aet" -> ["eat"]

====================================================================
Iteration 2
====================================================================

Current string

s = "tea"

Copy

stored = "tea"

Sort

stored = "aet"

Insert

result

"aet" -> ["eat","tea"]

====================================================================
Iteration 3
====================================================================

Current string

s = "tan"

Copy

stored = "tan"

Sort

stored = "ant"

Insert

result

"aet" -> ["eat","tea"]

"ant" -> ["tan"]

====================================================================
Iteration 4
====================================================================

Current string

s = "ate"

Copy

stored = "ate"

Sort

stored = "aet"

Insert

result

"aet" -> ["eat","tea","ate"]

"ant" -> ["tan"]

====================================================================
Iteration 5
====================================================================

Current string

s = "nat"

Copy

stored = "nat"

Sort

stored = "ant"

Insert

result

"aet" -> ["eat","tea","ate"]

"ant" -> ["tan","nat"]

====================================================================
Iteration 6
====================================================================

Current string

s = "bat"

Copy

stored = "bat"

Sort

stored = "abt"

Insert

result

"aet" -> ["eat","tea","ate"]

"ant" -> ["tan","nat"]

"abt" -> ["bat"]

====================================================================
Final Step
====================================================================

Traverse the unordered_map.

Copy every value into answer.

ultimate_result

[
    ["eat","tea","ate"],
    ["tan","nat"],
    ["bat"]
]

NOTE:

unordered_map does NOT preserve insertion order.

Therefore,

[
    ["bat"],
    ["eat","tea","ate"],
    ["tan","nat"]
]

is also a valid output.

====================================================================
Complexity Analysis
====================================================================

Let

N = Number of strings

K = Maximum length of a string

--------------------------------------------------
Time Complexity
--------------------------------------------------

For every string

Copy string

O(K)

Sort string

O(K log K)

Insert into unordered_map

Average O(1)

Therefore

One string

O(K log K)

For N strings

O(N × K log K)

--------------------------------------------------
Space Complexity
--------------------------------------------------

unordered_map stores every string

O(N × K)

Temporary copied string

O(K)

Final answer

O(N × K)

Overall

O(N × K)

====================================================================
Key Idea
====================================================================

Original String          Sorted Key

eat   ------------->     aet

tea   ------------->     aet

ate   ------------->     aet

tan   ------------->     ant

nat   ------------->     ant

bat   ------------->     abt

Strings that have the same sorted key belong to
the same anagram group.

====================================================================
Interview Summary
====================================================================

1. Traverse every string.
2. Make a copy.
3. Sort the copy.
4. Use the sorted copy as the hashmap key.
5. Store the original string in that key's vector.
6. Return all vectors stored in the hashmap.

Time  : O(N × K log K)

Space : O(N × K)

====================================================================
*/





