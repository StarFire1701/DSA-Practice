class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int leftsum=0;
        int rightsum=0;
        int maxscore=0;
        for(int i=0;i<k;i++){
            leftsum+=cardPoints[i];
        }
        maxscore=leftsum;
        if(k==n) return maxscore;
        int rpointer=n-1;
        for(int i=k-1;i>=0;i--){
            leftsum-=cardPoints[i];
            rightsum+=cardPoints[rpointer];
            rpointer--;
            maxscore=max(maxscore,leftsum+rightsum);
        }
        return maxscore;
    }
};