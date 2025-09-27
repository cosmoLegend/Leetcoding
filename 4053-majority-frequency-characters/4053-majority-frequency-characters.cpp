class Solution {
public:
    string majorityFrequencyGroup(string s) {
        vector<int> freq(26, 0);
        for (char c : s)
            freq[c - 'a']++;

        
        unordered_map<int, int> countMap;

        int chosenFreq = -1; 
        int maxSize = 0;    

        for (int f : freq) {
            if (f == 0)
                continue;

            int newCount = ++countMap[f];

            
            if (newCount > maxSize || (newCount == maxSize && f > chosenFreq)) {
                maxSize = newCount;
                chosenFreq = f;
            }
        }

        // Collect all letters having the chosen frequency
        string res;
        for (int i = 0; i < 26; i++) {
            if (freq[i] == chosenFreq)
                res.push_back('a' + i);
        }

        return res;
    }
};