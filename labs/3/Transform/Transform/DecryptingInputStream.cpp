#include "pch.h"
#include "DecryptingInputStream.h"
#include <algorithm>
#include <random>

using namespace std;

CDecryptingInputStream::CDecryptingInputStream(IInputDataStreamPtr &&strm, int key)
	: CInputStreamDecorator(move(strm))
{
	array<uint8_t, 256> encryptTable;
	for (size_t i = 0; i < 256; i++)
	{
		encryptTable[i] = (uint8_t)i;
	}

	shuffle(encryptTable.begin(), encryptTable.end(), mt19937(key));

	for (size_t i = 0; i < 256; ++i)
	{
		m_decryptTable[encryptTable[i]] = (uint8_t)i;
	}
}

bool CDecryptingInputStream::IsEOF() const
{
	return m_strm->IsEOF();
}

uint8_t CDecryptingInputStream::ReadByte()
{
	return m_decryptTable[m_strm->ReadByte()];
}