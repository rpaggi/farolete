#include "Random.hpp"

int RandomInteger( int low, int high)
{
   	// // srand ((int) std::time (NULL));
    // int k;
    // double d;
    // d = (double) rand( ) / ((double) RAND_MAX + 1);
    // k = d * (high - low + 1);
    // return low + k;
    // return ( MIN(low,high) + rand()%(MAX(low,high)-MIN(low,high)));
    return rand() % high + low;
}