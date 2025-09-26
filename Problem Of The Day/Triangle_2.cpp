class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;
        sort(nums.begin(), nums.end());
        long long count = 0; // use long long to be safe with accumulation

        for (int i = n - 1; i >= 2; --i) {
            int l = 0, r = i - 1;
            while (l < r) {
                // If nums[l] + nums[r] > nums[i], then all elements from l..r-1 paired with r are valid
                if ((long long)nums[l] + nums[r] > nums[i]) {
                    count += (r - l);
                    --r;
                } else {
                    ++l;
                }
            }
        }
        return (int)count;
    }
};