// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(int arr[], int n){
        int cs=0;
        int ms=0;
        int lar=arr[0];
        
        for(int i=0;i<n;i++){
            if(arr[i]>lar) lar=arr[i];
            cs+=arr[i];
            if(cs<0) cs=0;
            if(cs>ms){
                ms = cs;
            }
        }
        if(ms<=0){
            return lar;
        }
        else
            return ms;
    }
};

// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends