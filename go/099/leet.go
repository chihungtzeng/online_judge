package leet

/**
 * Definition for a binary tree node.
 */
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

const max_uint = ^uint(0)
const max_int = int(max_uint >> 1)
const min_int = -max_int - 1

var cur_max int
var mistake1, mistake2 *TreeNode
var cur_max_node *TreeNode
var nviolations int = -1

func recoverTree(root *TreeNode) {
	if root == nil {
		return
	}
	mistake1 = nil
	mistake2 = nil
	cur_max = min_int
	nviolations = 0
	cur_max_node = nil

	inorder(root)
	if mistake1 != nil && mistake2 != nil {
		mistake1.Val, mistake2.Val = mistake2.Val, mistake1.Val
	}
}

func inorder(root *TreeNode) {
	if root.Left != nil {
		inorder(root.Left)
	}

	if root.Val > cur_max {
		cur_max = root.Val
		cur_max_node = root
		if nviolations > 0 {
			nviolations = 0
		}
	} else {
		if nviolations == 0 {
			mistake1 = cur_max_node
			nviolations += 1
		}
		mistake2 = root
	}

	if root.Right != nil {
		inorder(root.Right)
	}
}
