#include "pch.h"
#include "Designer.h"

using namespace std;

CDesigner::CDesigner(IShapeFactory& factory)
	:m_factory(factory)
{
}

CPictureDraft CDesigner::CreateDraft(istream& inputData)
{
	CPictureDraft draft;
	string line;
	while (getline(inputData, line))
	{
		try
		{
			draft.AddShape(m_factory.CreateShape(line));
		}
		catch (const invalid_argument& exc)
		{
			cout << exc.what() << endl;
		}
	}
	return draft;
}