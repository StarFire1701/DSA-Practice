class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>ans;
        for(int i=1;i<=n/2;i++){
            ans.push_back(i);
        }
        int m=n/2;
        int a=1;
        int i=-1;
        while(a<=m){
            ans.push_back(i);
            i--;
            a++;
        }
        if(n%2!=0){
            ans.push_back(0);
        }
        return ans;
    }
};