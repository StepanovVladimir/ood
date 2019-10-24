#include "pch.h"
#include "ResizeImageCommand.h"

using namespace std;

CResizeImageCommand::CResizeImageCommand(shared_ptr<IImage> target, int width, int height)
	: m_target(target)
	, m_newWidth(width)
	, m_newHeight(height)
{
}

void CResizeImageCommand::DoExecute()
{
	int tmpWidth = m_target->GetWidth();
	int tmpHeight = m_target->GetHeight();
	swap(m_newWidth, tmpWidth);
	swap(m_newHeight, tmpHeight);
	m_target->Resize(tmpWidth, tmpHeight);
}

void CResizeImageCommand::DoUnexecute()
{
	int tmpWidth = m_target->GetWidth();
	int tmpHeight = m_target->GetHeight();
	swap(m_newWidth, tmpWidth);
	swap(m_newHeight, tmpHeight);
	m_target->Resize(tmpWidth, tmpHeight);
}