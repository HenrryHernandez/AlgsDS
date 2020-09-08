#include <bits/stdc++.h>

using namespace std;

bool pairWith(char c, char c2){
    if(c2 == ')'){
        if(c == '(')
            return true;
        else
            return false;
    }else if(c2 == '}'){
        if(c == '{')
            return true;
        else
            return false;
    }else if(c2 == ']'){
        if(c == '[')
            return true;
        else
            return false;
    }
}

bool checkExpression(string exp){
    cout << "expression inserted = " << exp << endl;

    stack<char> st;
    for(char c : exp){
        if(c == '(' || c == '{' || c == '['){
            st.push(c);
        }else if(c == ')' || c == '}' || c == ']'){
            if(st.empty() || !pairWith(st.top(), c)){
                return false;
            }else{
                st.pop();
            }
        }
    }

    return st.empty() ? true:false;
}

int main(){

    string exp = "()(a + (x * y))[asd*{c*(a + b) + (b + a)}{}]";

    if(checkExpression(exp)) cout << "valid" << endl;
    else cout << "no valid" << endl;

    return 0;
}
