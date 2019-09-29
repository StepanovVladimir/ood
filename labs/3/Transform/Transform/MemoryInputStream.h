#pragma once

#include "IInputDataStream.h"
#include <vector>

class CMemoryInputStream : public IInputDataStream
{
public:
	CMemoryInputStream(const std::vector<uint8_t> &bytes);

	bool IsEOF() const override;
	uint8_t ReadByte() override;
	std::streamsize ReadBlock(void *dstBuffer, std::streamsize size) override;
	
private:
	std::vector<uint8_t> m_bytes;
	size_t m_pos;
};

