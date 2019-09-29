#include "../../../../catch2/catch.hpp"
#include "../Transform/EncryptingOutputStream.h"
#include "../Transform/DecryptingInputStream.h"
#include "../Transform/MemoryOutputStream.h"
#include "../Transform/MemoryInputStream.h"
#include "../Transform/Decorator.h"

using namespace std;

TEST_CASE("Encrypt and decrypt tests")
{
	vector<uint8_t> bytes;

	IOutputDataStreamPtr outStrm = make_unique<CMemoryOutputStream>(bytes)
		<< DecorateWith<CEncryptingOutputStream>(100500)
		<< DecorateWith<CEncryptingOutputStream>(3);

	outStrm->WriteByte('a');
	outStrm->WriteByte('b');
	outStrm->WriteByte('c');
	outStrm->WriteByte('d');

	CHECK(bytes[0] != 'a');
	CHECK(bytes[1] != 'b');
	CHECK(bytes[2] != 'c');
	CHECK(bytes[3] != 'd');

	IInputDataStreamPtr inStrm = make_unique<CMemoryInputStream>(bytes)
		<< DecorateWith<CDecryptingInputStream>(100500)
		<< DecorateWith<CDecryptingInputStream>(3);

	CHECK(inStrm->ReadByte() == 'a');
	CHECK(inStrm->ReadByte() == 'b');
	CHECK(inStrm->ReadByte() == 'c');
	CHECK(inStrm->ReadByte() == 'd');
}