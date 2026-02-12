class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater  = 0;
        int lowIndex  = 0;
        int highIndex = height.size()-1;
        while((highIndex - lowIndex) > 0) {
            int water = highIndex - lowIndex;
            if(height[lowIndex] < height[highIndex]) {
                water *= height[lowIndex];
            } else{
                water *= height[highIndex];
            }
            
            if(water > maxWater) {
                maxWater = water;
            }

            else if (height[highIndex] > height[lowIndex]) {
                lowIndex  += 1;
            } else {
                highIndex -= 1;
            }
        }
        return maxWater;
    }
};
