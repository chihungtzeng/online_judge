package leet

import "testing"
import "fmt"
import "sort"

func TestT1(t *testing.T) {
	nodes := make([]TreeNode, 3)
	for i := 0; i < 3; i++ {
		nodes[i].Val = i
	}
	nodes[0].Left = &nodes[2]
	nodes[2].Right = &nodes[1]

	recoverTree(&nodes[0])
	vals := make([]int, 0, 8)
	vals = to_array(&nodes[0], vals)
	fmt.Printf("%#v\n", vals)
	if !sort.IntsAreSorted(vals) {
		t.Errorf("Expected sorted ints: %#v", vals)
	}
}

func TestT2(t *testing.T) {
	nnodes := 4
	nodes := make([]TreeNode, nnodes)
	for i := 0; i < nnodes; i++ {
		nodes[i].Val = i
	}
	nodes[2].Left = &nodes[0]
	nodes[2].Right = &nodes[3]
	nodes[3].Left = &nodes[1]

	recoverTree(&nodes[0])
	vals := make([]int, 0, 8)
	vals = to_array(&nodes[0], vals)
	fmt.Printf("%#v\n", vals)
	if !sort.IntsAreSorted(vals) {
		t.Errorf("Expected sorted ints: %#v", vals)
	}
}

func to_array(root *TreeNode, vals []int) []int {
	if root.Left != nil {
		vals = to_array(root.Left, vals)
	}
	vals = append(vals, root.Val)
	if root.Right != nil {
		vals = to_array(root.Right, vals)
	}
	return vals
}
