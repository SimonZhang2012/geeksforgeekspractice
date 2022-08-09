///https://practice.geeksforgeeks.org/problems/peak-element/1?page=1&category[]=Arrays&sortBy=submissions


class Solution:   
    def peakElement(self,arr, n):
        # Code here
        if n ==1:
            return 0
        
        if arr[0] >= arr[1]:
            return 0
            
        if arr[-1] >= arr[-2]:
            return n-1
            
        for i in range(2, len(arr)-1):
            if arr[i] >= arr[i-1] and arr[i] >= arr[i+1]:
                return i
        return 
        
