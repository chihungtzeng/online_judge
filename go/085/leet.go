package leet

// import "fmt"

func maximalRectangle(matrix [][]byte) int {
	nrows := len(matrix)
	if nrows == 0 {
		return 0
	}
	ncols := len(matrix[0])
	if ncols == 0 {
		return 0
	}

	heights := make([]int, ncols)
	ans := 0
	for r := 0; r < nrows; r++ {
		for c := 0; c < ncols; c++ {
			if matrix[r][c] == '0' {
				heights[c] = 0
			} else {
				heights[c] += 1
			}
		}
		can := largestRectangleArea(heights)
		//		fmt.Printf("heights: %#v, can: %d\n", heights, can)
		ans = max(ans, can)
	}

	return ans

}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func largestRectangleArea(heights []int) int {
	nelem := len(heights)
	h := make([]int, nelem+2)
	h[0], h[nelem+1] = -1, -1
	for i := 1; i <= nelem; i++ {
		h[i] = heights[i-1]
	}
	left := make([]int, nelem+2)
	for i := 1; i <= nelem; i++ {
		smaller := i - 1
		for h[smaller] >= h[i] {
			smaller = left[smaller]
		}
		left[i] = smaller
	}

	right := make([]int, nelem+2)
	right[nelem+1] = nelem + 1
	for i := nelem; i >= 1; i-- {
		smaller := i + 1
		for h[smaller] >= h[i] {
			smaller = right[smaller]
		}
		right[i] = smaller
	}
	ans := 0
	for i := 1; i <= nelem; i++ {
		area := h[i] * (right[i] - left[i] - 1)
		if area > ans {
			ans = area
		}
	}
	return ans
}
