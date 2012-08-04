#!/bin/bash
# Author : Rajat Khanduja 
# Date : 4/8/12
# Script to run tester.cpp for various test cases in the tests/input folder and compare output with corresponding output file in tests/output folder

function compile 
{
  # Argument 1 is the file that has to be compiled
  filename=$1
  g++ -I . $filename  
}

compile "tester.cpp" 
execname="./a.out"
input_folder="tests/input"
output_folder="tests/output"
temp_output="/tmp/out"

i=1
MAX_TESTS=20
passed=0
total_time=0

while [ $i -le $MAX_TESTS ]
do
  
  t=$(date +%s)
  $execname < $input_folder/$i >$temp_output
  t=$(($(date +%s) - t))
  total_time=$((total_time + t))
  diff=$(diff $temp_output $output_folder/$i)
  
  if [ ${#diff} -ne 0 ]
  then
    echo "Failed for "$i
  else
    passed=$((passed + 1))
  fi

  i=$((i + 1))
done

echo "Passed "$passed" tests"
