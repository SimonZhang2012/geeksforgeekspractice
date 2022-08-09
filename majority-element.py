#https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1

class Solution:
    def majorityElement(self, A, N):
        #Your code here
        currentCount = 0
        
        for element in A:
            if currentCount == 0:
                currentMajority = element
                currentCount = 1
            elif element == currentMajority:
                currentCount += 1
            else: # element != currentMajority
                currentCount -= 1
                
            if currentCount > N / 2:
                return currentMajority
                
        count = 0 
        for element in A:
            if element == currentMajority:
                count +=1
                if count > N /2:
                    return currentMajority
        return -1
