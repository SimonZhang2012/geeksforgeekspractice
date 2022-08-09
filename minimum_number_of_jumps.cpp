// Minimum number of jumps


class Solution{
  public:
    int minJumps(int arr[], int n){
        if (n<=1) {
            return 0;
        }
        int maxReach = 0;
        int l = 0;
        int r = 0;
        int jump = 0;
        
        while (l<=r) {
            //cout << "jump =" << jump << endl ;
            //cout << "loopin... [" <<l << r << "]" << endl;
            for (int i =l; i<=r; i++) {
                //cout << "checking..." <<i << endl;
                maxReach = max(maxReach, i + arr[i]);
                if (maxReach >=n-1) {
                    return jump+1;
                } 
            }
            jump ++;
            l = r + 1;
            r = maxReach;
        }
        return -1;
    }
};
