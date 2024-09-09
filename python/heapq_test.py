import heapq

def main():
    nums = [[2, 7, 1, 8, 2, 8], [3, 1, 4, 1, 5, 9, 2, 6]]
    ns = []
    for row in nums:
        for n in row:
            ns.append(n)
    heapq.heapify(ns)
    while ns:
        print(heapq.heappop(ns))


if __name__ == "__main__":
    main()
