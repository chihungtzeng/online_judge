package leet

import "testing"

func TestC(t *testing.T) {
	var tcs = map[string]int{
		"C":       100,
		"III":     3,
		"IV":      4,
		"IX":      9,
		"LVIII":   58,
		"MCMXCIV": 1994,
	}
	for key, expect := range tcs {
		actual := romanToInt(key)
		if actual != expect {
			t.Errorf("%s: expect %d, got %d\n", key, expect, actual)
		}
	}
}
