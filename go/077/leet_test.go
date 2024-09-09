package leet

import "testing"
import "fmt"

func TestC(t *testing.T) {
	res := combine(4, 2)
	fmt.Printf("%v\n", res)
	if len(res) != 6 {
		t.Errorf("Expect len=6")
	}
}

func TestC2(t *testing.T) {
	res := combine(5, 3)
	fmt.Printf("%v\n", res)
	if len(res) != 10 {
		t.Errorf("Expect len=10")
	}
}
