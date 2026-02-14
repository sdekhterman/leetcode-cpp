class Solution {
public:
    int singleNumber(vector<int>& nums) {
       int singleValue = 0;
       for( int i : nums) {
            singleValue ^= i;
       }
       return singleValue;
    }
};
