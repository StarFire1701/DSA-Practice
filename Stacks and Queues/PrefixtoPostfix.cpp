#include<bits/stdc++.h>
using namespace std;
int main(){
    string prefix = "-+A^-*BC/DE+F*GHI";
    string postfix = prefix_to_postfix(prefix);
    cout << postfix;
}
string prefix_to_postfix(string s){
    stack<string>st;
    int n = s.length();
    string top1 ="";
    string top2 ="";
    for(int i = n-1; i>=0;i--){
        if((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z')||(s[i]>='0'&&s[i]<='9')){
            st.push(string(1,s[i]));
        }
        else{
            top1 = st.top();
            st.pop();
            top2 = st.top();
            st.pop();
            st.push(top1 + top2 + s[i]);
        }

    }
    return st.top();
}