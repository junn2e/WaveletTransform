// CArrangeDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "WaveletTransform.h"
#include "CArrangeDlg.h"
#include "afxdialogex.h"


// CArrangeDlg 대화 상자

IMPLEMENT_DYNAMIC(CArrangeDlg, CDialog)

CArrangeDlg::CArrangeDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG2, pParent)
{
	m_tempImage = NULL;
	Height = 0;
	Width = 0;
}

CArrangeDlg::~CArrangeDlg()
{
}

void CArrangeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CArrangeDlg, CDialog)
	ON_WM_PAINT()
//	ON_WM_INITMENU()
END_MESSAGE_MAP()


// CArrangeDlg 메시지 처리기

BOOL CArrangeDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	CRect rect, rectC;
	GetWindowRect(&rect);
	GetClientRect(&rectC);

	int cx, cy;

	CSize sizeImg;
	sizeImg.cx = Width;
	sizeImg.cy = Height;

	cx = sizeImg.cx + rect.Width() - rectC.Width() + 4;
	// 정렬 영상 출력을 위한 대화상자 크기 조절
	cy = sizeImg.cy + rect.Height() - rectC.Height() + 4;

	SetWindowPos(this, 0, 0, cx, cy, SWP_NOZORDER);

	return TRUE;
	// return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should    return FALSE
}

void CArrangeDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	  // TODO: Add your message handler code here
	  // Do not call CDialog::OnPaint() for painting messages
	int i, j;
	unsigned char R, G, B;

	for (i = 0; i < Height; i++) {
		for (j = 0; j < Width; j++) {
			R = m_tempImage[i][j];

			G = B = R;
			dc.SetPixel(j, i, RGB(R, G, B));
			// 정규화된 정렬 영상을 화면에 출력
		}
	}

}

