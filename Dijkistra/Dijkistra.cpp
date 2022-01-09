// Dijkistra.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream> 
#include "assert.h"
using namespace std;

int findSommetMin(int* distance, bool* visitee, int nombre_sommet)
{
    int minSommet = -1;
    for (int i = 0; i < nombre_sommet; i++)
    {
        if (!visitee[i] && (minSommet == -1 || distance[i] < distance[minSommet]))
        {
            minSommet = i;
        }
    }
    return minSommet;
}
void dijkistra(int** graph, int nombre_sommet) {
    int* distance = new int[nombre_sommet];
    bool* visitee = new bool[nombre_sommet];
    for (int i = 0; i < nombre_sommet; i++)
    {
        distance[i] = INT_MAX;
        visitee[i] = false;
    }
    
    distance[0] = 0;
    for (int i = 0; i < nombre_sommet - 1; i++)
    {
        int sommet_mininmum = findSommetMin(distance, visitee, nombre_sommet);
        visitee[sommet_mininmum] = true;
        for (int j = 0; j < nombre_sommet; j++)
        {
            if (graph[sommet_mininmum][j] != 0 && !visitee[j]) {
                int dist = graph[sommet_mininmum][j] + distance[sommet_mininmum];
                if (dist < distance[j])
                {
                    distance[j] = dist;
                }
            }
        }

    }

    // show the shurtest PATH :
    for (int i = 0; i < nombre_sommet; i++)
    {
        cout << " ** sommet : " << i << " with distance : " << distance[i] << endl;
    }
    delete[] visitee;
    delete[] distance;
}

void init_Graph() {
    int nombre_arc, nombre_sommet;

    cout << "Donnez le nombre de sommet : ";
    cin >> nombre_sommet;
    cout << "Donnez le nombre d'arc : ";
    cin >> nombre_arc;
    int** graph = new int* [nombre_sommet];

    for (int i = 0; i < nombre_sommet; i++)
    {
        graph[i] = new int[nombre_sommet];
        for (int j = 0; j < nombre_sommet; j++)
        {
            graph[i][j] = 0;
        }
    }
    cout << "Source | destination | poids " << endl;
    for (int i = 0; i < nombre_arc; i++)
    {
        int s, d, poids;
        cin >> s>> d>> poids;
        assert(s >= 0 && s <= nombre_sommet && d >= 0 && d <= nombre_sommet);
        graph[s][d] = poids;
        graph[d][s] = poids;
    }
    cout << endl;
    dijkistra(graph,nombre_sommet);
}

int main()
{
    init_Graph();
    system("pause>0");
}

