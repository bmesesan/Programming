#include <iostream>
#include <vector>
#include <map>
using namespace std;

string tournamentWinner(vector<vector<string>> competitions,
                        vector<int> results) {
    std::map<std::string, int> teams_map;
    for (int i = 0; i < competitions.size(); i++) {
        std::string winning_team = "";
        if (results[i] == 0) {
            // away team won
            winning_team = competitions[i][1];
        } else {
            // home team won
            winning_team = competitions[i][0];
        }

        if (teams_map.count(winning_team) == 1) {
            teams_map[winning_team] += 3;
        } else {
            teams_map.insert({winning_team, 3});
        }
    }

    std::string final_winner = "";
    int max_score = 0;
    map<string, int>::iterator it;

    for (it = teams_map.begin(); it != teams_map.end(); it++)
    {
        if (it->second >= max_score) {
            final_winner = it->first;
            max_score = it->second;
        }
    }

    return final_winner;
}



void test_0(void) {
    // Test 1
    vector<vector<string>> competitions = {
            {"HTML", "C#"},
            {"C#", "Python"},
            {"Python", "HTML"}
    };
    vector<int> results = {0, 0, 1};
    std::string winning_team = tournamentWinner(competitions, results);
    printf("Done test 0!");
}

int main()
{
    // Test 1
    test_0();
}