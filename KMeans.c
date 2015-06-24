#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct RGB
{
        float red;
        float green;
        float blue;
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
        int k = 0;
        int cnt = 0;
        int iterations = 0;
        
        float distance[48];
        int closest[16];
        
        rgb colours[16];
        rgb clusters[3];
        rgb new[16];
        rgb sum;
        
        while (iterations != 3){
                
                for (i=0; i<16; i++){
                
                        colours[i].red = floor(pixels[i]/1000000);
                        colours[i].green = abs(floor(pixels[i]/1000000)*1000-floor(pixels[i]/1000));
                        colours[i].blue = abs(floor(pixels[i]/1000)*1000-pixels[i]);
                        
                        clusters[i].red = floor(centroids[i]/1000000);
                        clusters[i].green = abs(floor(centroids[i]/1000000)*1000-floor(centroids[i]/1000));
                        clusters[i].blue = abs(floor(centroids[i]/1000)*1000-centroids[i]);
                        
                }
                
                k = 0;
                
                for (j=0; j<3; j++){
                        
                        for (i=0; i<16; i++){
                                
                                distance[k] = sqrt((clusters[j].red - colours[i].red)*(clusters[j].red - colours[i].red) + (clusters[j].green - colours[i].green)*(clusters[j].green - colours[i].green) + (clusters[j].blue - colours[i].blue)*(clusters[j].blue - colours[i].blue));
                                
                                k++;
                        }
                }
                
                for (i=0; i<16; i++){
                
                        closest[i] = centroids[0];
                        
                        if(distance[i+1] < distance[i])
                                closest[i] = centroids[1];
                        if(distance[i+2] < distance[i+1])
                                closest[i] = centroids[2];
                }
                
                for (k=0; k<3; k++){
                        
                        for (i=0; i<16; i++){
                              
                                if(closest[i] == centroids[k]){
                                        
                                        new[i].red = floor(pixels[i]/1000000);
                                        new[i].green = abs(floor(pixels[i]/1000000)*1000-floor(pixels[i]/1000));
                                        new[i].blue = abs(floor(pixels[i]/1000)*1000-pixels[i]);
                                }        
                                else {
                                        new[i].red = 0;
                                        new[i].green = 0;
                                        new[i].blue = 0;
                                }
                                
                        }
                        for (i=0; i<16; i++){
                               
                                if(new[i].red != 0){
                                        cnt = cnt+1;
                                        
                                        sum.red = 0;
                                        sum.green = 0;
                                        sum.blue = 0;
                                        
                                        sum.red = sum.red + new[i].red;
                                        sum.green = sum.green + new[i].green;
                                        sum.blue = sum.blue + new[i].blue;
                                }
                        }
                        
                        clusters[k].red = floor(sum.red/cnt);
                        clusters[k].green = floor(sum.green/cnt);
                        clusters[k].blue = floor(sum.blue/cnt);
                        
                        for(i=0; i<3; i++){
                                
                                centroids[i] = ((clusters[i].red*1000000)+clusters[i].green*1000+clusters[i].blue);
                                
                                if(centroids[i] < 100000000){
                                        centroids[i]*10;
                                }
                        }
                }
                
                iterations = iterations+1;
        }
        
        return 0;
}
