// Brute Force
class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length();
        int m=t.length();
        int minlen=INT_MAX;
        int Startindex=-1;
        for(int i=0;i<n;i++){
            int hasharr[256]={0};
            int cnt=0;
            for(int j=0;j<m;j++){
                hasharr[t[j]]++;
            }
            for(int j=i;j<n;j++){
                if(hasharr[s[j]]>0){
                    cnt+=1;
                }
                hasharr[s[j]]--;
                if(cnt==m){
                   if((j-i+1)<minlen){
                    minlen=j-i+1;
                    Startindex=i;
                    break;
                   }
                }
            }
        }
        return Startindex==-1?"":s.substr(Startindex,minlen);
    }
};


// Optimal Solution

class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length();
        int m=t.length();
        if(m>n)return "";
        int Startindex=-1;
        int minlen = INT_MAX;
        int cnt=0;
        int hasharr[256]={0};
        int left=0;
        int right=0;
        for(int i=0;i<m;i++){
            hasharr[(unsigned char)t[i]]++;
        }
        while(right<n){
            if(hasharr[(unsigned char)s[right]]>0){
                cnt+=1;
            }
            hasharr[(unsigned char)s[right]]--;
            while(cnt==m){
                if((right-left+1)<minlen){
                    minlen=right-left+1;
                    Startindex=left;
                }
                hasharr[(unsigned char)s[left]]++;
                if(hasharr[(unsigned char)s[left]]>0){
                    cnt-=1;
                }
                left++;
            }
            right++;
        }
        return Startindex==-1?"":s.substr(Startindex,minlen);
    }
};