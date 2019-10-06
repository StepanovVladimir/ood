#pragma once

#include "IShapeFactory.h"

class CShapeFactory : public IShapeFactory
{
public:
	std::unique_ptr<CShape> CreateShape(const std::string& description) const override;

private:
	std::unique_ptr<CShape> CreateRectangle(std::istream& strm) const;
	std::unique_ptr<CShape> CreateTriangle(std::istream& strm) const;
	std::unique_ptr<CShape> CreateEllipse(std::istream& strm) const;
	std::unique_ptr<CShape> CreateRegularPolygon(std::istream& strm) const;

	Color StringToColor(const std::string& str) const;
};