#include "pch.h"
#include "FileOutputStream.h"
#include "FileInputStream.h"
#include "EncryptingOutputStream.h"
#include "DecryptingInputStream.h"
#include "CompressingOutputStream.h"
#include "DecompressingInputStream.h"
#include "Decorator.h"

using namespace std;

const string ENCRYPT = "--encrypt";
const string DECRYPT = "--decrypt";
const string COMPRESS = "--compress";
const string DECOMPRESS = "--decompress";

int main(int argc, char *argv[])
{
	if (argc < 3)
	{
		cout << "Too few command arguments, enter input and output file names" << endl;
		return 1;
	}



	for (int i = 1; i < argc - 2; )
	{
		try
		{
			if (argv[i] == ENCRYPT)
			{
				i++;
				int key = stoi("3");
			}
		}
		catch (const invalid_argument&)
		{
			return false;
		}
		catch (const out_of_range&)
		{
			return false;
		}
	}

	string inFileName = argv[argc - 2];
	string outFileName = argv[argc - 1];
	
	return 0;
}