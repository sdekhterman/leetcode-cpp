class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // one var to track how far ahead the next unique number is and one to track the total number of unique numbers 
        int gap = 0;
        int uniqueNum = 1;

        // check for edge cases so my for loop search doesn't get an index out of bounds error
        if (nums.size() == 0) {return 0;}
        if (nums.size() == 1) {return 1;}

        for(int i = 1; i < nums.size(); i++){
            // find how far ahead the next unique value is and override all repeats from current index to that next number's index
            if(nums[i-1] == nums[i]){
                gap = 0;
                while(nums[i]==nums[i+gap]){
                    if( (i+gap+1) == (nums.size()) ){break;}
                    gap++;
                }
                for(int j=i; j < (i+gap); j++){
                    nums[j] = nums[i+gap];
                }
            }
            // after override as otherwise overrides numbers wouldn't be counted
            if(nums[i-1] != nums[i]){uniqueNum++;}
        }
        return uniqueNum;
    }
};
