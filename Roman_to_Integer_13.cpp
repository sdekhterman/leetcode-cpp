class Solution {
public:
    int romanToInt(string s) {
        int exception = 0, Is = 0, Vs = 0, Xs = 0, Ls = 0, Cs = 0, Ds = 0, Ms = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'I') {Is += 1;}
            if (s[i] == 'V') {Vs += 1;}
            if (s[i] == 'X') {Xs += 1;}
            if (s[i] == 'L') {Ls += 1;}
            if (s[i] == 'C') {Cs += 1;}
            if (s[i] == 'D') {Ds += 1;}
            if (s[i] == 'M') {Ms += 1;}
        }
        return exception + Is * 1 + Vs * 5 + Xs * 10 + Ls * 50 + Cs * 100 + Ds * 500 + Ms * 1000;
    }
};
