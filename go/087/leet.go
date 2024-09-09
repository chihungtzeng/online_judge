package leet

func isScramble(s1 string, s2 string) bool {
	if len(s1) != len(s2) {
		return false
	}
	if s1 == s2 {
		return true
	}
	ccount := make([]int, 26)
	for idx, ch1 := range s1 {
		ch2 := s2[idx]
		ccount[ch1-'a'] += 1
		ccount[ch2-'a'] -= 1
	}
	for _, count := range ccount {
		if count != 0 {
			return false
		}
	}

	for i, ell := 1, len(s1); i < ell; i++ {
		if isScramble(s1[:i], s2[:i]) && isScramble(s1[i:ell], s2[i:ell]) {
			return true
		}
		if isScramble(s1[:i], s2[ell-i:ell]) && isScramble(s1[i:ell], s2[0:ell-i]) {
			return true
		}
	}

	return false

}
