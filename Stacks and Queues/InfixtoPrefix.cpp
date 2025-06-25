#include<bits/stdc++.h>
using namespace std;
int main(){
    string infix = "A+B*(C^D-E)^(F+G*H)-I";
    string prefix=infix_to_prefix(infix);
    cout<<prefix;
}
string infix_to_prefix(s){
    stack<char>st;
    string ans="";
    int n = s.size();
    reverse(s,n);
    for(int i=0;i<n;i++){
        if((s[i]>='A' && s[i]<='Z')||(s[i]>='a' && s[i]<='z')|| (s[i]>='0'&& s[i]<='9')){
            ans+=s[i];
        }
        else if(s[i]==')'){
            st.push(s[i]);
        }
        else if(s[i]=='('){
            while(!st.empty()&&st.top()!=')'){
                ans+=st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && prece(s[i])<prece(st.top())){
                ans+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    reverse(ans,n);
     return ans;
  }

  int prece(char c){
    return c=='^'?  3: (c=='*' || c == '/')? 2: (c == '+' || c == '-')?  1: -1; 
  }  

 void reverse(string s,int n){
    for(int i=0;i<(n/2);i++){
        char temp=s[i];
        s[i]=s[n-i-1];
        s[n-i-1]=temp;
    }
}
