#include <iostream>

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        size_t n = nums.size();
        int dest = n - 1;

        for (size_t i = n - 2; i > 0; --i) {
            if (i + nums[i] >= dest) {
                dest = i;
            }
        }

        return dest == 0;
    }
};

int main() {
    std::vector<int> vec{2, 3, 1, 1, 4};

    Solution ob;
    std::cout << ob.canJump(vec) << std::endl;

    return 0;
}