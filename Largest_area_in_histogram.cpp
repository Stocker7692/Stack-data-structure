#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void NSL(vector<int>&heights,vector<int>&nsl,int n){
        stack<int>st;
        for(int i=0;i<n;i++){
            while(st.size()>0 && (heights[st.top()]>=heights[i])) st.pop();
            if(st.size()==0) nsl.push_back(-1);
            else{
                nsl.push_back(st.top());
            }
            st.push(i);   
        }
        
    }
    
    void NSR(vector<int>&heights,vector<int>&nsr,int n){
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(st.size()>0 && (heights[st.top()]>=heights[i])) st.pop();
            if(st.size()==0) nsr.push_back(n);
            else{
                nsr.push_back(st.top());
            }
            st.push(i); 
        }
        
        reverse(nsr.begin(),nsr.end());
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>nsl;
        vector<int>nsr;
        NSL(heights,nsl,n);
        NSR(heights,nsr,n);
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            ans =max(ans,heights[i]*(nsr[i]-nsl[i]-1));
            
        }
        return ans;
        
        
    }
};