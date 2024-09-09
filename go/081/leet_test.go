package leet

import "testing"

func TestS(t *testing.T) {
	nums := []int{2, 5, 6, 0, 0, 1, 2}
	target := 0
	expect := true
	if search(nums, target) != expect {
		t.Errorf("expect %t\n", expect)
	}
	target = 3
	expect = false
	if search(nums, target) != expect {
		t.Errorf("expect %t\n", expect)
	}
}
