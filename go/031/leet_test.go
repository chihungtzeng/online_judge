package leet

import "testing"
import "fmt"

func TestN(t *testing.T) {
	var nums []int
	nums = []int{0, 1, 2, 3}
	fmt.Printf("before: %#v\n", nums)
	nextPermutation(nums)
	fmt.Printf("after: %#v\n\n", nums)

	nums = []int{3, 2, 1}
	fmt.Printf("before: %#v\n", nums)
	nextPermutation(nums)
	fmt.Printf("after: %#v\n\n", nums)

	nums = []int{1, 1, 5}
	fmt.Printf("before: %#v\n", nums)
	nextPermutation(nums)
	fmt.Printf("after: %#v\n\n", nums)

	nums = []int{1, 1, 5, 2, 0, 1, 1}
	fmt.Printf("before: %#v\n", nums)
	nextPermutation(nums)
	fmt.Printf("after: %#v\n\n", nums)

	nums = []int{3}
	nextPermutation(nums)
	if nums[0] != 3 {
		t.Errorf("Expect [3], got %v\n", nums)
	}

}

func TestN2(t *testing.T) {
	var nums []int
	nums = []int{1, 2}
	nextPermutation(nums)
	expect := []int{2, 1}
	if assertEqual(nums, expect) != true {
		t.Errorf("Expect %v, got %v\n", expect, nums)
	}

	nums = []int{3, 1, 4, 1, 5, 9, 6, 2}
	expect = []int{3, 1, 4, 1, 6, 2, 5, 9}
	nextPermutation(nums)
	if assertEqual(nums, expect) != true {
		t.Errorf("Expect %v, got %v\n", expect, nums)
	}

}

func TestN3(t *testing.T) {
	nums := []int{1, 1, 5, 2, 0, 1, 1}
	nextPermutation(nums)
	expect := []int{1, 1, 5, 2, 1, 0, 1}
	if assertEqual(nums, expect) != true {
		t.Errorf("Expect %v, got %v\n", expect, nums)
	}
}

func assertEqual(expect, actual []int) bool {
	if len(expect) != len(actual) {
		return false
	}
	for i := len(expect) - 1; i >= 0; i-- {
		if expect[i] != actual[i] {
			return false
		}
	}
	return true
}
