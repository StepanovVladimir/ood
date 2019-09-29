#include "pch.h"
#include "EncryptingOutputStream.h"
#include <algorithm>
#include <random>

using namespace std;

CEncryptingOutputStream::CEncryptingOutputStream(IOutputDataStreamPtr &&strm, unsigned key)
	: COutputStreamDecorator(move(strm))
{
	for (size_t i = 0; i < 256; i++)
	{
		m_encryptTable[i] = (uint8_t)i;
	}

	shuffle(m_encryptTable.begin(), m_encryptTable.end(), mt19937(key));
}

void CEncryptingOutputStream::WriteByte(uint8_t data)
{
	m_strm->WriteByte(m_encryptTable[data]);
}