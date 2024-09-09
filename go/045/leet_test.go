package leet

import "testing"

func TestJ(t *testing.T) {
	var actual, expect int
	expect = 2
	actual = jump([]int{2, 3, 1, 1, 4})
	if actual != expect {
		t.Errorf("Expect %d, Got %d\n", expect, actual)
	}

	expect = 0
	actual = jump([]int{0})
	if actual != expect {
		t.Errorf("Expect %d, Got %d\n", expect, actual)
	}

	expect = 0
	actual = jump([]int{2})
	if actual != expect {
		t.Errorf("Expect %d, Got %d\n", expect, actual)
	}

	expect = 4
	actual = jump([]int{1, 1, 1, 1, 1})
	if actual != expect {
		t.Errorf("Expect %d, Got %d\n", expect, actual)
	}

	expect = 1
	actual = jump([]int{3, 2, 1})
	if actual != expect {
		t.Errorf("Expect %d, Got %d\n", expect, actual)
	}
	expect = 3
	actual = jump([]int{3, 1, 4, 1, 5, 9, 2, 6, 2, 7, 1, 8, 2, 8})
	if actual != expect {
		t.Errorf("Expect %d, Got %d\n", expect, actual)
	}
}
