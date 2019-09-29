#pragma once

#include <iostream>

class IInputDataStream
{
public:
	virtual ~IInputDataStream() = default;

	virtual bool IsEOF() const = 0;
	virtual uint8_t ReadByte() = 0;
	virtual std::streamsize ReadBlock(void *dstBuffer, std::streamsize size) = 0;
};

using IInputDataStreamPtr = std::unique_ptr<IInputDataStream>;