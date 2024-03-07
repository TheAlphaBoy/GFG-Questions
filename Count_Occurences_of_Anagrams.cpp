//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    // code here
	    
	    int k=pat.length();
	    int n=txt.length();
	    // count pattern ke characters
	    unordered_map<char,int>mpat;
	    for(int i=0;i<k;i++){
	        mpat[pat[i]]++;
	    }
	    // Count unique elements of characters
	    int cnt = mpat.size();
	    int ans=0,i=0,j=0;
	    while(j<n){
	        // Calculations
	        // Search pattern in txt
	        if(mpat.find(txt[j]) != mpat.end()){
	            mpat[txt[j]]--;
	            if(mpat[txt[j]] == 0){
	                cnt--;
	            }
	        }
	        // Expanding the window
	        if(j-i+1 < k){
	            j++;
	        }
	        else if(j-i+1 == k){
	            if(cnt==0){
	                ans++;
	            }
	            // Remove previous calculation
	            if(mpat.find(txt[i]) != mpat.end()){
	                mpat[txt[i]]++;
	                if(mpat[txt[i]]==1){
	                    cnt++;
	                }
	            }
	            i++;
	            j++;
	        }
	    }
	    return ans;
	    
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
