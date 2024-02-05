// Partitions with Given Difference

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  // Ref : https://discuss.geeksforgeeks.org/comment/093ce8f4de532dace91cc1e62bd453e3/practice
  
  int countsubsetwithsums1(int n,vector<int>&arr,int s1){
      
      int mod=1e9+7;
      vector<vector<int>>t(n+1,vector<int>(s1+1));
      // Initiallising the dp as per the given conditions
      for(int i=0;i<n+1;i++){
            for(int j=0;j<s1+1;j++){
                if(i==0){
                    t[i][j]=0;
                }
                if(j==0){
                    t[i][j]=1;
                }
            }
        }
      for(int i=1;i<n+1;i++){
          for(int j=0;j<s1+1;j++){
              if(arr[i-1]<=j){
                  t[i][j]=(t[i-1][j-arr[i-1]] + t[i-1][j])%mod;
              }
              else{
                  t[i][j]=t[i-1][j] % mod;
              }
          }
      }
      return t[n][s1]%mod;
      
  }
  
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        
        int mod=1e9+7;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i]%mod;
        }
        // if sum is odd and sum is negative then return 0
        if(sum-d < 0 || ((d+sum) % 2)) return 0;
        
        int s1=(d+sum)/2;
        return countsubsetwithsums1(n,arr,s1);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends
