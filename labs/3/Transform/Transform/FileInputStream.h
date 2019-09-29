#pragma once

#include "IInputDataStream.h"
#include <fstream>

class CFileInputStream : public IInputDataStream
{
public:
	CFileInputStream(const std::string &fileName);
	
	bool IsEOF() const override;
	uint8_t ReadByte() override;
	std::streamsize ReadBlock(void *dstBuffer, std::streamsize size) override;

private:
	std::ifstream m_stream;
	char m_nextByte;
};