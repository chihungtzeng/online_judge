package leet

import "testing"

//import "fmt"

func TestJ1(t *testing.T) {
	words := []string{"This", "is", "an", "example", "of", "text", "justification."}
	maxWidth := 16
	expect := []string{
		"This    is    an",
		"example  of text",
		"justification.  "}
	actual := fullJustify(words, maxWidth)
	if !assertEqual(expect, actual) {
		t.Errorf("Expect %v, Got %v", expect, actual)
	}
}

func TestJ2(t *testing.T) {
	words := []string{"What", "must", "be", "acknowledgment", "shall", "be"}
	maxWidth := 16
	expect := []string{
		"What   must   be",
		"acknowledgment  ",
		"shall be        "}
	actual := fullJustify(words, maxWidth)
	if !assertEqual(expect, actual) {
		t.Errorf("Expect %v, Got %v", expect, actual)
	}
}

func TestJ3(t *testing.T) {
	words := []string{"Science", "is", "what", "we", "understand", "well", "enough", "to", "explain",
		"to", "a", "computer.", "Art", "is", "everything", "else", "we", "do"}
	maxWidth := 20
	expect := []string{
		"Science  is  what we",
		"understand      well",
		"enough to explain to",
		"a  computer.  Art is",
		"everything  else  we",
		"do                  "}
	actual := fullJustify(words, maxWidth)
	if !assertEqual(expect, actual) {
		t.Errorf("Expect %v, Got %v", expect, actual)
	}
}

func TestJ4(t *testing.T) {
	words := []string{""}
	maxWidth := 20
	expect := []string{"                    "}
	actual := fullJustify(words, maxWidth)
	if !assertEqual(expect, actual) {
		t.Errorf("Expect %v, Got %v", expect, actual)
	}
}

func TestJ5(t *testing.T) {
	words := []string{"."}
	maxWidth := 20
	expect := []string{".                   "}
	actual := fullJustify(words, maxWidth)
	if !assertEqual(expect, actual) {
		t.Errorf("Expect %v, Got %v", expect, actual)
	}
}

func assertEqual(expect, actual []string) bool {
	if len(expect) != len(actual) {
		return false
	}
	for i := 0; i < len(expect); i++ {
		if expect[i] != actual[i] {
			return false
		}
	}
	return true
}

func TestG1(t *testing.T) {
	words := []string{"This", "is", "an", "example", "of", "text", "justification."}
	maxWidth := 16
	expect := [][]string{
		{"This", "is", "an"},
		{"example", "of", "text"},
		{"justification."}}

	actual := grouping(words, maxWidth)
	if len(expect) != len(actual) {
		t.Errorf("Expect %v, Got %v", expect, actual)
		return
	}
	for i := 0; i < len(expect); i++ {
		if !assertEqual(expect[i], actual[i]) {
			t.Errorf("Expect %v, Got %v", expect, actual)
		}
	}
}

func TestG2(t *testing.T) {
	words := []string{"What", "must", "be", "acknowledgment", "shall", "be"}
	maxWidth := 16
	expect := [][]string{
		{"What", "must", "be"},
		{"acknowledgment"},
		{"shall", "be"}}
	actual := grouping(words, maxWidth)
	if len(expect) != len(actual) {
		t.Errorf("Expect %v, Got %v", expect, actual)
		return
	}
	for i := 0; i < len(expect); i++ {
		if !assertEqual(expect[i], actual[i]) {
			t.Errorf("Expect %v, Got %v", expect, actual)
		}
	}
}

func TestG3(t *testing.T) {
	words := []string{"Science", "is", "what", "we", "understand", "well", "enough", "to", "explain",
		"to", "a", "computer.", "Art", "is", "everything", "else", "we", "do"}
	maxWidth := 20
	expect := [][]string{
		{"Science", "is", "what", "we"},
		{"understand", "well"},
		{"enough", "to", "explain", "to"},
		{"a", "computer.", "Art", "is"},
		{"everything", "else", "we"},
		{"do"}}
	actual := grouping(words, maxWidth)
	if len(expect) != len(actual) {
		t.Errorf("Expect %v, Got %v", expect, actual)
		return
	}
	for i := 0; i < len(expect); i++ {
		if !assertEqual(expect[i], actual[i]) {
			t.Errorf("Expect %v, Got %v", expect, actual)
		}
	}
}

func TestS1(t *testing.T) {
	words := []string{"This", "is", "an"}
	expect := "This    is    an"
	maxWidth := 16
	actual := evenly_spread(words, maxWidth)
	if expect != actual {
		t.Errorf("Expect %v, Got %v", expect, actual)
	}
}

func TestL1(t *testing.T) {
	words := []string{"example", "of", "text"}
	expect := "example  of text"
	maxWidth := 16
	actual := evenly_spread(words, maxWidth)
	if expect != actual {
		t.Errorf("Expect %v, Got %v", expect, actual)
	}
}

func TestLS1(t *testing.T) {
	words := []string{"justification."}
	expect := "justification.  "
	maxWidth := 16
	actual := evenly_last_sentence(words, maxWidth)
	if expect != actual {
		t.Errorf("Expect %v, Got %v", expect, actual)
	}
}

func TestLS2(t *testing.T) {
	words := []string{"shall", "be"}
	expect := "shall be        "
	maxWidth := 16
	actual := evenly_last_sentence(words, maxWidth)
	if expect != actual {
		t.Errorf("Expect %v, Got %v", expect, actual)
	}
}
