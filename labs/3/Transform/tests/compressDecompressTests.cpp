#include "../../../../catch2/catch.hpp"
#include "../Transform/CompressingOutputStream.h"
#include "../Transform/DecompressingInputStream.h"
#include "../Transform/MemoryOutputStream.h"
#include "../Transform/MemoryInputStream.h"
#include "../Transform/Decorator.h"

using namespace std;

TEST_CASE("Compress and decompress tests")
{
	vector<uint8_t> bytes;

	SECTION("Write data")
	{
		IOutputDataStreamPtr outStrm = make_unique<CMemoryOutputStream>(bytes)
			<< DecorateWith<CCompressingOutputStream>();

		outStrm->WriteByte('a');
		outStrm->WriteByte('a');
		outStrm->WriteByte('a');
		outStrm->WriteByte('b');
		outStrm->WriteByte('b');
	}
	
	CHECK(bytes == vector<uint8_t>{ 3, 'a', 2, 'b' });

	IInputDataStreamPtr inStrm = make_unique<CMemoryInputStream>(bytes)
		<< DecorateWith<CDecompressingInputStream>();

	CHECK(inStrm->ReadByte() == 'a');
	CHECK(inStrm->ReadByte() == 'a');
	CHECK(inStrm->ReadByte() == 'a');
	CHECK(inStrm->ReadByte() == 'b');

	CHECK_FALSE(inStrm->IsEOF());

	CHECK(inStrm->ReadByte() == 'b');

	CHECK(inStrm->IsEOF());
	CHECK_THROWS_AS(inStrm->ReadByte(), ios_base::failure);
}

TEST_CASE("Compress and decompress read block tests")
{
	vector<uint8_t> bytes;

	SECTION("Write data")
	{
		IOutputDataStreamPtr outStrm = make_unique<CMemoryOutputStream>(bytes)
			<< DecorateWith<CCompressingOutputStream>();

		uint8_t srcData[] = { 'a', 'a', 'a', 'b', 'b' };
		outStrm->WriteBlock(srcData, 5);
	}

	CHECK(bytes == vector<uint8_t>{ 3, 'a', 2, 'b' });

	IInputDataStreamPtr inStrm = make_unique<CMemoryInputStream>(bytes)
		<< DecorateWith<CDecompressingInputStream>();

	uint8_t dstBuffer[6];
	CHECK(inStrm->ReadBlock(dstBuffer, 6) == 5);

	CHECK(dstBuffer[0] == 'a');
	CHECK(dstBuffer[1] == 'a');
	CHECK(dstBuffer[2] == 'a');
	CHECK(dstBuffer[3] == 'b');
	CHECK(dstBuffer[4] == 'b');
}