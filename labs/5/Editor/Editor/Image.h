#pragma once

#include "IImage.h"

class CImage : public IImage
{
public:
	CImage(const std::string& path, int width, int height);
	~CImage();

	std::string GetPath() const override;

	int GetWidth() const override;
	int GetHeight() const override;

	void Resize(int width, int height) override;

private:
	static size_t m_count;

	std::string m_path;
	int m_width;
	int m_height;
};