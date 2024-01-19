//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    void solve(string s,string op,vector<string>&ans){
        // Base Case
        if(s.empty()){
            ans.push_back(op);
            return;
        }
        
        string op1=op;
        string op2=op;
        op2.push_back(' ');
        op2.push_back(s[0]);
        op1.push_back(s[0]);
        s.erase(s.begin()+0);
        solve(s,op1,ans);
        solve(s,op2,ans);
        
    }
public:

    vector<string> permutation(string s){
        // Code Here
        
        vector<string>ans;
        string op;
        op.push_back(s[0]);
        s.erase(s.begin()+0);
        solve(s,op,ans);
        return ans;
        
    }
};

//{ Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}

// } Driver Code Ends
