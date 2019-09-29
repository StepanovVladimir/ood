#include "pch.h"
#include "InputStreamDecorator.h"

using namespace std;

CInputStreamDecorator::CInputStreamDecorator(IInputDataStreamPtr &&strm)
	: m_strm(move(strm))
{
}

streamsize CInputStreamDecorator::ReadBlock(void *dstBuffer, streamsize size)
{
	uint8_t *bytes = static_cast<uint8_t*>(dstBuffer);
	streamsize bytesCount = 0;
	for (streamsize i = 0; i < size; i++)
	{
		if (IsEOF())
		{
			break;
		}
		*bytes = ReadByte();
		bytes++;
		bytesCount++;
	}
	return bytesCount;
}