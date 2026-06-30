class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::unordered_map<int, int> hash_map = {{nums[0], 0}};
        bool areValuesEqual = false;
        bool isWithinK      = false;
        for (int i = 1; i < nums.size(); ++i) {
            areValuesEqual = (nums[i] == nums[hash_map[nums[i]]]);
            isWithinK      = (abs(i - hash_map[nums[i]]) <= k);

            if (areValuesEqual && isWithinK) {
                return true;
            }
            hash_map[nums[i]] = i;
        }
        return false;
    }
};
