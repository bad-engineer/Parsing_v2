#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "parsing_component.h"
void app_main(void)
{
	/*INPUT THE GPS CGA PACKET INTO STR CHAR ARRAY. BELOW, 3 EXAMPLES ARE GIVEN,(1) HAS VALID CHECKSUM, (2)
	 * HAS INVALID CHECKSUM, (3) HAS MISSING VALUES IN THE STRING*/
  char str[100] = "$GPGGA,115739.00,4158.8441367,N,09147.4416929,W,4,13,0.9,255.747,M,-32.00,M,01,0000*6E";
  //1- "$GPGGA,115739.00,4158.8441367,N,09147.4416929,W,4,13,0.9,255.747,M,-32.00,M,01,0000*6E";//a valid packet
    //2- "$GPGGA,181908.00,3404.7041778,N,07044.3966270,W,4,13,1.00,495.144,M,29.200,M,0.10,0000*40"; //invalid
 //3- "$GPGGA,123519.00,4807.038,N,01131.000,E,1,08,0.9,545.4,M,-164.0,M,,,,*47"; //has missing values
  parse_gps_data (str);
}
