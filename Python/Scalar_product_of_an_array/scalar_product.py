import sys
import numpy as np


def min_max_scalar_product(arr1, arr2):
    """
    Calculates the minimum and the maximum scalar product 
    between two given 1D numpy arrays.
    """

    # Dot product between: first array ascending, second array descending
    min_sp = np.dot(np.sort(arr1), np.sort(arr2)[::-1])

    # Dot product between: first array ascending, second array ascending
    max_sp = np.dot(np.sort(arr1), np.sort(arr2))

    return min_sp, max_sp


if __name__ == "__main__":
    if len(sys.argv) != 3:
        raise ValueError('Two input arrays needed!')
    
    # Split the input strings and turn them into numpy arrays of dtype float
    arr1 = np.asarray(sys.argv[1].split(','), dtype=np.float)
    arr2 = np.asarray(sys.argv[2].split(','), dtype=np.float)
    
    # Print input arrays
    print('Input array 1: ', arr1)
    print('Input array 2: ', arr2)
    
    # Calculate scalar product
    min_sp, max_sp = min_max_scalar_product(arr1, arr2)

    # Print result
    print('Minimum scalar product: %.2f' % min_sp)
    print('Maximum scalar product: %.2f' % max_sp)
    