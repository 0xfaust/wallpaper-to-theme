#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct RGB
{
        int red;
        int green;
        int blue;
} rgb;

int main()
{
    int pixels[16] = {123145178 
                    , 173249173
                    , 184230174
                    , 192138191
                    , 123251234
                    , 212238175
                    , 229172254
                    , 192217195
                    , 192248195
                    , 228172248
                    , 228229202
                    , 235192231
                    , 195212222
                    , 213215212
                    , 123212222
                    , 231231232  };
    
    int centroids[3] = {123231132
                    , 231123213
                    , 213231123 };
            
    int i, j;
    
    float distance;

    rgb colours[16];
    rgb clusters[3];

    for (i=0; i<16; i++){
        
        colours[i].red = floor(pixels[i]/1000000);
        colours[i].green = abs(floor(pixels[i]/1000000)*1000-floor(pixels[i]/1000));
        colours[i].blue = abs(floor(pixels[i]/1000)*1000-pixels[i]);
        
        clusters[i].red = floor(centroids[i]/1000000);
        clusters[i].green = abs(floor(centroids[i]/1000000)*1000-floor(centroids[i]/1000));
        clusters[i].blue = abs(floor(centroids[i]/1000)*1000-centroids[i]);

    }

    for (j=0; j<3; j++){
        for (i=0; i<16; i++){

            distance = sqrt((clusters[j].red - colours[i].red)*(clusters[j].red - colours[i].red) + (clusters[j].green - colours[i].green)*(clusters[j].green - colours[i].green) + (clusters[j].blue - colours[i].blue)*(clusters[j].blue - colours[i].blue));
            printf("%f\n", distance);
        }
    }

    return 0;
}
