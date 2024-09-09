package leet

import "testing"

func TestG1(t *testing.T) {
	n := 1
	trees := generateTrees(n)
	expect_len := 1
	if len(trees) != expect_len {
		t.Errorf("%d: expect len %d, got %d", n, expect_len, len(trees))
	}
	for _, tree := range trees {
		if tree == nil {
			t.Errorf("Expect tree root != nil")
		}
	}
}

func TestG2(t *testing.T) {
	n := 2
	trees := generateTrees(n)
	expect_len := 2
	if len(trees) != expect_len {
		t.Errorf("%d: expect len %d, got %d", n, expect_len, len(trees))
	}
	for _, tree := range trees {
		if tree == nil {
			t.Errorf("Expect tree root != nil")
		}
	}
}

func TestG3(t *testing.T) {
	n := 3
	trees := generateTrees(n)
	expect_len := 5
	if len(trees) != expect_len {
		t.Errorf("%d: expect len %d, got %d", n, expect_len, len(trees))
	}
	for _, tree := range trees {
		if tree == nil {
			t.Errorf("Expect tree root != nil")
		}
	}
}

func TestG4(t *testing.T) {
	n := 4
	trees := generateTrees(n)
	expect_len := 14
	if len(trees) != expect_len {
		t.Errorf("%d: expect len %d, got %d", n, expect_len, len(trees))
	}
	for _, tree := range trees {
		if tree == nil {
			t.Errorf("Expect tree root != nil")
		}
	}
}
