//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
int search(vector<int>& arr, int key) {
    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if mid is the key
        if (arr[mid] == key) {
            return mid;
        }

        // Determine which part is sorted
        if (arr[left] <= arr[mid]) {
            // Left part is sorted
            if (key >= arr[left] && key < arr[mid]) {
                right = mid - 1;  // Search in the left part
            } else {
                left = mid + 1;  // Search in the right part
            }
        } else {
            // Right part is sorted
            if (key > arr[mid] && key <= arr[right]) {
                left = mid + 1;  // Search in the right part
            } else {
                right = mid - 1;  // Search in the left part
            }
        }
    }

    return -1;  // Key not found
}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends