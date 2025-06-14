class Solution {
   
    const int  dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; 
    
public:
    int maxDistance(vector<vector<int>>& grid) {
        int rows  = grid.size(); 
        int  cols = grid[0].size(); 
        queue<pair<int, int>> landQueue;
        
 
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    landQueue.push({i, j});
                    grid[i][j] = 2; 
                }
            }
        }
        
         if (landQueue.empty()  || landQueue.size() == rows * cols)  { 
            return -1;
        }
        
        int  maxDistance = 0; 
        
       
        while (!landQueue.empty()) {
            int currentLevelSize = landQueue.size();
            
            
            for (int i = 0; i < currentLevelSize; i++) {
                auto [x, y] = landQueue.front();
                landQueue.pop();
                
                
                for (auto [dx, dy] : dirs) {
                    int nx = x + dx;
                    int ny = y + dy;
                    
                    
                    if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && grid[nx][ny] == 0) {
                        grid[nx][ny] = 2; 
                        landQueue.push({nx, ny});
                    }
                }
            }
            
            if (!landQueue.empty()) {
                maxDistance++;
            }
        }
        
        return maxDistance;
    }
};