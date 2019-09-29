#pragma once

#include "IOutputDataStream.h"

class COutputStreamDecorator : public IOutputDataStream
{
public:
	void WriteBlock(const void *srcData, std::streamsize size) override;

protected:
	COutputStreamDecorator(IOutputDataStreamPtr &&strm);

	IOutputDataStreamPtr m_strm;
};