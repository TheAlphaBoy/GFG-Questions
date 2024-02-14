//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    
		    string a=str;
		    string b=a;
		    int m=a.length();
		    int n=b.length();
		    return lcs(a,b,m,n);
		}
		
		int lcs(string a,string b,int m,int n){
		    vector<vector<int>>t(m+1,vector<int>(n+1,0));
		    
		    for(int i=1;i<m+1;i++){
		        for(int j=1;j<n+1;j++){
		            if(a[i-1]==b[j-1] && i!=j){
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
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
