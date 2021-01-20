// ColorDlg.cpp: 구현 파일
//

#include "pch.h"
#include "ColorDlg.h"
#include "ColorPicker.h"
#include "ColorPickerDlg.h"
#include "afxdialogex.h"


// ColorDlg 대화 상자

IMPLEMENT_DYNAMIC(ColorDlg, CDialogEx)

ColorDlg::ColorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_COLOR_DIALOG, pParent)
	, m_strRGB(_T(""))
{
	this->pParent = pParent;
}

ColorDlg::~ColorDlg()
{
}

void ColorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STATIC_RGB, m_strRGB);
	DDX_Control(pDX, IDC_STATIC_COLORBOX, m_colorbox);
}


BEGIN_MESSAGE_MAP(ColorDlg, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// ColorDlg 메시지 처리기



void ColorDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.

	if (!IsIconic())
	{
		CDialogEx::OnPaint();

		CRect rect;
		GetClientRect(&rect);
		CBrush myBrush(color);

		CDC *pDC = m_colorbox.GetWindowDC();
		CBrush *pOld = pDC->SelectObject(&myBrush);
		BOOL bRes = pDC->PatBlt(0, 0, rect.Width(), rect.Height(), PATCOPY);
		pDC->SelectObject(pOld);
	}
}


void ColorDlg::UpdateColor()
{
	r.Format(_T("%d"), GetRValue(color));
	g.Format(_T("%d"), GetGValue(color));
	b.Format(_T("%d"), GetBValue(color));
	m_strRGB.SetString("(" + r + "," + g + "," + b + ")");
	((CColorPickerDlg *)GetParent())->color = color;
}


void ColorDlg::PickColor()
{
	((CColorPickerDlg *)GetParent())->m_strRed.SetString(r);
	((CColorPickerDlg *)GetParent())->m_strGreen.SetString(g);
	((CColorPickerDlg *)GetParent())->m_strBlue.SetString(b);

	CString hex;
	hex.Format("#%06x", _ttoi(r) << 16 | _ttoi(g) << 8 | _ttoi(b)); // RGB to HEX
	((CColorPickerDlg *)GetParent())->m_strHex.SetString(hex);
	((CColorPickerDlg *)GetParent())->UpdateData(FALSE);

	((CColorPickerDlg *)GetParent())->ShowWindow(SW_SHOW);
}
