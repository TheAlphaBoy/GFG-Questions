//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    
    // int knapSack(int W, int wt[], int val[], int n) 
    // {
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
    //}
    
    // sol 2 : Using DP (Memoization or Top-Down Approach)
    
    // int knapSack(int W, int wt[], int val[], int n) 
    // {
    
    // vector<vector<int>> t (n+1,vector<int>(W+1,-1));
    // return solve(W,wt,val,n,t);
       
       
    // }
    // int solve(int W,int wt[],int val[],int n,vector<vector<int>>&t) {
        
    //     // Base Case
       
    //   if(n==0 || W==0){
    //       return 0;
    //   }
       
    //   // pehle hi check karlo ki kisi bhi block me element -1 ke alawa koi element hai to usi ko return kardo
    //   if(t[n][W] != -1) {
    //       return t[n][W];
    //   }
       
    //   // Choice Diagram Code
       
    //   // Choice to include item or not
       
    //   if(W >= wt[n-1]) {
    //       t[n][W]=max((val[n-1] + solve(W-wt[n-1],wt,val,n-1,t)),0+solve(W,wt,val,n-1,t));
    //       return t[n][W];
    //   }
    //   // No choice
    //   else{
    //       t[n][W]=0+solve(W,wt,val,n-1,t);
    //       return t[n][W];
    //   }
       
       // sol 3: Using DP (Tabulation Method or Bottom-up method)
       
       int knapSack(int w, int wt[], int val[], int n) 
    {
        // Taking static array bcz we can reduce the TC from O(n^2) to O(n)
        
        // it takes O(n) TC
        
        int t[n+1][w+1];

        // Initialize the first row to 0
        for(int j = 0; j < w+1; j++){
            t[0][j] = 0;
        }
        // Initialize the first column to 0
        for(int i = 1; i < n+1; i++){
            t[i][0] = 0;
}
        // it takes O(n*w) TC
        
        // for(int i=0;i<n+1;i++){
        //   for(int j=0;j<w+1;j++){
        //       if(i == 0 || j == 0)
        //             t[i][j] = 0;
        //   }
        // }
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<w+1;j++){
                // by choice diagram
                if(wt[i-1]<=j){
                    t[i][j]=max(val[i-1] + t[i-1][j - wt[i-1]] , t[i-1][j]);
                }
                else {
                    t[i][j]=t[i-1][j];
                }
            }
        }
        return t[n][w];
        
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
