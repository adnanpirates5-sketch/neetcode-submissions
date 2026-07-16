class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        
        if(nums.empty())
        {
            return 0;
        }

        unordered_set<int>duplicateset(nums.begin(),nums.end());

        vector<int>arr;

        for(int x:duplicateset)
        {
            arr.push_back(x);
        }

        sort(arr.begin(),arr.end());
        int l=1;
        int current=1;
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i-1]<arr[i]  &&  arr[i]==arr[i-1]+1)
            
            {
                current++;
            }
            else
            {
                current=1;
            }


            l=max(l,current);


        }

        

        return l;
        
    }
};

/*
    Approach:
    =========

    1. যদি input array খালি থাকে, তাহলে কোনো consecutive sequence থাকবে না।
       তাই সরাসরি 0 return করি।

    2. unordered_set ব্যবহার করে সব duplicate element remove করি।
       কারণ duplicate consecutive sequence গণনায় কোনো ভূমিকা রাখে না।

       Example:
       nums = [1,2,2,3]

       After unordered_set:
       {1,2,3}

    3. unordered_set sort করা যায় না, তাই set-এর সব element
       একটি vector-এ copy করি।

    4. vector-টিকে sort করি যাতে consecutive সংখ্যাগুলো পাশাপাশি আসে।

       Example:
       Before Sort : [100,4,200,1,3,2]
       After Sort  : [1,2,3,4,100,200]

    5. দুটি variable ব্যবহার করি:

       current = বর্তমান consecutive sequence-এর length
       l       = এখন পর্যন্ত পাওয়া longest consecutive sequence-এর length

       শুরুতে:
       current = 1
       l = 1

    6. Vector একবার traverse করি।

       যদি:
           arr[i] == arr[i-1] + 1

       তাহলে sequence continue করছে,
       তাই current++ করি।

       অন্যথায়,
       sequence break করেছে,
       তাই current = 1 করি।

    7. প্রতিবার iteration শেষে

           l = max(l, current);

       ব্যবহার করে longest sequence update করি।

    8. Loop শেষ হলে l return করি।


    ------------------------------------------------

    Dry Run:
    --------

    nums = [100,4,200,1,3,2]

    Remove Duplicate:
    {100,4,200,1,3,2}

    Copy into vector:
    [100,4,200,1,3,2]

    Sort:
    [1,2,3,4,100,200]

    current = 1
    l = 1

    1 -> 2 : current = 2, l = 2
    2 -> 3 : current = 3, l = 3
    3 -> 4 : current = 4, l = 4
    4 ->100: current = 1, l = 4
    100->200: current = 1, l = 4

    Answer = 4


    ------------------------------------------------

    Time Complexity:
    ----------------

    1. Creating unordered_set      : O(n)
    2. Copy set to vector          : O(n)
    3. Sorting vector              : O(n log n)
    4. Single traversal            : O(n)

    Overall Time Complexity:
    O(n log n)

    ------------------------------------------------

    Space Complexity:
    -----------------

    unordered_set : O(n)
    vector         : O(n)

    Total Auxiliary Space:
    O(n)

*/
