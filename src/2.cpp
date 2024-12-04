#include "../include/tools.h"

using namespace std;

bool checkVec(vector<int long> *d, vector<int long> *dAsc, vector<int long> *dDesc)
{
    sort(dAsc->begin(), dAsc->end(), lSortAsc);
    sort(dDesc->begin(), dDesc->end(), lSortDesc);

    bool isValid = false;

    if (std::equal(dAsc->begin(), dAsc->end(), d->begin()))
    {
        isValid = true;
        // cout << "Cas ASC" << endl;
        for (size_t i = 0; i < dAsc->size() - 1; ++i)
        {
            isValid &= ((*d)[i + 1] >= (*d)[i] + 1 && (*d)[i + 1] <= (*d)[i] + 3);
        }
    }
    if (std::equal(dDesc->begin(), dDesc->end(), d->begin()))
    {
        isValid = true;
        // cout << "Cas DESC" << endl;
        for (size_t i = 0; i < dDesc->size() - 1; ++i)
        {
            isValid &= ((*d)[i] >= (*d)[i + 1] + 1 && (*d)[i] <= (*d)[i + 1] + 3);
        }
    }

    return isValid;
}

int main()
{
    ifstream file;
    string line;
    file.open("./res/2.res");

    int result = 0;
    int resultWithCheat = 0;

    if (file.is_open())
    {
        while (getline(file, line))
        {
            vector<long int> datas;
            splitLine(line, &datas);

            vector<long int> datasAsc = datas;
            vector<long int> datasDesc = datas;

            bool isValid = checkVec(&datas, &datasAsc, &datasDesc);
            result += isValid;

            if (!isValid)
            {
                // S'il est invalide, on va tester pour chaque liste minus un élément
                for (size_t j = 0; j < datas.size(); ++j)
                {
                    vector<int long> eDatas = datas;
                    eDatas.erase(eDatas.begin() + j);

                    vector<int long> eDatasAsc = eDatas;
                    vector<int long> eDatasDesc = eDatas;

                    isValid = checkVec(&eDatas, &eDatasAsc, &eDatasDesc);

                    if (isValid)
                    {
                        resultWithCheat += isValid;
                        break;
                    }
                }
            }
        }
    }
    file.close();

    cout << "Nombre de dossiers valides   " << result << endl;
    cout << "Nombre de dossiers 'valides' " << result + resultWithCheat << endl;

    return 0;
}
