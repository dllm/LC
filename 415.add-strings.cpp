/*
 * @lc app=leetcode id=415 lang=cpp
 *
 * [415] Add Strings
 *
 * https://leetcode.com/problems/add-strings/description/
 *
 * algorithms
 * Easy (42.62%)
 * Total Accepted:    80.7K
 * Total Submissions: 188.7K
 * Testcase Example:  '"0"\n"0"'
 *
 * Given two non-negative integers num1 and num2 represented as string, return
 * the sum of num1 and num2.
 * 
 * Note:
 * 
 * The length of both num1 and num2 is < 5100.
 * Both num1 and num2 contains only digits 0-9.
 * Both num1 and num2 does not contain any leading zero.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 * 
 * 
 */
class Solution {
 public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        string ans = "";
        int sum = 0;
        int carry = 0;
        int a = 0;
        int b = 0;

        while (i >= 0 || j >= 0) {
            if (i >=0) {
               a = num1[i--] - '0';
            } else {
               a = 0;
            }
            if (j >= 0) {
               b = num2[j--] - '0';
            } else {
               b = 0;
            }
            sum = a + b + carry;
            carry = sum / 10;
            if (carry) {
               sum %= 10;
            }
            ans.insert(ans.begin(), sum + '0');
        }
        return carry ? "1" + ans : ans;
    }
};
