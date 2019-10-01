#include "pch.h"
#include "FileInputStream.h"

using namespace std;

CFileInputStream::CFileInputStream(const std::string &fileName)
{
	m_stream.open(fileName, ios::binary);
	if (!m_stream.is_open())
	{
		throw ios_base::failure("Failed to open file " + fileName);
	}
	m_stream.get(m_nextByte);
}

bool CFileInputStream::IsEOF() const
{
	return m_stream.eof();
}

uint8_t CFileInputStream::ReadByte()
{
	if (IsEOF())
	{
		throw ios_base::failure("Failed to read data");
	}
	uint8_t curByte = (uint8_t)m_nextByte;
	m_stream.get(m_nextByte);

	return (uint8_t)curByte;
}

streamsize CFileInputStream::ReadBlock(void *dstBuffer, std::streamsize size)
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