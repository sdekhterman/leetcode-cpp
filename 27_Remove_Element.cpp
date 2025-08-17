class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // track number of elements vs pointer at the back of the list
        int backPointer  = nums.size();

        // go up to number of original number
        for(int i = 0; i < backPointer; i++) {
            // check  when need to swap values
            if(nums[i] == val){
                // used to find the next original value in the in the back of the list to swap 
                // with no overlap  with front pointer i
                do{
                    backPointer--;
                    if(backPointer == 0 || backPointer ==i) {
                        break;
                    }
                }
                while(nums[backPointer] == val);
                nums[i] = nums[backPointer];

            }
            
        }
        return backPointer;
    }
};
