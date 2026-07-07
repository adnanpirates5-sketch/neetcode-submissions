class Solution {
public:
    bool isPalindrome(string s) {
        string newstring="";

        for(char c:s)
        {
            if(isalnum(c))
            {
            newstring+=tolower(c);
            }
        }

        return newstring==string(newstring.rbegin(),newstring.rend());
        
    }
};

/*
Algorithm:

1. একটি নতুন string (newstring) তৈরি করি।
2. পুরো input string একবার traverse করি।
3. যদি character টি alphanumeric (A-Z, a-z, 0-9) হয়,
   তাহলে সেটিকে lowercase করে newstring এ যোগ করি।
4. শেষে newstring এর reverse তৈরি করি।
5. যদি original newstring এবং reverse string সমান হয়,
   তাহলে এটি palindrome, নাহলে নয়।

Example:
Input : "A man, a plan, a canal: Panama"

Filtered + Lowercase:
"amanaplanacanalpanama"

Reverse:
"amanaplanacanalpanama"

দুটো একই হওয়ায় answer = true.

---------------------------------------------------------

Time Complexity:

ধরি input string এর length = n

1. Input string traverse করা        -> O(n)
2. Reverse string তৈরি করা          -> O(n)
3. দুইটি string compare করা         -> O(n)

Total Time Complexity:
O(n) + O(n) + O(n) = O(n)

---------------------------------------------------------

Space Complexity:

1. Filtered string (newstring) store করতে O(n)
2. Reverse string তৈরি করতে O(n)

Total Extra Space:
O(n)

---------------------------------------------------------

Note:
যদি newstring += tolower(c); ব্যবহার করি,
তাহলে append operation amortized O(1) হয় এবং overall
time complexity O(n) থাকে।

কিন্তু যদি newstring = newstring + tolower(c); ব্যবহার করি,
তাহলে প্রতিবার নতুন string create ও copy হয়,
যার কারণে worst-case time complexity O(n²) হতে পারে।
*/
