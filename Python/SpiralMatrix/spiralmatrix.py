# -*- coding: utf-8 -*-
import numpy as np

if __name__ == '__main__':
  n = int(input("Side of matrix (e.g. 4 for 4*4 matrix) : "))
  i, j, c, val, nn = 0, 0, 0, 1, n**2               #row, columns, count, iterartor value, no. of elements in matrix
  mat = np.zeros([n, n], dtype=int)   #initialize matrix
  while val <= nn:
        while j < n - 1:
            mat[i][j] = val
            val += 1
            j += 1
        while i < n - 1:
            mat[i][j] = val
            val += 1
            i += 1
        while j > c:
            mat[i][j] = val
            val += 1
            j -= 1
        while i > c:
            mat[i][j] = val
            val += 1
            i -= 1
        n -= 1
        i += 1
        j += 1
        c += 1
        if val == nn:
            a[i][j] = val
            break
  n = int(np.sqrt(nn))
  mat = mat.reshape(n,n)
  print("Spiral matrix is:\n", mat)