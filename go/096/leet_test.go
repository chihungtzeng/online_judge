package leet

import "testing"

func TestN(t *testing.T) {
	tcs := [][]int{
		{1, 1},
		{2, 2},
		{3, 5},
		{4, 14},
	}
	for _, tc := range tcs {
		input := tc[0]
		expect := tc[1]
		actual := numTrees(input)
		if expect != actual {
			t.Errorf("%d: expect %d, got %d\n", input, expect, actual)
		}
	}
}
