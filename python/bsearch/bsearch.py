
def bsearch(a, target):
    left = 0
    right = len(a) - 1
    mid = 0
    while left <= right:
        mid = (left + right) // 2
        if a[mid] < target:
            left = mid + 1
        elif a[mid] == target:
            return mid
        else:
            right = mid - 1
    return left  # lower_bound


pi=[1,2,3,13,13,15,16]
pi.sort()

print(list(range(len(pi))))
print(pi)
for target in range(-1, 18):
    idx = bsearch(pi, target)
    mapped_value = pi[idx] if idx < len(pi) else None
    print("target: {}, idx: {}, pi[idx]={}".format(target, idx, mapped_value))
    if target in pi and pi[idx] != target:
        print("WROING!")

