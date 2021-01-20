#pragma once

// ColorDlg 대화 상자

class ColorDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ColorDlg)

public:
	ColorDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~ColorDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_COLOR_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	CWnd *pParent;
	CString m_strRGB;
	CStatic m_colorbox;
	COLORREF color;
	CString r, g, b;
	void UpdateColor();
	void PickColor();
};
