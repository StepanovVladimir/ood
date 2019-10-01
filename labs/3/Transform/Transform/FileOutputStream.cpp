#include "pch.h"
#include "FileOutputStream.h"

using namespace std;

CFileOutputStream::CFileOutputStream(const string &fileName)
{
	m_stream.open(fileName, ios::binary);
	if (!m_stream.is_open())
	{
		throw ios_base::failure("Failed to open file " + fileName);
	}
}

void CFileOutputStream::WriteByte(uint8_t data)
{
	if (!(m_stream << data))
	{
		throw ios_base::failure("Failed to write data");
	}
}

void CFileOutputStream::WriteBlock(const void *srcData, std::streamsize size)
{
	const uint8_t *bytes = static_cast<const uint8_t*>(srcData);
	for (streamsize i = 0; i < size; i++)
	{
		WriteByte(*bytes);
		bytes++;
	}
}