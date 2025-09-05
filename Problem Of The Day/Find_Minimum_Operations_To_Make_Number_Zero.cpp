class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
           for (int ops = 0; ops <= 60; ops++) {
            long long target = 1LL * num1 - 1LL * ops * num2;
            if (target < ops) continue; 
            // __builtin_popcountll counts number of 1-bits
            if (__builtin_popcountll(target) <= ops) 
                return ops;
        }
        return -1;
    }
};