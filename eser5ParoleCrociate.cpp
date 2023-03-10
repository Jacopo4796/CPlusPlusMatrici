#include <iostream>
#include <random>
using namespace std;

int main()
{
    int rows = 15;
    int columns = 15;
    string words[] = {"ciao", "word", "cane", "libro", "oshio"}; // Creo un'array
    char empty = ' ';                                                   // Definisco gli spazi vuoti
    int wordsLength = sizeof(words) / sizeof(words[0]);                 // Lunghezza array
    int contatore = 0;
    char matrix[rows][columns]; // Creo una matrice formata da righe e colonne

    for (int i = 0; i < rows; i++) // Scorro le righe
    {
        for (int j = 0; j < columns; j++) // Scorro le colonne
        {
            matrix[i][j] = empty; // Metto dentro la matrice i caratteri vuoti
        }
    }

    for (int index = 0; index < wordsLength; index++) // Scorro la lunghezza dell'array
    {
        // Orizzontale da W verso E
        if (index % 5 == 1)                      // Se l'indice della parola è divisibile per 3 la parola sarà messa in orizzontale
        {                                        // orizzontale
            if (words[index].length() > columns) // Se la parola è più lunga delle colonne
            {
                cout << "word " << words[index] << " is too long" << endl; // La parola è troppo lunga
                continue;
            }
            else
            {
                contatore++;
                int x = random() % rows;
                int y = random() % (columns - words[index].length()); // Inserisce il numero randomico giusto per inserire la  parola

                while (matrix[x][y] != empty) // Finchè la posizione successiva è vuota
                {
                    x = random() % rows;
                    y = random() % (columns - words[index].length()); // Estrai numeri finchè la posizione è vuota
                }

                for (int i = 0; i < words[index].length(); i++)
                {
                    if (matrix[x][y + i] != empty) // Se ho spazi vuoti per tutta la lunghezza della parola
                    {
                        x = random() % rows;
                        y = random() % (columns - words[index].length()); // Cerca un posto se non ha spazi vuoti sufficenti
                        i = 0;                                            // Resetto il ciclo for
                    }
                }

                for (int i = 0; i < words[index].length(); i++) // Scorro la lunghezza della parola
                {
                    matrix[x][y + i] = words[index][i]; // Inserisco la parola
                }
            }
        }
        // Verticale da N verso S
        else if (index % 5 == 2) // Se l'indice della parola diviso 3 da resto 1 la parola sarà messa in verticale
        {
            if (words[index].length() > rows) // Se la parola è più lunga delle righe
            {
                cout << "word " << words[index] << " is too long" << endl; // La parola è troppo lunga
                continue;
            }
            else
            {
                contatore++;
                int x = random() % (rows - words[index].length()); // Inserisce il numero randomico giusto per inserire la parola
                int y = random() % columns;

                while (matrix[x][y] != empty) // Finchè la posizione successiva è vuota
                {
                    x = random() % (rows - words[index].length()); // Estrai numeri finchè la posizione è vuota
                    y = random() % columns;
                }

                for (int i = 0; i < words[index].length(); i++)
                {
                    if (matrix[x + i][y] != empty) // Se ho spazi vuoti per tutta la lunghezza della parola
                    {
                        x = random() % (rows - words[index].length()); // Cerca un posto se non ha spazi vuoti sufficenti
                        y = random() % columns;
                        i = 0; // Resetto il ciclo for
                    }
                }

                for (int i = 0; i < words[index].length(); i++) // Scorro la lunghezza della parola
                {
                    matrix[x + i][y] = words[index][i]; // Inserisco la parola
                }
            }
        }
        // Digonale da NW verso SE
        else if(index % 5 == 3)
        {
            if (words[index].length() > rows || words[index].length() > columns) // Se la parola è più lunga delle righe
            {
                cout << "word " << words[index] << " is too long" << endl; // La parola è troppo lunga
                continue;
            }
            else
            {
                contatore++;
                int x = random() % (rows - words[index].length()); // Inserisce il numero randomico giusto per inserire la parola
                int y = random() % (columns - words[index].length());
                {
                    while (matrix[x][y] != empty) // Finchè la posizione successiva è vuota e X ed Y sono uguali
                    {
                        x = random() % (rows - words[index].length()); // Estrai numeri finchè
                        y = random() % (columns - words[index].length());
                    }

                    for (int i = 0; i < words[index].length(); i++)
                    {
                        if (matrix[x + i][y + i] != empty) // Se ho spazi vuoti per tutta la lunghezza della parola e l'indice della parola è maggiore della colonna
                        {
                            x = random() % (rows - words[index].length()); // Cerca un posto se non ha spazi vuoti sufficenti
                            y = random() % (columns - words[index].length());
                            i = 0; // Resetto il ciclo for
                        }
                    }

                    for (int i = 0; i < words[index].length(); i++) // Scorro la lunghezza della parola
                    {
                        matrix[x + i][y + i] = words[index][i]; // Inserisco la parola
                    }
                }
            }
        }
        // Verticale da S verso N
        else if(index % 5 == 4)
        {
            if (words[index].length() > rows) // Se la parola è più lunga delle righe
            {
                cout << "word " << words[index] << " is too long" << endl; // La parola è troppo lunga
                continue;
            }
            else
            {
                contatore++;
                int x = random() % (rows - words[index].length()); // Inserisce il numero randomico giusto per inserire la parola
                int y = random() % columns;

                while (matrix[x][y] != empty) // Finchè la posizione successiva è vuota
                {
                    x = random() % (rows - words[index].length()); // Estrai numeri finchè la posizione è vuota
                    y = random() % columns;
                }

                for (int i = 0; i < words[index].length(); i++)
                {
                    if (matrix[x - i][y] != empty) // Se ho spazi vuoti per tutta la lunghezza della parola
                    {
                        x = random() % (rows - words[index].length()); // Cerca un posto se non ha spazi vuoti sufficenti
                        y = random() % columns;
                        i = 0; // Resetto il ciclo for
                    }
                }

                for (int i = 0; i < words[index].length(); i++) // Scorro la lunghezza della parola
                {
                    matrix[x - i][y] = words[index][i]; // Inserisco la parola
                }
            }
        }
        else
        {

        }
    }
    // fill the matrix with random char if empty
    // for (int i = 0; i < rows; i++)
    // {
    //     for (int j = 0; j < columns; j++)
    //     {
    //         if (matrix[i][j] == empty)
    //         {
    //             matrix[i][j] = random() % 25 + 97;
    //         }
    //     }
    // }

    cout << "devi trovare " << contatore << " parole" << endl;
    // Stampa
    cout << "    ";
    for (int i = 0; i < columns; i++)
    {
        if (i < 10)
        {
            cout << " " << i;
        }
        else
        {
            cout << " " << i;
        }
    }
    cout << endl;
    for (int i = 0; i < rows; i++)
    {

        if (i < 10)
        {
            cout << "  " << i << " |";
        }
        else
        {
            cout << " " << i << " |";
        }

        for (int j = 0; j < columns; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}