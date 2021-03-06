#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// similar to 153-FindMinimumInRotatedSortedArray
//
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.empty()) return -1;
        int left = 0, right = nums.size()-1;
        while (left < right) { // why < rather than <=, try case [1]
            int mid = left + (right-left)/2;
            if (nums[mid] < nums[mid+1]) // if nums[mid] < nums[mid+1], there must be a peak in nums[mid+1,...,right]
                left = mid+1;
            else // if nums[mid] > nums[mid+1], there must be a peak in nums[left,...,mid]
                right = mid;
        }
        return left;
    }
};


int main() {
    Solution s;
    vector<int> nums = {1,2};
    cout << s.findPeakElement(nums) << endl;
    return 0;
}
