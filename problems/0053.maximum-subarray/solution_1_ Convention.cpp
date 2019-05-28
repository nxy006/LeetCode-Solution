// Source: https://leetcode.com/problems/maximum-subarray/
// Author: NaN
// Time: 2019-05-23

/*
 * Method:
 *   Set A[0..i] that solution of arr[0..n] in 0..i range is known,
 *   then A[0..i+1] = max(A[0..i], arr[i]). In other words, if current sum add new value less
 *   than new value, then let new value as current sum go on.
 * 
 *   Note: Compare arr[0..n] with arr[i] is same to A[0..i] < 0, but the latter can reduce a
 *   compute and avoid possibility of overstep the boundary.
 * 
 *   Time complexity: O(n), Space complexity: O(1)
 * 
 * public static int maxSubArray(int[] A) {
 *   int maxSum=A[0], sum=A[0];
 *   for (int i=1;i<A.length;++i){
 *     sum = Math.max(sum+A[i], A[i]);
 *     maxSum=Math.max(maxSum, sum);	
 *   }
 *   return maxSum;
 * }
 * 
 * 算法：
 *   假设我们已知对 arr[0..n] 在 0..i 区间的解 A[0..i]，那么 A[0..i+1] = max(A[0..i], arr[i])，也就
 *   是说如果当前总和值加新的元素值小于新的元素值，就要开始新的总和值继续下去。
 * 
 *   注意：这里比较 A[0..i], arr[i] 的大小，与 A[0..i] < 0 的判断是等价的，但采用后者可以避免一次计算，同
 *   时也能避免计算中越界的可能性。
 * 
 *   时间复杂度：O(n)，空间复杂度：O(1)
 * 
 * public static int maxSubArray(int[] A) {
 *   int maxSum=A[0], sum=A[0];
 *   for (int i=1;i<A.length;++i){
 *     sum = Math.max(sum+A[i], A[i]);
 *     maxSum=Math.max(maxSum, sum);	
 *   }
 *   return maxSum;
 * }
 * 
 * Judge Result:
 *   Runtime: 8 ms, faster than 95.56% of C++ online submissions for Maximum Subarray.
 *   Memory Usage: 9.4 MB, less than 61.52% of C++ online submissions for Maximum Subarray.
 */

#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, max_sum = nums[0];

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            if (sum > max_sum) max_sum = sum;
            if (sum < 0) sum = 0;
        }
        return max_sum;
    }
};

int main() {
    vector<int> input_data;
    input_data.push_back(-2);
    input_data.push_back(1);
    input_data.push_back(-3);
    input_data.push_back(4);
    input_data.push_back(-1);
    input_data.push_back(2);
    input_data.push_back(1);
    input_data.push_back(-5);
    input_data.push_back(4);

    Solution solution;
    int ret = solution.maxSubArray(input_data);

    cout << "Output: " << ret << endl;
}
