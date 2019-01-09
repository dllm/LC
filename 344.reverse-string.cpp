/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 *
 * https://leetcode.com/problems/reverse-string/description/
 *
 * algorithms
 * Easy (62.23%)
 * Total Accepted:    342.6K
 * Total Submissions: 549.9K
 * Testcase Example:  '"hello"'
 *
 * Write a function that takes a string as input and returns the string
 * reversed.
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: "hello"
 * Output: "olleh"
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "A man, a plan, a canal: Panama"
 * Output: "amanaP :lanac a ,nalp a ,nam A"
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    string reverseString(string s) {
        int i = 0;
        int j = s.size() - 1;
        char tmp;
        while (i <= j) {
            tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
            i++; j--;
        }
        return s;
    }
};
