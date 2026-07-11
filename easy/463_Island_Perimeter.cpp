// my first attempt before implementing this with a random starting location and breath/depth first search
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if(1 == grid[i][j]) {
                    perimeter += 4;
                    // if valid index land up
                    if ((i + 1) < grid.size()){
                        perimeter -= grid[i + 1][j];
                    }
                    // ... down
                    if ((i - 1) >= 0){
                        perimeter -= grid[i - 1][j];
                    }
                    // ... left 
                    if ((j + 1) < grid[0].size()) {
                        perimeter -= grid[i][j+1];
                    }
                    // ... right
                    if ((j - 1) >= 0) {
                        perimeter -= grid[i][j - 1];
                    }
                }
            }
        }
        return perimeter;
    }
};
