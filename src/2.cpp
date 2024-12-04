#include "../include/tools.h"

using namespace std;

int main()
{
    ifstream file;
    string line;
    file.open("./res/2.res");

    int result = 0;

    if (file.is_open())
    {
        while (getline(file, line))
        {
            vector<long int> datas;
            splitLine(line, &datas);

            vector<long int> datasAsc = datas;
            vector<long int> datasDesc = datas;

            sort(datasAsc.begin(), datasAsc.end(), lSortAsc);
            sort(datasDesc.begin(), datasDesc.end(), lSortDesc);

            bool isValid = true;

            if (std::equal(datasAsc.begin(), datasAsc.end(), datas.begin()))
            {
                // cout << "Cas ASC" << endl;
                for (size_t i = 0; i < datasAsc.size() - 1; ++i)
                {
                    isValid &= (datas[i + 1] >= datas[i] + 1 && datas[i + 1] <= datas[i] + 3);
                }
                result += isValid;
            }
            if (std::equal(datasDesc.begin(), datasDesc.end(), datas.begin()))
            {
                // cout << "Cas DESC" << endl;
                for (size_t i = 0; i < datasDesc.size() - 1; ++i)
                {
                    isValid &= (datas[i] >= datas[i + 1] + 1 && datas[i] <= datas[i + 1] + 3);
                }
                result += isValid;
            }
        }
    }
    file.close();

    cout << "Nombre de dossiers valides" << result << endl;

    return 0;
}
