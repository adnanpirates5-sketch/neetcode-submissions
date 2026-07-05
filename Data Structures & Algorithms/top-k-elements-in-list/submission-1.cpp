class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int>frequencymap;

        for(int mp:nums)
        {
            frequencymap[mp]++;
        }

        vector<pair<int,int>>frequencystore;

        for(auto entry:frequencymap)
        {
            int number=entry.first;
            int frequency=entry.second;

            frequencystore.push_back({frequency,number});
        }

        sort(frequencystore.rbegin(),frequencystore.rend());

        vector<int>result;

        for(int i=0;i<k;i++)
        {
            result.push_back(frequencystore[i].second);
        }

        return result;
        
    }
};
