#include "pch.h"
#include "OutputStreamDecorator.h"

using namespace std;

COutputStreamDecorator::COutputStreamDecorator(IOutputDataStreamPtr &&strm)
	: m_strm(move(strm))
{
}

void COutputStreamDecorator::WriteBlock(const void *srcData, std::streamsize size)
{
	const uint8_t *bytes = static_cast<const uint8_t*>(srcData);
	for (streamsize i = 0; i < size; i++)
	{
		WriteByte(*bytes);
		bytes++;
	}
}