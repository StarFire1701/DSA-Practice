#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const double EPS = 1e-6;
    const double TARGET = 24.0;

    bool judgePoint24(vector<int>& cards) {
        vector<double> nums;
        for (int c : cards) nums.push_back((double)c);
        return solve(nums);
    }

    bool solve(vector<double>& nums) {
        int n = nums.size();
        if (n == 1) {
            return fabs(nums[0] - TARGET) < EPS;
        }

        // try all pairs
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                vector<double> next;
                for (int k = 0; k < n; k++) {
                    if (k != i && k != j) next.push_back(nums[k]);
                }

                // possible results of combining nums[i] and nums[j]
                vector<double> candidates = {
                    nums[i] + nums[j],
                    nums[i] - nums[j],
                    nums[j] - nums[i],
                    nums[i] * nums[j]
                };

                if (fabs(nums[j]) > EPS) candidates.push_back(nums[i] / nums[j]);
                if (fabs(nums[i]) > EPS) candidates.push_back(nums[j] / nums[i]);

                for (double c : candidates) {
                    next.push_back(c);
                    if (solve(next)) return true;
                    next.pop_back();
                }
            }
        }
        return false;
    }
};
