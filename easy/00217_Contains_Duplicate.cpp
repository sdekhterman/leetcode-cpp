class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std:unordered_map<int, int> hash_map;
        for (int i= 0; i< nums.size(); ++i) {
            if(hash_map[nums[i]] == 1) {
                return true;
            }
            hash_map[nums[i]] = 1;
        }
        return false;
    }
};
