
// ColorPickerDlg.h: 헤더 파일
#include "ColorDlg.h"
//

#pragma once


// CColorPickerDlg 대화 상자
class CColorPickerDlg : public CDialogEx
{
// 생성입니다.
public:
	CColorPickerDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_COLORPICKER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonCopy();
	afx_msg void OnBnClickedButtonPick();
	COLORREF color;
	CString r, g, b;
	CString m_strRed;
	CString m_strHex;
	CString m_strGreen;
	CString m_strBlue;
	CStatic m_cbox;

	// 변수선언
	static HMODULE g_hModule;
	static HHOOK g_hMouse;

	// 함수 선언
	static LRESULT CALLBACK MouseProc(int nCode, WPARAM wParam, LPARAM lParam); // 마우스 콜백 함수
	static void SetHook(); // 후킹 설정 함수
	static void UnHook(); // 후킹 해제 함수
};

