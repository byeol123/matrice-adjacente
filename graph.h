#include <stdio.h>

typedef struct gra
{
    int nb_vertices;
    int nb_arcs;
    int **matriceadjacence;
}graph;

void inig(graph* g);
void read_file(FILE* file_graphe, char* name_file, graph* g);
void readmatrix(graph* g);