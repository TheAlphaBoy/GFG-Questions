//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
void solve(int n,int zeros,int ones,string op,vector<string>&ans){
    
    // BC 
    if(n==0){
        ans.push_back(op);
        return;
    }
    if(zeros==ones){
        string op1=op;
        op1.push_back('1');
        solve(n-1,zeros,ones-1,op1,ans);
    }
    if(zeros>ones){
        string op1=op;
        string op2=op;
        op1.push_back('1');
        solve(n-1,zeros,ones-1,op1,ans);
        op2.push_back('0');
        solve(n-1,zeros-1,ones,op2,ans);
    }
    
}
	vector<string> NBitBinary(int n)
	{
	    // Your code goes here
	    
	    string op="";
	    vector<string>ans;
	    int zeros=n;
	    int ones=n;
	    solve(n,zeros,ones,op,ans);
	    return ans;
	    
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends
