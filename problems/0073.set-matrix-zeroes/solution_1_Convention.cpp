// Source: https://leetcode.com/problems/set-matrix-zeroes/submissions/
// Author: NaN
// Time: 2019-05-30

/*
 * Math:
 *   First, find all place that its value is zero, reocrd their place (horizontal and vertical), 
 *   Then, for every recorded place (horizontal and vertical), set value of row or col to zero.
 * 
 *   Time complexity: O(n*m), Space complexity: O(n+m)
 * 
 * 常规解法：
 *   首先找到所有值为 0 的点，记录其横纵位置，再遍历所有找到的横纵位置，置对应的行、列为 0 值即可。
 * 
 *   时间复杂度：O(n*m)，空间复杂度：O(n+m)
 * 
 * Judge Result:
 *   Runtime: 52 ms, faster than 33.00% of C++ online submissions for Set Matrix Zeroes.
 *   Memory Usage: 11.5 MB, less than 47.23% of C++ online submissions for Set Matrix Zeroes.
 */

#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> >& matrix) {
        vector<int> x, y;
        
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == 0) {
                    x.push_back(i);
                    y.push_back(j);
                }
            }
        }
        if (x.size() == 0) return ;
        
        for (int i = 0; i < x.size(); i++) {
            if (i > 0 && x[i] == x[i-1]) continue;
            
            for (int j = 0; j < matrix[0].size(); j++) {
                matrix[x[i]][j] = 0;
            }
        }
        for (int i = 0; i < y.size(); i++) {
            if (i > 0 && y[i] == y[i-1]) continue;
            
            for (int j = 0; j < matrix.size(); j++) {
                matrix[j][y[i]] = 0;
            }
        }
    }
};

int main() {
    vector<vector<int> > input_data;
    vector<int> row_data;
    row_data.push_back(1);
    row_data.push_back(1);
    row_data.push_back(1);
    input_data.push_back(row_data);

    row_data.clear();
    row_data.push_back(1);
    row_data.push_back(0);
    row_data.push_back(1);
    input_data.push_back(row_data);

    row_data.clear();
    row_data.push_back(1);
    row_data.push_back(1);
    row_data.push_back(1);
    input_data.push_back(row_data);

    Solution solution;
    solution.setZeroes(input_data);

    cout << "Output:" << endl;
    for (int i = 0; i < input_data.size(); i++) {
        for (int j = 0; j < input_data[i].size(); j++) cout << input_data[i][j] << " ";
        cout << endl;
    }
}
