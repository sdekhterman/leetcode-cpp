class Solution {
public:
    int strStr(string haystack, string needle) {
        // two pointer (index) algoithm
        for(int i = 0; i < haystack.size(); i++){
            if(haystack[i] == needle[0]){
                for(int j = 0; j < needle.size(); j++){
                    if((haystack[i+j] == haystack.size()) || (haystack[i+j] != needle[j])) {break;}
                    if(needle.size() == (j+1)) {return i;}
                }
            }
        }
        return -1;
    }
};
