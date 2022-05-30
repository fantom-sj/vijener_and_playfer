#pragma once


// ClassButton_shifr

class ClassButton_shifr : public CButton
{
	DECLARE_DYNAMIC(ClassButton_shifr)

public:
	ClassButton_shifr();
	virtual ~ClassButton_shifr();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClicked();
};


