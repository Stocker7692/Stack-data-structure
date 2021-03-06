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
    int maximalRectangle(vector<vector<char>>& matrix) { 
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>v(m,0);
        int res = largestRectangleArea(v);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='0'){
                    v[j]=0;
                }
                else{
                    v[j]=v[j]+1;
                }
            }
            res=max(res,largestRectangleArea(v));
        }
        return res;
        
    }
};