package leet

import "testing"

func TestS(t *testing.T) {
	var expect, actual bool
	var s1, s2 string

	s1, s2 = "great", "rgeat"
	expect, actual = true, isScramble(s1, s2)
	if expect != actual {
		t.Errorf("s1: %s, s2: %s: expect %t, got %t\n", s1, s2, expect, actual)
	}

	s1, s2 = "abcde", "caebd"
	expect, actual = false, isScramble(s1, s2)
	if expect != actual {
		t.Errorf("s1: %s, s2: %s: expect %t, got %t\n", s1, s2, expect, actual)
	}

	s1, s2 = "abb", "bba"
	expect, actual = true, isScramble(s1, s2)
	if expect != actual {
		t.Errorf("s1: %s, s2: %s: expect %t, got %t\n", s1, s2, expect, actual)
	}
	s1, s2 = "abc", "bca"
	expect, actual = true, isScramble(s1, s2)
	if expect != actual {
		t.Errorf("s1: %s, s2: %s: expect %t, got %t\n", s1, s2, expect, actual)
	}

}
