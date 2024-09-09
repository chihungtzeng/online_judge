package leet

import "testing"

func TestN(t *testing.T) {
	tcs := map[int]int{
		4:  2,
		8:  92,
		10: 724,
		//		14: 365596,
	}
	for n, expect := range tcs {
		actual := totalNQueens(n)
		if actual != expect {
			t.Errorf("%d: expect %d, got %d\n", n, expect, actual)
		}
	}
}
