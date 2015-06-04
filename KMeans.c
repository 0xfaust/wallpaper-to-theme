#include <stdio.h>
#include <stdio.h>                                                                                                                                              
#include <stdlib.h>
#include <math.h>

struct Point{
        int x, y;
};
double distance(struct Point a, struct Point b)
{
        double distance;
        distance = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
        return distance;
}

int main()
{

    int data[3][3];
    data[0][0] = 6; data[0][1] = 5; data[0][2] = 4;
    data[1][0] = 4; data[1][1] = 6; data[1][2] = 7;
    data[2][0] = 5; data[2][1] = 9; data[2][2] = 3;

    int center[2] = {1, 10};

    struct Point a, b;
    int i, j;

    for (i=0; i<10; i++){
            for (j=0; j<10; j++){
                a.x = data[i][j];
                a.y = data[i][j];
                b.x = center[0];
                b.y = center[1];
                printf("Distance: %f\n", distance(a, b));
            }
    }
    return 0;
}
