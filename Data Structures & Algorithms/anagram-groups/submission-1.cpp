class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;

        // Traverse each string one by one.
        // Runs n times, where n = number of strings.
        for (const auto& s : strs) {

            // Frequency array for letters 'a' to 'z'.
            // Size is fixed (26), so creating it is O(1).
            vector<int> count(26, 0);

            // Count the frequency of each character in the current string.
            // If the current string has length k, this loop runs k times.
            // Complexity: O(k)
            for (char c : s) {
                count[c - 'a']++;
            }

            // Build a unique key from the frequency array.
            string key = to_string(count[0]);

            // This loop always runs exactly 25 times (indices 1 to 25).
            // Since 25 is a constant, its complexity is O(1), NOT O(n).
            for (int i = 1; i < 26; ++i) {
                key += "," + to_string(count[i]);
            }

            // Store the string in its corresponding anagram group.
            res[key].push_back(s);
        }

        vector<vector<string>> result;

        // Copy all groups from the hash map into the answer.
        // If there are g groups, this loop runs g times (g <= n).
        for (const auto& pair : res) {
            result.push_back(pair.second);
        }

        return result;
        
    }
};
