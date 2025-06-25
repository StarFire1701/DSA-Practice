#include<bits/stdc++.h>
using namespace std;
int main(){
    string infix = "A+B*(C^D-E)^(F+G*H)-I";
    string postfix=infix_to_postfix(infix);
    cout<<postfix;
}
string infix_to_postfix(string s){
    stack<char>st;
    string ans = "";
    int n= s.size();
    for(int i=0;i<n;i++){
        if((s[i]>='A'&&s[i]<='Z')|| (s[i]>='a'&&s[i]<='z')|| (s[i]>='0' && s[i]<='9')){
            ans+=s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                ans+=st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && prece(s[i])<=prece(st.top())){
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
    return ans;
}

int prece(char c){
     return c=='^'?  3: (c=='*' || c == '/')? 2: (c == '+' || c == '-')?  1: -1; 
}