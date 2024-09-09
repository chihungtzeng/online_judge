package leet

import "fmt"

func nextPermutation(nums []int) {
	fmt.Printf("input nums:%v\n", nums)
	nelem := len(nums)
	ell := 0
	for ell = nelem - 2; (ell >= 0) && nums[ell] >= nums[ell+1]; ell-- {
	}
	k := 0
	if ell >= 0 {
		for k = nelem - 1; ell >= 0 && (k > ell) && nums[k] <= nums[ell]; k-- {
		}
		nums[k], nums[ell] = nums[ell], nums[k]
	}
	//fmt.Printf("ell=%d, k=%d, nums:%v\n", ell, k, nums)

	for i, j := ell+1, nelem-1; i < j; i, j = i+1, j-1 {
		nums[i], nums[j] = nums[j], nums[i]
	}
}
