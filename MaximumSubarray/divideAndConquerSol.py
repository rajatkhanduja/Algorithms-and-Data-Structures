#!/usr/bin/python
# Author : Rajat Khanduja
# Program to solve maximum subarray problem


def crossMaxArray (arr):
  mid = len(arr) / 2
  sum = 0
  maxSum = float ('-inf')
  a = mid
  minInd = a
  while a >= 0:
    sum += arr[a]
    if (sum > maxSum):
      maxSum = sum
      minInd = a
    a -= 1

  a = mid + 1
  maxInd = a
  while a < len(arr):
    sum += arr[a]
    if (sum > maxSum):
      maxSum = sum
      maxInd = a
    a += 1
  
  print minInd, maxInd, arr[minInd:maxInd + 1]
  return (arr[minInd:maxInd], maxSum)

def maxSubarray (arr):
  if len(arr) == 1:
    return (arr, arr[0])

  mid = len(arr) / 2
  print maxSubarray (arr[ : len(arr) / 2])
  (leftMax, leftMaxSum)   = maxSubarray (arr[ : len(arr) / 2])
  (rightMax, rightMaxSum) = maxSubarray (arr[len(arr) / 2 : ])
  (crossMax, crossMaxSum) = crossMaxArray (arr) 

  maxSum = max (leftMaxSum, rightMaxSum, crossMaxSum)

  if maxSum == leftMaxSum :
    print "Returning left" + str((leftMax, leftMaxSum))
    return (leftMax, leftMaxSum)
  elif maxSum == rightMaxSum:
    print "Returning right" + str((leftMax, leftMaxSum))
    return (rightMax, rightMaxSum)
  else :
    print "Returning cross" + str((leftMax, leftMaxSum))
    return (crossMax, crossMaxSum)


print maxSubarray ([-12,-2,-1, -3])
