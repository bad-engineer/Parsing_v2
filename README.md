This program parses the GPS data to extract parameters like latitude, longitude, etc,.The GPS Data string should be passed into the parse_gps_data function in the main.c file. The function returns time, latitude, longitude, and altitude. Additionally, if the string has missing values it shows a warning. Also, it calculates and validates checksum and issues a warning if the packet is invalid. Below, some examples of GPS data packets have been provided:

An example of a valid packet (checksum = 6E):

"$GPGGA,115739.00,4158.8441367,N,09147.4416929,W,4,13,0.9,255.747,M,-32.00,M,01,0000*6E" 

An example of an invalid packet: 

#"$GPGGA,181908.00,3404.7041778,N,07044.3966270,W,4,13,1.00,495.144,M,29.200,M,0.10,0000*40" 

An example of packet with missing values:

#"$GPGGA,123519.00,4807.038,N,01131.000,E,1,08,0.9,545.4,M,-164.0,M,,,,*47" 
