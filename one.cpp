#include<bits/stdc++.h>
using namespace std;

bool ischar(char ch)
{

    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
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
        for(int i=0;i<s.length();i++)
        {
            if(ischar(s[i])){}
            else{
                    num1 = (s[i] - '0');
                    break;
            }
        }
        //cout<<num1<<endl;
        for(int i=s.length()-1;i>=0;i--)
        {
            if(ischar(s[i])){}
            else{
                    num2 = (s[i] - '0');
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
