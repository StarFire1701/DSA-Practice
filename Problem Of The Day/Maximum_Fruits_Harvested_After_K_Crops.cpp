// Brute Force
class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        unordered_map<int,int>mpp;
        for(auto&f: fruits){
            mpp[f[0]]=f[1];
        }
        int maxfruits=0;
        //Left First
        for(int L=0;L<=k;L++){
            int R=k-2*L;
            if(R<0)continue;
            int leftbound=startPos-L;
            int rightbound=startPos+R;
            int total=0;
            for(int i=leftbound;i<=rightbound;i++){
                total+=mpp[i];
            }
            maxfruits=max(total,maxfruits);
        }
        //Right then
         for(int R=0;R<=k;R++){
            int L= k-2*R;
            if(L<0)continue;
            int leftbound=startPos-L;
            int rightbound=startPos+R;
            int total=0;
            for(int i=leftbound;i<=rightbound;i++){
                total+=mpp[i];
            }
            maxfruits=max(total,maxfruits);
        }
        return maxfruits;

    }
};