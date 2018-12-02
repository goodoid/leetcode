#include <vector>
#include <iostream>

using std::vector;
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(int obstacleGrid[3][3]) {
        int n = 3;//obstacleGrid.size();
        int m = 3;//obstacleGrid[0].size();
        int path_record[n][m];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (1 == obstacleGrid[i][j]) {
                    path_record[i][j] = 0;
                    std::cout<<i<<","<<j<<":"<<path_record[i][j]<<std::endl;
                    continue;
                }
                if (0 == i && 0 == j) {
                    path_record[i][j] = 1;
                    std::cout<<i<<","<<j<<":"<<path_record[i][j]<<std::endl;
                    continue;
                }
                int upper_path = 0;
                if (i > 0) {
                    upper_path = path_record[i-1][j];
                }
                int left_path = 0;
                if (j > 0) {
                    left_path = path_record[i][j-1];
                }
                path_record[i][j] = upper_path + left_path;
                std::cout<<i<<","<<j<<":"<<path_record[i][j]<<std::endl;
            }
        }
        return path_record[n-1][m-1];
    }
};

int main() {
  Solution s;
  int a[3][3] = {{0,0,0},{0,1,0},{0,0,0}};
  std::cout<<s.uniquePathsWithObstacles(a)<<std::endl;
}
