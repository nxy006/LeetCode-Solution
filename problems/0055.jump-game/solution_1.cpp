// Source: https://leetcode.com/problems/maximum-subarray/
// Author: NaN
// Time: 2019-05-23

/*
 * Some Method:
 *   (Wait...)
 *   Time complexity: O(n), Space complexity: O(1)
 * 
 * 
 * 模拟解法：
 *   以几何的角度考虑，本题是在一个数轴上，以各个点为圆心，以给出的值为半径画圆，最终看整个数轴上是否有不相连接的部分。
 *   因此，
 * 
 * Judge Result:
 *   Runtime: 8 ms, faster than 99.17% of C++ online submissions for Jump Game.
 *   Memory Usage: 9.9 MB, less than 72.23% of C++ online submissions for Jump Game.
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_place = nums[0];
        for(int i = 0; i < nums.size(); i++) {
            if (i > max_place) return false;
            if (i + nums[i] > max_place) max_place = i + nums[i];
            if (max_place >= nums.size()) return true;
        }

        return true;
    }
};

int main() {
    vector<int> input_data;
    input_data.push_back(2);
    input_data.push_back(3);
    input_data.push_back(1);
    input_data.push_back(1);
    input_data.push_back(4);

    Solution solution;
    bool ret = solution.canJump(input_data);

    cout << "Output: " << ret << endl;
}
