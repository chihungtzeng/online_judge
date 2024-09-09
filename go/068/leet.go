package leet

func fullJustify(words []string, maxWidth int) []string {
	groups := grouping(words, maxWidth)
	ret := make([]string, len(groups))
	for i := len(groups) - 2; i >= 0; i-- {
		ret[i] = evenly_spread(groups[i], maxWidth)
	}
	ret[len(groups)-1] = evenly_last_sentence(groups[len(groups)-1], maxWidth)
	return ret
}

func grouping(words []string, maxWidth int) [][]string {
	ret := make([][]string, 0)
	sg := make([]string, 0)
	spare := maxWidth
	occupy := 0
	for _, word := range words {
		if len(sg) == 0 {
			occupy = len(word)
		} else {
			occupy = len(word) + 1
		}

		if occupy <= spare {
			sg = append(sg, word)
			spare -= occupy
		} else {
			ret = append(ret, sg)
			sg = []string{word}
			spare = maxWidth - len(word)
		}
	}
	if len(sg) > 0 {
		ret = append(ret, sg)
	}
	return ret
}

func evenly_spread(words []string, maxWidth int) string {
	nwords := len(words)
	nchars := 0
	for i := 0; i < nwords; i++ {
		nchars += len(words[i])
	}
	nspace := maxWidth - nchars
	if nwords == 1 {
		return words[0] + gen_space(nspace)
	}

	avg := nspace / (nwords - 1)
	nspaces := make([]int, nwords-1)
	for i := nwords - 2; i >= 0; i-- {
		nspaces[i] = avg
	}
	remains := nspace - avg*(nwords-1)
	for i := 0; remains > 0; i++ {
		nspaces[i] += 1
		remains -= 1
	}
	var ret string
	for i := 0; i < len(nspaces); i++ {
		ret += words[i]
		ret += gen_space(nspaces[i])
	}
	ret += words[nwords-1]

	return ret
}

func evenly_last_sentence(words []string, maxWidth int) string {
	ret := words[0]
	nchar := len(words[0])
	for i := 1; i < len(words); i++ {
		ret += " "
		ret += words[i]
		nchar += 1 + len(words[i])
	}
	ret += gen_space(maxWidth - nchar)
	return ret
}

func gen_space(n int) string {
	space := make([]byte, n)
	for i := 0; i < n; i++ {
		space[i] = ' '
	}
	return string(space)
}
