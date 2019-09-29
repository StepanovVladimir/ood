#define CATCH_CONFIG_MAIN
#include "../../../../catch2/catch.hpp"
#include "../Transform/FileOutputStream.h"
#include "../Transform/MemoryOutputStream.h"

using namespace std;

TEST_CASE("Memory output stream tests")
{
	vector<uint8_t> bytes;
	CMemoryOutputStream outStrm(bytes);

	outStrm.WriteByte(1);
	outStrm.WriteByte(2);
	outStrm.WriteByte(3);

	CHECK(bytes == vector<uint8_t>{ 1, 2, 3 });
}

TEST_CASE("Memory output stream write block tests")
{
	vector<uint8_t> bytes;
	CMemoryOutputStream outStrm(bytes);
	uint8_t srcData[] = { 1, 2, 3 };

	outStrm.WriteBlock(srcData, 3);
	CHECK(bytes == vector<uint8_t>{ 1, 2, 3 });
}

TEST_CASE("File output stream tests")
{
	SECTION("Write to file")
	{
		CFileOutputStream outStrm("output.txt");
		outStrm.WriteByte('a');
		outStrm.WriteByte('b');
		outStrm.WriteByte('c');
	}
	
	SECTION("Check file")
	{
		ifstream inStrm("output.txt");
		string str;
		getline(inStrm, str);

		CHECK(str == "abc");
	}
}

TEST_CASE("File output stream write block tests")
{
	SECTION("Write to file")
	{
		CFileOutputStream outStrm("output.txt");
		uint8_t bytes[] = { 'a', 'b', 'c' };

		outStrm.WriteBlock(bytes, 3);
	}
	
	SECTION("Check file")
	{
		ifstream inStrm("output.txt");
		string str;
		getline(inStrm, str);

		CHECK(str == "abc");
	}
}