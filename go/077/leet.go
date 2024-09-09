package leet

func combine(n int, k int) [][]int {
	if k <= 0 {
		return make([][]int, 0, 1)
	}
	cans := make([]int, n)
	for i := 1; i <= n; i++ {
		cans[i-1] = i
	}
	return comb(cans, k)
}

func comb(cans []int, k int) [][]int {
	res := make([][]int, 0, 8)
	if k == 1 {
		for i := len(cans) - 1; i >= 0; i-- {
			res = append(res, []int{cans[i]})
		}

		return res
	}
	for i := len(cans) - 1; i >= 0; i-- {
		tmp := comb(cans[i+1:], k-1)

		for j := len(tmp) - 1; j >= 0; j-- {
			res = append(res, append(tmp[j], cans[i]))
		}
	}
	return res
}
