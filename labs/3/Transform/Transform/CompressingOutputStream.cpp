#include "pch.h"
#include "CompressingOutputStream.h"

CCompressingOutputStream::CCompressingOutputStream(IOutputDataStreamPtr &&strm)
	: COutputStreamDecorator(move(strm))
	, m_counter(0)
{
}

CCompressingOutputStream::~CCompressingOutputStream()
{
	if (m_counter != 0)
	{
		m_strm->WriteByte(m_counter);
		m_strm->WriteByte(m_value);
	}
}

void CCompressingOutputStream::WriteByte(uint8_t data)
{
	if (m_counter == 0)
	{
		m_counter = 1;
		m_value = data;
	}
	else if (m_value == data && m_counter < UCHAR_MAX)
	{
		m_counter++;
	}
	else
	{
		m_strm->WriteByte(m_counter);
		m_strm->WriteByte(m_value);
		m_counter = 1;
		m_value = data;
	}
}