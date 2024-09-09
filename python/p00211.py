import unittest
class WordDictionary(object):
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.words = {}

    def addWord(self, word):
        """
        Adds a word into the data structure.
        :type word: str
        :rtype: None
        """
        ell = len(word)
        if ell in self.words:
            self.words[ell][word] = 0
        else:
            self.words[ell] = {word: 0}

    def search(self, word):
        """
        Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter.
        :type word: str
        :rtype: bool
        """
        ell = len(word)
        if ell not in self.words:
            return False
        if "." not in word:
            return bool(word in self.words.get(ell, {}))
        import re
        rgx = re.compile(word)
        for candidate in self.words[ell]:
            if rgx.match(candidate):
                return True
        return False

class SolTest(unittest.TestCase):
    def test_1(self):
        sol = WordDictionary()
        sol.addWord("bad")
        sol.addWord("dad")
        sol.addWord("mad")
        self.assertEqual(sol.search("pad"), False)
        self.assertEqual(sol.search("bad"), True)
        self.assertEqual(sol.search(".ad"), True)
        self.assertEqual(sol.search("b.."), True)

    def test_2(self):
        sol = WordDictionary()
        self.assertEqual(sol.search("a"), False)

    def test_3(self):
        sol = WordDictionary()
        sol.addWord("a")
        sol.addWord("a")
        self.assertEqual(sol.search("."), True)
        self.assertEqual(sol.search("a"), True)
        self.assertEqual(sol.search("aa"), False)
        self.assertEqual(sol.search("a"), True)
        self.assertEqual(sol.search(".a"), False)
        self.assertEqual(sol.search("a."), False)

if __name__ == "__main__":
    unittest.main()
