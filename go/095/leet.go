package leet

/**
 * Definition for a binary tree node.
 */
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func generateTrees(n int) []*TreeNode {
	vals := make([]int, n)
	for i := 1; i <= n; i++ {
		vals[i-1] = i
	}
	// fmt.Printf("vals: %#v\n", vals)
	return genTrees(vals)
}

func genTrees(vals []int) []*TreeNode {
	nvals := len(vals)
	if nvals == 0 {
		return []*TreeNode{}
	}
	if nvals == 1 {
		return []*TreeNode{&TreeNode{Val: vals[0]}}
	}
	trees := make([]*TreeNode, 0, 8)
	for i := 0; i < nvals; i++ {
		left_trees := genTrees(vals[0:i])
		right_trees := genTrees(vals[i+1:])
		trees = append(trees, combineTrees(vals[i], left_trees, right_trees)...)
	}
	return trees
}

func combineTrees(root_val int, left_trees []*TreeNode, right_trees []*TreeNode) []*TreeNode {
	nl := len(left_trees)
	nr := len(right_trees)
	trees := make([]*TreeNode, 0, 8)
	if nl > 0 && nr > 0 {
		for i := 0; i < nl; i++ {
			for j := 0; j < nr; j++ {
				root := TreeNode{Val: root_val}
				root.Left = left_trees[i]
				root.Right = right_trees[j]
				trees = append(trees, &root)
			}
		}
	}
	if nl == 0 && nr > 0 {
		for i := 0; i < nr; i++ {
			root := TreeNode{Val: root_val}
			root.Right = right_trees[i]
			trees = append(trees, &root)
		}
	}
	if nl > 0 && nr == 0 {
		for i := 0; i < nl; i++ {
			root := TreeNode{Val: root_val}
			root.Left = left_trees[i]
			trees = append(trees, &root)
		}
	}
	return trees
}
