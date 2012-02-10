#!/usr/bin/python
# Author : Rajat Khanduja 
# Date : 10 Feb 2012
# This program takes in two strings and calculates the edit distance between them. 

cost_copy       = 0
cost_delete     = 1
cost_insert     = 1
cost_replace    = 1
cost_twiddle    = 1

def edit_distance (string1, string2):
  
  len1  = len(string1)
  len2  = len(string2)
  table = dict()

  for i in range (0,len1 + 1):
    table[i,0] = cost_delete * i

  for i in range (0,len2 + 1):
    table[0,i] = cost_insert * i

  for i in range (1, len1 + 1):
    for j in range (1, len2 + 1) :
      if string1[i-1] == string2[j-1]:
        table[i,j] = table[i-1, j-1] + cost_copy
      else:
        table[i,j] = min ( cost_replace + table[i - 1, j - 1], cost_insert + table[i, j - 1], cost_delete + table[i - 1, j])

        if i >= 2 and j >= 2 and (string1[i-1] == string2[j-2]) and (string1[i-2] == string2[j-1]) :
          table[i,j] = min (table[i,j], cost_twiddle + table[i - 2, j - 2])

  return (table[len1, len2])


def main ():
  inp1 = str(raw_input ())
  inp2 = str(raw_input ())

  print edit_distance (inp1, inp2)


if __name__ == '__main__':
  main()
