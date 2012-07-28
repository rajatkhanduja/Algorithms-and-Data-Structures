#!/usr/bin/python
# Author : Rajat Khanduja

def bruteForceMaxSubArray (arr):
  maxSum = float('-inf')
  minInd = -1
  maxInd = -1
  for i in range (0, len(arr)):
    maxSumTmp = float ('-inf')
    minIndTmp = i
    maxIndTmp = -1
    sum = 0
    for j in range (i, len(arr)):
      sum += arr[j]
      if sum > maxSumTmp:
        maxSumTmp = sum
        maxIndTmp = j

    if maxSumTmp > maxSum :
      maxSum = maxSumTmp
      minInd = minIndTmp
      maxInd = maxIndTmp

  return arr[minInd:maxInd + 1]
  

print bruteForceMaxSubArray ([-1,2,3])
