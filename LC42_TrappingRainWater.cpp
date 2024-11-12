#include <iostream>

class Solution {
public:
    int trap(std::vector<int>& height) {
        size_t i = 0;
        size_t j = height.size() - 1;
        int val = 0;
        int l_max = height[i];
        int r_max = height[j];

        while (i < j) {
            if (height[i] >= height[j]) {
                --j;
                if (height[j] > r_max) {
                    r_max = height[j];
                }

                val += r_max - height[j];
            }
            else {
                ++i;
                
                if (height[i] > l_max) {
                    l_max = height[i];
                }

                val += l_max - height[i];
            }
        }

        return val;
    }
};

int main() {
    std::vector vec{0, 1, 2, 1, 0, 1, 0, 2, 3, 2, 2, 4, 1, 0, 0, 1, 1, 0, 1, 0};
    Solution ob;

    std::cout << "Result: " << ob.trap(vec) << std::endl;
    return 0;
}