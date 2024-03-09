//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    
    void findlps(string pat,vector<int>&lps){
        int prefix=0;
        int suffix=1;
        while(suffix<pat.length()){
            if(pat[prefix] == pat[suffix]){
                lps[suffix]=prefix+1;
                ++prefix;
                ++suffix;
            }
            else{
                if(prefix==0){
                    lps[suffix]=0;
                    ++suffix;
                }
                else{
                    prefix=lps[prefix-1];
                }
            }
        }
    }
    
        vector <int> search(string pat, string txt)
        {
            //code here
            
            vector<int>lps(pat.length(),0);
            findlps(pat,lps);
            int first=0;
            int second=0;
            vector<int>ans;
            while(first<txt.length()){
                if(txt[first] == pat[second]){
                    ++first;
                    ++second;
                }
                if(second == pat.length()){
                    ans.push_back(first-second+1);
                    second=lps[second-1];
                }
                else if(txt[first] != pat[second]){
                    if(second==0){
                        ++first;
                    }
                    else{
                        second=lps[second-1];
                    }
                }
            }
            return ans;
            
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends
