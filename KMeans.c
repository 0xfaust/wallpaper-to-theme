#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define CLUSTERS 3

double distance(int dim, double *p1, double *p2)
{
        int i;
        double d = 0; //lol breasts
        for (i = 0; i < dim; i++){
            d += ((p1[i] - p2[i]) * (p1[i] - p2[i]));
        }
        return d;
}
void all_distances(int dim, int n, int k, double *data, double *centroid, double *out)
{
        int i, j;
        for (i = 0; i < n; i++){
                for (j = 0; j < k; j++){
                        out[i*k + j] = distance(dim, &data[i * dim], &centroid[j * dim]);
                }
        }

}
