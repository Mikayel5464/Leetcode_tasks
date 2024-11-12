#include <iostream>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int result = 0;

        for (int i : nums) {
            result ^= i;
        }

        return result;
    }
};

int main() {
    std::vector<int> vec{4, 1, 2, 1 ,2};
    Solution ob;

    std::cout << "Single number: " << ob.singleNumber(vec) << std::endl;

    return 0;
}