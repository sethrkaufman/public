/*
 * compile with: g++ test.cpp -laiousbcpp -lusb-1.0 -o test
 */
#include <aiousb.h>
#include <stdio.h>
using namespace AIOUSB;
int main( int argc, char **argv ) {
  unsigned long result = AIOUSB_Init();
  if( result == AIOUSB_SUCCESS ) {
    const int MAX_NAME_SIZE = 20;
    char name[ MAX_NAME_SIZE + 2 ];
    unsigned long productID
      , nameSize = MAX_NAME_SIZE;
    result = QueryDeviceInfo( diFirst
      , &productID, &nameSize, name, NULL, NULL );
    if( result == AIOUSB_SUCCESS ) {
      name[ nameSize ] = 0;
      printf( "Found a device with product ID %#06x and name '%s'\n"
        , ( unsigned ) productID, name );
    } else
      printf( "Error '%s' querying device\n"
        , AIOUSB_GetResultCodeAsString( result ) );
    AIOUSB_Exit();
  }  // if( result ...
  return ( int ) result;
}  // main()
