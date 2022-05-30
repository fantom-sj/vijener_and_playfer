#pragma once
#include <vector>

class ClassButton_criptoAnaliz : public CButton
{
	DECLARE_DYNAMIC(ClassButton_criptoAnaliz)

public:
	ClassButton_criptoAnaliz();
	virtual ~ClassButton_criptoAnaliz();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClicked();
};

