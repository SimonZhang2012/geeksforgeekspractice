//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    int circularSubarraySum(int arr[], int num){
        
        std::vector<int> input(arr, arr + num);
        if (num == 1) {
            return input[0];
        }
        
        // find the maximum subarray sum using kadane's algorithm
    	// this is to ensure if the maximum sum does not need wrapping
    	int maximum_from_kadane = kadane(input);
    	
    	if (maximum_from_kadane <= 0) {
    	    return maximum_from_kadane;
    	}
    
    	// calculate the total sum of the input array
    	// and also reverse the signs of the elements
    	int max_sum = 0;
    	for (int i = 0; i < input.size(); i++)
    	{
    		max_sum = max_sum + input[i];
    		input[i] = -input[i]; // invert the sign
    	}
    
    	// subtract the minimum sum from the total array sum
    	// total sum = array_sum - -(sum from kadane's algorithm)
    	max_sum = max_sum + kadane(input);
    	
    	//cout << "maximum_from_kadane = " << maximum_from_kadane << endl;
    	//cout << "max_sum = " << max_sum << endl;
    
        // the maximum of the two sum will be the result
    	return (maximum_from_kadane > max_sum) ? maximum_from_kadane : max_sum;
    }
    
    
    
    /**
     * Kadane's algorithm:
     * calculates the maximum subarray sum
     * input: is the input array with integers
     * */
    int kadane(const vector<int> &input)
    {
    
    	// variable to store the size
    	int size = input.size();
    
    	// variable to hold maximum so far
    	int max_so_far = 0;
    
    	// variable to hold current sum
    	int currentSum = 0;
    
    	// iterate over the array and add the elements to the current sum
    	for (int i = 0; i < size; i++)
    	{
    		currentSum = currentSum + input[i]; // add the current element
    
    		// if currentSum is greater than max sum so far then update it
    		if (max_so_far < currentSum)
    			max_so_far = currentSum;
    		// if at any point current sum reaches negative, reset it to 0
    		if (currentSum < 0)
    			currentSum = 0;
    	}
    	
    	// Handle the edge case while all elements are negative 
    	if (max_so_far == 0) {
    	    return *max_element(input.begin(), input.end());
    	}
    
    	return max_so_far;
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends
