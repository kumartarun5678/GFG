//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minRemoval(vector<vector<int>> &intervals) {
        int n = intervals.size();
        if (n == 0) return 0;
        sort(intervals.begin(), intervals.end());
    
        int cnt = 0;
        int prev = intervals[0][1]; // Initialize prev with the end of the first interval
    
        for (int i = 1; i < n; i++) {
            // Check for overlap
            if (intervals[i][0] < prev) {
                cnt++;
                prev = min(prev, intervals[i][1]); // Update prev to the min end
            } else {
                prev = intervals[i][1]; // No overlap, just update prev
            }
        }
    
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        Solution obj;
        cout << obj.minRemoval(intervals) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends