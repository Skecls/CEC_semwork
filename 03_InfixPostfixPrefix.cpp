#include <bits/stdc++.h>

using namespace std;

class convert{
    public:
        bool precedence(char op1,char op2){
            if(op1 == '(') return true;
            if(op1 == '^') return false;
            if(op2 == '^') return true;
            else if(op1 == '+' || op1 == '-'){
                if(op2 == '+' || op2 == '-'){
                    return false;
                }
                else{
                    return true;
                }
            }
            else{
                if(op2 == '*' || op2 == '/'){
                    return false;
                }
                else{
                    return false;
                }
            }
        }

        void infixtopostfix(string exp,int n){
            stack<char> s;
            string postfixexp = "";
            for(int i = 0;i < n;i++){
                cout<<exp[i]<<" ";
                if(exp[i] >= 'a' && exp[i] <= 'z'){
                    cout<<"character ";
                    postfixexp += exp[i];
                    cout<<postfixexp;
                }
                else if(exp[i] == '('){
                    cout<<"opening bracket ";
                    s.push(exp[i]);
                    cout<<"pushed in stack";
                }
                else if(exp[i] == ')'){
                    cout<<"closing bracket ";
                    while(s.top() != '('){ 
                        cout<<s.top()<<" poped and added to string ";
                        postfixexp += s.top();
                        s.pop();
                    }
                    s.pop();
                }
                else{
                    cout<<"operator";
                    if(s.empty()){
                        s.push(exp[i]);
                    }
                    else{
                        while(!s.empty() && !precedence(s.top(),exp[i])){
                            postfixexp += s.top();
                            cout<<s.top()<<" poped and added to string ";
                            s.pop();
                        }
                        s.push(exp[i]);
                    }
                    cout<<exp[i]<<" pushed to stack";
                }
                cout<<endl;
            }
            while(!s.empty()){
                postfixexp += s.top();
                s.pop();
            }
            cout<<"\npostifx equivalent:"<<postfixexp<<endl;
        }

        void reverse(string &str){
            int n = str.length();
            for(int i = 0;i < n / 2;i++){
                swap(str[i],str[n - i - 1]);
            }
        }

        bool precedence_infix2prefix(char op1,char op2){
            if(op1 == ')') return true;
            if(op1 == '^') return false;
            if(op2 == '^') return true;
            else if(op1 == '+' || op1 == '-'){
                if(op2 == '+' || op2 == '-'){
                    return true;
                }
                else{
                    return true;
                }
            }
            else{
                if(op2 == '*' || op2 == '/'){
                    return true;
                }
                else{
                    return false;
                }
            }
        }

        void infixtoprefix(string exp,int n){
            reverse(exp);
            string prefixexp = "";
            stack<char> s;
            for(int i = 0;i < n;i++){
                cout<<exp[i]<<" ";
                if(exp[i] >= 'a' && exp[i] <= 'z'){
                    cout<<"character ";
                    prefixexp += exp[i];
                    cout<<prefixexp;
                }
                else if(exp[i] == ')'){
                    cout<<"closing bracket ";
                    s.push(exp[i]);
                    cout<<"pushed in stack";
                }
                else if(exp[i] == '('){
                    cout<<"openeing brackets ";
                    while(!s.empty() && s.top() != ')'){
                        prefixexp += s.top();
                        cout<<s.top()<<"poped and added in string";
                        s.pop();
                    }
                    s.pop();
                }
                else{
                    cout<<"operator ";
                    if(s.empty()){
                        cout<<exp[i]<<" pushed";
                        s.push(exp[i]);
                    }
                    else{
                        while(!precedence_infix2prefix(s.top(),exp[i])){
                            prefixexp += s.top();
                            cout<<s.top()<<"poped and added in string";
                            s.pop();
                        }
                        s.push(exp[i]);
                        cout<<exp[i]<<" pushed";
                    }
                }
                cout<<endl;
            }
            while(!s.empty()){
                prefixexp += s.top();
                s.pop();
            }
            reverse(prefixexp);
            cout<<"\nprefix equivalent :"<<prefixexp;
        }
};

int main(){
    string infixexp;
    char ch = 'y';
    int val;
    convert c;
    do{
        cout<<"enter an infix expression:";
        cin>>infixexp;
        int n = infixexp.size();
        cout<<"select from the menu:\n";
        cout<<"1.Infix to Postfix\n";
        cout<<"2.Infix to Prefix\n";
        cout<<"enter your choice:";
        cin>>val;
        switch(val){
            case 1: c.infixtopostfix(infixexp,n);
                break;
            case 2: c.infixtoprefix(infixexp,n);
                break;
            default:cout<<"enter a correct choice";
        }
        cout<<"\ndo you want to continue(y/n):";
        cin>>ch;
        ch = tolower(ch);
        cout<<"\n\n";
    }while(ch == 'y');
    return 0;
}