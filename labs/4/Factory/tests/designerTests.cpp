#include "../../../../catch2/catch.hpp"
#include "../Factory/Designer.h"
#include "MockShape.h"
#include "MockShapeFactory.h"
#include <sstream>

using namespace std;

TEST_CASE("Designer on empty input tests")
{
	CMockShapeFactory shapeFactory;
	CDesigner designer(shapeFactory);
	istringstream strm;
	CPictureDraft pictureDraft = designer.CreateDraft(strm);

	CHECK(pictureDraft.IsEmpty());
}

TEST_CASE("Designer tests")
{
	CMockShapeFactory shapeFactory;
	CDesigner designer(shapeFactory);
	istringstream strm("Rectangle 1 2.4 3 Black\nTriangle 2 3 4 Red\nEllipse 3 4.5 5 Yellow\n");
	CPictureDraft pictureDraft = designer.CreateDraft(strm);

	CHECK(pictureDraft.GetShapesCount() == 3);
	
	const CMockShape* mockShape1 = dynamic_cast<const CMockShape*>(&(pictureDraft[0]));
	const CMockShape* mockShape2 = dynamic_cast<const CMockShape*>(&(pictureDraft[1]));
	const CMockShape* mockShape3 = dynamic_cast<const CMockShape*>(&(pictureDraft[2]));

	CHECK(mockShape1->GetDescr() == "Rectangle 1 2.4 3 Black");
	CHECK(mockShape2->GetDescr() == "Triangle 2 3 4 Red");
	CHECK(mockShape3->GetDescr() == "Ellipse 3 4.5 5 Yellow");
}