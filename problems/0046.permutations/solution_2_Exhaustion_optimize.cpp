// Source: https://leetcode.com/problems/permutations/
// Author: NaN
// Time: 2019-05-23

/*
 * Method of exhaustion(optimize):
 *   Exhaustion vaildate whether vector include element or not is slow. Place exchange
 *     time, use additional vector record selectable infomation.
 * 
 *   Time complexity: O(n^2), Space complexity: O(n)
 * 
 * 穷举算法（优化）：
 *   遍历检查 vector 是否包含一个值的效率较低，以空间换时间，优化为使用辅助序列记录一个值是否被选中，
 *   可以在 O(1) 效率内完成检查。
 * 
 *   时间复杂度：O(n^2)，空间复杂度：O(n)
 * 
 * Judge Result:
 *   Runtime: 12 ms, faster than 95.42% of C++ online submissions for Permutations.
 *   Memory Usage: 9.4 MB, less than 54.69% of C++ online submissions for Permutations.
 */

#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > ret;
        vector<int> solution;
        vector<int> selected_flags;
        for(int i = 0; i < nums.size(); i++) selected_flags.push_back(0);

        nextPermutation(nums, selected_flags, ret, solution);
        return ret;
    }

    void nextPermutation(vector<int>& nums, vector<int>& selected_flags, vector<vector<int> >& ret, vector<int>& solution) {
        if (solution.size() == nums.size()){
            ret.push_back(solution);
        } else {
            for(int i = 0; i < nums.size(); i++) {
                if (selected_flags[i]) continue;

                solution.push_back(nums[i]);
                selected_flags[i] = 1;
                nextPermutation(nums, selected_flags, ret, solution);
                solution.pop_back();
                selected_flags[i] = 0;
            }
        }
    }
};

int main() {
    vector<int> input_data;
    input_data.push_back(1);
    input_data.push_back(2);
    input_data.push_back(3);

    Solution solution;
    vector<vector<int> > ret = solution.permute(input_data);

    for(int i = 0; i < ret.size(); i++) {
        cout << ret[i][0];
        for(int j = 1; j < ret[i].size(); j++) {
            cout << ", " << ret[i][j];
        }
        cout << endl;
    }
}
