#include "pch.h"
#include "ConstDocumentItem.h"

using namespace std;

shared_ptr<const IParagraph> CConstDocumentItem::GetParagraph() const
{
	return nullptr;
}

shared_ptr<const IImage> CConstDocumentItem::GetImage() const
{
	return nullptr;
}