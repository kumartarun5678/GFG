//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {

    // Function to find the trapped water between the blocks.
  public:
     int trappingWater(vector<int> &arr) {
       int max = 0;
        int count = 0;
        int result = 0;

        
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] >= max) {
                // When a new max (or equivalent) is found
                max = arr[i];
                result += count;
                count = 0;
            } else {
                // Otherwise increment count
                count += max - arr[i];
            }
        }
        max = 0;
        count = 0;

        // Backwards Iteration
        for (int i = arr.size() - 1; i >= 0; i--) {
            if (arr[i] > max) {
                // When a new max is found
                max = arr[i];
                result += count;
                count = 0;
            } else {
               
                count += max - arr[i];
            }
        }

        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.trappingWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends