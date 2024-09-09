#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;
  vector<string> words = { "a", "b", "ab", "cde" };
  vector<int> expect{ 2, 3 };
  EXPECT_EQ(sol.groupStrings(words), expect);
}

TEST(kk, t2)
{
  Solution sol;
  vector<string> words = { "a", "ab", "abc" };
  vector<int> expect{ 1, 3 };
  EXPECT_EQ(sol.groupStrings(words), expect);
}

TEST(kk, t3)
{
  Solution sol;
  vector<string> words = { "cugrd", "ivjrq", "fpzv",  "itwvr", "oifs",  "tuphn", "btsxy", "umyvr", "ibdzr", "uzemy",
                           "govyl", "gxwor", "xbnt",  "szvjr", "pzmho", "isemd", "zewnr", "rchq",  "akgpr", "cvynr",
                           "zewml", "exvnq", "bgzex", "ibwvy", "whlfq", "suojr", "jvyr",  "txmhq", "iplrf", "aifq",
                           "izenq", "dzhrq", "nqok",  "bszoq", "cjgyl", "insul", "tmld",  "cwxhd", "kvhjd", "fvzq",
                           "czejq", "ugyhl", "btkel", "ugzjq", "agpxy", "kwodq", "itozj", "cspzy", "agyln", "isydq",
                           "adgpr", "itkxj", "akyhj", "asgpv", "tzeln", "gvorq", "bewod", "aidv",  "ksrnd", "asvnr",
                           "njde",  "abuxo", "ckzjr", "cuyfq", "vhrf",  "rsce",  "tgxnq", "cgzwr", "wyre",  "cwynq",
                           "adsxr", "rpt",   "akusm", "uexmh", "bszew", "ksufq", "jvun",  "aikjo", "kpyjd", "sovnr",
                           "kpmvn", "tsmvr", "csvrf", "kpodq", "bszwl", "uzvrf", "cpvor", "nvmk",  "kxvoq", "inkxo",
                           "ayjdf", "shldf", "bsglf", "mygu",  "lurv",  "atswm", "wylho", "suwnf", "atzxo", "uigf" };
  vector<int> expect{ 94, 2 };
  EXPECT_EQ(sol.groupStrings(words), expect);
}

TEST(kk, t4)
{
  Solution sol;
  vector<string> words = { "web", "a", "te", "hsx", "v", "k", "a", "roh" };
  vector<int> expect{ 5, 4 };
  EXPECT_EQ(sol.groupStrings(words), expect);
}

TEST(kk, t5)
{
  Solution sol;
  vector<string> words = { "xhg", "kove", "ti", "cs", "itfzx", "m", "nrszq", "suc", "gs" };

  vector<int> expect{ 7, 3 };
  EXPECT_EQ(sol.groupStrings(words), expect);
}

TEST(kk, t6)
{
  Solution sol;
  vector<string> words = { "cs", "suc", "gs"};

  vector<int> expect{ 1, 3 };
  EXPECT_EQ(sol.groupStrings(words), expect);
}

TEST(kk, t7)
{
  Solution sol;
  vector<string> words = { "umeihvaq",
                           "ezflcmsur",
                           "ynikwecaxgtrdbu",
                           "u",
                           "q",
                           "gwrv",
                           "ftcuw",
                           "ocdgslxprzivbja",
                           "zqrktuepxs",
                           "cpqolvnwxz",
                           "geqis",
                           "xgfdazthbrolci",
                           "vwnrjqzsoepa",
                           "udzckgenvbsty",
                           "lpqcw",
                           "nekpvchqfgdo",
                           "iapjhxvdrmwetz",
                           "gw",
                           "waxokchnmifsruj",
                           "vqp",
                           "vbpkij",
                           "ufjvbstzh",
                           "swiu",
                           "knslbdcahfrox",
                           "ctofplkhednmv",
                           "g",
                           "zk",
                           "idretzjbpl",
                           "pxqdauys",
                           "mfgrqaktbzpv",
                           "vdtq",
                           "wyxjrcie",
                           "kl",
                           "jpcdzmli",
                           "oth",
                           "yumdawhfbskcjo",
                           "rvfksqhu",
                           "swemnvjpg",
                           "rnl",
                           "zgd",
                           "rmzdbcsqht",
                           "ure",
                           "qlusoaxprtebn",
                           "zkbmvtpya",
                           "jszxuwevfidkm",
                           "smlft",
                           "cpwugmbzfsqr",
                           "cblkjevhp",
                           "iyfnozaulex",
                           "qvlok",
                           "wsgm",
                           "du",
                           "awyplckj",
                           "aey",
                           "ycsjqnt",
                           "vtoqzsyx",
                           "ejqixsmrdhlofyp",
                           "kvlmurbzjg",
                           "lysdahgpwmrcn",
                           "af",
                           "jkezhdu",
                           "etjzqiyghdnovm",
                           "ycwdfnluoke",
                           "kwshbx",
                           "pyvaznljqwes",
                           "xakinu",
                           "e",
                           "zjexfgvhtabwcy",
                           "thuvwlnjkbxym",
                           "jorzeslpidmhubq",
                           "wnr",
                           "qzdv",
                           "qeovrbmwzgpdh",
                           "jkioenptaygfubh",
                           "bvndzxijope",
                           "cudizhjntbes",
                           "rnhzitpqoexwb",
                           "ihezcmfqouyl",
                           "q",
                           "mwtsdjqn",
                           "hrmc",
                           "hxaocbyikluvqsf",
                           "d",
                           "vgwjzuaondbcm",
                           "ibqxltf",
                           "rzyhguptmesqo",
                           "ruwgy",
                           "jvprwhtzuf",
                           "aupngodjexkiw",
                           "yhijelwpvtsrbqc",
                           "gtick",
                           "koilywcfbs",
                           "elv",
                           "dehxzlitskq",
                           "ptvbkql",
                           "msfxyjahlzo",
                           "oslxzfwrpmtyh",
                           "gypuchkwa",
                           "rsqij",
                           "tw",
                           "igbcylqfhtmjkr",
                           "nryhzjgi",
                           "pw",
                           "bnfairow",
                           "xjzrf",
                           "olxfypjtmrncuv",
                           "ifhue",
                           "akcvofuyzwbj",
                           "tvhxfeuiykpwbsz",
                           "wnrztclfpm",
                           "ozvypnfwrqg",
                           "cwkgr",
                           "gjyzrucplbsfe",
                           "pdtzmfoy",
                           "wehd",
                           "bnvqhcmg",
                           "uyw",
                           "sgynxljqbf",
                           "tvxbq",
                           "wcmguioelbdrkvx",
                           "okvtyexuj",
                           "hjbc",
                           "uidcswzm",
                           "jemtkvshizaub",
                           "rmb",
                           "jpgnqdemzcxa",
                           "dmalekhiyj",
                           "akocedu",
                           "rlpqufcv",
                           "r",
                           "lohgs",
                           "xapnorj",
                           "cdb",
                           "icopdtzxy",
                           "xcrflvojqgpkwt",
                           "elv",
                           "rp",
                           "yv",
                           "u",
                           "atdxqeilhkg",
                           "olfvmrgkb",
                           "rplxskabvtqmhw",
                           "n",
                           "rldswkyoujmfxpn",
                           "rvgejzdusoya",
                           "hvoft",
                           "wskgmjchz",
                           "luagnzkj",
                           "ywe",
                           "i",
                           "wcqtsk",
                           "umpvywknjbxacsd",
                           "ynavjpcrgq",
                           "jyftmklci",
                           "xfol",
                           "zh",
                           "kut",
                           "zvawyielscotkn",
                           "p",
                           "wykpqdjoz",
                           "uabtpxkvq",
                           "uabtifwhrvxc",
                           "sdcamqup",
                           "srghwfptloxvke",
                           "sfdywtx",
                           "tuohnxzjqmac",
                           "pwxjyhdurnfz",
                           "axgfcuqtiyhjz",
                           "rwqpyh",
                           "bmoznqavicdgp",
                           "jcu",
                           "vnkc",
                           "jpb",
                           "nvfqyahjkul",
                           "radpctwixygb",
                           "pvjmk",
                           "s",
                           "dzyqjbwucne",
                           "mgh",
                           "ivc",
                           "eaqc",
                           "yjimsadtcwbgk",
                           "lo",
                           "ayirlsfevtwpnd",
                           "wcsk",
                           "xlvejy",
                           "kcjrqf",
                           "a",
                           "ixsdga",
                           "vk",
                           "cqxyfotziwrvl",
                           "zmxboiewhfdjlnr",
                           "kdpwngf",
                           "zyretijxpw",
                           "ncw",
                           "ljw",
                           "mrxeciy",
                           "aqwcofnjypsgi",
                           "byuvhj",
                           "ukidyqzhxgowmc",
                           "cpqsmu",
                           "auwmcrpdisbzokg",
                           "pxgwmvfq",
                           "azgljrsyeqwxfic",
                           "xmlgpdrzwqe",
                           "emgdcqntjpwrf",
                           "hrwq",
                           "zmjkx",
                           "npabcide",
                           "dvlfxnt",
                           "kilqsvmborf",
                           "lvsxjnbimhpzfow",
                           "sqcym",
                           "tcjmkwq",
                           "yugkwdzvmteon",
                           "pq",
                           "nklmb",
                           "azqcnodkimtxve",
                           "ovpcfe",
                           "uqkcwjimbvdyx",
                           "xvdazh",
                           "xk" };

  vector<int> expect{ 190, 21 };
  set<string> wset{words.begin(), words.end()};
  EXPECT_EQ(sol.groupStrings(words), expect);
  LOG(INFO) << "words size: " << words.size() << ", words set size: " << wset.size();

}

