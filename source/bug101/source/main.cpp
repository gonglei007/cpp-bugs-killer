#include <iostream>
#include <stdio.h>
#include <string.h>

class mat3_t{
    public:
        float mat[3][3];
        mat3_t( float src[3][3] );
        void print();
};

mat3_t::mat3_t( float src[3][3] )
{
    memcpy( this->mat, src, sizeof( src ) );
}

void mat3_t::print()
{
    for(int i=0; i<3; ++i){
        for(int j=0; j<3; ++j){
            std::cout << this->mat[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    std::cout << "Output matrix:" << std::endl;

    float mat3Data[3][3] = {{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}};

    mat3_t mat3(mat3Data);
    mat3.print();

    return 0;
}