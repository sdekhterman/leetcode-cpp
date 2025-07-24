class Solution {
public:
    int romanToInt(string s) {
        // value of each character and a running total 
        const int iVal = 1, vVal = 5, xVal = 10, lVal = 50, cVal = 100, dVal = 500, mVal = 1000;
        int total = 0;

        // need to start from leftmost char to catch subtraction exceptions
        for (int i = 0; i < s.length(); i++) {
            // handle the subtraction exceptions (example 4 = IV, I = 1 V = 5)
            if(i<(s.length()-1)){
                if((s[i] == 'I')&&((s[i+1] == 'V') || (s[i+1] == 'X'))){
                    total -= iVal; i++;
                }
                if((s[i] == 'X')&&((s[i+1] == 'L') || (s[i+1] == 'C'))){
                    total -= xVal; i++;
                }
                if((s[i] == 'C')&&((s[i+1] == 'D') || (s[i+1] == 'M'))){
                    total -= cVal; i++;
                }
            }

            // add char to count normally otherwise
            if (s[i] == 'I') {total += iVal;}
            if (s[i] == 'V') {total += vVal;}
            if (s[i] == 'X') {total += xVal;}
            if (s[i] == 'L') {total += lVal;}
            if (s[i] == 'C') {total += cVal;}
            if (s[i] == 'D') {total += dVal;}
            if (s[i] == 'M') {total += mVal;}
        }
        return total;
    }
};
