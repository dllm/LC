/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 *
 * https://leetcode.com/problems/maximal-square/description/
 *
 * algorithms
 * Medium (32.49%)
 * Total Accepted:    124.8K
 * Total Submissions: 381.9K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest square
 * containing only 1's and return its area.
 *
 * Example:
 *
 *
 * Input:
 *
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 *
 * Output: 4
 *
 */
class Solution {
 public:
     int maximalSquare(vector<vector<char>>& matrix) {
         if (matrix.empty() || matrix[0].empty())
            return 0;
         int m = matrix.size();
         int n = matrix[0].size();
         vector<vector<int>> s(m, vector<int>(n, 0));

         for ( int i = 0; i < m; i++ ) {
             s[i][0] = matrix[i][0] - '0';
         }

         for ( int j = 0; j < n; j++ ) {
             s[0][j] = matrix[0][j] - '0';
         }

         for ( int i = 1; i < m; i++ ) {
             for ( int j = 1; j < n; j++ ) {
                 if (matrix[i][j] == '0') {
                     s[i][j] = 0;
                 } else {
                     s[i][j] = min(s[i-1][j-1],
                             min(s[i-1][j], s[i][j-1])) + 1;
                 }
              //  cout << "s[" << i << "][" <<j <<"]" << s[i][j] << endl;
             }
         }

         int res = 0;

         for ( int i = 0; i < m; i++ ) {
             for ( int j = 0; j < n; j++ ) {
                res = max(res, s[i][j]);
             }
         }
         return res*res;
     }
};
