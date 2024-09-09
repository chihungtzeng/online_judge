package leet

func invertTree(root *TreeNode) *TreeNode {
	if root != nil {
		tmp := root.Left
		root.Left = root.Right
		root.Right = tmp
		invertTree(root.Left)
		invertTree(root.Right)
	}
	return root
}
