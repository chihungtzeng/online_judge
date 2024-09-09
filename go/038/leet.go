package leet

// import "fmt"

func countAndSay(n int) string {
	if n == 1 {
		return "1"
	}
	prev := []byte{'1'}
	var char byte
	var count int
	for i := 2; i <= n; i++ {
		cur := make([]byte, 0, 128)
		prev_char := prev[0]
		count = 1
		for j, ell := 1, len(prev); j < ell; j++ {
			char = prev[j]
			if char == prev_char {
				count += 1
			} else {
				cur = append(cur, byte(count)+'0')
				cur = append(cur, prev_char)

				prev_char = char
				count = 1
			}
		}
		cur = append(cur, byte(count)+'0')
		cur = append(cur, prev_char)
		prev = cur
		// fmt.Printf("cur: %v\n", cur)
	}
	return string(prev)
}
