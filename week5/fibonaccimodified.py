#!/bin/python3

import math
import os
import random
import re
import sys

'''
I had to solve this problem in python
since not even unsigned long long int is enough
to hold the numbers that the test cases reach
'''

def fibonacciModified(t1, t2, n):
    sys.set_int_max_str_digits(0)
    while n>2:
        sum = 0
        sum = t1 + pow(t2, 2)
        t1 = t2
        t2 = sum
        n -= 1
    
    return sum

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    t1 = int(first_multiple_input[0])

    t2 = int(first_multiple_input[1])

    n = int(first_multiple_input[2])

    result = fibonacciModified(t1, t2, n)

    fptr.write(str(result) + '\n')

    fptr.close()
