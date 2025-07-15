// Brute Force

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int cnt=0;
        for(int i=0;i<n;i++){
            int hasharr[3]={0};
            for(int j=i;j<n;j++){
                hasharr[ s[j] - 'a'] = 1;
                if(hasharr[0] + hasharr[1] + hasharr[2] ==3){
                    cnt+=1;
                }
            }
        }
        return cnt;
    }
};


// Better Solution , not huge but slightly

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int cnt=0;
        for(int i=0;i<n;i++){
            int hasharr[3]={0};
            for(int j=i;j<n;j++){
                hasharr[ s[j] - 'a'] = 1;
                if(hasharr[0] + hasharr[1] + hasharr[2] ==3){
                    cnt+=(n-j);
                    break;
                }
            }
        }
        return cnt;
    }
};

//Optimal Solution

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int cnt=0;
        int pointer=0;
        int hasharr[3]={-1,-1,-1};
        while(pointer<n){
            hasharr[s[pointer]-'a']=pointer;
            if(hasharr[0]>=0 && hasharr[1]>=0 && hasharr[2]>=0){
                int mini=min({hasharr[0],hasharr[1],hasharr[2]});
                cnt = cnt + (mini+1);
            }
            pointer=pointer+1;
        }
       
        return cnt;
    }
};