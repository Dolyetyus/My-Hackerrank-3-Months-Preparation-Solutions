#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'diagonalDifference' function below.
#
# The function is expected to return an INTEGER.
# The function accepts 2D_INTEGER_ARRAY arr as parameter.
#

def diagonalDifference(arr):
    totalDiff = 0
    lr = 0
    rl = 0
    x = 0
    
    for i in range(len(arr)):
        lr += arr[i][i]
    
    for i in range(len(arr))[::-1]:
        rl += arr[x][i]
        x+=1
    
    totalDiff = abs(lr-rl)
    
    return totalDiff

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    arr = []

    for _ in range(n):
        arr.append(list(map(int, input().rstrip().split())))

    result = diagonalDifference(arr)

    fptr.write(str(result) + '\n')

    fptr.close()
