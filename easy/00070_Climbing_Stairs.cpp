class Solution {
public:
    map<int, int> dict = {{1,1},{2,2},{3,3}};
    int climbStairs(int n) {
        // entries not already in the map have a value of zero
        if (dict[n] == 0) {
            dict[n] = climbStairs(n-1) + climbStairs(n-2);
        }
        return dict[n];
    }
};
