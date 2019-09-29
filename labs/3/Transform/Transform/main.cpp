#include "pch.h"
#include "FileOutputStream.h"
#include "FileInputStream.h"
#include "EncryptingOutputStream.h"
#include "DecryptingInputStream.h"
#include "CompressingOutputStream.h"
#include "DecompressingInputStream.h"
#include "Decorator.h"

using namespace std;

int main(int argc, char *argv[])
{
	{
		IInputDataStreamPtr inStrm = make_unique<CFileInputStream>("input.dat");
		IOutputDataStreamPtr outStrm = make_unique<CFileOutputStream>("output.dat")
			<< DecorateWith<CCompressingOutputStream>()
			<< DecorateWith<CEncryptingOutputStream>(100500)
			<< DecorateWith<CEncryptingOutputStream>(3);

		while (!inStrm->IsEOF())
		{
			uint8_t byte = inStrm->ReadByte();
			outStrm->WriteByte(byte);
		}
	}
	{
		IInputDataStreamPtr inStrm = make_unique<CFileInputStream>("output.dat")
			<< DecorateWith<CDecompressingInputStream>()
			<< DecorateWith<CDecryptingInputStream>(100500)
			<< DecorateWith<CDecryptingInputStream>(3);
		IOutputDataStreamPtr outStrm = make_unique<CFileOutputStream>("input.dat.restored");

		while (!inStrm->IsEOF())
		{
			uint8_t byte = inStrm->ReadByte();
			outStrm->WriteByte(byte);
		}
	}
}