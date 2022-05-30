#pragma once


// ClassButton_unshifr
// ClassButton_criptoAnaliz
class ClassButton_unshifr : public CButton
{
	DECLARE_DYNAMIC(ClassButton_unshifr)

public:
	ClassButton_unshifr();
	virtual ~ClassButton_unshifr();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClicked();
};


