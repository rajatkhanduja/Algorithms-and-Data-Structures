#!/usr/bin/python
# Author : Rajat Khanduja
# Date : 8/3/2012
# A script to test the programs in the associated folders.
#
# Goals :- 
#    - The program runs the program with the test input and compares with the test output.
#        - If the folder doesn't contain the test input, it generates test cases using the genCases.py [default] (read requirements).
#        - Program reports if the outputs don't match. Reporting maybe turned off, in case the output needs to be observed by a human.
#        - 
#    - The program compiles a file from source code and conducts the above mentioned tests.
#        - Language and the compiler to be used, can be determined using the extension of the file.
#        - The user can provide the compiler to be used and the parameters to be passed to the compiler/interpreter.
#
#    - The program waits for 'k' seconds which defaults to 10 (unless overridden by user) before killing the program.
#
# TODO XXX XXX XXX Complete XXX XXX XXX
# Requirements : Following directory structure is required to be able to meet the above goals.
#
