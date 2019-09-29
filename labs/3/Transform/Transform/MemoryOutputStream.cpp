#include "pch.h"
#include "MemoryOutputStream.h"

using namespace std;

CMemoryOutputStream::CMemoryOutputStream(std::vector<uint8_t> &bytes)
	: m_bytes(bytes)
{
}

void CMemoryOutputStream::WriteByte(uint8_t data)
{
	if (m_bytes.size() == UINT32_MAX)
	{
		throw ios_base::failure("Failed to write data");
	}
	m_bytes.push_back(data);
}

void CMemoryOutputStream::WriteBlock(const void *srcData, streamsize size)
{
	const uint8_t *bytes = static_cast<const uint8_t*>(srcData);
	for (streamsize i = 0; i < size; i++)
	{
		WriteByte(*bytes);
		bytes++;
	}
}