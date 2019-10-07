#include "MockShape.h"

using namespace std;

CMockShape::CMockShape(const string& descr)
	: CShape(Color::Black)
	, m_descr(descr)
{
}

void CMockShape::Draw(ICanvas& canvas) const
{
}

const string& CMockShape::GetDescr() const
{
	return m_descr;
}