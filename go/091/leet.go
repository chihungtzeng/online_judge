package leet

func numDecodings(s string) int {
	lens := len(s)
	if lens == 0 || s[0] == '0' {
		return 0
	}
	var d, d10 int
	ans := make([]int, lens)

	if lens == 1 {
		return 1
	}

	d10 = int(s[0] - '0')
	d = int(s[1] - '0')

	if lens >= 2 {
		ans[0] = 1
		val := d10*10 + d
		if d == 0 {
			if val > 26 {
				return 0
			} else {
				ans[1] = 1
			}
		} else {
			if val <= 26 {
				ans[1] = 2
			} else {
				ans[1] = 1
			}
		}
	}

	for i := 2; i < lens; i++ {
		d10 = d
		d = int(s[i] - '0')
		if d == 0 {
			if d10 == 0 || d10 > 2 {
				return 0
			} else {
				ans[i] = ans[i-2]
			}
		} else {
			val := (d10 << 3) + (d10 << 1) + d
			if d10 == 0 {
				ans[i] = ans[i-1]
			} else if val <= 26 {
				ans[i] = ans[i-1] + ans[i-2]
			} else {
				ans[i] = ans[i-1]
			}
		}
	}

	return ans[lens-1]
}
