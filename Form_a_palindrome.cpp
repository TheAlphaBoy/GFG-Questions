//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int countMin(string str){
    //complete the function here
    
    // Same as minimum number of deletion to make it palindrome
    // use LPS function (Longest Palindromic Subsequence)
    
    string a=str;
    string b(a.rbegin(),a.rend());
    int m=a.length();
    int n=b.length();
    return m-lps(a,b,m,n);
    }
    // LPS function (Longest Palindromic Subsequence)
    int lps(string a,string b,int m,int n){
        vector<vector<int>>t(m+1,vector<int>(n+1,0));
        
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(a[i-1]==b[j-1]){
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
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends
