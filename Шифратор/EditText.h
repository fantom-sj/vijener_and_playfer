#pragma once


// CEditText

class CEditText : public CEdit
{
	DECLARE_DYNAMIC(CEditText)

public:
	CEditText();
	virtual ~CEditText();

protected:
	DECLARE_MESSAGE_MAP()
};

struct TEXT {
public:
	TCHAR *text = new TCHAR;
	LONG lenght_text;
};

