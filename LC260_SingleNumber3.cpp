#include <iostream>

class Solution {
public:
    std::vector<int> singleNumber(std::vector<int>& nums) {
        long res = 0;
        size_t n = nums.size();

        for (size_t i = 0; i < n; ++i) {
            res ^= nums[i];
        }

        long mask = res & (-res);

        int v1 = 0;
        int v2 = 0;

        for (size_t i = 0; i < n; ++i) {
            if (nums[i] & mask) {
                v1 ^= nums[i];
            } else {
                v2 ^= nums[i];
            }
        }

        return {v1, v2};
    }

    void print(std::vector<int>& nums) {
        size_t size = nums.size();

        for (size_t i = 0; i < size; ++i) {
            std::cout << nums[i] << " ";
        }

        std::cout << std::endl;
    }
};

int main() {
    std::vector<int> vec1{1, 2, 1, 3, 2, 5};
    //std::vector<int> vec2{-1, 0};
    
    Solution ob;
    std::cout << "Start: " << std::endl;
    ob.print(vec1);

    std::cout << std::endl;

    std::vector<int> result_vec = ob.singleNumber(vec1);
    std::cout << "Result: " << std::endl;
    ob.print(result_vec);

    return 0;
}