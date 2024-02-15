//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

//  Sol 1 : Recursive Approach

    // int matrixMultiplication(int n, int arr[])
    // {
    //     // code here
        
    //     // step 1 : Find i & j
    //     int i=1;
    //     int j=n-1;
        
    //     return solve(arr,i,j);
    // }
    // int solve(int arr[],int i,int j){
    //     // step 2 : Base Case
    //     if(i>=j){
    //         return 0;
    //     }
    //     // Step 3 : find k loop scheme
    //     int mini = INT_MAX;
    //     for(int k=i;k<j;k++){
    //         int temp_ans=solve(arr,i,k) + solve(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];
    //         // Step 4 : Calculate the min temp_ans and store in mini
    //         if(temp_ans<mini){
    //             mini = temp_ans;
    //         }
    //     }
    //     return mini;
    // }
    
    // Sol 2 : Using Memoization Apprpach (D.P.)
    
    // creating globally
    int t[101][101];
    
    int matrixMultiplication(int n, int arr[]) {
        
        int i=1;
        int j=n-1;
        memset(t,-1,sizeof(t));
        return mcm(arr,i,j);
    }
    
    int mcm(int arr[],int i,int j){
        // BC
        if(i>=j){
            return 0;
        }
        
        if(t[i][j] != -1){
            return t[i][j];
        }
        int mini=INT_MAX;
        for(int k=i;k<j;k++){
            int temp_ans=mcm(arr,i,k) + mcm(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];
            if(temp_ans<mini){
                mini=temp_ans;
            }
        }
        return t[i][j]=mini;
        
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
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends
