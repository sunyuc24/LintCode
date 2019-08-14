# LintCode
Report my LintCode problem's solution.

#########Update 2019.8.9###########

6.Merge Two Sorted Array
Merge two given sorted ascending integer array A and B into a new sorted integer array.
Example:

Input:  A=[1,2,3,4], B=[2,4,5,6]
Output: [1,2,2,3,4,4,5,6]
	
Explanation: return array merged.
This problem can solved with Binary search algorithm.
Binary search is a fast search algorithm with run-time complexity of ¦¯(log n). 
The array should be in the sorted form.
Procedure binary_search

   A ¡û sorted array
   n ¡û size of array
   x ¡û value to be searched

   Set lowerBound = 1
   Set upperBound = n 

   while x not found
      if upperBound < lowerBound 
         EXIT: x does not exists.
   
      set midPoint = lowerBound + ( upperBound - lowerBound ) / 2
      
      if A[midPoint] < x
         set lowerBound = midPoint + 1
         
      if A[midPoint] > x
         set upperBound = midPoint - 1 

      if A[midPoint] = x 
         EXIT: x found at location midPoint
   end while
   
end procedure