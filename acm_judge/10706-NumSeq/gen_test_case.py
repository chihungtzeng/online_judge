
def main():
    tc = range(1, 100) + range(950, 1005) + range(2**31 - 50, 2**31)
    print len(tc)
    for item in tc:
        print item


if __name__ == "__main__":
    main()
