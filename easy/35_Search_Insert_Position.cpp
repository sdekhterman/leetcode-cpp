class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lowIndex = 0;
        int midIndex = 0;
        int highIndex = nums.size() - 1;

        // corner cased that while loop misses
        if(nums[lowIndex] > target){
            return 0;
        }

        if(nums[highIndex] < target){
            return nums.size();
        }

        while(lowIndex <= highIndex) {
            midIndex = std::floor((highIndex - lowIndex)/2) + lowIndex;
            if((nums[midIndex] == target)){
                return midIndex;
            }

            // in between two numbers
            if(lowIndex == midIndex) {
                return midIndex+1;
            }

            if(nums[midIndex] < target) {
                lowIndex = midIndex;
            }

            if(nums[midIndex] > target) {
                highIndex = midIndex;
            }
        }
        return 0;
    }
};
