//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // You need to complete this function

    // avoid space at the starting of the string in "move disk....."
    int count=0;
    long long toh(int N, int from, int to, int aux) {
        // Your code here
        // BC
        if(N==0){
            return count;
        }
        count++;
        // Hypothesis step
        toh(N-1,from,aux,to);
        // print Nth disc from source rod to destination rod
        cout<<"move disk "<<N<<" from rod "<<from<<" to rod "<<to<<endl;
        //Induction step
        toh(N-1,aux,to,from);
    }

};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;//testcases
    while (T--) {
        
        int N;
        cin >> N;//taking input N
        
        //calling toh() function
        Solution ob;
        
        cout << ob.toh(N, 1, 3, 2) << endl;
    }
    return 0;
}



// } Driver Code Ends
