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

        int l=0;
        int r=newstring.size()-1;

        while(l<r)
        {

            if(newstring[l]!=newstring[r])
            {
                return false;
            }
            l++;
            r--;
        }

        return true;
        
    }
};

/*
Algorithm:

1. একটি নতুন string (newstring) তৈরি করি।
2. পুরো input string একবার traverse করি।
3. যদি character টি alphanumeric (A-Z, a-z, 0-9) হয়,
   তাহলে সেটিকে lowercase করে newstring এ যোগ করি।
4. এরপর দুইটি pointer নেই:
      l = শুরু (left)
      r = শেষ (right)
5. যতক্ষণ l < r:
      - যদি newstring[l] != newstring[r] হয়,
        তাহলে এটি palindrome নয়, তাই false return করি।
      - অন্যথায় l এক ধাপ সামনে এবং r এক ধাপ পিছনে নিয়ে যাই।
6. যদি পুরো string compare করার পর কোনো mismatch না পাওয়া যায়,
   তাহলে string টি palindrome, তাই true return করি।

---------------------------------------------------------

Example:

Input:
"A man, a plan, a canal: Panama"

Filtered + Lowercase:
"amanaplanacanalpanama"

Comparison:

a == a
m == m
a == a
n == n
...

সব character match করেছে,
তাই answer = true.

---------------------------------------------------------

Time Complexity:

ধরি input string এর দৈর্ঘ্য = n

1. Input string traverse করে filtered string তৈরি -> O(n)
2. Two pointers দিয়ে palindrome check -> O(n)

Total Time Complexity:
O(n) + O(n) = O(n)

---------------------------------------------------------

Space Complexity:

Filtered string (newstring) store করতে O(n)

Two pointers (l, r) শুধুমাত্র constant extra memory ব্যবহার করে -> O(1)

Total Extra Space:
O(n)

---------------------------------------------------------

Note:

এই solution টি আগের solution থেকে ভালো কারণ এখানে
reverse string তৈরি করা হয়নি।

আগের solution:
Extra Space = O(n) + O(n)

এই solution:
Extra Space = O(n)

Time Complexity একই O(n), কিন্তু memory usage কম।
*/
