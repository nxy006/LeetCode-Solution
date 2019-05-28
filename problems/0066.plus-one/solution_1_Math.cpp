// Source: https://leetcode.com/problems/plus-one/
// Author: NaN
// Time: 2019-05-28

/*
 * Math:
 *   Use carry-over.
 * 
 * 数学解法：
 *   使用进位即可。
 * 
 *   时间复杂度：O(n)，空间复杂度：O(1)
 * 
 * Judge Result:
 *   Runtime: 4 ms, faster than 93.47% of C++ online submissions for Plus One.
 *   Memory Usage: 8.6 MB, less than 33.43% of C++ online submissions for Plus One.
 */

#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int temp = 1;
        for(int i = digits.size() - 1; i >= 0; i--) {
            if (temp == 0) break;
            digits[i] = digits[i] + temp;
            if (digits[i] >= 10) {
                digits[i] %= 10;
                temp = 1;
            } else {
                temp = 0;
            }
        }
        
        if (temp == 1) {
            digits.push_back(digits[digits.size() - 1]);
            for(int i = digits.size() - 1; i > 0; i--)  digits[i] = digits[i-1];
            digits[0] = 1;
        }
        
        return digits;
    }
};

int main() {
    vector<int> input_data;
    input_data.push_back(1);
    input_data.push_back(2);
    input_data.push_back(3);

    Solution solution;
    vector<int> ret = solution.plusOne(input_data);

    cout << "Output:";
    for (int i = 0; i < ret.size(); i++) cout << " " << ret[i];
}
