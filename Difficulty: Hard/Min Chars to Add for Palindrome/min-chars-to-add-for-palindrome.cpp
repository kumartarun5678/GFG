//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minChar(string& s) {
        string reversedS = s;
        reverse(reversedS.begin(), reversedS.end());
        
        string temp = s + "#" + reversedS; // Combine original, separator, and reversed string
        int n = temp.size();
        vector<int> lps(n, 0); // LPS array
    
        // Compute the LPS array
        for (int i = 1; i < n; i++) {
            int j = lps[i - 1];
            while (j > 0 && temp[i] != temp[j]) {
                j = lps[j - 1];
            }
            if (temp[i] == temp[j]) {
                j++;
            }
            lps[i] = j;
        }
    
        // The length of the longest palindromic suffix is given by the last value in the LPS array
        int longestPalindromicSuffix = lps[n - 1];
        return s.size() - longestPalindromicSuffix; // Characters to add
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.minChar(str);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends