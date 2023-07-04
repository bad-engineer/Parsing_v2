#include <stdio.h>
#include "parsing_component.h"
#include <stdlib.h>
#include <string.h>
 /*The function basically works by counting the no. of tokens and assigning the appropriate token
  * into the parameters of the struct*/
GPSData
parse_gps_data (char *packet)
{
  int tokenCount = 0; // initialize no. of tokens to 0
    //CALC CHECKSUM
    int checksum = 0;//initialize checksum to 0
    size_t packetLength = strlen(packet);//calculate length of packet
    int startIndex = 0; // Will store start index after "$" char
    int endIndex = 0; // Will store end index before "*" char

    // Find the start index ('$')
    for (int i = 0; i < packetLength; i++) {
        if (packet[i] == '$') {
            startIndex = i + 1; // now startIndex points to first char after $
            break;
        }
    }

    // Find the end index ('*')
    for (int i = startIndex; i < packetLength; i++) {
        if (packet[i] == '*') {
            endIndex = i-1; // now endIndex points to char before *
            break;
        }
    }
     checksum = (packet[startIndex]); // stores value of first char after $
    // Calculate checksum for characters between '$' and '*'
    for (int i = startIndex; i < endIndex; i++) {
        checksum = checksum^ (unsigned char)packet[i+1];
    }
        printf("checksum: %d\n", checksum);
    //checksum calculated
  GPSData data; // struct instance
  const char s[2] = ","; //delimiter for extracting tokens from sentence
  char *token;
  token[12]; // expected max length of a token
  char *subtoken; // subtoken for finding * character by re-tokenizing 15th token
  subtoken[8]; // expected max length of subtoken
  //get the first token
  token = strtok (packet, s); // extract first token using delimiter s= ","

  // walk through other tokens
  while (token != NULL) //while there's a valid value in token
    {
      tokenCount += 1; // walk through tokens
      if (tokenCount == 2) // 2nd token is time, when encountered store in struct.TIME
	{
	  strcpy (data.TIME, token);

	}
      if (tokenCount == 3) // 3rd token is latitude, when encountered store in struct.latitude
	{
	  strcpy (data.latitude, token);

	}
      if (tokenCount == 5) // 5th token is longitude, when encountered store in struct.longitude
	{
	  strcpy (data.longitude, token);

	}
      if (tokenCount == 10) // 10th token is altitude, when encountered store in struct.altitude
	{
	  strcpy (data.altitude, token);

	}
      if (tokenCount == 15)// 15 token contains checksum value, when encountered re-tokenize and find *
	{
	  const char *checksumStart = strchr (token, '*'); // find "*"
	  checksumStart++; //point to the value after "*"
	  char receivedChecksum[3];	// Buffer to hold the checksum value
	  strncpy (receivedChecksum, checksumStart, 2);//copy the checksum value
	  receivedChecksum[2] = '\0';	// Null-terminate the string
	  int expectedChecksum = strtol (receivedChecksum, NULL, 16);//change to int representation
	  printf ("Expected Checksum: %d\n", expectedChecksum);
	  if (checksum == expectedChecksum)
	    {
	      printf ("VALID PACKET\n");
	    }
	  else
	    {
	      printf ("Warning: Checksum not validated\n");
	    }
	}
      token = strtok (NULL, s);//reuse token
    }
  printf ("Tokens in total: %d\n", tokenCount);
  if (tokenCount != 15)
    {
      printf ("WARNING: MISSING VALUES!\n");//total tokens in a valid string are 15
    }


      printf ("Time: %s\n", data.TIME);
      printf ("Latitude: %s\n", data.latitude);
      printf ("Longitude: %s\n", data.longitude);
      printf ("Altitude: %s\n", data.altitude);

  return data;// struct return parameters printed above can be accessed from main()
}
