// https://practice.geeksforgeeks.org/problems/find-duplicates-in-an-array/1

class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        
        for (int i = 0; i < n; i++) {
            arr[arr[i]%n] += n;
        }
        
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (arr[i] >= n*2) {
                result.push_back(i);
            }
        }
        
        if (result.empty()) {
            result.push_back(-1);
        }
        
        return result;
    }
};
