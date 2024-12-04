#include "../include/tools.h"

using namespace std;

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
