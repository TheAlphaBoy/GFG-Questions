//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

int solve(int arr[],int n,int sum){
    vector<vector<int>>t(n+1,vector<int>(sum+1,0));
    for(int i=0;i<n;i++){
        t[i][0]=1;
    }
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=j){
                t[i][j]=t[i-1][j-arr[i-1]] || t[i-1][j];
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[n][sum];
    
}

    int equalPartition(int n, int arr[])
    {
        // code here
        
        int sum=0;
        
        for(int i=0;i<n;i++){
            sum +=arr[i];
        }
        if(sum%2!=0){
            return 0;
        }
        else{
            return solve(arr,n,sum/2);
        }
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends
