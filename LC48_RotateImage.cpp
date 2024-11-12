#include <iostream>

class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        size_t n = matrix.size();

        for (size_t i = 0; i < n / 2; ++i) {
            std::swap(matrix[i], matrix[n - i - 1]);
        }

        for (size_t i = 0; i < n; ++i) {
            for (size_t j = i + 1; j < n; ++j) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }
    }

    void print(std::vector<std::vector<int>>& matrix) {
        size_t n = matrix.size();

        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < n; ++j) {
                std::cout << matrix[i][j] << " ";
            }

            std::cout << std::endl;
        }
    }
};

int main() {
    std::vector<std::vector<int>> nums{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Solution ob;

    std::cout << "Matrix: " << std::endl;
    ob.print(nums);

    ob.rotate(nums);
    std::cout << std::endl;

    std::cout << "Rotated Matrix: " << std::endl;
    ob.print(nums);

    return 0;
}