//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    // int lcs(int n, int m, string s1, string s2)
    // {
        // your code here
        
        // Sol 1 : Recursive Approach (TLE ocuured)
        
        // BC
        // if(n==0 || m==0)
        // return 0;
        // // Choice Diagram
        // if(s1[n-1]==s2[m-1]){
        //     return 1+lcs(n-1,m-1,s1,s2);
        // }
        // else{
        //     return max(lcs(n-1,m,s1,s2),lcs(n,m-1,s1,s2));
        // }
    // }
        
        // Sol 2: Memoization Approach (dp's Top-down Approach)
        
        int solve(int n,int m,string &s1,string &s2,int t[][1001]){
            // BC
            if(n==0 || m==0){
                return 0;
            }
            // if already executed the value to that element then return that index
            if(t[n][m] !=-1){
                return t[n][m];
            }
            // Choice diagram
            if(s1[n-1]==s2[m-1]){
                    return t[n][m]= 1+solve(n-1,m-1,s1,s2,t);
            }
            else{
                return t[n][m]= max(solve(n-1,m,s1,s2,t),solve(n,m-1,s1,s2,t));
            }
        }
        
    int lcs(int n, int m, string s1, string s2)
    {
        int t[1001][1001];
        memset (t,-1,sizeof(t));
        return solve(n,m,s1,s2,t);
        
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends
