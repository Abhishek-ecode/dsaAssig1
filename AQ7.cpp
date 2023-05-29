#include <iostream>
#include <vector>

void moveZeroes(std::vector<int>& nums) {
    int left = 0;
    int right = 0;

    while (right < nums.size()) {
        if (nums[right] != 0) {
            std::swap(nums[left], nums[right]);
            left++;
        }
        right++;
    }

    while (left < nums.size()) {
        nums[left] = 0;
        left++;
    }
}

int main() {
    std::vector<int> nums = {0, 1, 0, 3, 12};

    moveZeroes(nums);

    std::cout << "Result: ";
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}

