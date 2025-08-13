class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
        for(int i=0;i<=n;i++){
            long long temp=pow(3,i);
            if(temp==n)return true;
            if(temp>n) break;
        }
        return false;
    }
};