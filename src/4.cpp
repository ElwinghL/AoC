#include "../include/tools.h"

using namespace std;

struct lineXMAS
{
    vector<int> x;
    vector<int> m;
    vector<int> a;
    vector<int> s;
};

int main()
{
    ifstream file;
    string line;
    vector<lineXMAS> allLines;

    int long result = 0;

    file.open("./res/4.res");

    if (file.is_open())
    {
        // On remplit notre vecteur
        while (getline(file, line))
        {
            lineXMAS coord;
            for (size_t i = 0; i < line.size(); ++i)
            {
                char c = line[i];
                switch (c)
                {
                case 'X':
                    coord.x.push_back(i);
                    break;
                case 'M':
                    coord.m.push_back(i);
                    break;
                case 'A':
                    coord.a.push_back(i);
                    break;
                case 'S':
                    coord.s.push_back(i);
                    break;
                default:
                    break;
                }
            }
            allLines.push_back(coord);
        }
    }
    file.close();

    for (size_t counter = 0; counter < allLines.size(); ++counter)
    {
        lineXMAS line = allLines[counter];
        // On se focalise sur les X
        for (int x : line.x)
        {
            // On cherche la suite de chars dans la ligne
            if (find(line.m.begin(), line.m.end(), x + 1) != line.m.end())
                if (find(line.a.begin(), line.a.end(), x + 2) != line.a.end())
                    if (find(line.s.begin(), line.s.end(), x + 3) != line.s.end())
                        ++result;
            // On cherche la suite de chars dans la ligne dans l'autre sens
            if (find(line.m.begin(), line.m.end(), x - 1) != line.m.end())
                if (find(line.a.begin(), line.a.end(), x - 2) != line.a.end())
                    if (find(line.s.begin(), line.s.end(), x - 3) != line.s.end())
                        ++result;
            // On regarde dans les 3 lignes suivantes si les placements existent
            if (counter <= allLines.size() - 4)
            {
                lineXMAS next = allLines[counter + 1];
                lineXMAS nextOne = allLines[counter + 2];
                lineXMAS nextTwo = allLines[counter + 3];
                // On brute force TOUTES les solutions (oui, c'est sale)
                if (find(next.m.begin(), next.m.end(), x - 1) != next.m.end())
                    if (find(nextOne.a.begin(), nextOne.a.end(), x - 2) != nextOne.a.end())
                        if (find(nextTwo.s.begin(), nextTwo.s.end(), x - 3) != nextTwo.s.end())
                            ++result;
                // Ici on peut à la place faire un seul if avec une concaténation de conditions
                if (find(next.m.begin(), next.m.end(), x) != next.m.end())
                    if (find(nextOne.a.begin(), nextOne.a.end(), x) != nextOne.a.end())
                        if (find(nextTwo.s.begin(), nextTwo.s.end(), x) != nextTwo.s.end())
                            ++result;
                if (find(next.m.begin(), next.m.end(), x + 1) != next.m.end())
                    if (find(nextOne.a.begin(), nextOne.a.end(), x + 2) != nextOne.a.end())
                        if (find(nextTwo.s.begin(), nextTwo.s.end(), x + 3) != nextTwo.s.end())
                            ++result;
            }
            // On regarde dans les 3 lignes suivantes si les placements existent
            if (counter >= 3)
            {
                lineXMAS next = allLines[counter - 1];
                lineXMAS nextOne = allLines[counter - 2];
                lineXMAS nextTwo = allLines[counter - 3];
                // On brute force TOUTES les solutions (oui, c'est sale)
                if (find(next.m.begin(), next.m.end(), x - 1) != next.m.end())
                    if (find(nextOne.a.begin(), nextOne.a.end(), x - 2) != nextOne.a.end())
                        if (find(nextTwo.s.begin(), nextTwo.s.end(), x - 3) != nextTwo.s.end())
                            ++result;
                // Ici on peut à la place faire un seul if avec une concaténation de conditions
                if (find(next.m.begin(), next.m.end(), x) != next.m.end())
                    if (find(nextOne.a.begin(), nextOne.a.end(), x) != nextOne.a.end())
                        if (find(nextTwo.s.begin(), nextTwo.s.end(), x) != nextTwo.s.end())
                            ++result;
                if (find(next.m.begin(), next.m.end(), x + 1) != next.m.end())
                    if (find(nextOne.a.begin(), nextOne.a.end(), x + 2) != nextOne.a.end())
                        if (find(nextTwo.s.begin(), nextTwo.s.end(), x + 3) != nextTwo.s.end())
                            ++result;
            }
        }
    }
    // Maudite consigne de la partie 2, si j'avais su je me serai centré sur le A dès le départ.
    int resultV2 = 0;
    for (size_t counter = 1; counter < allLines.size(); ++counter)
    {
        lineXMAS line = allLines[counter];
        // On se focalise sur les X
        for (int a : line.a)
        {
            // On regarde dans les 3 lignes suivantes si les placements existent
            if (counter <= allLines.size() - 1 && counter >= 1)
            {
                lineXMAS nextOne = allLines[counter + 1];
                lineXMAS previousOne = allLines[counter - 1];

                if ((find(previousOne.m.begin(), previousOne.m.end(), a - 1) != previousOne.m.end() && find(nextOne.s.begin(), nextOne.s.end(), a + 1) != nextOne.s.end()) ||
                    (find(previousOne.s.begin(), previousOne.s.end(), a - 1) != previousOne.s.end() && find(nextOne.m.begin(), nextOne.m.end(), a + 1) != nextOne.m.end()))
                    if ((find(previousOne.m.begin(), previousOne.m.end(), a + 1) != previousOne.m.end() && find(nextOne.s.begin(), nextOne.s.end(), a - 1) != nextOne.s.end()) ||
                        (find(previousOne.s.begin(), previousOne.s.end(), a + 1) != previousOne.s.end() && find(nextOne.m.begin(), nextOne.m.end(), a - 1) != nextOne.m.end()))
                        ++resultV2;
            }
        }
    }
    cout << "Le nombre de XMAS dans le fichier  : " << result << endl;
    cout << "Le nombre de X-MAS dans le fichier : " << resultV2 << endl;

    return 0;
}
