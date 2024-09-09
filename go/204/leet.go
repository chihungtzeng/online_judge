package leet

import "sort"

var primes = []int{2, 3, 5}
var upto = 5
var offset = 2

func countPrimes(n int) int {
	if n >= upto {
		extend(n)
	}

	return sort.SearchInts(primes, n)
}

func extend(n int) {
	for i := upto + offset; i < n; i += offset {
		offset = 6 - offset
		upto = i
		if isPrime(i) {
			primes = append(primes, i)
		}
	}
}

func isPrime(n int) bool {
	for i, j := 2, len(primes)-1; i < j; i++ {
		val := primes[i]
		if val*val > n {
			break
		}
		if n%val == 0 {
			return false
		}
	}
	return true
}
