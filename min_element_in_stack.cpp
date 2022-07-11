#include<bits/stdc++.h>
using namespace std;

class MinStack {
public:
    stack<int>s;
    stack<int>ss;
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(ss.size()==0 || val<=ss.top()){
            ss.push(val);
        }
        
        
    }
    
    void pop() {
        if(s.top()==ss.top()){
            s.pop();
            ss.pop();
        }
        else {
            s.pop();
        }
        
    }
    
    int top() {
        if(s.size()==0) return -1;
        return s.top();
        
    }
    
    int getMin() {
        if(ss.size()==0){
            return -1;
        }
        return ss.top();
        
        
    }
};
// USING ONE STACK

 stack<long long int>st;
    long long int min_ele=0;
   
    void push(int val) {
        if(st.size()==0){
            st.push(val);
            min_ele=val;
        }
        else{
            if(val>min_ele){
                st.push(val);
            }
            else{
                long long int p =2*(long long)val-min_ele;
                st.push(p);
                min_ele=val;
            }
        }
        
    }
    
    void pop() {
        if(st.top()>min_ele){
            st.pop();
        }
        else{
            min_ele=2*min_ele-st.top();
            st.pop();
        }
        
    }
    
    int top() {
        if(st.size()==0) return -1;
        if(st.top()>min_ele) return st.top();
        else{
            return min_ele;
        }
        
    }
    
    int getMin() {
        if(st.size()==0) return -1;
        return min_ele;
        
    }