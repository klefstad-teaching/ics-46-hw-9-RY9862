using namespace std;

#include <iostream>
#include <fstream>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include "ladder.h"

void error(string word1, string word2, string msg) { cerr << "Error processing " << word1 << " and " << word2 << ": " << msg << endl; }

bool edit_distance_within(const std::string& str1, const std::string& str2, int d) {
    int len1 = str1.length();
    int len2 = str2.length();
    int str1_i = 0;
    int str2_i = 0;
    int count = 0;
    
    if (abs(len2 - len1) > d) return false;

    while (str1_i < len1 && str2_i < len2) {

        if (tolower(str1[str1_i]) != tolower(str2[str2_i])) {
            if (++count > d) return false;

            if (len1 > len2) ++str1_i;

            else if (len1 < len2) ++str2_i;

            else if (len1 == len2) {
                ++str1_i; 
                ++str2_i;
            }
        }

        else {
            ++str1_i; 
            ++str2_i;
        }
    }

    return (count + abs(len1 - str1_i) + abs(len2 - str2_i)) <= d;
}

bool is_adjacent(const string& word1, const string& word2) { return edit_distance_within(word1, word2, 1); }

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list) {
    queue<vector<string>> ladder_queue;
    ladder_queue.push({begin_word});

    set<string> visited;
    visited.insert(begin_word);

    while (!ladder_queue.empty()) {
        vector<string> ladder = ladder_queue.front();
        ladder_queue.pop();

        string last_word = ladder.back();

        for (string word: word_list) {

            if (is_adjacent(last_word, word)) {

                if (visited.find(word) == visited.end()) {
                    visited.insert(word);

                    vector<string> new_ladder = ladder;
                    new_ladder.push_back(word);

                    if (word == end_word) return new_ladder;

                    ladder_queue.push(new_ladder);
                }
            }
        }
    }

    return {};
}

void load_words(set<string> & word_list, const string& file_name) {
    ifstream in(file_name);
    string word;

    if (!in) {
        throw runtime_error("Can't open input file");
    }

    while (in >> word) {
        word_list.insert(word);
    }

    in.close();
}


void print_word_ladder(const vector<string>& ladder) {
    for (const auto & word: ladder)
        cout << word << " ";

    cout << endl;
}

#define my_assert(e) {cout << #e << ((e) ? " passed": " failed") << endl;}
void verify_word_ladder() {
    set<string> word_list;
    load_words(word_list, "src/words.txt");

    my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);
    my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);
    my_assert(generate_word_ladder("code", "data", word_list).size() == 6);
    my_assert(generate_word_ladder("work", "play", word_list).size() == 6);
    my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);
    my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);
} 