/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (45.03%)
 * Total Accepted:    243.7K
 * Total Submissions: 536.2K
 * Testcase Example:  '5'
 *
 * Given a non-negative integer numRows, generate the first numRows of Pascal's
 * triangle.
 *
 *
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 *
 * Example:
 *
 *
 * Input: 5
 * Output:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 *
 *
 */
class Solution {
 public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if (numRows <= 0) {
            return res;
        }
        res.assign(numRows, vector<int>(1));

        for (int i = 0; i < numRows; i++) {
			res[i][0]=1;
            if (i == 0) continue;
            for (int j=1; j< i; j++) {
                res[i].push_back(res[i-1][j]+res[i-1][j-1]);
            }
            res[i].push_back(1);
        }
        return res;
    }
};
