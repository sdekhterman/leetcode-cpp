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
// my second attempt where I implement breadth-first search
# include <queue>
class Solution {
public:
    void addLand(vector<vector<int>>& grid, queue <vector<int>>& neighboringLand, 
                 int i, int j) {
        if(grid[i][j] == 1) {
            vector<int> neighbor = {i, j}; 
            neighboringLand.push(neighbor); 
            grid[i][j] = 2;
        }
    }
    void addWater(vector<vector<int>>& grid, queue <vector<int>>& neighboringWater, 
                   int i, int j) {
        if(grid[i][j] == 0) {
            vector<int> neighbor = {i, j}; 
            neighboringWater.push(neighbor); 
            grid[i][j] = -1;
        }
    }
    void waterBFS_step (vector<vector<int>>& grid, 
                          queue <vector<int>>& neighboringLand, 
                          queue <vector<int>>& neighboringWater, 
                          int i, int j) {
        addLand( grid,  neighboringLand, i, j);
        addWater(grid, neighboringWater, i, j);
    }
    
    void landBFS_step(vector<vector<int>>& grid, queue <vector<int>>& neighboringLand, 
                 int i, int j, int& perimeter) {
        if (grid[i][j] > 0) {
            perimeter -= 1;
            addLand(grid, neighboringLand, i, j);
        }
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int i                = grid.size()   /2;
        int j                = grid[0].size()/2;
        vector<int> neighbor = {i, j};

        bool landFound       = grid[i][j];
        queue <vector<int>> neighboringWater;
        queue <vector<int>> neighboringLand;
        
        if (landFound){ neighboringLand.push(neighbor); grid[i][j] =  2;}
        else {       neighboringWater.push(neighbor); grid[i][j] = -1;}
        
        vector<int> current  = {i, j};
        while(neighboringLand.empty() && (!neighboringWater.empty())){
            current = neighboringWater.front();
            i       = current[0];
            j       = current[1];
            neighboringWater.pop();
            if ((i + 1) < grid.size()) {
                waterBFS_step (grid,neighboringLand, neighboringWater, i+1, j);
            }
            if ((i - 1) >= 0) {
                waterBFS_step (grid,neighboringLand, neighboringWater, i-1, j);
            }
            if ((j + 1) < grid[0].size()) {
                waterBFS_step (grid,neighboringLand, neighboringWater, i, j+1);
            }
            if ((j - 1) >= 0) {
                waterBFS_step (grid,neighboringLand, neighboringWater, i, j-1);
            }
        }
        
        int perimeter = 0;
        while(!neighboringLand.empty()){
            current = neighboringLand.front();
            i       = current[0];
            j       = current[1];
            neighboringLand.pop();
            perimeter += 4;
            if ((i + 1) < grid.size()) {
                landBFS_step(grid, neighboringLand, i+1, j, perimeter);
            }
            if ((i - 1) >= 0) {
                landBFS_step(grid, neighboringLand, i-1, j, perimeter);
            }
            if ((j + 1) < grid[0].size())  {
                landBFS_step(grid, neighboringLand, i, j+1, perimeter);
            }
            if ((j - 1) >= 0) {
                landBFS_step(grid, neighboringLand, i, j-1, perimeter);
            }
            
        }
        return perimeter;
    }
};


// my third attempt where I implement depth-first search

class Solution {
public:
    void dfsRecursiveStep(vector<vector<int>>& grid, int i, int j, int& perimeter, bool touchingLand) {
        cout << i << ", " << j << ", " << grid[i][j] << endl;
        if (!touchingLand) {
            if(1 == grid[i][j]) {touchingLand = true;}
            if (!touchingLand) {
                if(0 == grid[i][j]) {
                    grid[i][j]   = -1;
                    touchingLand = false;
                    if ((i + 1) < grid.size()) {
                        if((0 == grid[i+1][j]) || (1 == grid[i+1][j])) {
                            dfsRecursiveStep(grid, i+1, j, perimeter, touchingLand);
                        }
                    }
                    if ((j + 1) < grid[0].size())  {
                        if((0 == grid[i][j+1]) || (1 == grid[i][j+1])) {
                            if (grid[i][j+1] > 0) {perimeter -= 1;}
                            dfsRecursiveStep(grid, i, j+1, perimeter, touchingLand);
                        }
                    }
                    if ((i - 1) >= 0) {
                        if((0 == grid[i-1][j]) || (1 == grid[i-1][j])) {
                            if (grid[i-1][j] > 0) {perimeter -= 1;}
                            dfsRecursiveStep(grid, i-1, j, perimeter, touchingLand);
                        }
                    }
                    if ((j - 1) >= 0) {
                        if((0 == grid[i][j-1]) || (1 == grid[i][j-1])) {
                            if (grid[i][j-1] > 0) {perimeter -= 1;}
                            dfsRecursiveStep(grid, i, j-1, perimeter, touchingLand);
                        }
                    }
                }
            }
        }
        if (touchingLand) {
            if(1 == grid[i][j]) {
                grid[i][j]   = 2;
                perimeter   += 4; 
                touchingLand = true;

                if ((i + 1) < grid.size()) {
                    if(1 == grid[i+1][j]) {
                        dfsRecursiveStep(grid, i+1, j, perimeter, touchingLand);
                    }
                }
                if ((j + 1) < grid[0].size())  {
                    if(1 == grid[i][j+1]) {
                        if (grid[i][j+1] > 0) {perimeter -= 1;}
                        dfsRecursiveStep(grid, i, j+1, perimeter, touchingLand);
                    }
                }
                if ((i - 1) >= 0) {
                    if(1 == grid[i-1][j]) {
                        if (grid[i-1][j] > 0) {perimeter -= 1;}
                        dfsRecursiveStep(grid, i-1, j, perimeter, touchingLand);
                    }
                }
                if ((j - 1) >= 0) {
                    if(1 == grid[i][j-1]) {
                        if (grid[i][j-1] > 0) {perimeter -= 1;}
                        dfsRecursiveStep(grid, i, j-1, perimeter, touchingLand);
                    }
                }
            }
            
        }
        // TODO: mak grid and perimeter class vars so they don't need to passed every function call to save on memory overhead. 
            
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int i             = grid.size()   /2;
        int j             = grid[0].size()/2;
        int perimeter     = 0;
        bool touchingLand = grid[i][j];
        dfsRecursiveStep(grid, i, j, perimeter, touchingLand);

        return perimeter;
    }
};
