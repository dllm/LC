/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (30.74%)
 * Total Accepted:    357.1K
 * Total Submissions: 1.2M
 * Testcase Example:  '"hello"\n"ll"'
 *
 * Implement strStr().
 * 
 * Return the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 * 
 * Example 1:
 * 
 * 
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 * 
 * 
 * Clarification:
 * 
 * What should we return when needle is an empty string? This is a great
 * question to ask during an interview.
 * 
 * For the purpose of this problem, we will return 0 when needle is an empty
 * string. This is consistent to C's strstr() and Java's indexOf().
 * 
 */
class Solution {
 public:
    int strStr(string haystack, string needle) {
            int n = haystack.size();
            int m = needle.size();
            int i = 0;
            int s = 0;
            if (m == 0) return 0;
            if (m > n) return -1;

            while (i <= n-m) {
                s = 0;
                while (haystack[i+s] == needle[s]) {
                    s++;
                    if (s >= m) break;
                }
                if (s == m)
                    return i;
                i++;
        }
            return -1;
    }
};
