class Solution {
public:
    int maxArea(vector<int>& heights) {
       int ans=0;
       int area;
        for(int i=0;i<heights.size();i++)
        {
            for(int j=i+1;j<heights.size();j++)
            {
                area=abs(j-i)*min(heights[i],heights[j]);

                ans=max(area,ans);
            }
        }
        return ans;
        
    }
};
