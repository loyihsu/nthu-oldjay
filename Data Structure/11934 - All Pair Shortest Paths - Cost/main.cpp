// Problem: http://140.114.86.238/problem/11934/
#include <iostream>

int **dist;

void shortestPath(int n);

int main()
{
    int noOfMatrix, noOfVertices, i, j;

    std::cin >> noOfMatrix;

    while (noOfMatrix--)
    {
        std::cin >> noOfVertices;

        dist = new int*[noOfVertices];

        for (i = 0; i < noOfVertices; i++)
        {
            dist[i] = new int [noOfVertices];
        }

        for (i = 0; i < noOfVertices; i++)
        {
            for (j = 0; j < noOfVertices; j++)
            {
                std::cin >> dist[i][j];
            }
        }

        shortestPath(noOfVertices);

        for (i = 0; i < noOfVertices; i++)
        {
            for (j = 0; j < noOfVertices; j++)
            {
                if (i != j && dist[i][j] != 0)
                    std::cout << "Cost(" << i << "," << j << "):" << dist[i][j] << std::endl;
            }
        }
        if (noOfMatrix)
            std::cout << std::endl;

        for (i = 0; i < noOfVertices; i++)
        {
            delete[] dist[i];
        }

        delete [] dist;
    }

    return 0;
}

void shortestPath(int n)
{
    int source, distination, i;

    for (i = 0; i < n; i++)
    {
        for (source = 0; source < n; source++)
        {
            for (distination = 0; distination < n; distination++)
            {
                if (dist[source][i] && dist[i][distination] && dist[source][distination])
                {
                    if (dist[source][i] + dist[i][distination] < dist[source][distination])
                        dist[source][distination] = dist[source][i] + dist[i][distination];
                } else if (dist[source][i] && dist[i][distination] && !dist[source][distination])
                {
                    dist[source][distination] = dist[source][i] + dist[i][distination];
                }
            }
        }
    }

    return;
}