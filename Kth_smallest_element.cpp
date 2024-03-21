//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        
        // If we use MaxHeap, we have O(k) space and O(nLogk) time.
        // If we use MinHeap, we have O(1) space and O(n + klogn) time.
        
        // If k is small such that k~logk, 
        // MinHeap gets reduced to ~O(n + logn)
        // MaxHeap gets reduced to ~O(n)
        
        // If k is of the order n,<=n:
        // Min gives O(n + nlogn)
        // Max gives O(nlogn)
        
        // So always prefer max for kth smallest and min for kth largest.
        // Side note: if it's explicitly given all elements are distinct, then and only then go for quickselect method.
        
        priority_queue<int>maxHeap;
        
        for(int i=0;i<=r;++i){
            maxHeap.push(arr[i]);
            if(maxHeap.size()>k){
                maxHeap.pop();
            }
        }
        return maxHeap.top();
    }
    
};



//{ Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends
