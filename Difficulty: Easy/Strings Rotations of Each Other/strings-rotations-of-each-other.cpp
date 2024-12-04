//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to check if two strings are rotations of each other or not.
bool areRotations(string &s1, string &s2) {
    if (s1.size() != s2.size()) return false;

    // Build the prefix-suffix table for KMP
    string combined = s1 + s1;
    vector<int> lps(s2.size(), 0);
    int len = 0, i = 1;

    while (i < s2.size()) {
        if (s2[i] == s2[len]) {
            lps[i++] = ++len;
        } else {
            if (len != 0)
                len = lps[len - 1];
            else
                lps[i++] = 0;
        }
    }

    // Perform KMP Search
    i = 0;
    int j = 0;
    while (i < combined.size()) {
        if (s2[j] == combined[i]) {
            i++;
            j++;
        }

        if (j == s2.size()) {
            return true; // Match found
        } else if (i < combined.size() && s2[j] != combined[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    return false;
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1;
        string s2;
        cin >> s1 >> s2;
        Solution sol;
        int result = sol.areRotations(s1, s2);
        if (result) {
            cout << "true" << endl;

        } else {
            cout << "false" << endl;
        }
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends