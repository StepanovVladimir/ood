#pragma once

#include "IInputDataStream.h"

class CInputStreamDecorator : public IInputDataStream
{
public:
	std::streamsize ReadBlock(void *dstBuffer, std::streamsize size) override;

protected:
	CInputStreamDecorator(IInputDataStreamPtr &&strm);

	IInputDataStreamPtr m_strm;
};