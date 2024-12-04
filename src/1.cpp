#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <sstream>
#include <algorithm> // std::sort
#include <vector>

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

bool lSort(long int a, long int b) { return a < b; }

int main()
{
    ifstream file;
    string line;
    file.open("./res/1.res");

    long int distance = 0, similirity = 0;
    vector<long int> tab1, tab2;

    if (file.is_open())
    {
        while (getline(file, line))
        {
            // On remplit les tableaux ligne par ligne
            fillTabs(line, &tab1, &tab2);
        }
    }
    file.close();
    // On tri nos tableaux
    sort(tab1.begin(), tab1.end(), lSort);
    sort(tab2.begin(), tab2.end(), lSort);

    for (size_t i = 0; i < tab1.size(); ++i)
    {
        distance += abs(tab1[i] - tab2[i]);
    }

    // On print le résultat
    cout << "Totale de la distance : " << distance << endl;

    //On retire les doublons de tab1 :
    tab1.erase( unique( tab1.begin(), tab1.end() ), tab1.end() );

    for (size_t i = 0; i < tab1.size(); ++i)
    {
        similirity += tab1[i] * count(tab2.begin(), tab2.end(), tab1[i]);
    }
    cout << "Totale de similitude  : " << similirity << endl;
    return 0;
}
