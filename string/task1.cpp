#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "Enter a String:";
    string s;
    getline(cin, s);
    int countAlpha = 0, countDigi = 0, countSpec = 0;
    for (int i = 0; i < (int)s.size(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            ++countAlpha;
        }
        else if (s[i] >= '0' && s[i] <= '9')
        {
            ++countDigi;
        }
        else
            ++countSpec;
    }
    cout << "Number of Alphabets: " << countAlpha << endl;
    cout << "Number of Digits: " << countDigi << endl;
    cout << "Number of Special Charecters: " << countSpec << endl;
    return 0;
}