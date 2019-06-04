// Source: https://leetcode.com/problems/search-insert-position/
// Author: NaN
// Time: 2019-06-04

/*
 * Method of exhaustion:
 *   Exhaustion, check correct value for every place.
 * 
 *   Time complexity: O(n), Space complexity: O(1)
 * 
 * 穷举法：
 *   穷举算法，检查每个值直到找到合适的位置。
 * 
 *   时间复杂度：O(n)，空间复杂度：O(1)
 * 
 * Judge Result:
 *   Runtime: 8 ms, faster than 88.43% of C++ online submissions for Search Insert Position.
 *   Memory Usage: 9 MB, less than 54.16% of C++ online submissions for Search Insert Position.
 */

#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++) {
            if (nums[i] >= target) return i;
        }
        return nums.size();
    }
};

int main() {
    vector<int> input_data;
    input_data.push_back(1);
    input_data.push_back(3);
    input_data.push_back(5);
    input_data.push_back(6);

    Solution solution;
    cout << "Output: " << solution.searchInsert(input_data, 5) << endl;
}
