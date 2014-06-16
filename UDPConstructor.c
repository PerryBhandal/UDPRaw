#include <stdio.h>
#include "UDPConstructor.h"

UDPConstructor::UDPConstructor(char srcIP, unsigned short srcPort, char destIP, unsigned short destPort) {
	initStaticVars(srcIP, srcPort, destIP, destPort);
}


void UDPConstructor::initStaticVars(char srcIP, unsigned short srcPort, char destIP, unsigned short destPort) {
	mVersionIHL = packVersionIHL();
	mDSCPECN = packDSCPECN();
	mIdentification = packIdentification();
	mFlagsFragOffset = packFlagsFragOffset();
	mTimeToLive = packTimeToLive();
	mProtocol = packProtocol();
	mSrcIP = DataPacker::ipToInt(srcIP);
	mDestIP = DataPacker::ipToInt(destIP);
	mSrcPort = srcPort;
	mDestPort = destort;
}

unsigned short UDPConstructor::packChecksum() {
	unsigned short packed = 0;
	
	return packed;
}

unsigned char UDPConstructor::packProtocol() {
	//0x11 identifies UDP packets.
	char packed = 0x11;

	return packed;
}

unsigned char UDPConstructor::packVersionIHL() {
	unsigned char packed = 0;

	//Set the version to 4, represents ipv4
	packed += 4 << 4;

	//Set the IHL to 5, represents number of words in header.
	packed += 5;

	return packed;
}

unsigned char UDPConstructor::packDSCPECN() {
	//TODO: Not sure if this is right. Wireshark caps of a udp packet don't show the field. Going with
	//0x00 for now on both.

	unsigned char packed = 0;

	return packed;
}

unsigned short UDPConstructor::packIdentification() {
	//TODO: Still not sure how identification is set. For now using 0.
	unsigned short packed = 0;

	return packed;
}

unsigned short UDPConstructor::packFlagsFragOffset() {
	unsigned short packed = 0;

	//Add flags, just using 0x02 for now (means don't fragment)
	packed += 2;

	//Fragment offset is skipped for now, believe it's 0.

	return packed;

}

unsigned char UDPConstructor::packTimeToLive() {
	unsigned char packed = 0;

	//Add TTL. For now just going to set it to 64.
	packed += 64;

	return packed;

}

int main(int argc, char* argv[]) {
	//UDPConstructor myCon("25.25.3.15", 5200, "29.22.14.65", 3555);
}