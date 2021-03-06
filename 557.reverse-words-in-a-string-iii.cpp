/*
 * @lc app=leetcode id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
 *
 * https://leetcode.com/problems/reverse-words-in-a-string-iii/description/
 *
 * algorithms
 * Easy (62.42%)
 * Total Accepted:    105.1K
 * Total Submissions: 168.2K
 * Testcase Example:  `"Let's take LeetCode contest"`
 *
 * Given a string, you need to reverse the order of characters in each word
 * within a sentence while still preserving whitespace and initial word order.
 * 
 * Example 1:
 * 
 * Input: "Let's take LeetCode contest"
 * Output: "s'teL ekat edoCteeL tsetnoc"
 * 
 * 
 * 
 * Note:
 * In the string, each word is separated by single space and there will not be
 * any extra space in the string.
 * 
 */
class Solution {
 public:
    string reverseWords(string s) {
        unsigned int n = s.size();
        int b = 0;
        int i = 0;

        while (i < n) {
            b = i;
            while (s[i] != ' ' && i < n) {
                i++;
            }
            int tmp = i - 1;
            while (b <= tmp) {
                swap(s[b], s[tmp]);
                b++;
                tmp--;
            }
            i++;
        }
        return s;
    }
};
