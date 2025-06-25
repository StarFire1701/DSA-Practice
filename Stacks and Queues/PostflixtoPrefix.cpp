#include<bits/stdc++.h>
using namespace std;
int main(){
    string postfix= "ABC*DE/-FGH*+^+I-";
    string prefix = postfix_to_prefix(postfix);
    cout << prefix;
}
string postfix_to_prefix(string s){
    int n = s.length();
    stack<string>st;
    string top1 ="";
    string top2 ="";
    for(int i=0;i<n;i++){
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
            st.push(string(1,s[i]));
        } else{
            top1 = st.top();
            st.pop();
            top2 = st.top();
            st.pop();
            st.push(s[i] + top2 + top1);
        }
    }
    return st.top();
}