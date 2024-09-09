import bisect

def bsearch(ell, target):
    """
    ell -- A list
    target -- Search |target| in |ell|.

    Returns: The index of |target|
    """
    left = 0
    right = len(ell) - 1
    while left <= right:
        middle = ((left + right) >> 1)
        if ell[middle] == target:
            return middle
        elif ell[middle] < target:
            left = middle + 1
        else:
            right = middle - 1
    return middle


def main():
    ell = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59,
           61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127,
           131, 137, 139, 149]
    assert bisect.bisect_left(ell, 11) == bsearch(ell, 11)
    assert 4 == bsearch(ell, 11)
    assert bisect.find_le(ell, 12) == bsearch(ell, 12)
    assert len(ell) - 1 == bsearch(ell, 1234)
    assert 0 == bsearch(ell, -8)

if __name__ == "__main__":
    main()
