class Solution {
public:
    int lengthOfLastWord(string s) {
        // edge case: empty 
        if(s.empty()) {return 0;}
        
        while(s.back() == ' ') {
            s.pop_back();
        }
        
        // edge case: just spaces 
        if(s.empty()) {return 0;}
        
        int length = 0;
        while(s.back() != ' '){
            s.pop_back();
            length++;

            // edge case: no spaces before one word 
            if(s.empty()) {break;}
        }
        return length;

    }
};
