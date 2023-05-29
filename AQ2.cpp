#include <iostream>
#include <vector>

int removeElement(std::vector<int>& nums, int val) {
    int i = 0;
    int j = 0;

    while (i < nums.size()) {
        if (nums[i] != val) {
            nums[j] = nums[i];
            ++j;
        }
        ++i;
    }

    return j;
}

int main() {
    std::vector<int> nums = {3, 2, 2, 3};
    int val = 3;

    int count = removeElement(nums, val);

    std::cout << "Count: " << count << std::endl;
    std::cout << "nums: ";
    for (int i = 0; i < count; ++i) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

