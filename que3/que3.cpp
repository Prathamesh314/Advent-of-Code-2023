#include <bits/stdc++.h>
#include <fstream>
using namespace std;

// Function to trim leading whitespace
std::string ltrim(const std::string &s) {
    size_t start = s.find_first_not_of(" \t\n\r\f\v");
    return (start == std::string::npos) ? "" : s.substr(start);
}

// Function to trim trailing whitespace
std::string rtrim(const std::string &s) {
    size_t end = s.find_last_not_of(" \t\n\r\f\v");
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

// Function to trim both leading and trailing whitespace
std::string trim(const std::string &s) {
    return rtrim(ltrim(s));
}

// Function to split a string and return a vector of string;
std::vector<std::string> split(const std::string &s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::stringstream ss(s);
    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

void solve() {
    std::ifstream inputFile("input.txt");
    std::string line;
    vector<string> strs;
    if (inputFile.is_open()) {
        while (std::getline(inputFile, line)) {
            // Process each line
            strs.push_back(line);
        }
        inputFile.close();
    } else {
        std::cout << "Unable to open file" << std::endl;
    }

    int n = strs.size();
    unordered_map<int, unordered_map<string, vector<int>>> mp;

    for (int i = 0; i < n; i++) {
        string s = strs[i];
        vector<string> str_vec = split(s, ';');
        string first = str_vec[0];
        vector<string> games = split(first, ':');
        str_vec[0] = trim(games[1]);
        string game = games[0];
        unordered_map<string, vector<int>> mp2;
        for (auto it : str_vec) {
            vector<string> splt = split(it, ',');
            for (int j = 0; j < splt.size(); j++) {
                string sss = trim(splt[j]);
                int index = 0;
                while (sss[index] != 32) {
                    index++;
                }
                mp2[sss.substr(index + 1)].push_back(stoi(sss.substr(0, index)));
            }
        }
        mp[stoi(game.substr(5))] = mp2;
    }

    int ans = 0;
    for (auto it : mp) {
        bool canadd = true;
        for (auto it2 : it.second) {
            if (it2.first == "red") {
                for (auto it3 : it2.second) {
                    if (it3 > 12) {
                        canadd = false;
                        break;
                    }
                }
                if (!canadd) break;
            }
            if (it2.first == "green") {
                for (auto it3 : it2.second) {
                    if (it3 > 13) {
                        canadd = false;
                        break;
                    }
                }
                if (!canadd) break;
            }
            if (it2.first == "blue") {
                for (auto it3 : it2.second) {
                    if (it3 > 14) {
                        canadd = false;
                        break;
                    }
                }
                if (!canadd) break;
            }
        }
        if (canadd) {
            cout << "Game: " << it.first << endl;
            ans += it.first;
        }
    }
    cout << "Ans: " << ans << endl;
}

int main() {
    solve();
    return 0;
}