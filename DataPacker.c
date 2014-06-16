#include <stdio.h>
#include <stdlib.h>
#include "DataPacker.h"

unsigned int DataPacker::ipToInt(char* ip) {
	//!Initialize an array for storing integer versions of each octet
	unsigned int octets[5] = {0};
	int curOctet = 0;

	//!Parse out each octet and store it in our octet array
	char curCharIndex = 0;
	//Octet buffer stores a character representation of an octet as it's being assembled
	char octetBuffer[4] = {0};
	int octetBufferIndex = 0;
	while (ip[curCharIndex] != '\0') {
		//!Check if we've hit a period (splits each octet)
		if (ip[curCharIndex] == '.') {
			//!We've hit a period, this number is complete.

			//Add our null terminator to complete our string
			octetBuffer[octetBufferIndex] = '\0';

			//Get an integer of the octet and store it
			int assembledNum = atoi(octetBuffer);
			octets[curOctet] = assembledNum;
			curOctet++;

			//Zero out our array to remove details about this octet
			for (int i=0; i < 4; i++) {
				octetBuffer[i] = 0;
			}

			//Reset our index into the octet buffer
			octetBufferIndex = 0;
		} else {
			//!We haven't hit a period, we're still assembling a single octet.
			octetBuffer[octetBufferIndex] = ip[curCharIndex];
			octetBufferIndex++;
		}

		//!Move to the next element in our string
		curCharIndex++;
	}

	//Add the last number that's in our current buffer (represents lsat octet)
	octets[curOctet] = atoi(octetBuffer);

	unsigned int packedNum = 0;

	//!Convert the integer array to a weighted int.
	for (int i=0; i < 4; i++) {
		unsigned int toAdd = octets[i];

		toAdd = toAdd << ((3-i)*8);

		packedNum += toAdd;
	}

	return packedNum;
}