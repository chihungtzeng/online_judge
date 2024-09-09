package leet

import "testing"
import "sort"

func TestR(t *testing.T) {
	var s string = "25525511135"
	var actual []string
	actual = restoreIpAddresses(s)
	expect := []string{"255.255.11.135", "255.255.111.35"}
	if !assertEqual(expect, actual) {
		t.Errorf("%s: expect %#v, got %#v\n", s, expect, actual)
	}
}

func TestR2(t *testing.T) {
	var s string = "1231231231234"
	var actual []string
	actual = restoreIpAddresses(s)
	if len(actual) != 0 {
		t.Errorf("%s: expect length = 0, got %d\n", s, len(actual))
	}

	s = "00000000000000000000000"
	actual = restoreIpAddresses(s)
	if len(actual) != 0 {
		t.Errorf("%s: expect length = 0, got %d\n", s, len(actual))
	}

	s = "000000"
	actual = restoreIpAddresses(s)
	if len(actual) != 0 {
		t.Errorf("%s: expect length = 0, got %d\n", s, len(actual))
	}

	s = "012301230"
	actual = restoreIpAddresses(s)
	if len(actual) != 0 {
		t.Errorf("%s: expect length = 0, got %d\n", s, len(actual))
	}
}

func TestR3(t *testing.T) {
	var s string = "0000"
	var actual []string
	expect := []string{"0.0.0.0"}

	actual = restoreIpAddresses(s)
	if !assertEqual(expect, actual) {
		t.Errorf("%s: expect %#v, got %#v\n", s, expect, actual)
	}
}

func TestR4(t *testing.T) {
	s := "12301230"
	actual := restoreIpAddresses(s)
	expect := []string{"1.230.1.230", "1.230.12.30", "1.230.123.0", "12.30.1.230", "12.30.12.30", "12.30.123.0", "123.0.1.230", "123.0.12.30", "123.0.123.0"}

	if !assertEqual(expect, actual) {
		t.Errorf("%s: expect %#v, got %#v\n", s, expect, actual)
	}
}

func TestR5(t *testing.T) {
	s := "010010"

	actual := restoreIpAddresses(s)
	expect := []string{"0.10.0.10", "0.100.1.0"}

	if !assertEqual(expect, actual) {
		t.Errorf("%s: expect %#v, got %#v\n", s, expect, actual)
	}
}

func assertEqual(expect, actual []string) bool {
	if len(expect) != len(actual) {
		return false
	}
	sort.Strings(expect)
	sort.Strings(actual)
	for i := 0; i < len(expect); i++ {
		if expect[i] != actual[i] {
			return false
		}
	}
	return true
}
