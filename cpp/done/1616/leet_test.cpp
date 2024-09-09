#include "leet.cpp"

#include <gtest/gtest.h>
#include <bitset>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  string a = "x", b = "y";
  EXPECT_EQ(sol.checkPalindromeFormation(a, b), true);
}

TEST(kk, t2) {
  Solution sol;
  string a = "abdef", b = "fecab";
  EXPECT_EQ(sol.checkPalindromeFormation(a, b), true);
}

TEST(kk, t3) {
  Solution sol;
  string a = "ulacfd", b = "jizalu";
  EXPECT_EQ(sol.checkPalindromeFormation(a, b), true);
}

TEST(kk, t4) {
  Solution sol;
  string a = "xbdef", b = "xecab";
  EXPECT_EQ(sol.checkPalindromeFormation(a, b), false);
}

TEST(kk, t5) {
  Solution sol;
  string a = "abc", b = "dba";
  EXPECT_EQ(sol.checkPalindromeFormation(a, b), true);
}

TEST(kk, t6) {
  Solution sol;
  string a = "pvhmupgqeltozftlmfjjde", b = "yjgpzbezspnnpszebzmhvp";

  EXPECT_EQ(sol.checkPalindromeFormation(a, b), true);
}

TEST(kk, t7) {
  Solution sol;
  string a = "abda", b = "acmc";

  EXPECT_EQ(sol.checkPalindromeFormation(a, b), false);
}

TEST(kk, t8) {
  Solution sol;
  string a = "aejbaalflrmkswrydwdkdwdyrwskmrlfqizjezd",
         b = "uvebspqckawkhbrtlqwblfwzfptanhiglaabjea";

  EXPECT_EQ(sol.checkPalindromeFormation(a, b), true);
}

TEST(kk, t9) {
  Solution sol;
  string a = "nsltrtzgkjxazdehgfbzpzorrklcaozcpdobaxobvjfyichwtehvxhspulryplkicuzyoilvrdjcysxvuroijemfjivwcfofgxawvjiychtjnznqbdqjjringklftowjchtrfaighzgynzxrvjrpmcomfvjgkuazkwibtwrtyyreynjielurqpynhtfhtujwpqpxkhaiigqlnilpqohgygetlrsgkbyjhpphqqmbndrihucqlkswhwvhhkqvvpwptlzebgnqwlhvllvwlphbfzhcrrpfcovddozmkwshbzmfnhitmhijypxiudpswilstoruocwsxxteearusqyivlforugwreewzbbsbxnacethadvgurttfzvhdddylniawhjuwazbgtxapqtciqxzmlnrtbnqcfrqpkobzqhjcashgjtoiwoyfpunukiztfuwcplidxlnztrcjvplbqglsgnzwdlbzocboehnrmyqowvujdlmucozcffpewdqmdmudescxjskngccjlvmofdv",
         b = "dkqxxbtiihevpbplnbnubxosgprhshhantbgyezkgkjrbrfyrpdeplbucprkssmpxffpllslorgqnvlhnavabljjqtyzulatllctaogjafbrbnsxlpwknctxbfgvcmzhgoezcjffjniqomhubotvcokleakdtnmyzctcecmhgbdyzrkwawflkeilmudqckbmhuxsruszkqkotcikozbvttxfopmygkrvwlicicmguciiypeimxterfsbovajpfxbyrkzjkqlmvvmlqkjzkrybxfpjavobsfretxmiepyiicugmcicilwvrkgympofxttvbzokictokqkzsursxuhmbkcqdumlieklfwawkrzydbghmcectczymntdkaelkocvtobuhmoqinjffjczeoghzmcvgfbxtcnkwplxsnbrbfajgoatclltaluzytjfmejioruvxsycjdrvlioyzuciklpyrlupshxvhetwhciyfjvboxabodpczoaclkrrozpzbfghedzaxjkgztrtlsn";

  EXPECT_EQ(sol.checkPalindromeFormation(a, b), true);
}

TEST(kk, t10) {
  Solution sol;
  string a = "ydttjpuhvfyheiazalcepbrlpknptmqacxagvccpumatkgxkdlzdgbwtdaqbqmctydedwycdicxqoggxjcgmyutsyfaqlcdrtdydxunnbzsafdtuzyxartojufudtveiwrdgvoyrbqydjbuqlefwhvmvgqezapkrkpazeqgvmvhwfelqubjdyqbryovgdrwievtdufujotraxyzutdfaszbnnuxdydtrdclqafystuymgcjxggoqxcidcywdedytcmqbqadtwbgljsjudrtpmrojowjrykftrsohtnahawivrfkaoubspheawcyvivk",
         b = "aknlqkhftumnjgclfjkxjqsxaugbdcilzehmhnasfepfjkmrjatcvtdcjcizenrzrayimyjcklsvuvsrxjgnpgtmehesysccdymbgaifmyrdlejotnufefsmbozsnkpxtewihtgsekouuovcipljhvtzzjptdzlkjvmhokrfpxbaicjjliikdxkwthqxvbfumytyiwhwkkthuhixexsdmkuqkasepcrzwiebzzoridulymnbialddkpztellfbpelmriaflmwkvdzldkxgktamupccvgaxcaqmtpnkplrbpeclazaiehyfvhupjttdy";

  EXPECT_EQ(sol.checkPalindromeFormation(a, b), true);
}
