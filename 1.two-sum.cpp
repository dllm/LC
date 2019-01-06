class Solution {
public:
    vector<int> twoSum(const vector<int>& nums, int target) {
        unordered_map <int, int> map;
        vector<int> res;

        for (int i = 0; i < nums.size(); i++) {
                map[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
                int x = target - nums[i];

                if (map.count(x) && map[x] != i) {
                        res.push_back(i);
                        res.push_back(map[x]);
                        break;
                }
        }
        return res;
    }
};
