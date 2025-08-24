class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0, zeroes = 0, ans = 0;

        for (int right = 0; right < n; right++) {
            if (nums[right] == 0) zeroes++;

            while (zeroes > 1) {
                if (nums[left] == 0) zeroes--;
                left++;
            }

            ans = max(ans, right - left); // notice: no +1 here
        }

        return ans;
    }
};
