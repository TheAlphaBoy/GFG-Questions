//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

// Sol 1 : Recursive Approach

    // int palindromicPartition(string str)
    // {
    //     // code here
        
    //     int i=0;
    //     int n=str.length();
    //     int j=n-1;
    //     return mcm(str,n,i,j);
    // }
    // int mcm(string str,int n,int i,int j){
    //     // BC
    //     if(i>=j){
    //         return 0;
    //     }
    //     if(ispalindrome(str,n,i,j)){
    //         return 0;
    //     }
    //     int mini=INT_MAX;
    //     for(int k=i;k<j;k++){
    //         int temp_ans = mcm(str,n,i,k)+mcm(str,n,k+1,j)+1;
    //         mini=min(mini,temp_ans);
    //     }
    //     return mini;
    // }
    // int ispalindrome(string str,int n,int i,int j){
    //     if(i==j)
    //     return 1;
    //     if(i>j)
    //     return 1;
    //     while(i<j){
    //         if(str[i]!=str[j]){
    //             return 0;
    //         }
    //         i++;
    //         j--;
    //     }
    //     return 1;
    // }
    
    // Sol 2 : Memoization Approach
    
    // declare 2d array globally
    int t[501][501];
    
    int palindromicPartition(string str){
        
        // initialise the dp with -1
        
        memset(t,-1,sizeof(t));
        int i=0;
        int n=str.length();
        int j=n-1;
        return mcm(str,n,i,j);
        
    }
    
    int mcm(string& str,int n,int i,int j){
        // BC
        if(i>=j){
            return 0;
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }
        if(ispalindrome(str,n,i,j)){
            return 0;
        }
        int mini=INT_MAX;
        for(int k=i;k<j;k++){
            //Because if the left string (after partition) is not a palindrome then we can't
            //make a partition there, so it would be a waste of time to check for the ans at 
            //that partition. Also if, left side string is  a palindrome no need to call PP(str,n,i,k)
            //because we will not be doing any partition in the left side, we will just calculate 
            //the ans for right side and add 1(because we just made a partition here).
            if(ispalindrome(str,n,i,k)){
                int temp_ans = mcm(str,n,i,k)+mcm(str,n,k+1,j)+1;
                mini=min(mini,temp_ans);
            }
        }
        return t[i][j] = mini;
    }
    bool ispalindrome(string& str,int n,int i,int j){
        if(i==j)
        return true;
        // if(i>j)
        // return true;
        while(i<j){
            if(str[i]!=str[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
