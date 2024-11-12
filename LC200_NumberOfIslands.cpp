#include <iostream>

class Solution {
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        size_t n = grid.size();
        size_t m = grid[0].size();
        size_t cnt = 0;

        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < m; ++j) {
                if (grid[i][j] == '1') {
                    ++cnt;
                    sincIsland(grid, i, j);
                }
            }
        }

        return cnt;
    }

    void sincIsland(std::vector<std::vector<char>>& grid, size_t i, size_t j) {
        if (grid[i][j] == '0') {
            return;
        }

        grid[i][j] = '0';

        if (i > 0) {
            sincIsland(grid, i - 1, j);
        }
        
        if (j > 0) {
            sincIsland(grid, i, j - 1);
        }

        if (i < grid.size() - 1) {
            sincIsland(grid, i + 1, j);
        }

        if (j < grid[0].size() - 1) {
            sincIsland(grid, i, j + 1);
        }
    }
};

int main() {
    std::vector<std::vector<char>> grid {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    Solution ob;

    std::cout << "Number of islands: " << ob.numIslands(grid) << std::endl;

    return 0;
}