#include "pch.h"
#include "MemoryInputStream.h"

using namespace std;

CMemoryInputStream::CMemoryInputStream(const std::vector<uint8_t> &bytes)
	: m_bytes(bytes)
	, m_pos(0)
{
}

bool CMemoryInputStream::IsEOF() const
{
	return m_pos == m_bytes.size();
}

uint8_t CMemoryInputStream::ReadByte()
{
	if (m_pos == m_bytes.size())
	{
		throw ios_base::failure("Failed to read data");
	}

	return m_bytes[m_pos++];
}

streamsize CMemoryInputStream::ReadBlock(void *dstBuffer, std::streamsize size)
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