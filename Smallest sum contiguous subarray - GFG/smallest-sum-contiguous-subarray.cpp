//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  int smallestSumSubarray(vector<int>& a){
      //Code here
      int minSofar=INT_MAX,currMin=0;
      for(int i=0;i<a.size();i++)
      {
          currMin=currMin+a[i];
          minSofar=min(minSofar,currMin);
          if(currMin>a[i])
        {  currMin=a[i];
          minSofar=min(minSofar,currMin);
        }
          
      }
      return minSofar;
  }
};


//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        
        int ans = ob.smallestSumSubarray(a);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends