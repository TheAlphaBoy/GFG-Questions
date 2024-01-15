//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    private:
    void insert(stack<int>&s,int val) {
    // BC
    if(s.size()==0){
        s.push(val);
        return;
    }
    // Hypothesis step
    int ans=s.top();
    s.pop();
    insert(s,val);
    // induction step
    s.push(ans);
    return;
    
    }
public:

    void Reverse(stack<int> &s){
        
        // BC
        if(s.size()==1) return;
        // Hypothesis step
        int val =s.top();
        s.pop();
        Reverse(s);
        // Induction step
        insert(s,val);
        return;
        
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends
