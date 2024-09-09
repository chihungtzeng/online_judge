package leet

import "testing"

func TestR1(t *testing.T) {
	matrix := [][]byte{
		{'1', '0', '1', '0', '0'},
		{'1', '0', '1', '1', '1'},
		{'1', '1', '1', '1', '1'},
		{'1', '0', '0', '1', '0'},
	}
	expect := 6
	actual := maximalRectangle(matrix)
	if expect != actual {
		t.Errorf("expect %d, got %d\n", expect, actual)
	}
}

func TestR2(t *testing.T) {
	matrix := [][]byte{
		{'0', '0', '0', '0', '0'},
		{'0', '0', '0', '0', '0'},
		{'1', '1', '1', '0', '0'},
		{'0', '0', '1', '0', '0'},
	}
	expect := 3
	actual := maximalRectangle(matrix)
	if expect != actual {
		t.Errorf("expect %d, got %d\n", expect, actual)
	}
}

func TestR3(t *testing.T) {
	matrix := [][]byte{
		{'1', '0', '1', '0', '0'},
		{'1', '0', '1', '1', '1'},
		{'1', '1', '1', '1', '0'},
		{'1', '0', '0', '1', '0'},
	}
	expect := 4
	actual := maximalRectangle(matrix)
	if expect != actual {
		t.Errorf("expect %d, got %d\n", expect, actual)
	}
}
