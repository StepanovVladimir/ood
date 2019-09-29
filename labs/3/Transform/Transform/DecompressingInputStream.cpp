#include "pch.h"
#include "DecompressingInputStream.h"

CDecompressingInputStream::CDecompressingInputStream(IInputDataStreamPtr &&strm)
	: CInputStreamDecorator(move(strm))
	, m_counter(0)
{
}

bool CDecompressingInputStream::IsEOF() const
{
	return m_counter == 0 && m_strm->IsEOF();
}

uint8_t CDecompressingInputStream::ReadByte()
{
	if (m_counter == 0)
	{
		ReadCounterAndValue();
	}
	m_counter--;
	return m_value;
}

void CDecompressingInputStream::ReadCounterAndValue()
{
	m_counter = m_strm->ReadByte();
	if (m_strm->IsEOF())
	{
		throw std::ios_base::failure("Compressed data has an odd number of bytes");
	}
	m_value = m_strm->ReadByte();
}