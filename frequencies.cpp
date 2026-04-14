#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void getWords(vector<string>& words, ifstream& file);
string convertWord(const string& word);
void sortWords(vector<string>& words);
vector<pair<string, int>> getWordCounts(vector<string>& words);

int main()
{
    vector<string> myWords;

    ifstream file("homes.txt", ios::in);
    if(file.fail())
    {
        cout << "Error: Input file failed to open" << endl;
        exit(1);
    }

    getWords(myWords, file);

    return 0;
}

void getWords(vector<string>& words, ifstream& file)
{
    string word;
    while(file >> word)
    {
        words.push_back(word);
    }
}

string convertWord(const string& word)
{
    string converted;
    for(char c : word)
    {
        if(isalpha(c))
            converted += tolower(c);
    }

    return converted;
}


void sortWords(vector<string>& words)
{
    sort(words.begin(), words.end())
}

