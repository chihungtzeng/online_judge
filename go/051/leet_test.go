package leet

import "testing"
import "fmt"

func TestQ(t *testing.T) {
	n := 4
	ans := solveNQueens(n)
	for idx, board := range ans {
		fmt.Printf("Sol %d:\n", idx)
		for i := 0; i < n; i++ {
			fmt.Printf("%v\n", board[i])
		}
	}
	if len(ans) != 2 {
		t.Errorf("%d: expect %d solutions, got %d\n", n, 2, len(ans))
	}

	n = 8
	ans = solveNQueens(n)
	if len(ans) != 92 {
		t.Errorf("%d: expect %d solutions, got %d\n", n, 92, len(ans))
	}

}
