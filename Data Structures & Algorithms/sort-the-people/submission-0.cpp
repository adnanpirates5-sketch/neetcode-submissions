class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {

        unordered_map<int,string>maps;

        for(int i=0;i<names.size();i++)
        {
          maps[heights[i]]=names[i];
        }
        
        sort(heights.rbegin(),heights.rend());

        vector<string>res;

        for(int i=0;i<heights.size();i++)
        {
            res.push_back(maps[heights[i]]);
        }

        return res;
    }
};

/*
=========================================
LeetCode 2418. Sort the People
=========================================

Approach:
---------
1. Create an unordered_map where:
      height -> corresponding name

2. Since all heights are guaranteed to be distinct,
   every height uniquely identifies one person.

3. Sort the heights array in descending order.

4. Traverse the sorted heights array and use the map
   to retrieve the corresponding names.

5. Store the names in the answer vector and return it.

-----------------------------------------
Example:
-----------------------------------------

names   = ["Mary","John","Emma"]
heights = [180,165,170]

Step 1:
Map:
180 -> Mary
165 -> John
170 -> Emma

Step 2:
Sort heights (Descending)

180 170 165

Step 3:
Retrieve names using map

180 -> Mary
170 -> Emma
165 -> John

Answer:
["Mary","Emma","John"]

-----------------------------------------
Why unordered_map?
-----------------------------------------

unordered_map provides average O(1) lookup.

Instead of sorting both arrays together,
we only sort the heights and use the map
to quickly find the corresponding name.

-----------------------------------------
Time Complexity:
-----------------------------------------

Building unordered_map : O(n)

Sorting heights        : O(n log n)

Building answer        : O(n)

Overall Time Complexity:
O(n log n)

-----------------------------------------
Space Complexity:
-----------------------------------------

unordered_map : O(n)

Answer vector : O(n)

Overall Space Complexity:
O(n)

-----------------------------------------
Note:
-----------------------------------------

This solution modifies the original heights array
because it is sorted in-place.

If preserving the original array is required,
create a copy before sorting.

The solution works because the problem guarantees
that every height is unique.
*/