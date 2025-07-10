class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     
        int n=s.length();
        if(n==0) return 0;
        if(n==1) return 1;
        int hasharr[256]={-1};
        fill(hasharr, hasharr + 256, -1);
        int left=0;
        int right=0;
        int maxlen=0;
        while(right<n){
            if(hasharr[s[right]]!=-1){
                if(hasharr[s[right]]>=left){
                    left=hasharr[s[right]]+1;
                }
            }
            int len = right-left+1;
            maxlen=max(len,maxlen);
            hasharr[s[right]]=right;
            right++;
        }
        return maxlen;
        
    }
};