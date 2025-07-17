class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size();
        int m=s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int left=0;
        int right=0;
        int cnt=0;
        while(left < n && right < m ){
            if(g[left]>s[right]){
                right++;
            } else if(g[left]<=s[right]){
                cnt+=1;
                left++;
                right++;
            }
        }
        return cnt;
    }
};