/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (51.62%)
 * Total Accepted:    347.5K
 * Total Submissions: 669.8K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct integers, nums, return all possible subsets (the
 * power set).
 *
 * Note: The solution set must not contain duplicate subsets.
 *
 * Example:
 *
 *
 * Input: nums = [1,2,3]
 * Output:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 *
 */
class Solution {
 public:
        vector<vector<int>> subsets(vector<int>& nums) {
            vector<vector<int>> res;
            vector<int> sav;
            sav.assign(nums.size(), 0);
            // sort(nums.end(), nums.begin());
            helper(sav, 0, nums, res);
            //sort(res.begin(), res.end());
            return res;
        }
        void helper(vector<int>& save, int k, vector<int>& nums,
                                    vector<vector<int>> &res){
            vector<int> out;
            if (k == nums.size()) {
                for (int i = 0; i < nums.size(); i++) {
                    if (save[i] == 1) {
                        // cout << nums[i] << endl;
                        out.push_back(nums[i]);
                    }
                }
                res.push_back(out);
                return;
            }
            save[k] = 1;
            helper(save, k + 1, nums, res);
            save[k] = 0;
            helper(save, k + 1, nums, res);
        }
};
