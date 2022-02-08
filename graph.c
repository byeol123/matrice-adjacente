#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void inig(graph* g)
{
    g = malloc(sizeof(graph));
    g->nb_vertices = 0;
    g->nb_arcs = 0;
}

void read_file(FILE* file_graphe, char* name_file, graph* g)
{
    file_graphe = fopen(name_file, "r");
    if (file_graphe == NULL)
    {
        printf("can't open file\n");
    }
    
    fscanf(file_graphe, "%d\n", &g->nb_vertices);    
    printf("il y a %d sommets\n", g->nb_vertices);
    g->matriceadjacence =(int**)malloc(g->nb_vertices * sizeof(int*));
    for (int i = 0; i < g->nb_vertices; i++)
    {
        g->matriceadjacence[i] = (int*)malloc(g->nb_vertices * sizeof(int));
    }
    for (int i = 0; i < g->nb_vertices; i++)
    {
        for (int j = 0; j < g->nb_vertices; j++)
        {
            g->matriceadjacence[i][j] = 0;
        }
        
    }
    
    while (!feof(file_graphe))
    {
        int a, b;
        fscanf(file_graphe, "%d %d\n", &a, &b);
        g->matriceadjacence[a][b] = 1;
        g->nb_arcs+= 1;
        printf("%d %d\n", a, b);         
    }
    printf("\n");
    fclose(file_graphe);

}
void readmatrix(graph* g)
    {
        for (int i = 0; i < g->nb_vertices; i++)
        {
            for (int j = 0; j < g->nb_vertices; j++)
            {
                printf("%d ",g->matriceadjacence[i][j]);
            }
            printf("\n");
        }
        
    }