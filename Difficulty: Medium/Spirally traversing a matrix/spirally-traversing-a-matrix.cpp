//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        // code here
        vector<int> ans;
        int row = matrix.size();
        int col = matrix[0].size();
        int count = 0;
        int total = row * col;
        int startingRow = 0;
        int startingCol = 0;
        int endingRow = row - 1;
        int endingCol = col - 1;
    
        while (count < total) {
          for (int index = startingCol; index <= endingCol && count < total;index++) 
          {
            ans.push_back(matrix[startingRow][index]);
            count++;
          }
          startingRow++;
    
          for (int index = startingRow; index <= endingRow && count < total;index++) 
          {
            ans.push_back(matrix[index][endingCol]);
            count++;
          }
          endingCol--;
    
          for (int index = endingCol; index >= startingCol && count < total;index--) 
          {
            ans.push_back(matrix[endingRow][index]);
            count++;
          }
          endingRow--;
    
          for (int index = endingRow; index >= startingRow && count < total;index--) 
          {
            ans.push_back(matrix[index][startingCol]);
            count++;
          }
          startingCol++;
        }
    
        return ans;
    
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++) {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends