class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // handle noncomparision cases
        if (s.length()==0){return 0;}
        if (s.length()==1){return 1;}

        int leftIndex=0, rightIndex=0, maxLength = 1;
        
        for(int i = 1; i < s.length(); i++) {
            for(int j = leftIndex; j <= rightIndex; j++) {
                if (s[i] == s[j]) {
                    leftIndex = j+1;
                    rightIndex = i;
                    break;
                }
                if(j == rightIndex){
                    rightIndex+=1;
                    break; // without this for-loop will run again and cut off at the newly added character
                }
            }
            if((rightIndex-leftIndex+1) > maxLength) {
                maxLength = rightIndex-leftIndex+1;
            }
        }
        return maxLength;
    }
};
