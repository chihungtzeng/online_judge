package leet

func subsets(nums []int) [][]int {
	nelem := uint(len(nums))
	nsets := 1 << nelem
	ret := make([][]int, nsets)
	for cur := 0; cur < nsets; cur++ {
		var b uint
		for b = 0; b < nelem; b++ {
			if 1 == (cur>>b)&1 {
				ret[cur] = append(ret[cur], nums[b])
			}
		}
	}
	return ret
}
