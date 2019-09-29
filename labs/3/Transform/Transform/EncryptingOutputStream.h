#pragma once

#include "OutputStreamDecorator.h"
#include <array>

class CEncryptingOutputStream : public COutputStreamDecorator
{
public:
	CEncryptingOutputStream(IOutputDataStreamPtr &&strm, unsigned key);

	void WriteByte(uint8_t data) override;

private:
	std::array<uint8_t, 256> m_encryptTable;
};