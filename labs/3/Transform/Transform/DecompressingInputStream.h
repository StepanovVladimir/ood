#pragma once

#include "InputStreamDecorator.h"

class CDecompressingInputStream : public CInputStreamDecorator
{
public:
	CDecompressingInputStream(IInputDataStreamPtr &&strm);

	bool IsEOF() const override;
	uint8_t ReadByte() override;

private:
	uint8_t m_counter;
	uint8_t m_value;

	void ReadCounterAndValue();
};