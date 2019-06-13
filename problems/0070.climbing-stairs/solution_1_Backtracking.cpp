// Source: https://leetcode.com/problems/climbing-stairs/
// Author: NaN
// Time: 2019-06-03

/*
 * Backtracking:
 *   The following is formula as we can know, achieve and reocrd middle answer.
 *     | climbStairs(n) = climbStairs(n - 1) + climbStairs(n - 2)
 *     | climbStairs(1) = 1
 *     | climbStairs(2) = 2
 * 
 *   Time complexity: O(n), Space complexity: O(n)
 * 
 * 回溯法：
 *   可知公式，实现并使用数组存储中间值即可
 *     | climbStairs(n) = climbStairs(n - 1) + climbStairs(n - 2)
 *     | climbStairs(1) = 1
 *     | climbStairs(2) = 2
 * 
 *   时间复杂度：O(n)，空间复杂度：O(n)
 * 
 * Judge Result:
 *   Runtime: 0 ms, faster than 100.00% of C++ online submissions for Climbing Stairs.
 *   Memory Usage: 8.5 MB, less than 34.45% of C++ online submissions for Climbing Stairs.
 */

#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int a[100];
    int climbStairs(int n) {
        for (int i = 1; i <= n; i++) a[i] = 0;
        return steps(n);
    }
    
    int steps(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (a[n] != 0) return a[n];
        return a[n] = steps(n - 1) + steps(n - 2);
    }
};

int main() {
    Solution solution;
    cout << "Output: " << solution.climbStairs(3) << endl;
}
