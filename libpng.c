#include <stdlib.h>                                                                                                                                             
#include <stdio.h>
#include <png.h>

int main( int argc, char **argv )
{
    int x, y;
    int height, width;

    png_structp png_ptr;
    png_infop info_ptr;

    png_bytep *row_pointers;

    void user_error_fn(png_structp png_ptr, png_const_charp error_msg);
    void user_warning_fn(png_structp png_ptr, png_const_charp warning_msg);

    FILE *fp = fopen( "test.png", "rb");
    {

        png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);

        info_ptr = png_create_info_struct(png_ptr);

        png_read_info(png_ptr, info_ptr);
        width = png_get_image_width(png_ptr, info_ptr);
        height = png_get_image_height(png_ptr, info_ptr);

        row_pointers = (png_bytep*) malloc(sizeof(png_bytep) * height);
        for (y=0; y<height; y++)
            row_pointers[y] = (png_byte*)malloc(png_get_rowbytes(png_ptr,info_ptr));

        png_read_image(png_ptr, row_pointers);

        fclose(fp);
    }

    for (y=0; y<height; y++)
    {
        png_byte *row = row_pointers[y];
        for (x=0; x<width; x++)
        {
            png_byte* ptr = &(row[x*4]);
            printf("Pixel at position [ %d - %d ] has RGBA values: %d - %d - %d - %d\n", x, y, ptr[0], ptr[1], ptr[2], ptr[3]);
        }
    }
}
