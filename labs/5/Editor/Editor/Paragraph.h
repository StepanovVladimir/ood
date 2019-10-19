#pragma once

#include "IParagraph.h"

class CParagraph : public IParagraph
{
public:
	CParagraph(const std::string& text);

	const std::string& GetText() const override;
	std::string& GetText() override;
	void SetText(const std::string& text) override;

private:
	std::string m_text;
};