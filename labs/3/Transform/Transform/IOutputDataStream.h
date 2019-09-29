#pragma once

#include <iostream>

class IOutputDataStream
{
public:
	virtual ~IOutputDataStream() = default;

	virtual void WriteByte(uint8_t data) = 0;
	virtual void WriteBlock(const void *srcData, std::streamsize size) = 0;
};

using IOutputDataStreamPtr = std::unique_ptr<IOutputDataStream>;