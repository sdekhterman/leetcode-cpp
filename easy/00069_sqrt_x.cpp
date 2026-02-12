#include <iostream>
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) {return 0;}
        int root  = 1;
        int sub_limit = 3;
        int limit = sub_limit;

        while (limit < x) {
            root++;
            sub_limit += 2;
            if(sub_limit == 92681) {break;}
            limit += sub_limit;
        }
        return root;
    }
};
