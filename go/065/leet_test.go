package leet

import "testing"

func TestMatche(t *testing.T) {
	tcs := map[string]bool{
		"1e":         false,
		"1e2.":       false,
		"1e2.1":      false,
		"1e0":        true,
		"1.e0":       true,
		"+1e0":       true,
		"+.2e3":      true,
		"-1e0":       true,
		"2e10":       true,
		"-90e3":      true,
		"e3":         false,
		"6e-1":       true,
		"99e2.5":     false,
		"53.5e93":    true,
		"078332e437": true,
		".2e3":       true,
		".e3":        false,
	}
	for s, expect := range tcs {
		actual := matche(s)
		if actual != expect {
			t.Errorf("%s: should be %t, got %t", s, expect, actual)
		}
	}
}
func TestIs(t *testing.T) {
	tcs := map[string]bool{
		"0":          true,
		" 0.1 ":      true,
		"abc":        false,
		"1 a":        false,
		"2e10":       true,
		" -90e3   ":  true,
		" 1e":        false,
		"e3":         false,
		" 6e-1":      true,
		" 99e2.5 ":   false,
		"53.5e93":    true,
		" --6 ":      false,
		"-+3":        false,
		"95a54e53":   false,
		" ":          false,
		"078332e437": true,
		".2e3":       true,
		".e3":        false,
	}
	for s, expect := range tcs {
		actual := isNumber(s)
		if actual != expect {
			t.Errorf("\"%s\": expect %t, got %t", s, expect, actual)
		}
	}
}
