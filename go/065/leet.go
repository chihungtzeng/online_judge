package leet

import "strconv"
import "regexp"

func isNumber(s string) bool {
	s = trim_space(s)
	_, err := strconv.ParseFloat(s, 64)
	if err == nil {
		return true
	}
	if matche(s) {
		return true
	}
	return false
}

func matche(s string) bool {
	var withe = regexp.MustCompile(`^[+-]?([0-9]+\.|\.[0-9]+|[0-9]+\.[0-9]+|[0-9]+)e[+-]?[0-9]+$`)
	return withe.MatchString(s)
}

func trim_space(s string) string {
	slen := len(s)
	i := 0
	j := 0
	for i = 0; i < slen && s[i] == ' '; i++ {
	}
	for j = slen - 1; j >= 0 && s[j] == ' '; j-- {
	}
	if i > j {
		return ""
	}
	return s[i : j+1]
}
