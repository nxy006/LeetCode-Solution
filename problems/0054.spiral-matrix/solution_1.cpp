// Source: https://leetcode.com/problems/maximum-subarray/
// Author: NaN
// Time: 2019-05-23

/*
 * Some Method:
 *   (Wait...)
 *   Time complexity: O(n), Space complexity: O(1)
 * 
 * 模拟算法（递归实现）：
 *   模拟算法强行模拟执行过程，按右、下、左、上顺序移动，如果越过可用范围则转向，并缩小可用范围（行列的最大最小范围），
 *   直到找不到符合条件的值为止。
 * 
 *   时间复杂度：？，空间复杂度：？
 * 
 * Judge Result:
 *   Runtime: 4 ms, faster than 92.93% of C++ online submissions for Spiral Matrix.
 *   Memory Usage: 9.7 MB, less than 5.08% of C++ online submissions for Spiral Matrix.
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> ret;
        if (matrix.size()) nextPlace(matrix, 0, 0, 0, matrix.size()-1, 0, matrix[0].size()-1, 0, ret);
        return ret;
    }

    void nextPlace(vector<vector<int> > matrix, int row, int col, int min_row, int max_row, int min_col, int max_col, int direction, vector<int>& ret) {
        if (row < min_row || row > max_row || col < min_col || col > max_col) return ;
        ret.push_back(matrix[row][col]);

        // walking
        switch(direction) {
            case 0: col++; break;   // right
            case 1: row++; break;   // down
            case 2: col--; break;   // left
            case 3: row--; break;   // up
        }

        // change direction
        if (col > max_col)      {col--; row++; min_row++; direction = 1;}
        else if (row > max_row) {row--; col--; max_col--; direction = 2;}
        else if (col < min_col) {col++; row--; max_row--; direction = 3;}
        else if (row < min_row) {row++; col++; min_col++; direction = 0;}
        nextPlace(matrix, row, col, min_row, max_row, min_col, max_col, direction, ret);
    }
};

int main() {
    vector<vector<int> > input_data;
    vector<int> row_data;
    row_data.push_back(1);
    row_data.push_back(2);
    row_data.push_back(3);
    input_data.push_back(row_data);

    row_data.clear();
    row_data.push_back(4);
    row_data.push_back(5);
    row_data.push_back(6);
    input_data.push_back(row_data);

    row_data.clear();
    row_data.push_back(7);
    row_data.push_back(8);
    row_data.push_back(9);
    input_data.push_back(row_data);

    Solution solution;
    vector<int> ret = solution.spiralOrder(input_data);

    cout << "Output:";
    for(int i = 0; i < ret.size(); i++)
        cout << " " << ret[i];
}
