/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 *
 * https://leetcode.com/problems/product-of-array-except-self/description/
 *
 * algorithms
 * Medium (52.99%)
 * Total Accepted:    210.3K
 * Total Submissions: 395.8K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given an array nums of n integers where n > 1,  return an array output such
 * that output[i] is equal to the product of all the elements of nums except
 * nums[i].
 * 
 * Example:
 * 
 * 
 * Input:  [1,2,3,4]
 * Output: [24,12,8,6]
 * 
 * 
 * Note: Please solve it without division and in O(n).
 * 
 * Follow up:
 * Could you solve it with constant space complexity? (The output array does
 * not count as extra space for the purpose of space complexity analysis.)
 * 
 */
class Solution {
 public:
    vector<int> productExceptSelf(vector<int>& nums) {
       vector<int> p(nums.size(), 1);
       int product = 1;

       for (int i = 0; i < nums.size(); i++) {
           p[i] = product;
           product *= nums[i];
       }
       product = 1;
       for ( int i = nums.size()-1; i >= 0; i-- ) {
            p[i] *= product;
            product *= nums[i];
       }
       return p;
    }
};
