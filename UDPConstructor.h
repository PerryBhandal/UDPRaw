class UDPConstructor {
	public:
		UDPConstructor(char srcIP, unsigned short srcPort, char destIP, unsigned short destPort);
		unsigned char* createPacket(char data);

	private:
		void initStaticVars();

		unsigned char packVersionIHL();
		unsigned char packDSCPECN();
		unsigned short packIdentification();
		unsigned short packFlagsFragOffset();
		unsigned char packTimeToLive();
		unsigned char packProtocol();
		unsigned short packChecksum();

		unsigned char mVersionIHL;
		unsigned char mDSCPECN;
		unsigned short mTotalLength;
		unsigned short mIdentification;
		unsigned short mFlagsFragOffset;
		unsigned char mTimeToLive;
		unsigned char mProtocol;
		unsigned short mHeaderChecksum;
		unsigned int mSrcIP;
		unsigned int mDestIP;
		unsigned short mSrcPort;
		unsigned short mDestPort;

};
