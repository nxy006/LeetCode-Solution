// Source: https://leetcode.com/problems/permutations/
// Author: NaN
// Time: 2019-05-23

/*
 * Method of exhaustion:
 *   Exhaustion by backtrack achieved, for every place try every possible value.
 *   Time complexity: O(n^2), Space complexity: O(n)
 * 
 * 穷举算法：
 *   回溯法实现的穷举算法，为每个位置遍历所有可能性。
 *   时间复杂度：O(n^2)，空间复杂度：O(n)
 * 
 * Judge Result:
 *   Runtime: 28 ms, faster than 7.57% of C++ online submissions.
 *   Memory Usage: 10.4 MB, less than 11.71% of C++ online submissions.
 */

#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > ret;
        vector<int> solution;
        nextPermutation(nums, ret, solution);
        return ret;
    }

    void nextPermutation(vector<int>& nums, vector<vector<int> >& ret, vector<int>& solution) {
        if (solution.size() == nums.size()){
            ret.push_back(solution);
        } else {
            for(int i = 0; i < nums.size(); i++) {
                if (checkExist(solution, nums[i])) continue;

                solution.push_back(nums[i]);
                nextPermutation(nums, ret, solution);
                solution.pop_back();
            }
        }
    }

    bool checkExist(vector<int> solution, int target) {
        for(int i = 0; i < solution.size(); i++) {
            if (solution[i] == target) return true;
        }
        return false;
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
