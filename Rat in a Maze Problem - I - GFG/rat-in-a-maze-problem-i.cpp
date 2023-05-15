//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool issafe(int x,int y,int n,vector<vector<int>> &arr,vector<vector<bool>>&vis){
        if((x>=0 && x<n) && (y>=0 && y<n) && arr[x][y] == 1 && vis[x][y]!=1){
            return true;
        }
        return false;
    }
    void solve(vector<vector<int>> &arr,vector<vector<bool>>&vis,int x,int y,int n,string path,vector<string>&ans){
        if(x == n-1 && y == n-1){
            ans.push_back(path);
            return;
        }
        // mark visited to the node
        vis[x][y]=1;
        //for downward
        if(issafe(x+1,y,n,arr,vis)){
            solve(arr,vis,x+1,y,n,path+"D",ans);
        }
        //for left
        if(issafe(x,y-1,n,arr,vis)){
            solve(arr,vis,x,y-1,n,path+"L",ans);
        }
        //for right
        if(issafe(x,y+1,n,arr,vis)){
            solve(arr,vis,x,y+1,n,path+"R",ans);
        }
        //for up
        if(issafe(x-1,y,n,arr,vis)){
            solve(arr,vis,x-1,y,n,path+"U",ans);
        }
        //mark unvisited while backtracking
        vis[x][y]=0;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string>ans;
        vector<vector<bool>>vis(n,vector<bool>(n,0));
        if(m[0][0] == 0){
            return ans;
        }
        string path="";
        solve(m,vis,0,0,n,path,ans);
        return ans;
    }
};
    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends