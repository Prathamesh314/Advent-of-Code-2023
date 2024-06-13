#include<bits/stdc++.h>
using namespace std;



bool ischar(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}


int getnumber(string s, int i)
{
    if(s.substr(i, 3) == "one") {return 1;}
    else if(s.substr(i, 3) == "two") {return 2;}
    else if(s.substr(i, 5) == "three") {return 3;}
    else if(s.substr(i, 4) == "four") {return 4;}
    else if(s.substr(i, 4) == "five") {return 5;}
    else if(s.substr(i, 3) == "six") {return 6;}
    else if(s.substr(i, 5) == "seven") {return 7;}
    else if(s.substr(i, 5) == "eight") {return 8;}
    else if(s.substr(i, 4) == "nine") {return 9;}
    return -1;
}

int getnumber_from_end(string s, int i)
{
    int start = max(0, i - 2);
    string substring = s.substr(start, i - start + 1);

    if(substring == "one") return 1;
    if(substring == "two") return 2;
    start = max(0, i-4);
    substring = s.substr(start, i - start + 1);
    if(substring == "three") return 3;
    start = max(0, i-3);
    substring = s.substr(start, i - start + 1);
    if(substring == "four") return 4;
    else if(substring == "five") return 5;
    start = max(0,i-2);
    substring = s.substr(start, i - start + 1);
    if(substring == "six") return 6;
    start = max(0, i-4);
    substring = s.substr(start, i - start + 1);
    if(substring == "seven") return 7;
    else if(substring == "eight") return 8;
    start = max(0, i-3);
    substring = s.substr(start, i - start + 1);
    if(substring == "nine") return 9;

    return -1;
 
}


void solve()
{
    int n = 1000;
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        int num1=-1, num2=-1;
        /* cout<<s<<endl; */

        for(int i=0;i<s.length();i++){
            if(ischar(s[i]))
            {
                num1 = getnumber(s,i);
                if(num1 != -1)
                    break;
            }            else{
                num1 = (s[i] - '0');
                break;
            }
        }


        for(int i=s.length()-1;i>=0;i--)
        {
            if(ischar(s[i])){
                num2 = getnumber_from_end(s,i);
                if(num2 != -1) break;
            }
            else{

                num2 = s[i]-'0';
                break;
            }
        }

        sum += (num1*10) + num2;
    }
    cout<<sum<<endl;
}

int main()
{
    solve();
    return 0;
}
