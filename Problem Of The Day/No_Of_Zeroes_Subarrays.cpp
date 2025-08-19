class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
         long long count = 0;  // answer
        long long streak = 0; // length of current zero streak

        for (int n : nums) {
            if (n == 0) {
                streak++;
                count += streak; // each new zero extends all previous zero subarrays
            } else {
                streak = 0;
            }
        }
        return count;
    }
};