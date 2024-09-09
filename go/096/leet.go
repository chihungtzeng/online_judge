package leet

func numTrees(n int) int {
	cnums := []int{1, 1, 2}

	if n+1 > len(cnums) {
		for start := len(cnums); start <= n+1; start++ {
			t := 0
			for i, j := 0, start-1; j >= 0; i, j = i+1, j-1 {
				t += cnums[i] * cnums[j]
			}
			cnums = append(cnums, t)
		}
	}
	return cnums[n]
}
