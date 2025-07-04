class Solution {
public:
    int detonate(vector<vector<int>>& bombs, vector<bool>& detonated, int i) {
        int ans = 0, n = bombs.size();
        for(int j = 0; j < n; j++){
            if(!detonated[j]){
                int x1 = bombs[i][0], y1 = bombs[i][1], r1 = bombs[i][2];
                int x2 = bombs[j][0], y2 = bombs[j][1], r2 = bombs[j][2];
                long dist = pow(x1- x2, 2) + pow(y1 -y2, 2);

                if(dist <= (long) r1 *r1){
                    detonated[j] = true;
                    ans += 1 + detonate(bombs, detonated, j);
                }
            }
        }
        return ans;
    }
     int maximumDetonation(vector<vector<int>>& bombs) {
        int maxDetonated = 0, n = bombs.size();

        for(int i = 0; i < n; i++){
            vector<bool>detonated(n, false);
            detonated[i] = true;
            int curr = 1 + detonate(bombs, detonated, i);
            maxDetonated = max(maxDetonated, curr);
        }
        return maxDetonated;
     }
};