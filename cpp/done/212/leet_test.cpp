#include "leet.cpp"

#include <gtest/gtest.h>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<char>> board{{'o', 'a', 'a', 'n'},
                             {'e', 't', 'a', 'e'},
                             {'i', 'h', 'k', 'r'},
                             {'i', 'f', 'l', 'v'}};
  vector<string> words{"oath", "pea", "eat", "rain"};
  std::vector<string> expect{"eat", "oath"};
  std::sort(expect.begin(), expect.end());
  EXPECT_EQ(sol.findWords(board, words), expect);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<char>> board{{'a'}};
  vector<string> words{"a"};
  std::vector<string> expect{"a"};
  EXPECT_EQ(sol.findWords(board, words), expect);
}
TEST(kk, t3) {
  Solution sol;
  vector<vector<char>> board{{'a', 'p', 't'}};
  vector<string> words{"ap", "pt", "pap"};
  std::vector<string> expect{"ap", "pt"};
  std::sort(expect.begin(), expect.end());

  auto actual = sol.findWords(board, words);
  std::sort(actual.begin(), actual.end());
  EXPECT_EQ(actual, expect);
}

TEST(kk, t4) {
  Solution sol;
  vector<vector<char>> board{{'a'}, {'p'}, {'t'}};
  vector<string> words{"ap", "pt", "pap"};
  std::vector<string> expect{"ap", "pt"};

  auto actual = sol.findWords(board, words);
  std::sort(actual.begin(), actual.end());
  EXPECT_EQ(actual, expect);
}

TEST(kk, t5) {
  Solution sol;
  vector<vector<char>> board;
  vector<string> words{"ap", "pt", "pap"};
  std::vector<string> expect;
  EXPECT_EQ(sol.findWords(board, words), expect);
}
TEST(kk, t6) {
  Solution sol;
  vector<vector<char>> board{
      {'a', 'a', 'a', 'a'}, {'a', 'a', 'a', 'a'}, {'a', 'a', 'a', 'a'},
      {'a', 'a', 'a', 'a'}, {'b', 'c', 'd', 'e'}, {'f', 'g', 'h', 'i'},
      {'j', 'k', 'l', 'm'}, {'n', 'o', 'p', 'q'}, {'r', 's', 't', 'u'},
      {'v', 'w', 'x', 'y'}, {'z', 'z', 'z', 'z'}};
  vector<string> words{
      "aaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaab", "aaaaaaaaaaaaaaac",
      "aaaaaaaaaaaaaaad", "aaaaaaaaaaaaaaae", "aaaaaaaaaaaaaaaf",
      "aaaaaaaaaaaaaaag", "aaaaaaaaaaaaaaah", "aaaaaaaaaaaaaaai",
      "aaaaaaaaaaaaaaaj", "aaaaaaaaaaaaaaak", "aaaaaaaaaaaaaaal",
      "aaaaaaaaaaaaaaam", "aaaaaaaaaaaaaaan", "aaaaaaaaaaaaaaao",
      "aaaaaaaaaaaaaaap", "aaaaaaaaaaaaaaaq", "aaaaaaaaaaaaaaar",
      "aaaaaaaaaaaaaaas", "aaaaaaaaaaaaaaat", "aaaaaaaaaaaaaaau",
      "aaaaaaaaaaaaaaav", "aaaaaaaaaaaaaaaw", "aaaaaaaaaaaaaaax",
      "aaaaaaaaaaaaaaay", "aaaaaaaaaaaaaaaz", "aaaaaaaaaaaaaaba",
      "aaaaaaaaaaaaaabb", "aaaaaaaaaaaaaabc", "aaaaaaaaaaaaaabd",
      "aaaaaaaaaaaaaabe", "aaaaaaaaaaaaaabf", "aaaaaaaaaaaaaabg",
      "aaaaaaaaaaaaaabh", "aaaaaaaaaaaaaabi", "aaaaaaaaaaaaaabj",
      "aaaaaaaaaaaaaabk", "aaaaaaaaaaaaaabl", "aaaaaaaaaaaaaabm",
      "aaaaaaaaaaaaaabn", "aaaaaaaaaaaaaabo", "aaaaaaaaaaaaaabp",
      "aaaaaaaaaaaaaabq", "aaaaaaaaaaaaaabr", "aaaaaaaaaaaaaabs",
      "aaaaaaaaaaaaaabt", "aaaaaaaaaaaaaabu", "aaaaaaaaaaaaaabv",
      "aaaaaaaaaaaaaabw", "aaaaaaaaaaaaaabx", "aaaaaaaaaaaaaaby",
      "aaaaaaaaaaaaaabz", "aaaaaaaaaaaaaaca", "aaaaaaaaaaaaaacb",
      "aaaaaaaaaaaaaacc", "aaaaaaaaaaaaaacd", "aaaaaaaaaaaaaace",
      "aaaaaaaaaaaaaacf", "aaaaaaaaaaaaaacg", "aaaaaaaaaaaaaach",
      "aaaaaaaaaaaaaaci", "aaaaaaaaaaaaaacj", "aaaaaaaaaaaaaack",
      "aaaaaaaaaaaaaacl", "aaaaaaaaaaaaaacm", "aaaaaaaaaaaaaacn",
      "aaaaaaaaaaaaaaco", "aaaaaaaaaaaaaacp", "aaaaaaaaaaaaaacq",
      "aaaaaaaaaaaaaacr", "aaaaaaaaaaaaaacs", "aaaaaaaaaaaaaact",
      "aaaaaaaaaaaaaacu", "aaaaaaaaaaaaaacv", "aaaaaaaaaaaaaacw",
      "aaaaaaaaaaaaaacx", "aaaaaaaaaaaaaacy", "aaaaaaaaaaaaaacz",
      "aaaaaaaaaaaaaada", "aaaaaaaaaaaaaadb", "aaaaaaaaaaaaaadc",
      "aaaaaaaaaaaaaadd", "aaaaaaaaaaaaaade", "aaaaaaaaaaaaaadf",
      "aaaaaaaaaaaaaadg", "aaaaaaaaaaaaaadh", "aaaaaaaaaaaaaadi",
      "aaaaaaaaaaaaaadj", "aaaaaaaaaaaaaadk", "aaaaaaaaaaaaaadl",
      "aaaaaaaaaaaaaadm", "aaaaaaaaaaaaaadn", "aaaaaaaaaaaaaado",
      "aaaaaaaaaaaaaadp", "aaaaaaaaaaaaaadq", "aaaaaaaaaaaaaadr",
      "aaaaaaaaaaaaaads", "aaaaaaaaaaaaaadt", "aaaaaaaaaaaaaadu",
      "aaaaaaaaaaaaaadv", "aaaaaaaaaaaaaadw", "aaaaaaaaaaaaaadx",
      "aaaaaaaaaaaaaady", "aaaaaaaaaaaaaadz", "aaaaaaaaaaaaaaea",
      "aaaaaaaaaaaaaaeb", "aaaaaaaaaaaaaaec", "aaaaaaaaaaaaaaed",
      "aaaaaaaaaaaaaaee", "aaaaaaaaaaaaaaef", "aaaaaaaaaaaaaaeg",
      "aaaaaaaaaaaaaaeh", "aaaaaaaaaaaaaaei", "aaaaaaaaaaaaaaej",
      "aaaaaaaaaaaaaaek", "aaaaaaaaaaaaaael", "aaaaaaaaaaaaaaem",
      "aaaaaaaaaaaaaaen", "aaaaaaaaaaaaaaeo", "aaaaaaaaaaaaaaep",
      "aaaaaaaaaaaaaaeq", "aaaaaaaaaaaaaaer", "aaaaaaaaaaaaaaes",
      "aaaaaaaaaaaaaaet", "aaaaaaaaaaaaaaeu", "aaaaaaaaaaaaaaev",
      "aaaaaaaaaaaaaaew", "aaaaaaaaaaaaaaex", "aaaaaaaaaaaaaaey",
      "aaaaaaaaaaaaaaez", "aaaaaaaaaaaaaafa", "aaaaaaaaaaaaaafb",
      "aaaaaaaaaaaaaafc", "aaaaaaaaaaaaaafd", "aaaaaaaaaaaaaafe",
      "aaaaaaaaaaaaaaff", "aaaaaaaaaaaaaafg", "aaaaaaaaaaaaaafh",
      "aaaaaaaaaaaaaafi", "aaaaaaaaaaaaaafj", "aaaaaaaaaaaaaafk",
      "aaaaaaaaaaaaaafl", "aaaaaaaaaaaaaafm", "aaaaaaaaaaaaaafn",
      "aaaaaaaaaaaaaafo", "aaaaaaaaaaaaaafp", "aaaaaaaaaaaaaafq",
      "aaaaaaaaaaaaaafr", "aaaaaaaaaaaaaafs", "aaaaaaaaaaaaaaft",
      "aaaaaaaaaaaaaafu", "aaaaaaaaaaaaaafv", "aaaaaaaaaaaaaafw",
      "aaaaaaaaaaaaaafx", "aaaaaaaaaaaaaafy", "aaaaaaaaaaaaaafz",
      "aaaaaaaaaaaaaaga", "aaaaaaaaaaaaaagb", "aaaaaaaaaaaaaagc",
      "aaaaaaaaaaaaaagd", "aaaaaaaaaaaaaage", "aaaaaaaaaaaaaagf",
      "aaaaaaaaaaaaaagg", "aaaaaaaaaaaaaagh", "aaaaaaaaaaaaaagi",
      "aaaaaaaaaaaaaagj", "aaaaaaaaaaaaaagk", "aaaaaaaaaaaaaagl",
      "aaaaaaaaaaaaaagm", "aaaaaaaaaaaaaagn", "aaaaaaaaaaaaaago",
      "aaaaaaaaaaaaaagp", "aaaaaaaaaaaaaagq", "aaaaaaaaaaaaaagr",
      "aaaaaaaaaaaaaags", "aaaaaaaaaaaaaagt", "aaaaaaaaaaaaaagu",
      "aaaaaaaaaaaaaagv", "aaaaaaaaaaaaaagw", "aaaaaaaaaaaaaagx",
      "aaaaaaaaaaaaaagy", "aaaaaaaaaaaaaagz", "aaaaaaaaaaaaaaha",
      "aaaaaaaaaaaaaahb", "aaaaaaaaaaaaaahc", "aaaaaaaaaaaaaahd",
      "aaaaaaaaaaaaaahe", "aaaaaaaaaaaaaahf", "aaaaaaaaaaaaaahg",
      "aaaaaaaaaaaaaahh", "aaaaaaaaaaaaaahi", "aaaaaaaaaaaaaahj",
      "aaaaaaaaaaaaaahk", "aaaaaaaaaaaaaahl", "aaaaaaaaaaaaaahm",
      "aaaaaaaaaaaaaahn", "aaaaaaaaaaaaaaho", "aaaaaaaaaaaaaahp",
      "aaaaaaaaaaaaaahq", "aaaaaaaaaaaaaahr", "aaaaaaaaaaaaaahs",
      "aaaaaaaaaaaaaaht", "aaaaaaaaaaaaaahu", "aaaaaaaaaaaaaahv",
      "aaaaaaaaaaaaaahw", "aaaaaaaaaaaaaahx", "aaaaaaaaaaaaaahy",
      "aaaaaaaaaaaaaahz", "aaaaaaaaaaaaaaia", "aaaaaaaaaaaaaaib",
      "aaaaaaaaaaaaaaic", "aaaaaaaaaaaaaaid", "aaaaaaaaaaaaaaie",
      "aaaaaaaaaaaaaaif", "aaaaaaaaaaaaaaig", "aaaaaaaaaaaaaaih",
      "aaaaaaaaaaaaaaii", "aaaaaaaaaaaaaaij", "aaaaaaaaaaaaaaik",
      "aaaaaaaaaaaaaail", "aaaaaaaaaaaaaaim", "aaaaaaaaaaaaaain",
      "aaaaaaaaaaaaaaio", "aaaaaaaaaaaaaaip", "aaaaaaaaaaaaaaiq",
      "aaaaaaaaaaaaaair", "aaaaaaaaaaaaaais", "aaaaaaaaaaaaaait",
      "aaaaaaaaaaaaaaiu", "aaaaaaaaaaaaaaiv", "aaaaaaaaaaaaaaiw",
      "aaaaaaaaaaaaaaix", "aaaaaaaaaaaaaaiy", "aaaaaaaaaaaaaaiz",
      "aaaaaaaaaaaaaaja", "aaaaaaaaaaaaaajb", "aaaaaaaaaaaaaajc",
      "aaaaaaaaaaaaaajd", "aaaaaaaaaaaaaaje", "aaaaaaaaaaaaaajf",
      "aaaaaaaaaaaaaajg", "aaaaaaaaaaaaaajh", "aaaaaaaaaaaaaaji",
      "aaaaaaaaaaaaaajj", "aaaaaaaaaaaaaajk", "aaaaaaaaaaaaaajl",
      "aaaaaaaaaaaaaajm", "aaaaaaaaaaaaaajn", "aaaaaaaaaaaaaajo",
      "aaaaaaaaaaaaaajp", "aaaaaaaaaaaaaajq", "aaaaaaaaaaaaaajr",
      "aaaaaaaaaaaaaajs", "aaaaaaaaaaaaaajt", "aaaaaaaaaaaaaaju",
      "aaaaaaaaaaaaaajv", "aaaaaaaaaaaaaajw", "aaaaaaaaaaaaaajx",
      "aaaaaaaaaaaaaajy", "aaaaaaaaaaaaaajz", "aaaaaaaaaaaaaaka",
      "aaaaaaaaaaaaaakb", "aaaaaaaaaaaaaakc", "aaaaaaaaaaaaaakd",
      "aaaaaaaaaaaaaake", "aaaaaaaaaaaaaakf", "aaaaaaaaaaaaaakg",
      "aaaaaaaaaaaaaakh", "aaaaaaaaaaaaaaki", "aaaaaaaaaaaaaakj",
      "aaaaaaaaaaaaaakk", "aaaaaaaaaaaaaakl", "aaaaaaaaaaaaaakm",
      "aaaaaaaaaaaaaakn", "aaaaaaaaaaaaaako", "aaaaaaaaaaaaaakp",
      "aaaaaaaaaaaaaakq", "aaaaaaaaaaaaaakr", "aaaaaaaaaaaaaaks",
      "aaaaaaaaaaaaaakt", "aaaaaaaaaaaaaaku", "aaaaaaaaaaaaaakv",
      "aaaaaaaaaaaaaakw", "aaaaaaaaaaaaaakx", "aaaaaaaaaaaaaaky",
      "aaaaaaaaaaaaaakz", "aaaaaaaaaaaaaala", "aaaaaaaaaaaaaalb",
      "aaaaaaaaaaaaaalc", "aaaaaaaaaaaaaald", "aaaaaaaaaaaaaale",
      "aaaaaaaaaaaaaalf", "aaaaaaaaaaaaaalg", "aaaaaaaaaaaaaalh",
      "aaaaaaaaaaaaaali", "aaaaaaaaaaaaaalj", "aaaaaaaaaaaaaalk",
      "aaaaaaaaaaaaaall", "aaaaaaaaaaaaaalm", "aaaaaaaaaaaaaaln",
      "aaaaaaaaaaaaaalo", "aaaaaaaaaaaaaalp", "aaaaaaaaaaaaaalq",
      "aaaaaaaaaaaaaalr", "aaaaaaaaaaaaaals", "aaaaaaaaaaaaaalt",
      "aaaaaaaaaaaaaalu", "aaaaaaaaaaaaaalv", "aaaaaaaaaaaaaalw",
      "aaaaaaaaaaaaaalx", "aaaaaaaaaaaaaaly", "aaaaaaaaaaaaaalz",
      "aaaaaaaaaaaaaama", "aaaaaaaaaaaaaamb", "aaaaaaaaaaaaaamc",
      "aaaaaaaaaaaaaamd", "aaaaaaaaaaaaaame", "aaaaaaaaaaaaaamf",
      "aaaaaaaaaaaaaamg", "aaaaaaaaaaaaaamh", "aaaaaaaaaaaaaami",
      "aaaaaaaaaaaaaamj", "aaaaaaaaaaaaaamk", "aaaaaaaaaaaaaaml",
      "aaaaaaaaaaaaaamm", "aaaaaaaaaaaaaamn", "aaaaaaaaaaaaaamo",
      "aaaaaaaaaaaaaamp", "aaaaaaaaaaaaaamq", "aaaaaaaaaaaaaamr",
      "aaaaaaaaaaaaaams", "aaaaaaaaaaaaaamt", "aaaaaaaaaaaaaamu",
      "aaaaaaaaaaaaaamv", "aaaaaaaaaaaaaamw", "aaaaaaaaaaaaaamx",
      "aaaaaaaaaaaaaamy", "aaaaaaaaaaaaaamz", "aaaaaaaaaaaaaana",
      "aaaaaaaaaaaaaanb", "aaaaaaaaaaaaaanc", "aaaaaaaaaaaaaand",
      "aaaaaaaaaaaaaane", "aaaaaaaaaaaaaanf", "aaaaaaaaaaaaaang",
      "aaaaaaaaaaaaaanh", "aaaaaaaaaaaaaani", "aaaaaaaaaaaaaanj",
      "aaaaaaaaaaaaaank", "aaaaaaaaaaaaaanl", "aaaaaaaaaaaaaanm",
      "aaaaaaaaaaaaaann", "aaaaaaaaaaaaaano", "aaaaaaaaaaaaaanp",
      "aaaaaaaaaaaaaanq", "aaaaaaaaaaaaaanr", "aaaaaaaaaaaaaans",
      "aaaaaaaaaaaaaant", "aaaaaaaaaaaaaanu", "aaaaaaaaaaaaaanv",
      "aaaaaaaaaaaaaanw", "aaaaaaaaaaaaaanx", "aaaaaaaaaaaaaany",
      "aaaaaaaaaaaaaanz", "aaaaaaaaaaaaaaoa", "aaaaaaaaaaaaaaob",
      "aaaaaaaaaaaaaaoc", "aaaaaaaaaaaaaaod", "aaaaaaaaaaaaaaoe",
      "aaaaaaaaaaaaaaof", "aaaaaaaaaaaaaaog", "aaaaaaaaaaaaaaoh",
      "aaaaaaaaaaaaaaoi", "aaaaaaaaaaaaaaoj", "aaaaaaaaaaaaaaok",
      "aaaaaaaaaaaaaaol", "aaaaaaaaaaaaaaom", "aaaaaaaaaaaaaaon",
      "aaaaaaaaaaaaaaoo", "aaaaaaaaaaaaaaop", "aaaaaaaaaaaaaaoq",
      "aaaaaaaaaaaaaaor", "aaaaaaaaaaaaaaos", "aaaaaaaaaaaaaaot",
      "aaaaaaaaaaaaaaou", "aaaaaaaaaaaaaaov", "aaaaaaaaaaaaaaow",
      "aaaaaaaaaaaaaaox", "aaaaaaaaaaaaaaoy", "aaaaaaaaaaaaaaoz",
      "aaaaaaaaaaaaaapa", "aaaaaaaaaaaaaapb", "aaaaaaaaaaaaaapc",
      "aaaaaaaaaaaaaapd", "aaaaaaaaaaaaaape", "aaaaaaaaaaaaaapf",
      "aaaaaaaaaaaaaapg", "aaaaaaaaaaaaaaph", "aaaaaaaaaaaaaapi",
      "aaaaaaaaaaaaaapj", "aaaaaaaaaaaaaapk", "aaaaaaaaaaaaaapl",
      "aaaaaaaaaaaaaapm", "aaaaaaaaaaaaaapn", "aaaaaaaaaaaaaapo",
      "aaaaaaaaaaaaaapp", "aaaaaaaaaaaaaapq", "aaaaaaaaaaaaaapr",
      "aaaaaaaaaaaaaaps", "aaaaaaaaaaaaaapt", "aaaaaaaaaaaaaapu",
      "aaaaaaaaaaaaaapv", "aaaaaaaaaaaaaapw", "aaaaaaaaaaaaaapx",
      "aaaaaaaaaaaaaapy", "aaaaaaaaaaaaaapz", "aaaaaaaaaaaaaaqa",
      "aaaaaaaaaaaaaaqb", "aaaaaaaaaaaaaaqc", "aaaaaaaaaaaaaaqd",
      "aaaaaaaaaaaaaaqe", "aaaaaaaaaaaaaaqf", "aaaaaaaaaaaaaaqg",
      "aaaaaaaaaaaaaaqh", "aaaaaaaaaaaaaaqi", "aaaaaaaaaaaaaaqj",
      "aaaaaaaaaaaaaaqk", "aaaaaaaaaaaaaaql", "aaaaaaaaaaaaaaqm",
      "aaaaaaaaaaaaaaqn", "aaaaaaaaaaaaaaqo", "aaaaaaaaaaaaaaqp",
      "aaaaaaaaaaaaaaqq", "aaaaaaaaaaaaaaqr", "aaaaaaaaaaaaaaqs",
      "aaaaaaaaaaaaaaqt", "aaaaaaaaaaaaaaqu", "aaaaaaaaaaaaaaqv",
      "aaaaaaaaaaaaaaqw", "aaaaaaaaaaaaaaqx", "aaaaaaaaaaaaaaqy",
      "aaaaaaaaaaaaaaqz", "aaaaaaaaaaaaaara", "aaaaaaaaaaaaaarb",
      "aaaaaaaaaaaaaarc", "aaaaaaaaaaaaaard", "aaaaaaaaaaaaaare",
      "aaaaaaaaaaaaaarf", "aaaaaaaaaaaaaarg", "aaaaaaaaaaaaaarh",
      "aaaaaaaaaaaaaari", "aaaaaaaaaaaaaarj", "aaaaaaaaaaaaaark",
      "aaaaaaaaaaaaaarl", "aaaaaaaaaaaaaarm", "aaaaaaaaaaaaaarn",
      "aaaaaaaaaaaaaaro", "aaaaaaaaaaaaaarp", "aaaaaaaaaaaaaarq",
      "aaaaaaaaaaaaaarr", "aaaaaaaaaaaaaars", "aaaaaaaaaaaaaart",
      "aaaaaaaaaaaaaaru", "aaaaaaaaaaaaaarv", "aaaaaaaaaaaaaarw",
      "aaaaaaaaaaaaaarx", "aaaaaaaaaaaaaary", "aaaaaaaaaaaaaarz",
      "aaaaaaaaaaaaaasa", "aaaaaaaaaaaaaasb", "aaaaaaaaaaaaaasc",
      "aaaaaaaaaaaaaasd", "aaaaaaaaaaaaaase", "aaaaaaaaaaaaaasf",
      "aaaaaaaaaaaaaasg", "aaaaaaaaaaaaaash", "aaaaaaaaaaaaaasi",
      "aaaaaaaaaaaaaasj", "aaaaaaaaaaaaaask", "aaaaaaaaaaaaaasl",
      "aaaaaaaaaaaaaasm", "aaaaaaaaaaaaaasn", "aaaaaaaaaaaaaaso",
      "aaaaaaaaaaaaaasp", "aaaaaaaaaaaaaasq", "aaaaaaaaaaaaaasr",
      "aaaaaaaaaaaaaass", "aaaaaaaaaaaaaast", "aaaaaaaaaaaaaasu",
      "aaaaaaaaaaaaaasv", "aaaaaaaaaaaaaasw", "aaaaaaaaaaaaaasx",
      "aaaaaaaaaaaaaasy", "aaaaaaaaaaaaaasz", "aaaaaaaaaaaaaata",
      "aaaaaaaaaaaaaatb", "aaaaaaaaaaaaaatc", "aaaaaaaaaaaaaatd",
      "aaaaaaaaaaaaaate", "aaaaaaaaaaaaaatf", "aaaaaaaaaaaaaatg",
      "aaaaaaaaaaaaaath", "aaaaaaaaaaaaaati", "aaaaaaaaaaaaaatj",
      "aaaaaaaaaaaaaatk", "aaaaaaaaaaaaaatl", "aaaaaaaaaaaaaatm",
      "aaaaaaaaaaaaaatn", "aaaaaaaaaaaaaato", "aaaaaaaaaaaaaatp",
      "aaaaaaaaaaaaaatq", "aaaaaaaaaaaaaatr", "aaaaaaaaaaaaaats",
      "aaaaaaaaaaaaaatt", "aaaaaaaaaaaaaatu", "aaaaaaaaaaaaaatv",
      "aaaaaaaaaaaaaatw", "aaaaaaaaaaaaaatx", "aaaaaaaaaaaaaaty",
      "aaaaaaaaaaaaaatz", "aaaaaaaaaaaaaaua", "aaaaaaaaaaaaaaub",
      "aaaaaaaaaaaaaauc", "aaaaaaaaaaaaaaud", "aaaaaaaaaaaaaaue",
      "aaaaaaaaaaaaaauf", "aaaaaaaaaaaaaaug", "aaaaaaaaaaaaaauh",
      "aaaaaaaaaaaaaaui", "aaaaaaaaaaaaaauj", "aaaaaaaaaaaaaauk",
      "aaaaaaaaaaaaaaul", "aaaaaaaaaaaaaaum", "aaaaaaaaaaaaaaun",
      "aaaaaaaaaaaaaauo", "aaaaaaaaaaaaaaup", "aaaaaaaaaaaaaauq",
      "aaaaaaaaaaaaaaur", "aaaaaaaaaaaaaaus", "aaaaaaaaaaaaaaut",
      "aaaaaaaaaaaaaauu", "aaaaaaaaaaaaaauv", "aaaaaaaaaaaaaauw",
      "aaaaaaaaaaaaaaux", "aaaaaaaaaaaaaauy", "aaaaaaaaaaaaaauz",
      "aaaaaaaaaaaaaava", "aaaaaaaaaaaaaavb", "aaaaaaaaaaaaaavc",
      "aaaaaaaaaaaaaavd", "aaaaaaaaaaaaaave", "aaaaaaaaaaaaaavf",
      "aaaaaaaaaaaaaavg", "aaaaaaaaaaaaaavh", "aaaaaaaaaaaaaavi",
      "aaaaaaaaaaaaaavj", "aaaaaaaaaaaaaavk", "aaaaaaaaaaaaaavl",
      "aaaaaaaaaaaaaavm", "aaaaaaaaaaaaaavn", "aaaaaaaaaaaaaavo",
      "aaaaaaaaaaaaaavp", "aaaaaaaaaaaaaavq", "aaaaaaaaaaaaaavr",
      "aaaaaaaaaaaaaavs", "aaaaaaaaaaaaaavt", "aaaaaaaaaaaaaavu",
      "aaaaaaaaaaaaaavv", "aaaaaaaaaaaaaavw", "aaaaaaaaaaaaaavx",
      "aaaaaaaaaaaaaavy", "aaaaaaaaaaaaaavz", "aaaaaaaaaaaaaawa",
      "aaaaaaaaaaaaaawb", "aaaaaaaaaaaaaawc", "aaaaaaaaaaaaaawd",
      "aaaaaaaaaaaaaawe", "aaaaaaaaaaaaaawf", "aaaaaaaaaaaaaawg",
      "aaaaaaaaaaaaaawh", "aaaaaaaaaaaaaawi", "aaaaaaaaaaaaaawj",
      "aaaaaaaaaaaaaawk", "aaaaaaaaaaaaaawl", "aaaaaaaaaaaaaawm",
      "aaaaaaaaaaaaaawn", "aaaaaaaaaaaaaawo", "aaaaaaaaaaaaaawp",
      "aaaaaaaaaaaaaawq", "aaaaaaaaaaaaaawr", "aaaaaaaaaaaaaaws",
      "aaaaaaaaaaaaaawt", "aaaaaaaaaaaaaawu", "aaaaaaaaaaaaaawv",
      "aaaaaaaaaaaaaaww", "aaaaaaaaaaaaaawx", "aaaaaaaaaaaaaawy",
      "aaaaaaaaaaaaaawz", "aaaaaaaaaaaaaaxa", "aaaaaaaaaaaaaaxb",
      "aaaaaaaaaaaaaaxc", "aaaaaaaaaaaaaaxd", "aaaaaaaaaaaaaaxe",
      "aaaaaaaaaaaaaaxf", "aaaaaaaaaaaaaaxg", "aaaaaaaaaaaaaaxh",
      "aaaaaaaaaaaaaaxi", "aaaaaaaaaaaaaaxj", "aaaaaaaaaaaaaaxk",
      "aaaaaaaaaaaaaaxl", "aaaaaaaaaaaaaaxm", "aaaaaaaaaaaaaaxn",
      "aaaaaaaaaaaaaaxo", "aaaaaaaaaaaaaaxp", "aaaaaaaaaaaaaaxq",
      "aaaaaaaaaaaaaaxr", "aaaaaaaaaaaaaaxs", "aaaaaaaaaaaaaaxt",
      "aaaaaaaaaaaaaaxu", "aaaaaaaaaaaaaaxv", "aaaaaaaaaaaaaaxw",
      "aaaaaaaaaaaaaaxx", "aaaaaaaaaaaaaaxy", "aaaaaaaaaaaaaaxz",
      "aaaaaaaaaaaaaaya", "aaaaaaaaaaaaaayb", "aaaaaaaaaaaaaayc",
      "aaaaaaaaaaaaaayd", "aaaaaaaaaaaaaaye", "aaaaaaaaaaaaaayf",
      "aaaaaaaaaaaaaayg", "aaaaaaaaaaaaaayh", "aaaaaaaaaaaaaayi",
      "aaaaaaaaaaaaaayj", "aaaaaaaaaaaaaayk", "aaaaaaaaaaaaaayl",
      "aaaaaaaaaaaaaaym", "aaaaaaaaaaaaaayn", "aaaaaaaaaaaaaayo",
      "aaaaaaaaaaaaaayp", "aaaaaaaaaaaaaayq", "aaaaaaaaaaaaaayr",
      "aaaaaaaaaaaaaays", "aaaaaaaaaaaaaayt", "aaaaaaaaaaaaaayu",
      "aaaaaaaaaaaaaayv", "aaaaaaaaaaaaaayw", "aaaaaaaaaaaaaayx",
      "aaaaaaaaaaaaaayy", "aaaaaaaaaaaaaayz", "aaaaaaaaaaaaaaza",
      "aaaaaaaaaaaaaazb", "aaaaaaaaaaaaaazc", "aaaaaaaaaaaaaazd",
      "aaaaaaaaaaaaaaze", "aaaaaaaaaaaaaazf", "aaaaaaaaaaaaaazg",
      "aaaaaaaaaaaaaazh", "aaaaaaaaaaaaaazi", "aaaaaaaaaaaaaazj",
      "aaaaaaaaaaaaaazk", "aaaaaaaaaaaaaazl", "aaaaaaaaaaaaaazm",
      "aaaaaaaaaaaaaazn", "aaaaaaaaaaaaaazo", "aaaaaaaaaaaaaazp",
      "aaaaaaaaaaaaaazq", "aaaaaaaaaaaaaazr", "aaaaaaaaaaaaaazs",
      "aaaaaaaaaaaaaazt", "aaaaaaaaaaaaaazu", "aaaaaaaaaaaaaazv",
      "aaaaaaaaaaaaaazw", "aaaaaaaaaaaaaazx", "aaaaaaaaaaaaaazy",
      "aaaaaaaaaaaaaazz"};
  std::vector<string> expect{
      "aaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaab", "aaaaaaaaaaaaaaac",
      "aaaaaaaaaaaaaaad", "aaaaaaaaaaaaaaae", "aaaaaaaaaaaaaabc",
      "aaaaaaaaaaaaaabf", "aaaaaaaaaaaaaacb", "aaaaaaaaaaaaaacd",
      "aaaaaaaaaaaaaacg", "aaaaaaaaaaaaaadc", "aaaaaaaaaaaaaade",
      "aaaaaaaaaaaaaadh", "aaaaaaaaaaaaaaed", "aaaaaaaaaaaaaaei"};

  auto actual = sol.findWords(board, words);
  std::sort(actual.begin(), actual.end());
  EXPECT_EQ(actual, expect);
}

