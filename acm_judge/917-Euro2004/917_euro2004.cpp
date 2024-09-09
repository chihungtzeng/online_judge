#include <iostream>
#include <sstream>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <assert.h>
#include <stdio.h>

#define LOGGING 0

class Team;

enum class game_result {
    win,
    tie,
    lose
};

class IDManager {
private:
    std::unordered_map<std::string, int> name_to_id;
    int last_id;
public:
    IDManager() {
        name_to_id.reserve(20000);
        last_id = 0;
    }

    void reset() {
        name_to_id.clear();
        last_id = 0;
    }

    int get_last_id() const {
        return last_id;
    }

    int add_name(const std::string& name) {
        const auto& hit = name_to_id.find(name);
        if (hit != name_to_id.end())
            return hit->second;
        else
            return _add_name(name);
    }

    int get_id(const std::string& name) {
        return add_name(name);
    }

    void get_all_team_names(std::vector<std::string> names) const
    {
        for(const auto& pair: name_to_id) {
            names.push_back(pair.first);
        }
    }
private:
    int _add_name(const std::string& name) {
        ++last_id;
        name_to_id.insert({name, last_id});
        return last_id - 1;
    }

};

class LeagueHistory {
private:
    std::vector<int> history;

public:
    LeagueHistory() { history.reserve(10); }

    void add(int h) { history.push_back(h); }
    int get_last_num_points() const { return history.back(); }

    std::vector<int> get_history() const { return history; }

    std::string to_string() const
    {
        std::ostringstream s;

        s << "\"";
        for (const auto v : history) {
            s << v << " ";
        }
        s << "\"";
        return std::string(s.str());
    }

    int compare(const LeagueHistory& other) const
    {
        if (*this == other)
            return 0;
        else if (*this < other)
            return -1;
        else
            return 1;
    }

    bool operator>(const LeagueHistory& other) const
    {
        const auto other_history = other.get_history();
        const auto min_size = std::min(history.size(),
            other_history.size());
        for (unsigned i = 0; i < min_size; ++i) {
            if (history[i] > other_history[i])
                return true;
            else if (history[i] < other_history[i]) {
                return false;
            }
        }
        if (history.size() > min_size)
            return true;
        else
            return false;
    }

    bool operator<(const LeagueHistory& other) const
    {
        if ((*this == other) || (*this > other))
            return false;
        else
            return true;
    }

    bool operator==(const LeagueHistory& other) const
    {
        const auto other_history = other.get_history();
        const auto my_size = history.size();
        if (my_size != other_history.size())
            return false;

        for (unsigned i = 0; i < my_size; ++i) {
            if (history[i] != other_history[i])
                return false;
        }
        return true;
    }
};

class Game {
private:
    int players_id[2];
    int num_goals[2];
    Team *players[2];

public:
    Game(const int id0, const int id1, int score0, int score1)
    {
        players_id[0] = id0;
        players_id[1] = id1;
        num_goals[0] = score0;
        num_goals[1] = score1;
        players[0] = nullptr;
        players[1] = nullptr;
    }
    void set_players_pointer(const int index, Team* pt)
    {
        players[index] = pt;
    }
    Team* get_players_pointer(const int index) const
    {
        return players[index];
    }
    bool is_tie() const { return num_goals[0] == num_goals[1]; }
    bool is_player0_win() const { return num_goals[0] > num_goals[1]; }
    int get_player_id(int idx) const { return players_id[idx]; }
    int get_num_goals_by_index(int i) const { return num_goals[i]; }
};

class GameDatabase {
public:
    std::vector<Game> games;

public:
    GameDatabase()
    {
        games.reserve(20000);
    }

    void reset()
    {
        games.clear();
    }

    void get_all_team_names(std::vector<std::string>& names) const
    {
    }
    void add_game(const int id0, const int id1, int score0, int score1)
    {
        games.push_back(Game(id0, id1, score0, score1));
    }
    int get_num_games() const { return games.size(); }
};

class Team {
private:
    std::string name;
    LeagueHistory league_history;
    int num_goals_scored;
    int num_goals_conceded;
    int num_points;
    int num_wins;
    int id;
    bool updated;

public:
    Team(const std::string& _name)
        : name(_name)
        , num_goals_scored(0)
        , num_goals_conceded(0)
        , num_points(0)
        , num_wins(0)
        , id(0)
        , updated(true)
    {
    }

    void set_num_goals_scored(int goals)
    {
        num_goals_scored = goals;
    }
    int get_num_goals_scored() const { return num_goals_scored; }
    int get_num_goals_conceded() const { return num_goals_conceded; }
    void set_num_points(int points) { num_points = points; }
    int get_num_points() const { return num_points; }
    void set_num_wins(int wins) { num_wins = wins; }
    int get_num_wins() const { return num_wins; }
    std::string get_name() const { return name; }
    int get_id() const { return id; }
    void set_id(int _id) { id = _id; }

    void add_num_goals_scored(int goals)
    {
        num_goals_scored += goals;
    }

    void add_num_goals_conceded(int goals)
    {
        num_goals_conceded += goals;
    }

    void add_num_wins()
    {
        num_wins++;
    }

    bool get_updated() const { return updated; }
    void set_updated(bool b) { updated = b; }

    LeagueHistory get_league_history() const { return league_history; }

    bool same_league_with(const Team& other) const
    {
        return league_history == other.get_league_history();
    }

    bool equal_in_all_parameters(const Team& other) const
    {
        if (same_league_with(other)) {
            return num_goals_scored == other.get_num_goals_scored()
                && num_wins == other.get_num_wins();
        }
        else {
            return false;
        }
    }

    bool can_update_league_history() const
    {
        if (updated)
            return false;
        else
            return num_points != league_history.get_last_num_points();
    }
    void add_points(game_result res)
    {
        if (res == game_result::win)
            num_points += 3;
        else if (res == game_result::tie)
            num_points += 1;
    }

    void add_to_league(int league_id)
    {
        league_history.add(league_id);
    }

    void update_league_history()
    {
#if LOGGING
        std::cout << name << " update points: " << num_points
                  << "\n";
#endif
        league_history.add(num_points);
        set_updated(true);
    }

    std::string to_string() const
    {
        std::ostringstream s;
        s << name
          << " ("
          << "point=" << num_points
          << " goal_avg=" << num_goals_scored << "/" << num_goals_conceded
          << " wins=" << num_wins
          << " league_history: " << league_history.to_string()
          << ")";
        return std::string(s.str());
    }

    int has_same_goal_average(const Team& other) const
    {
        auto myself = get_num_goals_scored() - get_num_goals_conceded();
        auto rival = other.get_num_goals_scored() - other.get_num_goals_conceded();
        if (myself == rival)
            return 0;
        else if (myself < rival)
            return -1;
        else
            return 1;
    }

    int has_same_wins(const Team& other) const
    {
        auto my = get_num_wins();
        auto rival = other.get_num_wins();
        if (my == rival)
            return 0;
        else if (my < rival)
            return -1;
        else
            return 1;
    }

    int has_same_goals(const Team& other) const
    {
        auto my = get_num_goals_scored();
        auto rival = other.get_num_goals_scored();
        if (my == rival)
            return 0;
        else if (my < rival)
            return -1;
        else
            return 1;
    }

    int perform_better_than(const Team& other) const
    {
        // return value:
        //  0: the same
        //  -1: perform worse than the rival
        //  1 : perform better than the rival
        // The comparison does not include the team name
        auto same_league = same_league_with(other);
        if (same_league) {
            // In the same league, their points are the same so we compare
            // other parameters
            auto goal_average_compare = has_same_goal_average(other);
            if (goal_average_compare)
                return goal_average_compare;
            else {
                auto wins_compare = has_same_wins(other);
                if (wins_compare)
                    return wins_compare;
                else {
                    auto goals_compare = has_same_goals(other);
                    if (goals_compare)
                        return goals_compare;
                    else
                        return 0;
                }
            }
        }
        else {
            // Not in the same league, so their points are different
            return league_history > other.get_league_history() ? 1 : -1;
        }
    }

    bool operator==(const Team& other) const
    {
        return name.compare(other.name) == 0;
    }

    bool operator<(const Team& other) const
    {
        if (*this == other)
            return false;

        auto better = perform_better_than(other);
        if (better > 0)
            return true;
        else if (better < 0)
            return false;
        else
            return (name.compare(other.name) < 0) ? true : false;
    }

    int operator>(const Team& other) const
    {
        if (*this == other)
            return false;
        if (*this < other)
            return false;
        return true;
    }
};

class TeamManager {
private:
    GameDatabase gdb;
    std::unordered_map<std::string, Team> teams;
    IDManager id_manager;

public:
    TeamManager() {}

    void reset()
    {
        teams.clear();
        gdb.reset();
        id_manager.reset();
    }

    void read_game_database(FILE *fp)
    {
        int num_plays;
        int num_goals[2];
        char names[2][21];

        assert(fp != NULL);
        assert(gdb.get_num_games() == 0);

        fscanf(fp, "%d", &num_plays);
        while (num_plays--) {
            fscanf(fp, "%s %s %d %d", names[0], names[1], &num_goals[0], &num_goals[1]);
            int id0 = id_manager.add_name(names[0]);
            int id1 = id_manager.add_name(names[1]);
            gdb.add_game(id0, id1, num_goals[0], num_goals[1]);
        }
    }

    void show_ranks()
    {
        std::vector<Team> vec_teams;
        vec_teams.reserve(teams.size());

        for (const auto& pair : teams) {
            vec_teams.push_back(pair.second);
        }

        std::sort(vec_teams.begin(), vec_teams.end());

        int rank = 1;
        int rank_jump = 1;
        auto cur = vec_teams.begin();
        auto prev = cur;
        std::cout << rank << " " << cur->get_name() << "\n";
        cur++;
        while (cur != vec_teams.end()) {
            if (cur->equal_in_all_parameters(*prev)) {
                // use the same rank as the previous team
                rank_jump++;
            }
            else {
                rank += rank_jump;
                rank_jump = 1;
            }
            std::cout << rank << " " << cur->get_name() << "\n";
            prev = cur;
            cur++;
        }
    }

    void calc_ranks()
    {
        construct_team_map();
        calc_leagues();
        calc_other_parameters();
#ifndef ONLINE_JUDGE
        show_teams_info();
#endif
    }

private:
    void calc_other_parameters()
    {
        // update (1) goal-average (2) num_wins (3) num of goal scored
        Team* players[2] = { nullptr, nullptr };
        for (const auto game : gdb.games) {
            players[0] = game.get_players_pointer(0);
            players[1] = game.get_players_pointer(1);
            if (!(players[0]->same_league_with(*players[1])))
                continue;

            int player_scores[2];
            player_scores[0] = game.get_num_goals_by_index(0);
            player_scores[1] = game.get_num_goals_by_index(1);

            players[0]->add_num_goals_scored(player_scores[0]);
            players[1]->add_num_goals_scored(player_scores[1]);
            players[0]->add_num_goals_conceded(player_scores[1]);
            players[1]->add_num_goals_conceded(player_scores[0]);
            if (!game.is_tie()) {
                int winner = game.is_player0_win() ? 0 : 1;
                players[winner]->add_num_wins();
            }
        }
    }

    void calc_leagues()
    {
        int keep_going = 0;
        do {
            set_updated_flag_for_teams(false);
            reset_points_for_teams();
            calc_points_for_teams();
            keep_going = update_league_history();
            set_updated_flag_for_teams(true);
        } while (keep_going);
    }

    int update_league_history()
    {
        int do_update = 0;
        for (auto& pair : teams) {
            auto& team = pair.second;
            if (team.can_update_league_history()) {
#if LOGGING
                std::cout << "Team " << team.get_name()
                          << " can update legaure"
                          << "\n";
#endif
                std::vector<Team*> league;
                get_league_by_team(team, league);
                for (auto* team_ptr : league) {
                    team_ptr->update_league_history();
                }
                do_update = 1;
            }
        }
        return do_update;
    }

    void calc_points_for_teams()
    {
        for (const auto& game : gdb.games) {
            update_points_for_players(game);
        }
    }

    void update_points_for_players(const Game& game)
    {
        Team* players[2] = { game.get_players_pointer(0), game.get_players_pointer(1)};

        if (!(players[0]->same_league_with(*players[1])))
            return;

        if (game.is_tie()) {
            players[0]->add_points(game_result::tie);
            players[1]->add_points(game_result::tie);
        }
        else {
            int winner = game.is_player0_win() ? 0 : 1;
            players[winner]->add_points(game_result::win);
        }
    }

    void reset_points_for_teams()
    {
        for (auto& pair : teams) {
            pair.second.set_num_points(0);
        }
    }
    void set_updated_flag_for_teams(bool flag)
    {
        for (auto& pair : teams) {
            pair.second.set_updated(flag);
        }
    }

    void construct_team_map()
    {
        std::vector<std::string> names;
        gdb.get_all_team_names(names);
        for (const auto& name : names) {
            add_team_by_name(name);
        }
        for(auto& game: gdb.games) {
            const std::string* player_name;
            for(int i=0; i<2; i++){
                if (!game.get_players_pointer(i)) {
                    player_name = game.get_player_name(i);
                    game.set_players_pointer(i,
                        get_team_by_name(*player_name));
                }
            }
        }
        // Initially, every team belongs to league 0
        for (auto& pair : teams) {
            pair.second.add_to_league(0);
        }
    }

    void get_league_by_team(const Team& other, std::vector<Team*>& league)
    {
        assert(league.size() == 0);
        league.reserve(1000);
        for (auto& pair : teams) {
            auto* t = &(pair.second);
            if (t->get_league_history() == other.get_league_history())
                league.push_back(t);
        }
    }

    Team* add_team_by_name(const std::string& name)
    {
        auto hit = teams.find(name);
        if (hit == teams.end()) {
            teams.insert({ name, Team(name) });
            hit = teams.find(name);
        }
        return &(hit->second);
    }
    Team* get_team_by_name(const std::string& name)
    {
        auto hit = teams.find(name);
        if (hit != teams.end())
            return &(hit->second);
        else
            return add_team_by_name(name);
    }
    void show_teams_info() const
    {
        for (const auto& pair : teams) {
            auto& team = pair.second;
            std::cout << team.to_string() << "\n";
        }
        std::cout << "\n";
    }
    bool can_update_league() const
    {
        for (const auto& pair : teams) {
            if (pair.second.can_update_league_history())
                return true;
        }
        return false;
    }
};

int main(int argc, char* argv[])
{
    TeamManager tm;
    int num_cases;
    FILE *fp = NULL;
#ifndef ONLINE_JUDGE
    fp = fopen("../in5.txt", "r");
#else
    fp = stdin;
#endif
    fscanf(fp, "%d", &num_cases);
    while (num_cases--) {
        tm.reset();
        tm.read_game_database(fp);
        tm.calc_ranks();
        tm.show_ranks();
        if (num_cases)
            std::cout << "\n";
    }
#ifndef ONLINE_JUDGE
    fclose(fp);
#endif

    return 0;
}
