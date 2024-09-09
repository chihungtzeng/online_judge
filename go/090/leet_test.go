package leet

import "testing"
import "fmt"

func TestS(t *testing.T) {
	nums := []int{1, 2, 2}
	subsets := subsetsWithDup(nums)
	fmt.Printf("%v\n", subsets)
	if len(subsets) != 6 {
		t.Errorf("Length wrong")
	}
}
