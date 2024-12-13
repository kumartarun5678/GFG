//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   vector<vector<int>> insertInterval(vector<vector<int>> &intervals, vector<int> &newInterval) {
    vector<vector<int>> result;
    bool inserted = false;

    for (const auto &interval : intervals) {
        if (interval[1] < newInterval[0]) {
            // Current interval ends before newInterval starts
            result.push_back(interval);
        } else if (interval[0] > newInterval[1]) {
            // Current interval starts after newInterval ends
            if (!inserted) {
                result.push_back(newInterval);
                inserted = true;
            }
            result.push_back(interval);
        } else {
            // Overlapping intervals, merge them
            newInterval[0] = min(newInterval[0], interval[0]);
            newInterval[1] = max(newInterval[1], interval[1]);
        }
    }

    // Add the merged interval if it was not inserted
    if (!inserted) {
        result.push_back(newInterval);
    }

    return result;
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
        vector<int> newInterval(2);
        cin >> newInterval[0] >> newInterval[1];

        Solution obj;
        vector<vector<int>> ans = obj.insertInterval(intervals, newInterval);
        cout << "[";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[" << ans[i][0] << ',' << ans[i][1] << ']';
            if (i != (ans.size() - 1))
                cout << ",";
        }
        cout << "]" << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends