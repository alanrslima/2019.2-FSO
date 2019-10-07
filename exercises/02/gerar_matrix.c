#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** create(int dim)
{
    int** new = (int **) calloc((dim*2), sizeof(int *));

    for(int i = 0; i < (dim*2); ++i)
        new[i] = (int *) calloc(dim, sizeof(int *));

    srand(time(NULL));
    for(int i = 0; i < (dim*2); ++i)
    {
        for(int j = 0; j < dim; ++j)
        {
            int value;
            do
            {
                value = rand() % 100;
            } while (value == 0);

            new[i][j] = value; 
        }
    }

    return new;
}

int main(int argc, char* argv[])
{
    int dim;

    dim = atoi(argv[1]);
    int** matriz = create(dim);

    FILE* f;

    f = fopen("matriz_gerada", "w");

    fprintf(f, "%d\n", dim);

    for(int i = 0; i < dim*2; ++i)
    {
        for(int j = 0; j < dim; ++j)
        {
            if(j == (dim-1))
                fprintf(f, "%d", matriz[i][j]);                
            else
                fprintf(f, "%d ", matriz[i][j]);
        }
        if(i != ((dim*2) - 1))
            fprintf(f, "\n");
    }

    return 0;
}