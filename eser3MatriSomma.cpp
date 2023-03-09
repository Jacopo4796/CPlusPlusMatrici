#include <iostream>
#include <random>
using namespace std;

int main()
{
    int righe = 9;
    int colonne = 9;
    int somma = 0;
    //            Y       X
    //           LAT     LONG
    int matrice[righe][colonne];
    for (int i = 0; i < righe; i++)
    {
        for (int j = 0; j < colonne; j++)
        {
            matrice[i][j] = rand() % 10;
        }
    }
    cout << "    ";
    for (int i = 0; i < colonne; i++)
    {
        cout << i << " ";
    }
    cout << endl;
    int trattini = colonne * 2 + 4;
    for (int i = 0; i < trattini; i++)
    {
        cout << "-";
    }
    cout << endl;
    for (int i = 0; i < righe; i++)
    {
        cout << i << "|  ";
        for (int j = 0; j < colonne; j++)
        {
            cout << matrice[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < righe; i++)
    {
        for (int j = 0; j < colonne; j++)
        {
            somma += matrice[i][j];
        }
    }
    cout << endl;
    cout << "La somma dei valori della matrice è: " << somma << endl;
}