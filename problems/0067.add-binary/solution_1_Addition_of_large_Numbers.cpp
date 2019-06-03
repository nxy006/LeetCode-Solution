// Source: https://leetcode.com/problems/add-binary/
// Author: NaN
// Time: 2019-06-02

/*
 * Addition of large Numbers:
 *   According to method of math, binary adding from back to front. notice carry.
 * 
 *   Time complexity: O(n), Space complexity: O(1)
 * 
 * 大数相加：
 *   按正常的数学方法，低位到高位逐个相加即可，注意处理进位。
 * 
 *   时间复杂度：O(n)，空间复杂度：O(1)
 * 
 * Judge Result:
 *   Runtime: 12 ms, faster than 13.69% of C++ online submissions for Add Binary.
 *   Memory Usage: 9.4 MB, less than 7.11% of C++ online submissions for Add Binary.
 */

#include<iostream>
#include<string>

using namespace std;

// This Solution require C++11 Runtime Enviroment.
class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length() - 1, j = b.length() - 1, temp = 0, flag = 0;
        string ret = "";
        
        while(i >= 0 && j >= 0) {
            temp = (a[i--] - '0') + (b[j--] - '0') + flag;
            
            if (temp >= 2) {
                temp = temp % 2;
                flag = 1;
            } else {
                flag = 0;
            }
            
            ret = to_string(temp) + ret;
        }
        
        while(i >= 0) {
            temp = (a[i--] - '0') + flag;
            if (temp >= 2) {
                temp = temp % 2;
                flag = 1;
            } else {
                flag = 0;
            }
            
            ret = to_string(temp) + ret;
        }
        
        while(j >= 0) {
            temp = (b[j--] - '0') + flag;
            if (temp >= 2) {
                temp = temp % 2;
                flag = 1;
            } else {
                flag = 0;
            }
            
            ret = to_string(temp) + ret;
        }
        
        if (flag) return "1" + ret;
        else return ret;
    }
};

int main() {
    Solution solution;
    cout << "Output:" << solution.addBinary("11", "1") << endl;
}
