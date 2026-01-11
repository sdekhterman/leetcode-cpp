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
            cout << height[lowIndex] << " and " << height[highIndex] << " and " << water << endl;
            if(water > maxWater) {
                maxWater = water;
            }

            int lowInc  = (height[lowIndex]  < height[lowIndex +1]);
            int highInc = (height[highIndex] < height[highIndex-1]);
            if        ( lowInc & !highInc) {
                lowIndex  += 1;
            } else if (!lowInc &  highInc) {
                highIndex -= 1;
            } else {
                if (height[highIndex-1] == height[lowIndex+1]) {
                    int lowIncStep  = height[lowIndex +1] - height[lowIndex];
                    int highIncStep = height[highIndex-1] - height[highIndex];
                    if(lowIncStep > highIncStep) {
                        lowIndex  += 1;
                    } else {
                        highIndex -= 1;
                    }
                }
                else if (height[highIndex-1] > height[lowIndex+1]) {
                    lowIndex  += 1;
                } else {
                    highIndex -= 1;
                }
            }
        }
        return maxWater;
    }
};
