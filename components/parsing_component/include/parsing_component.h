#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*DEFINING A STRUCT TO STORE LATITUDE, LONGITUDE, ALTITUDE, AND TIME FROM THE INPUT DATA STRING*/
typedef struct
{
  char latitude[15]; //size of array as per the expected max length of the parameter
  char longitude[15];
  char altitude[10];
  char TIME[12];
} GPSData;

GPSData
parse_gps_data (char *packet);
