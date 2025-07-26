class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // strings init empty, i.e. = ''
        string prefix;
        // first string used due to given problem const.
        for (int i = 0; i< strs[0].length(); i++) {
            //start at j=1 so all chars don't match with the first string
            for (int j = 1; j< strs.size(); j++) {
                if (strs[0][i] != strs[j][i]){
                    return prefix; // return early if pattern broken
                }
            }
            prefix+=strs[0][i]; // add char if matches with each string
        }
        return prefix;
    }
};
