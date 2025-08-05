class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        // go through the string
        for(int i = 0; i < s.length(); i++){
            // add newest open bracket to stack
            if((s[i] == '(') || (s[i] == '{') || (s[i] == '[')){st.push(s[i]); continue;}
            // cover edge case where no open brackets
            if(st.size() == 0) {return false;}
            //removed matching open bracket from stack
            if((st.top() == '(') && (s[i] == ')')){st.pop();}
            else if((st.top() == '{') && (s[i] == '}')){st.pop();}
            else if((st.top() == '[') && (s[i] == ']')){st.pop();}
            // cover edge case where there are mismatching open and closing bracket.
            else{return false;}
        }
        return (st.size() == 0);
    }
};
