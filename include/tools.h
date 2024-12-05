#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <sstream>
#include <algorithm> // std::sort
#include <vector>
#include <regex>

using namespace std;

void splitLine(string line, string *s1, string *s2)
{
    istringstream sline(line);
    getline(sline, *s1, ' ');
    for (int i = 0; i <= 3; ++i)
    {
        getline(sline, *s2, ' ');
    }
}

void splitLine(string line, vector<string> *vec)
{
    istringstream sline(line);
    string data = "";
    while (getline(sline, data, ' '))
    {
        vec->push_back(data);
    }
}
void splitLine(string line, vector<int long> *vec)
{
    istringstream sline(line);
    string data = "";
    while (getline(sline, data, ' '))
    {
        vec->push_back(stol(data.c_str()));
    }
}

void getInts(string line, long int *d1, long int *d2)
{
    string s1 = "", s2 = "";
    splitLine(line, &s1, &s2);
    *d1 = stol(s1.c_str());
    *d2 = stol(s2.c_str());
}

void fillTabs(string line, vector<long int> *tab1, vector<long int> *tab2)
{
    long int d1 = 0, d2 = 0;
    getInts(line, &d1, &d2);

    tab1->push_back(d1);
    tab2->push_back(d2);
}

bool lSortAsc(long int a, long int b) { return a < b; }
bool lSortDesc(long int a, long int b) { return a > b; }
