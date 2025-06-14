#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Solution {
 public:
    int   snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
         int totalSquares = n * n;

         auto getCoordinates = [&](int position) -> pair<int, int> {
             int rowFromBottom = (position - 1) / n;
            int  row = n - 1 - rowFromBottom;
             int col = (position - 1) % n;
            if (rowFromBottom % 2 == 1) {
                col = n - 1 - col;
            }
              return {row, col};
        };

         vector<bool> visited(totalSquares + 1, false);
         queue<int> bfsQueue;
          bfsQueue.push(1);
          visited[1] = true;

        int   moves = 0;
         while   (!bfsQueue.empty()) {
            int   levelSize = bfsQueue.size();

            for  (int i = 0; i < levelSize; ++i) {
                   int current = bfsQueue.front();
                  bfsQueue.pop();

                if  (current == totalSquares) {
                    return moves;
                }

                for (int roll = 1; roll <= 6; ++roll) {
                    int next = current + roll;
                    if (next > totalSquares) continue;

                    auto  [row, col] = getCoordinates(next);
                    int  destination = (board[row][col] != -1) ? board[row][col] : next;

                    if   (!visited[destination]) {
                        visited[destination] = true;
                         bfsQueue.push(destination);
                    }
                }
            }

            moves++;
        }

        return -1; 
    }
};
