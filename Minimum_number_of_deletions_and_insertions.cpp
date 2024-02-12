//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    
	    int m=str1.length();
	    int n=str2.length();
	    // use Aditya verma's concept
	    int del=m-lcs(str1,str2,m,n);
        int add=n-lcs(str1,str2,m,n);
        return add+del;
	} 
	int lcs(string str1,string str2,int m,int n){
	    // Initialising 2D vector with zero
        vector<vector<int>>t(m+1,vector<int>(n+1,0));
        
        for(int i=1;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(str1[i-1]==str2[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                }
                else{
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        return t[m][n];
	}
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends
