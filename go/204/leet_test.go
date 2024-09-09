package leet

import "testing"

func TestP(t *testing.T) {
	ns := [][]int{{4, 2}, {10, 4}, {100, 25}, {7920, 1000}, {7919, 999}}

	for _, val := range ns {
		in := val[0]
		expect := val[1]
		actual := countPrimes(in)
		if actual != expect {
			t.Errorf("%d: expect %d, got %d", in, expect, actual)
		}
	}
}

func TestIsP(t *testing.T) {
	nps := []int{25}
	for _, val := range nps {
		if isPrime(val) == true {
			t.Errorf("%d: expect false, got true", val)
		}
	}
}
