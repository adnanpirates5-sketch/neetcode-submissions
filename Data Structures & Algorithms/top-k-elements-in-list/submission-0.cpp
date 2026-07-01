class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // Stores: number -> frequency
        unordered_map<int, int> frequencyMap;

        // Count the frequency of each number
        for (int num : nums)
        {
            frequencyMap[num]++;
        }

        // Stores: (frequency, number)
        vector<pair<int, int>> frequencyNumberPairs;

        // Copy data from the map into the vector
        for (auto entry : frequencyMap)
        {
            int number = entry.first;
            int frequency = entry.second;

            frequencyNumberPairs.push_back({frequency, number});
        }

        // Sort in descending order based on frequency
        sort(frequencyNumberPairs.rbegin(), frequencyNumberPairs.rend());

        // Store the answer
        vector<int> answer;

        // Take the first k most frequent numbers
        for (int i = 0; i < k; i++)
        {
            answer.push_back(frequencyNumberPairs[i].second);
        }

        return answer;
    }
};
/*

ধরি,

n = array-এর মোট element সংখ্যা
m = unique (distinct) element-এর সংখ্যা
Time Complexity Analysis

১. Frequency Count

প্রথমে পুরো array একবার traverse করা হয় এবং প্রতিটি element-এর frequency hash map-এ সংরক্ষণ করা হয়।

Loop চলে n বার।
প্রতিবার hash map-এ insert/update করতে average O(1) সময় লাগে।

Complexity: O(n)

২. Hash Map থেকে Vector-এ Copy

এবার hash map-এর প্রতিটি entry vector-এ রাখা হয়।

এখানে loop n বার নয়, m বার চলে।
কারণ hash map-এ শুধু unique element থাকে।

Complexity: O(m)

৩. Sorting

Vector-এ মোট mটি element (frequency, number) pair থাকে।

এই mটি element sort করতে লাগে:

Complexity: O(m log m)

এটাই পুরো algorithm-এর সবচেয়ে expensive step।

৪. প্রথম kটি Element নেওয়া

Sorting শেষে প্রথম kটি element result-এ নেওয়া হয়।

Complexity: O(k)

Overall Time Complexity

সবগুলো যোগ করলে পাই:

O(n + m + m log m + k)

যেহেতু,

k ≤ m
m ≤ n

তাই dominant term হলো m log m।

সুতরাং,

Overall: O(n + m log m)
Worst Case (সব element unique হলে, m = n): O(n log n)
Space Complexity Analysis

এই algorithm-এ অতিরিক্ত memory ব্যবহার হয়:

Frequency hash map → O(m)
Vector of pairs → O(m)
Result vector → O(k)

মোট:

O(m + m + k)

যেহেতু k ≤ m, তাই simplify করলে:

Overall Space Complexity: O(m)

Worst case-এ m = n হলে:

Space Complexity: O(n) */
