#include <iostream>
#include <vector>

std::vector<int> findErrorNums(std::vector<int>& nums) {
    int n = nums.size();
    int xorAll = 0;
    int xorNums = 0;

    // Calculate the XOR of all numbers from 1 to n
    for (int i = 1; i <= n; ++i) {
        xorAll ^= i;
    }

    // Calculate the XOR of all elements in nums
    for (int num : nums) {
        xorNums ^= num;
    }

    // Calculate the XOR of the missing number and the duplicate number
    int xorDiff = xorAll ^ xorNums;

    // Find a set bit in the XOR result
    int bit = xorDiff & ~(xorDiff - 1);

    int missing = 0;
    int duplicate = 0;

    // Find the missing number and the duplicate number
    for (int i = 1; i <= n; ++i) {
        if ((i & bit) != 0) {
            missing ^= i;
        } else {
            duplicate ^= i;
        }
    }

    for (int num : nums) {
        if ((num & bit) != 0) {
            missing ^= num;
        } else {
            duplicate ^= num;
        }
    }

    return {duplicate, missing};
}

int main() {
    std::vector<int> nums = {1, 2, 2, 4};

    std::vector<int> result = findErrorNums(nums);

    std::cout << "Result: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}

