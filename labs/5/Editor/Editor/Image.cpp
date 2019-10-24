#include "pch.h"
#include "Image.h"
#include <filesystem>

using namespace std;

const string CImage::IMAGES_DIRECTORY = "Resources";
size_t CImage::m_count = 1;

CImage::CImage(const string& path, int width, int height)
{
	Resize(width, height);

	if (!filesystem::exists(path))
	{
		throw runtime_error("This path does not exist");
	}

	string fileExtension = path.substr(path.size() - 4);

	if (fileExtension != ".png" && fileExtension != ".jpg")
	{
		throw runtime_error("Unknown file extension");
	}

	filesystem::create_directory(IMAGES_DIRECTORY);
	m_path = IMAGES_DIRECTORY + '/' + to_string(m_count) + fileExtension;
	filesystem::copy_file(path, m_path);
	m_count++;
}

CImage::~CImage()
{
	filesystem::remove(m_path);
}

string CImage::GetPath() const
{
	return m_path;
}

int CImage::GetWidth() const
{
	return m_width;
}

int CImage::GetHeight() const
{
	return m_height;
}

void CImage::Resize(int width, int height)
{
	if (width < 1 || width > 10000 || height < 1 || height > 10000)
	{
		throw runtime_error("Valid image sizes are from 1 to 10000 pixels");
	}
	m_width = width;
	m_height = height;
}