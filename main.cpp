#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <chrono>
#include <iomanip>

using namespace std;


void Write_Matrix(string str, size_t rows, size_t cols)
{
    vector<vector<int>> m(rows);
    for(auto& i : m)
        i.resize(cols);

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            m[i][j] = rand() % 1000;
        }
    }

    ofstream data(str);

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            data << setw(5) << m[i][j];
        }
        data << endl;
    }

    data.close();
}


void Read_Matrix(vector<vector<int>>& m, int rows, int cols, string str)
{
    m.resize(rows);
    for(auto& i : m)
        i.resize(cols);

    ifstream data;
    data.open(str);

    if(data.is_open()) {
        for(int i = 0; i < m.size(); i++) {
            for(int j = 0; j < m[i].size(); j++) {
                data >> m[i][j];
            }
        }
    }

    data.close();
}


void Mltiplication(string str_1, string str_2)
{

}


int main() {
    srand(time(NULL));
    size_t row = 10, col = 10;
    vector<vector<int>> v1, v2, v3;

    //Write_Matrix("Mat_1.txt", row, col);
    //Write_Matrix("Mat_2.txt", row, col);

    Read_Matrix(v1, row, col, "Mat_1.txt");
    Read_Matrix(v2, row, col, "Mat_2.txt");
    
    //cout << v1[0][0] << " " << v1[0][1] << endl;
    //cout << v2[0][0] << " " << v2[0][1] << endl;

    return 0;
}
