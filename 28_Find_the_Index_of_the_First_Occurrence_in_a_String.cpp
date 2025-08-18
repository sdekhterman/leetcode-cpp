class Solution {
public:
    int strStr(string haystack, string needle) {
        int subIndex = 0;
        for(int i = 0; i < haystack.size(); i++){
            if(haystack[i] == needle[subIndex]){
                cout<< needle[subIndex];
                subIndex++;
                if(subIndex == needle.size()){
                    return i+1-needle.size();
                }
            } else{
                subIndex = 0;
            }

        }
        return -1;
    }
};
