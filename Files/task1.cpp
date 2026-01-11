#include <iostream>
#include <fstream>
using namespace std;

int main() {

    ofstream outfile("intput.txt");

    if(!outfile) cout<<"Error file opening!"<<endl;

    cout<<"Enter your paragraph: ";
    string str;
    getline(cin,str);

    outfile<< str <<endl;

    outfile.close();

    cout << "Enter the word to be replaced: ";
    string findword;
    cin >> findword;

    cout << "Enter word to replace: ";
    string replacedword;
    cin >> replacedword;

    string word;
    string ansstring = "";
    ifstream infile("intput.txt");

    while (infile >> word)
    {
        string realWord = word;
        string pun = "";

        int size = word.size();
        char lastchar = word[size-1];

        if(lastchar == '.' || lastchar == '!' || lastchar == '?')
        {
            pun = lastchar;
            realWord.pop_back();
        }

        if(realWord == findword)
        {
            ansstring += (replacedword + pun);
        }
        else
        {
            ansstring += (realWord + pun);
        }

        ansstring += " ";
    }

    if (!ansstring.empty())
    {
        ansstring.pop_back();
    }

    cout << ansstring << endl;

    infile.close();



    return 0;
}