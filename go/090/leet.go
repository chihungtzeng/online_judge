package leet

import "sort"

func subsetsWithDup(nums []int) [][]int {
	nelem := uint(len(nums))
	ub := uint(1 << nelem)
	res := make([][]int, 0, 16)
	visited := make(map[uint]bool)

	for i := uint(0); i < ub; i++ {
		subset := make_subset(nums, nelem, i)
		digest := hash(subset)
		_, hit := visited[digest]
		if !hit {
			visited[digest] = true
			res = append(res, subset)
		}
	}
	return res
}

func hash(nums []int) uint {
	res := uint(2166136261)
	for _, num := range nums {
		res = res ^ uint(num)
		res += res << 13
		res ^= res >> 7
	}
	return res
}

func make_subset(nums []int, nelem uint, ons uint) []int {
	res := make([]int, 0, 32)
	for i := uint(0); i < nelem; i++ {
		if ons&(1<<i) > 0 {
			res = append(res, nums[i])
		}
	}
	sort.Ints(res)
	return res
}
