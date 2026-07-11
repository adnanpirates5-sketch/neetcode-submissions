class Solution {
public:
    int maxArea(vector<int>& heights) {

        int l=0;
        int r=heights.size()-1;
        int ans=0;

        while(l<r)
        {
            int area=abs(r-l)*min(heights[l],heights[r]);
            ans=max(area,ans);

            if(heights[l]<heights[r])
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return ans;
        
    }
};

/*
Approach (Two Pointers)

১. শুরুতে দুটি pointer ব্যবহার করি:
   - l = array-এর প্রথম index
   - r = array-এর শেষ index

২. প্রতিবার এই দুইটি bar দিয়ে তৈরি container-এর area হিসাব করি।
      Width  = r - l
      Height = min(heights[l], heights[r])
      Area   = (r - l) * min(heights[l], heights[r])

৩. প্রতিবার maximum area update করি।
      ans = max(ans, area)

৪. এরপর শুধুমাত্র ছোট height-এর pointer-টি move করি।
   - যদি heights[l] < heights[r] হয়, তাহলে l++
   - নাহলে r--

   কারণ:
   Container-এর height সবসময় ছোট bar দ্বারা নির্ধারিত হয়।
   যদি বড় height-এর pointer সরানো হয়, তাহলে width কমে যাবে কিন্তু
   ছোট height একই থাকবে বা আরও কমে যেতে পারে। ফলে বড় area পাওয়ার
   কোনো সম্ভাবনা থাকে না।
   তাই ছোট height-এর pointer সরিয়ে এমন একটি bar খুঁজে বের করার চেষ্টা করি,
   যার height বেশি হতে পারে এবং area বৃদ্ধি পেতে পারে।

৫. Pointer দুটি একে অপরকে অতিক্রম বা একই জায়গায় পৌঁছালে loop শেষ হয়।

Time Complexity: O(n)
- প্রতিটি pointer সর্বোচ্চ একবার করে array-এর মধ্য দিয়ে অগ্রসর হয়।
- তাই পুরো algorithm-এর সময় জটিলতা O(n)।

Space Complexity: O(1)
- শুধুমাত্র কয়েকটি variable ব্যবহার করা হয়েছে।
- কোনো অতিরিক্ত data structure ব্যবহার করা হয়নি।
*/
