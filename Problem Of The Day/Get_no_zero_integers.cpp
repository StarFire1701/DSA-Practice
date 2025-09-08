class Solution {
public:
    bool haszero(int n){
        while(n>0){
            if(n%10==0)return true;
            n=n/10;
        }
        return false;
    }
    vector<int> getNoZeroIntegers(int n) {
        for(int i=1;i<n;i++){
            int b=n-i;
            if(!haszero(i) && !haszero(b)){
                return {i,b};
            }
        }
        return {};
    }
};