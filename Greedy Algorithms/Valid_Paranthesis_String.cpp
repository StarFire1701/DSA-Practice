// Brute Force
class Solution {
public:
    bool checkParenthesis(string s,int index,int cnt,int n){
        if(cnt<0)return false;
        if(index==n){
            return cnt==0;
        }
        if(s[index]=='('){
            return checkParenthesis(s,index+1,cnt+1,n);
        }
        if(s[index]==')'){
            return checkParenthesis(s,index+1,cnt-1,n);
        }

        return ((checkParenthesis(s,index+1,cnt+1,n))||(checkParenthesis(s,index+1,cnt-1,n))||checkParenthesis(s,index+1,cnt,n));
    }
    bool checkValidString(string s) {
        int n=s.length();
        return checkParenthesis(s,0,0,n);
    }
};


//Optimal Approach

class Solution{
public:
bool checkValidString(string s) {
        int n=s.length();
        int maxi=0;
        int mini=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                maxi+=1;
                mini+=1;
            } else if(s[i]==')'){
                maxi-=1;
                mini-=1;
            } else{
                maxi+=1;
                mini-=1;
            }
            if(mini<0) mini=0;
            if(maxi<0) return false;
        }
        return mini==0;
    }
};