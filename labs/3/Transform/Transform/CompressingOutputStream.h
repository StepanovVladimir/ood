#pragma once

#include "OutputStreamDecorator.h"

class CCompressingOutputStream : public COutputStreamDecorator
{
public:
	CCompressingOutputStream(IOutputDataStreamPtr &&strm);
	~CCompressingOutputStream();

	void WriteByte(uint8_t data) override;

private:
	uint8_t m_counter;
	uint8_t m_value;
};