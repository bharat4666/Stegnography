#include <stdio.h>
#include "encode.h"
#include "types.h"
#include "string.h"

OperationType check_operation_type(char *argv[])
{
    if(strcmp(argv[1],"-e") == 0)
        return e_encode;
    else if(strcmp(argv[1],"-d") == 0)
        return e_decode;
    else 
        return e_unsupported;
}

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        printf("Invalid operation input\n");
        printf("For encoding : ./a.out -e beautiful.bmp [stego.bmp]\n");
        printf("For decoding : ./a.out -d stego.bmp [decode.txt]\n");
        return 0;
    }
    if(check_operation_type(argv) == e_encode)
    {
        if(argc < 4)
        {
            printf("Not enough arguments\n");
            return 0;
        }
        printf("Selected encoding\n");
        EncodeInfo encode;
        if(read_and_validate_encode_args(argv,&encode) == e_success)
        {
            printf("Read and validate encode arguments is successful\n");
            printf("-------------Encoding started--------------------\n");
            if(do_encoding(&encode) == e_success)
            {
                printf("Encoding successful\n");
            }
            else
            {
                printf("Failed to perform encoding\n");
            }
        }
    }
    else if(check_operation_type(argv)== e_decode)
    {
        if(argc < 3)
        {
            printf("Not enought argument\n");
            return 0;
        }
        else
            printf("Selected decoding\n");
    }
    else
    {
        printf("Invalid operation input\n");
        printf("For encoding : ./a.out -e beautiful.bmp [stego.bmp]\n");
        printf("For decoding : ./a.out -d stego.bmp [decode.txt]\n");   
    }
    return 0;
}
