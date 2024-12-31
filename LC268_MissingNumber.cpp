#include <iostream>
#include <vector>

class Solution {
public:
	int missingNumber(std::vector<int>& nums) {
		int res = nums[0];
		int size = nums.size();

		for (int i = 1; i < size; ++i) {
			res ^= nums[i] ^ i;
		}

		return res ^ size;
	}
};

int main() {
	std::vector<int> vec{9, 6, 4, 2, 3, 5, 7, 0, 1};
	
	Solution sol;

	std::cout << "Result: " << sol.missingNumber(vec) << std::endl;

	return 0;
}
