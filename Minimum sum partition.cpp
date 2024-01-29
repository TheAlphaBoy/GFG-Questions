// Minimum sum partition

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    
    // Ref : https://discuss.geeksforgeeks.org/comment/5aac981c-8a96-41de-90c5-07ece446e1ee/practice

  public:
//   vector<int> solve(bool t[n+1][sum+1],int n,int sum,vector<int>&ans){
//       for(int j=0;j<sum+1;j++){
//           if(t[n][j]==true){
//               ans.push_back(j);
//           }
//       }
//       return ans;
//   }
 
//  bool find_subset(vector<int>arr,int n,int sum,vector<int>&ans){
     
//      bool t[n+1][sum+1];
//      for(int i=0,j=0;j<sum+1;j++){
//          t[0][j]=false;
//      }
//      for(int i=0,j=0;i<n+1;i++){
//          t[i][0]=true;
//      }
//      for(int i=1;i<n+1;i++){
//          for(int j=1;j<sum+1;j++){
//                 if(arr[i-1]<=j){
//                     t[i][j]=t[i-1][j] || t[i-1][j-arr[i-1]];
//                 }
//                 else{
//                     t[i][j]=t[i-1][j];
//                 }
//          }
//      }
//      solve(t,n,sum,ans);
     
//  }
  
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    
	    int sum=0; // or range
	    for(int i=0;i<n;i++){
	        sum += arr[i];
	    }
	    
	    bool t[n+1][sum+1];
	    
        for(int i=0,j=0;j<sum+1;j++){
         t[0][j]=false;
        }
        
        for(int i=0,j=0;i<n+1;i++){
         t[i][0]=true;
        }
        
        for(int i=1;i<n+1;i++){
            
            for(int j=1;j<sum+1;j++){
                if(abs(arr[i-1])<=j){
                    t[i][j]=t[i-1][j] || t[i-1][j-arr[i-1]];
                }
                else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
        
        vector<int>ans;
        
        for(int j=0;j<=sum/2;j++){
            if(t[n][j]==true){
              ans.push_back(j);
            }
        }

	    int mini = INT_MAX;
	    for(int i=0;i<ans.size();i++) {
	        mini=min(mini,sum-2*ans[i]);
	    }
	    return mini;
	    
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends
