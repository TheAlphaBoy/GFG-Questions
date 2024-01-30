//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    // Ref : Editorial sol
    
    public:
    
    static bool cmp(Item a,Item b){
        double ans1=(double)a.value/a.weight;
        double ans2=(double)b.value/b.weight;
        // jo bhi bada hai usse return kro
        return ans1>ans2;;
    }
    
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        
        sort(arr,arr+n,cmp);
        
        int currwt=0;
        double finalval=0.0;
        
        for(int i=0;i<n;i++){
            if(currwt + arr[i].weight<=W){
                currwt += arr[i].weight;
                finalval += arr[i].value;
            }
            else{
                int remainwt=W-currwt;
                finalval += arr[i].value * ((double)remainwt/arr[i].weight);
                break;
            }
        }
        return finalval;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(6)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends
