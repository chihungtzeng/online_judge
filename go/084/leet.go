package leet

/* Idea:
	1. for each element i, find the maximal rectangle with heights[i]. To do so,
	   we need to find the corresponding rectangle width.
  2. For each element i, find the nearest element j in the left-hand side
		 with heights[j] < heights[i]. If no such j exists, set j to -1.
		 Likelise, find the nearest element k in the right-hand side with
		 heights[k] < heights[i]. If no such k exists, set k to len(heights).
		 The maximal area of the rectanle w.r.t h[i] is |k - j - 1| * heights[i]
  3. The key is to find such j and k efficiently, we can do it without naive
	   iteration from i-1 to 0 for finding j and from i + 1 to len(heights) for
		 finding k. It can be done by "jumping" to the next possible element
		 with smaller height.
  4. In implementation, I place two pseudo elements in the both sides of the array
	   to avoid excessive if-else statements.
*/
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
