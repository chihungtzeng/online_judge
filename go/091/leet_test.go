package leet

import "testing"

func TestD(t *testing.T) {
	tcs := map[string]int{
		"226":             3,
		"12":              2,
		"31415926271828":  16,
		"314150926271828": 0,
		"314159206271828": 8,
		"0":               0,
		"10":              1,
		"1110":            2,
		"301":             0,
		"20":              1,
		"9":               1,
		"":                0,
	}
	for s, expect := range tcs {
		actual := numDecodings(s)
		if actual != expect {
			t.Errorf("%s: expect %d, got %d\n", s, expect, actual)
		}
	}
}
