package leet

import "testing"

func TestL(t *testing.T) {
	var expect, actual int
	expect = 10
	actual = largestRectangleArea([]int{2, 1, 5, 6, 2, 3})
	if expect != actual {
		t.Errorf("Expect %d, Got %d\n", expect, actual)
	}

	expect = 0
	actual = largestRectangleArea([]int{})
	if expect != actual {
		t.Errorf("Expect %d, Got %d\n", expect, actual)
	}

	expect = 100
	actual = largestRectangleArea([]int{100})
	if expect != actual {
		t.Errorf("Expect %d, Got %d\n", expect, actual)
	}

	expect = 20
	actual = largestRectangleArea([]int{10, 15})
	if expect != actual {
		t.Errorf("Expect %d, Got %d\n", expect, actual)
	}

	expect = 1
	actual = largestRectangleArea([]int{0, 1, 0, 1})
	if expect != actual {
		t.Errorf("Expect %d, Got %d\n", expect, actual)
	}

}
