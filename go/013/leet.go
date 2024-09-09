package leet

var ch2int = map[string]int{
	"I":  1,
	"V":  5,
	"X":  10,
	"L":  50,
	"C":  100,
	"D":  500,
	"M":  1000,
	"IV": 4,
	"IX": 9,
	"XL": 40,
	"XC": 90,
	"CD": 400,
	"CM": 900,
}

func romanToInt(s string) int {
	if len(s) == 1 {
		return ch2int[s]
	}
	done := false
	pos := 0
	ret := 0
	for !done {
		matched := consumeAt(s, pos)
		ret += ch2int[matched]
		pos += len(matched)
		if pos >= len(s) {
			done = true
		}
	}
	return ret
}

func consumeAt(s string, pos int) string {
	if pos < len(s)-1 {
		greedy := s[pos : pos+2]
		_, hit := ch2int[greedy]
		if hit {
			return greedy
		}
	}
	return string(s[pos])
}
