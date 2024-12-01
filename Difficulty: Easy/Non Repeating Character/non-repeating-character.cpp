//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the first non-repeating character in a string.
    char nonRepeatingChar(string &s) {
        // Your code here
        // sort(s.begin(),s.end());
        unordered_map<char,int>mp;
        for(auto &ch:s){
            mp[ch]++;
        }
        for(int i=0;i<s.size();i++){
                if (mp.find(s[i])!=mp.end()) {
                     if(mp[s[i]]==1)
                     {return s[i];}
                }
          }
        return '$';
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;

    while (T--) {

        string S;
        cin >> S;
        Solution obj;
        char ans = obj.nonRepeatingChar(S);

        if (ans != '$')
            cout << ans;
        else
            cout << "-1";

        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends