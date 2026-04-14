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
void print(vector<pair<string, int>>& wordCount);

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
    sortWords(myWords);
    
    vector<pair<string, int>> myWordCounts = getWordCounts(myWords);

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
    sort(words.begin(), words.end());
}

vector<pair<string, int>> getWordCounts(vector<string>& words)
{
    vector<pair<string, int>> wordCounts;

    if(words.empty())
        return wordCounts;

    string currWord = words[0];
    int count = 1;

    for(size_t i = 1; i < words.size(); i++)
    {
        if(words[i] == currWord)
        {
            count++;
        }
        else
        {
            wordCounts.push_back(make_pair(currWord, count));
            currWord = words[i];
            count = 1;
        }
    }

    wordCounts.push_back(make_pair(currWord, count));

    return wordCounts;
}

void print(const vector<pair<string, int>>& wordCounts)
{
    cout << "Word Frequencies of passage from Sherlock Holmes" << endl;
    cout << "------------------------------------------------" << endl;
    
    for(size_t i = 0; i < wordCounts.size(); i++)
    {
        cout << wordCounts[i].first << " : " << wordCounts[i].second << endl;
    }
}
