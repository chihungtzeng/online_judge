package leet

import "fmt"

func solveNQueens(n int) [][]string {
	var ans [][]string

	board := make([][]byte, n)
	for i := 0; i < n; i++ {
		board[i] = make([]byte, n)
		for j := 0; j < n; j++ {
			board[i][j] = '.'
		}
	}
	ans = make([][]string, 0, 8)

	for i := 0; i < n; i++ {
		board[0][i] = 'Q'
		bt(&ans, board, n, 1)
		board[0][i] = '.'
	}
	return ans
}

func bt(ans *[][]string, board [][]byte, n, r int) {
	if r == n {
		sb := make([]string, n)
		for i := 0; i < n; i++ {
			sb[i] = string(board[i])
		}
		// show_sb(sb, n)
		*ans = append(*ans, sb)
		return
	}
	for c := 0; c < n; c++ {
		if can_put_queen(board, n, r, c) {
			board[r][c] = 'Q'
			bt(ans, board, n, r+1)
			board[r][c] = '.'
		}
	}
}

func can_put_queen(board [][]byte, n, r, c int) bool {
	for i := 0; i < r; i++ {
		if board[i][c] == 'Q' {
			return false
		}
	}
	for i, j := r-1, c-1; i >= 0 && j >= 0; i, j = i-1, j-1 {
		if board[i][j] == 'Q' {
			return false
		}
	}
	for i, j := r-1, c+1; i >= 0 && j < n; i, j = i-1, j+1 {
		if board[i][j] == 'Q' {
			return false
		}
	}
	return true
}

func show_sb(sb []string, n int) {
	for i := 0; i < n; i++ {
		fmt.Printf("%v\n", sb[i])
	}
	fmt.Printf("------------\n")
}
