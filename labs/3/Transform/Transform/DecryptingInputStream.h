#pragma once

#include "InputStreamDecorator.h"
#include <array>

class CDecryptingInputStream : public CInputStreamDecorator
{
public:
	CDecryptingInputStream(IInputDataStreamPtr &&strm, int key);

	bool IsEOF() const override;
	uint8_t ReadByte() override;

private:
	std::array<uint8_t, 256> m_decryptTable;
};