#include<bits/stdc++.h>
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

void solve()
{
    int n = 5;
    unordered_map<int, unordered_map<string, int>> mp;
    for(int i=0;i<n;i++)
    {
        string str;
        cin>>str;

        cout<<"String: "<<str<<endl;

        // char str[100000];
        // cin.getline(str, 100000);
        // char *ptr; // declare a pointer for storing splitted words
        
        // ptr = strtok(str, ";");

        vector<string> str_vec = split(str,';');

        for(auto ptr: str_vec)
        {
            cout<<ptr<<" ";
            // ptr = strtok(NULL, ";");
        }
        cout<<endl;

        string first = str_vec[0];
        string game = "";
        int j = 0;
        while(first[j] != ':')
        {
            game += first[j];
            j++;
        }

        str_vec[0] = first.substr(j+2);

        unordered_map<string, int> mp2;
        for(auto it: str_vec)
        {
            vector<string> splt = split(it, ',');
            for(int i=0;i<splt.size();i++)
            {
                string sss = trim(splt[i]);
                int index = 0;
                while(sss[index] != 32)
                {
                    index++;
                }

                mp2[sss.substr(index+1)] += stoi(sss.substr(0, index));
            }
        }

        for(auto it: mp2)
        {

            cout<<it.first<<" "<<it.second<<endl;
        }

        mp[stoi(game.substr(5))] = mp2;

    }

    int ans = 0;
    for(auto it: mp)
    {
        bool canadd = false;
        for(auto it2: it.second)
        {
            if(it2.first == "red")
            {
                if(it2.second <= 12)
                    canadd = true;
                else
                    canadd = false;
            }
            if(it2.first == "green")
            {
                if(it2.second <= 13)
                    canadd = true;
                else
                    canadd = false;
            }
            if(it2.first == "blue")
            {
                if(it2.second <= 14)
                    canadd = true;
                else
                    canadd = false;
            }
        }

        if(canadd)
            ans += it.first;
    }

    cout<<"Ans: "<<ans<<endl;

}

int main()
{
    solve();
    return 0;
}
