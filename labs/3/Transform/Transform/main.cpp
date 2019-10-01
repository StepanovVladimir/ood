#include "pch.h"
#include "FileOutputStream.h"
#include "FileInputStream.h"
#include "EncryptingOutputStream.h"
#include "DecryptingInputStream.h"
#include "CompressingOutputStream.h"
#include "DecompressingInputStream.h"
#include <vector>
#include <optional>

using namespace std;

const string ENCRYPT = "--encrypt";
const string DECRYPT = "--decrypt";
const string COMPRESS = "--compress";
const string DECOMPRESS = "--decompress";

struct OutputOption
{
	enum Option
	{
		Encrypt,
		Compress
	};
	Option option;
	optional<int> key;
};

struct InputOption
{
	enum Option
	{
		Decrypt,
		Decompress
	};
	Option option;
	optional<int> key;
};

void GetOptions(int argc, char *argv[], vector<OutputOption> &outputOptions, vector<InputOption> &inputOptions)
{
	bool thereIsCompression = false;
	bool thereIsDecompression = false;
	for (int i = 1; i < argc - 2; )
	{
		if (argv[i] == ENCRYPT)
		{
			i++;
			int key = stoi(argv[i]);
			outputOptions.push_back({ OutputOption::Encrypt, key });
		}
		else if (argv[i] == DECRYPT)
		{
			i++;
			int key = stoi(argv[i]);
			inputOptions.push_back({ InputOption::Decrypt, key });
		}
		else if (argv[i] == COMPRESS)
		{
			if (thereIsCompression)
			{
				throw invalid_argument("You cannot compress data multiple times");
			}
			outputOptions.push_back({ OutputOption::Compress, nullopt });
		}
		else if (argv[i] == DECOMPRESS)
		{
			if (thereIsDecompression)
			{
				throw invalid_argument("You cannot decompress data multiple times");
			}
			inputOptions.push_back({ InputOption::Decompress, nullopt });
		}
		else
		{
			throw invalid_argument("Unexpected command: " + string(argv[i]));
		}

		i++;
	}
}

IOutputDataStreamPtr GetDecoratedOutputStream(const string fileName, const vector<OutputOption> &outputOptions)
{
	IOutputDataStreamPtr outStrm = make_unique<CFileOutputStream>(fileName);
	for (int i = (int)outputOptions.size() - 1; i >= 0; i--)
	{
		if (outputOptions[i].option == OutputOption::Encrypt)
		{
			int key = outputOptions[i].key.value();
			outStrm = make_unique<CEncryptingOutputStream>(move(outStrm), key);
		}
		else
		{
			outStrm = make_unique<CCompressingOutputStream>(move(outStrm));
		}
	}
	return outStrm;
}

IInputDataStreamPtr GetDecoratedInputStream(const string fileName, const vector<InputOption> &inputOptions)
{
	IInputDataStreamPtr inStrm = make_unique<CFileInputStream>(fileName);
	for (size_t i = 0; i < inputOptions.size(); i++)
	{
		if (inputOptions[i].option == InputOption::Decrypt)
		{
			int key = inputOptions[i].key.value();
			inStrm = make_unique<CDecryptingInputStream>(move(inStrm), key);
		}
		else
		{
			inStrm = make_unique<CDecompressingInputStream>(move(inStrm));
		}
	}
	return inStrm;
}

int main(int argc, char *argv[])
{
	if (argc < 3)
	{
		cout << "Too few command arguments, enter input and output file names" << endl;
		return 1;
	}

	vector<OutputOption> outputOptions;
	vector<InputOption> inputOptions;
	try
	{
		GetOptions(argc, argv, outputOptions, inputOptions);
	}
	catch (const invalid_argument &err)
	{
		cout << err.what();
		return 1;
	}
	catch (const out_of_range &err)
	{
		cout << err.what();
		return 1;
	}

	string outFileName = argv[argc - 1];
	string inFileName = argv[argc - 2];
	IOutputDataStreamPtr outStrm = GetDecoratedOutputStream(outFileName, outputOptions);
	IInputDataStreamPtr inStrm = GetDecoratedInputStream(inFileName, inputOptions);
	
	while (!inStrm->IsEOF())
	{
		uint8_t byte = inStrm->ReadByte();
		outStrm->WriteByte(byte);
	}

	return 0;
}
