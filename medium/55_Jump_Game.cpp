class Solution {
public:
    bool canJump(vector<int>& nums) {
        // O(1) - O(n^2) because why we want a consistant O(n)
        // Base cases to avoid loop logic
        if(nums.empty()  ){return false;}
        if(nums.size()==1){return true;}

        for(int i = 0; i < (nums.size()-1);){
            if(nums[i] == 0){
                // look back from 0 item index
                int dist = 0;
                for(int j = i; j >= 0; j--){
                    if(nums[j] > dist) {break;}
                    dist++;
                    if(j==0){return false;}
                }
                i+=1;
            }
            else if((i+nums[i]) > (nums.size()-1)){
                i = nums.size()-1; // make sure index valid as we skip
            } else {
                i += nums[i];
            }
        }
        return true;
    }
};
