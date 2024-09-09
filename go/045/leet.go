package leet

import "sort"

func jump(nums []int) int {
	nelem := len(nums)
	if nelem <= 1 {
		return 0
	}
	// reachable[i]: the most distant position that can be reached with exactly i jumps.
	reachable := make([]int, nelem)
	num_steps := 1
	reachable[1] = nums[0]
	for pos, end := 1, nelem-1; pos < end; pos++ {
		// reachable[:num_steps] is increasing and its values are properly
		// calculated. nsteps_to_pos is the minimum number of jumps that reaches
		// |pos|.
		nsteps_to_pos := sort.SearchInts(reachable[:num_steps], pos)
		reachable[nsteps_to_pos+1] = max(pos+nums[pos], reachable[nsteps_to_pos+1])
		num_steps = max(nsteps_to_pos+1, num_steps)
	}
	return sort.SearchInts(reachable[:num_steps], nelem-1)
}

func max(x, y int) int {
	if x > y {
		return x
	} else {
		return y
	}
}
