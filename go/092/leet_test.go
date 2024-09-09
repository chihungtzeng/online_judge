package leet

import "testing"
import "fmt"

func TestR(t *testing.T) {
	var nodes []ListNode
	var head *ListNode
	var expect []int

	nodes = makeList()
	head = reverseBetween(&nodes[0], 1, 2)
	expect = []int{2, 1, 3, 4}
	if is_equal(head, expect) == false {
		fmt.Printf("expect: %v\n", expect)
		showList(head)
		t.Errorf("Wrong reverse\n")
	}

	nodes = makeList()
	head = reverseBetween(&nodes[0], 1, 4)
	expect = []int{4, 3, 2, 1}
	if is_equal(head, expect) == false {
		fmt.Printf("expect: %v\n", expect)
		showList(head)
		t.Errorf("Wrong reverse\n")
	}

	nodes = makeList()
	head = reverseBetween(&nodes[0], 2, 3)
	expect = []int{1, 3, 2, 4}
	if is_equal(head, expect) == false {
		fmt.Printf("expect: %v\n", expect)
		showList(head)
		t.Errorf("Wrong reverse\n")
	}

	nodes = makeList()
	head = reverseBetween(&nodes[0], 2, 4)
	expect = []int{1, 4, 3, 2}
	if is_equal(head, expect) == false {
		fmt.Printf("expect: %v\n", expect)
		showList(head)
		t.Errorf("Wrong reverse\n")
	}

	nodes = makeList()
	head = reverseBetween(&nodes[0], 4, 4)
	expect = []int{1, 2, 3, 4}
	if is_equal(head, expect) == false {
		fmt.Printf("expect: %v\n", expect)
		showList(head)
		t.Errorf("Wrong reverse\n")
	}

}

func is_equal(head *ListNode, expect []int) bool {
	cur := head
	for i := 0; i < len(expect); i++ {
		if cur == nil || expect[i] != cur.Val {
			return false
		}
		cur = cur.Next
	}
	if cur != nil {
		return false
	}
	return true
}

func showList(head *ListNode) {
	cur := head
	fmt.Printf("List Vals: ")
	for cur != nil {
		fmt.Printf("%d ", cur.Val)
		cur = cur.Next
	}
	fmt.Printf("\n")
}

func makeList() []ListNode {
	nodes := make([]ListNode, 4)
	for i := 0; i < 4; i++ {
		nodes[i].Val = i + 1
	}
	for i := 0; i < 3; i++ {
		nodes[i].Next = &nodes[i+1]
	}
	return nodes
}
