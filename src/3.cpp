#include "../include/tools.h"

using namespace std;

int main()
{

    ifstream file;
    string line;

    int long result = 0;

    file.open("./res/3.res");

    if (file.is_open())
    {
        regex rgx(R"(mul\((\d+)+,(\d+)+\))");

        while (getline(file, line))
        {
            smatch matches;
            while (regex_search(line, matches, rgx))
            {
                result += atoi(matches[1].str().c_str()) * atoi(matches[2].str().c_str());
                // Pour ne pas boulcer sur la suite à l'infini
                line = matches.suffix().str();
            }
        }
    }

    cout << "Nombre total de multiplications : " << result << endl;
    file.close();
}