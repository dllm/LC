/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 *
 * https://leetcode.com/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (40.02%)
 * Total Accepted:    158.4K
 * Total Submissions: 393.1K
 * Testcase Example:  '"aab"'
 *
 * Given a string s, partition s such that every substring of the partition is
 * a palindrome.
 *
 * Return all possible palindrome partitioning of s.
 *
 * Example:
 *
 *
 * Input: "aab"
 * Output:
 * [
 * ⁠ ["aa","b"],
 * ⁠ ["a","a","b"]
 * ]
 *
 *
 */
class Solution {
 public:
        vector<vector<string>> partition(string s) {
            vector<vector<string>> res;
            vector<string> out;
            pal(res, out, s);
            return res;
        }
        bool isPal(string s) {
            int i = 0;
            int j = s.size() - 1;
            if (s.size() == 0) return true;
            while (i < j) {
                if (s[i++] != s[j--]) {
                    return false;
                }
            }
            return true;
        }
        void pal(vector<vector<string>> &res, vector<string> &out, string s) {
            if (s.size() == 0) {
                res.push_back(out);
                out.clear();
            } else {
                for (int i = 1; i <= s.size(); i++) {
                    string cur = s.substr(0, i);
                    // cout << "cur " << cur << endl;
                    if (isPal(cur)) {
                        out.push_back(cur);
                    //    cout << "substr " << s.substr(i) << endl;
                        pal(res, out, s.substr(i));
                    }
                }
            }
        }
};
