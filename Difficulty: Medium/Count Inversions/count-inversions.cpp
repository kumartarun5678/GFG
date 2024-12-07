//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count inversions in the array.
    int mergeAndCount(vector<int>& arr, vector<int>& temp, int left, int right) {
        int mid = left + (right - left) / 2;
        int cnt = 0;
        
        int i = left; // Starting index for left subarray
        int j = mid + 1; // Starting index for right subarray
        int k = left; // Starting index to be sorted
        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
                cnt += (mid - i + 1); // All remaining elements in left subarray are greater than arr[j]
            }
        }
    
        while (i <= mid) {
            temp[k++] = arr[i++];
        }
    
        while (j <= right) {
            temp[k++] = arr[j++];
        }
    
        for (int i = left; i <= right; i++) {
            arr[i] = temp[i]; // Copy the sorted subarray into original array
        }
    
        return cnt;
    }
    
    int mergeSortAndCount(vector<int>& arr, vector<int>& temp, int left, int right) {
        int cnt = 0;
        if (left < right) {
            int mid = left + (right - left) / 2;
    
            cnt += mergeSortAndCount(arr, temp, left, mid); // Count inversions in left subarray
            cnt += mergeSortAndCount(arr, temp, mid + 1, right); // Count inversions in right subarray
            cnt += mergeAndCount(arr, temp, left, right); // Count inversions while merging
    
        }
        return cnt;
    }
    
    int inversionCount(vector<int>& arr) {
        int n = arr.size();
        vector<int> temp(n);
        return mergeSortAndCount(arr, temp, 0, n - 1);
    }
    
    };
    

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends