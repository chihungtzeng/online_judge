package leet

import "fmt"

func totalNQueens(n int) int {
	board := make([][]int, n)
	for i := 0; i < n; i++ {
		board[i] = make([]int, n)
	}
	ans := 0
	for i := 0; i < n; i++ {
		board[0][i] = 1
		ans += bt(board, n, 1)
		board[0][i] = 0
	}
	return ans
}

func bt(board [][]int, n, r int) int {
	if r == n {
		//		show_board(board, n)
		return 1
	}
	var ret int
	for c := 0; c < n; c++ {
		if can_put_queen(board, n, r, c) {
			board[r][c] = 1
			ret += bt(board, n, r+1)
			board[r][c] = 0
		}
	}
	return ret
}

func can_put_queen(board [][]int, n, r, c int) bool {
	for i := 0; i < r; i++ {
		if board[i][c] == 1 {
			return false
		}
	}
	for i, j := r-1, c-1; i >= 0 && j >= 0; i, j = i-1, j-1 {
		if board[i][j] == 1 {
			return false
		}
	}
	for i, j := r-1, c+1; i >= 0 && j < n; i, j = i-1, j+1 {
		if board[i][j] == 1 {
			return false
		}
	}
	return true
}

func show_board(board [][]int, n int) {
	for i := 0; i < n; i++ {
		fmt.Printf("%v\n", board[i])
	}
	fmt.Printf("------------\n")
}
