//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    
    // Ref : https://discuss.geeksforgeeks.org/comment/dc6264a0d32086f3d03c4f7187a0ed97/practice

	public:
	int count_zeros(int arr[],int i) {  //returns the numberof zeros in array till index i
	
	    int count=0;
	    for(int j=0;j<i+1;j++){
	        if(arr[j]==0)
	        count++;
	    }
	    return count;
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        
        long long mod=1e9+7;
        
        long long t[n+1][sum+1];
        
        for(int j=0;j<sum+1;j++){
            t[0][j]=0;
        }
        
        for(int i=0;i<n+1;i++){
            t[i][0]= pow(2,count_zeros(arr,i));
        }
        
        for(int i=1;i<n+1;i++) {
            for(int j=1;j<sum+1;j++) {
                if(arr[i-1]<=j){
                    t[i][j]=((t[i-1][j-arr[i-1]]) % mod + (t[i-1][j]) % mod) % mod;
                }
                else{
                    t[i][j] = (t[i-1][j]) % mod;
                }
            }
        }
        return t[n][sum];
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends
