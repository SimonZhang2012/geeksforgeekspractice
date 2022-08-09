https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1?page=1&category[]=Arrays&sortBy=submissions

class Solution:
    #User function Template for python3
    
    # arr[]: Input Array
    # N : Size of the Array arr[]
    #Function to count inversions in the array.

    def inversionCount(self, arr, n):
        return self.mergeSort(arr, 0, n - 1)

    def merge(self, arr, left, mid, right):
        i = left
        j = mid
        k = 0
        invCount = 0
        temp = [0 for x in range(right - left + 1)]
     
        while (i < mid) and (j <= right):
            if arr[i] <= arr[j]:
                temp[k] = arr[i]
                k += 1
                i += 1
     
            else:
                temp[k] = arr[j]
                invCount += mid - i
                k += 1
                j += 1
     
        while i < mid:
            temp[k] = arr[i]
            k += 1
            i += 1
     
        while j <= right:
            temp[k] = arr[j]
            k += 1
            j += 1
     
        k = 0
        for i in range(left, right + 1):
            arr[i] = temp[k]
            k += 1
     
        return invCount
 
     
    def mergeSort(self, arr, left, right):
        invCount = 0
     
        if right > left:
            mid = (right + left) // 2
     
            invCount = self.mergeSort(arr, left, mid)
            invCount += self.mergeSort(arr, mid + 1, right)
            invCount += self.merge(arr, left, mid + 1, right)
     
        return invCount
