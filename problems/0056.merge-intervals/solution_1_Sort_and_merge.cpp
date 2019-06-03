// Source: https://leetcode.com/problems/merge-intervals/
// Author: NaN
// Time: 2019-06-01

/*
 * Sort and merge:
 *   Sort data by start index ascending order, and check every data whather can expand current
 *   interval, if exceed range of current interval then create new interval.
 * 
 *   Time complexity: O(n), Space complexity: O(n)
 * 
 * 排序后合并：
 *   将数据按开始位置升序排列，依次判断每个数据是否可以拓展当前序列，如过超出范围则开始新的的序列。
 * 
 *   时间复杂度：O(n)，空间复杂度：O(n)
 * 
 * Judge Result:
 *   Runtime: 16 ms, faster than 75.90% of C++ online submissions for Merge Intervals. 
 *   Memory Usage: 12.5 MB, less than 13.05% of C++ online submissions for Merge Intervals.
 */

#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ret;
        vector<int> current_interval;
        if (intervals.size() == 0) return ret;
        
        sort(intervals.begin(), intervals.end(), lessmark);
        
        current_interval = intervals[0];
        for(int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= current_interval[0] && intervals[i][0] <= current_interval[1]) {
                if (intervals[i][1] > current_interval[1]) current_interval[1] = intervals[i][1];
            } else {
                ret.push_back(current_interval);
                current_interval = intervals[i];
            }
        }
        ret.push_back(current_interval);
        
        return ret;
    }

private:
    static bool lessmark(const vector<int>& item1, const vector<int>& item2) {
         return item1[0] < item2[0];
     }
};

int main() {
    vector<vector<int> > input_data;
    vector<int> row_data;
    row_data.push_back(1);
    row_data.push_back(3);
    input_data.push_back(row_data);

    row_data.clear();
    row_data.push_back(2);
    row_data.push_back(6);
    input_data.push_back(row_data);

    row_data.clear();
    row_data.push_back(8);
    row_data.push_back(10);
    input_data.push_back(row_data);

    row_data.clear();
    row_data.push_back(15);
    row_data.push_back(18);
    input_data.push_back(row_data);

    Solution solution;
    vector<vector<int> > ret = solution.merge(input_data);

    cout << "Output:" << endl;
    for (int i = 0; i < ret.size(); i++) cout << ret[i][0] << ", " << ret[i][0] << endl;
}
