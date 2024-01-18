//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    private:
    void solve(vector<int> arr,vector<int>op,int i,set<vector<int>>&st){
        // BC
        if(i==arr.size()){
            st.insert(op);
            return;
        }
        solve(arr,op,i+1,st);
        op.push_back(arr[i]);
        solve(arr,op,i+1,st);
        
    }
    
    public:
    //Function to find all possible unique subsets.
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        // code here 
        
        vector<int>op;
        sort(arr.begin(),arr.end());
        set<vector<int>>st;
        solve(arr,op,0,st);
        vector<vector<int>>ans;
        for(auto i:st){
            ans.push_back(i);
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   



// } Driver Code Ends
