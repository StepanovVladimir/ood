#include "../../../../catch2/catch.hpp"
#include "../Transform/FileInputStream.h"
#include "../Transform/MemoryInputStream.h"

using namespace std;

TEST_CASE("Memory input stream tests")
{
	vector<uint8_t> bytes{ 1, 2, 3, 4 };
	CMemoryInputStream inStrm(bytes);

	CHECK_FALSE(inStrm.IsEOF());

	CHECK(inStrm.ReadByte() == 1);
	CHECK(inStrm.ReadByte() == 2);
	CHECK(inStrm.ReadByte() == 3);

	CHECK_FALSE(inStrm.IsEOF());

	CHECK(inStrm.ReadByte() == 4);

	CHECK(inStrm.IsEOF());
	CHECK_THROWS_AS(inStrm.ReadByte(), ios_base::failure);
}

TEST_CASE("Memory input stream read block tests")
{
	CMemoryInputStream inStrm1(vector<uint8_t>{ 1, 2, 3, 4 });
	uint8_t bytes[4];

	CHECK(inStrm1.ReadBlock(bytes, 2) == 2);

	CHECK(bytes[0] == 1);
	CHECK(bytes[1] == 2);
	CHECK_FALSE(inStrm1.IsEOF());

	CHECK(inStrm1.ReadBlock(bytes, 2) == 2);
	
	CHECK(bytes[0] == 3);
	CHECK(bytes[1] == 4);
	CHECK(inStrm1.IsEOF());

	CHECK(inStrm1.ReadBlock(bytes, 2) == 0);

	CHECK(bytes[0] == 3);
	CHECK(bytes[1] == 4);

	CMemoryInputStream inStrm2(vector<uint8_t>{ 1, 2 });

	CHECK(inStrm2.ReadBlock(bytes, 4) == 2);

	CHECK(bytes[0] == 1);
	CHECK(bytes[1] == 2);
	CHECK(inStrm2.IsEOF());
}

TEST_CASE("File input stream tests")
{
	CHECK_THROWS_AS(CFileInputStream("non-existentFile"), ios_base::failure);

	CFileInputStream inStrm("input.txt");

	CHECK_FALSE(inStrm.IsEOF());

	CHECK(inStrm.ReadByte() == 'a');
	CHECK(inStrm.ReadByte() == 'b');
	CHECK(inStrm.ReadByte() == 'c');

	CHECK_FALSE(inStrm.IsEOF());

	CHECK(inStrm.ReadByte() == 'd');

	CHECK(inStrm.IsEOF());

	CHECK_THROWS_AS(inStrm.ReadByte(), ios_base::failure);
}

TEST_CASE("File input stream read block tests")
{
	CFileInputStream inStrm1("input.txt");
	uint8_t bytes[6];

	CHECK(inStrm1.ReadBlock(bytes, 2) == 2);

	CHECK(bytes[0] == 'a');
	CHECK(bytes[1] == 'b');
	CHECK_FALSE(inStrm1.IsEOF());

	CHECK(inStrm1.ReadBlock(bytes, 2) == 2);

	CHECK(bytes[0] == 'c');
	CHECK(bytes[1] == 'd');
	CHECK(inStrm1.IsEOF());

	CHECK(inStrm1.ReadBlock(bytes, 2) == 0);

	CHECK(bytes[0] == 'c');
	CHECK(bytes[1] == 'd');

	CFileInputStream inStrm2("input.txt");

	CHECK(inStrm2.ReadBlock(bytes, 6) == 4);

	CHECK(bytes[0] == 'a');
	CHECK(bytes[1] == 'b');
	CHECK(bytes[2] == 'c');
	CHECK(bytes[3] == 'd');
	CHECK(inStrm2.IsEOF());
}