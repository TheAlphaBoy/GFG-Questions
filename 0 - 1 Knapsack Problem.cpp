//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       
       // sol 1 : Recursive Approach (TLE occur)
       
    //   // Base Case
       
    //   if(n==0 || W==0){
    //       return 0;
    //   }
       
    //   // Choice Diagram Code 
       
    //   // Choice to include item or not
       
    //   if(W >= wt[n-1]) {
    //       return max((val[n-1] + knapSack(W-wt[n-1],wt,val,n-1)),knapSack(W,wt,val,n-1));
    //   }
    //   // No choice
    //   else{
    //       return knapSack(W,wt,val,n-1);
    //   }
    
    // sol 2 : Using DP (Memoization or Top-Down Approach)
    
    vector<vector<int>> t (n+1,vector<int>(W+1,-1));
    return solve(W,wt,val,n,t);
       
       
    }
    int solve(int W,int wt[],int val[],int n,vector<vector<int>>&t) {
        
        // Base Case
       
       if(n==0 || W==0){
           return 0;
       }
       
       // pehle hi check karlo ki kisi bhi block me element -1 ke alawa koi element hai to usi ko return kardo
       if(t[n][W] != -1) {
           return t[n][W];
       }
       
       // Choice Diagram Code
       
       // Choice to include item or not
       
       if(W >= wt[n-1]) {
           t[n][W]=max((val[n-1] + solve(W-wt[n-1],wt,val,n-1,t)),0+solve(W,wt,val,n-1,t));
           return t[n][W];
       }
       // No choice
       else{
           t[n][W]=0+solve(W,wt,val,n-1,t);
           return t[n][W];
       }
        
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
