class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        // Sort the array. The common prefix of the whole array must be 
        // a prefix of both the first and last strings after sorting.
        sort(strs.begin(), strs.end());
        string first = strs.front();
        string last = strs.back();
        int i = 0;

        // Compare characters until mismatch
        while (i < first.size() && i < last.size() && first[i] == last[i]) {
            i++;
        }
        return first.substr(0, i);
    }
};
