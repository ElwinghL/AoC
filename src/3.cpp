#include "../include/tools.h"

using namespace std;

int main()
{

    ifstream file;
    string line;

    int long result = 0;
    int long resultV2 = 0;

    file.open("./res/3.res");

    if (file.is_open())
    {
        regex rgx(R"(mul\((\d+)+,(\d+)+\)|do\(\)|don't\(\))");
        regex rDo(R"(do\(\))");
        regex rDn(R"(don't\(\))");

        bool isActivated = true;

        while (getline(file, line))
        {
            smatch matches;
            // On cherche un de nos symboles
            while (regex_search(line, matches, rgx))
            {
                if (regex_match(matches.str(), rDo))
                    isActivated = true;
                else if (regex_match(matches.str(), rDn))
                    isActivated = false;
                else
                {
                    // Pour l'acte 1
                    result += atoi(matches[1].str().c_str()) * atoi(matches[2].str().c_str());
                    // Pour l'acte 2
                    if (isActivated)
                        resultV2 += atoi(matches[1].str().c_str()) * atoi(matches[2].str().c_str());
                }
                // Pour ne pas boulcer sur la suite à l'infini
                line = matches.suffix().str();
            }
        }
    }

    cout << "Nombre total de multiplications   : " << result << endl;
    cout << "Nombre partiel de multiplications : " << resultV2 << endl;
    file.close();
}
