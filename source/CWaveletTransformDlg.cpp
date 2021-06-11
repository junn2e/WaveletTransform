// CWaveletTransformDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "WaveletTransform.h"
#include "CWaveletTransformDlg.h"
#include "afxdialogex.h"
#include "WaveletTransformDoc.h"
#include "CArrangeDlg.h"   



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


// CWaveletTransformDlg 대화 상자

IMPLEMENT_DYNAMIC(CWaveletTransformDlg, CDialog)

CWaveletTransformDlg::CWaveletTransformDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
	, m_Error(0)
	, m_SNR(0)
	, m_FilterCheck(0)
	, m_Level(0)
{
	m_pDoc = NULL;
}
CWaveletTransformDlg::CWaveletTransformDlg(CWaveletTransformDoc *pDoc, CWnd* pParent /*=NULL*/)
	:CDialog(IDD_DIALOG1, pParent)
{
	m_pDoc = pDoc; // Doc 클래스 참조
	m_Level = 1; // Wavelet 분해 레벨 초기화
	m_Error = 0.0f; // MSE 초기화
	m_SNR = 0.0f; // SNR 초기화
	m_FilterCheck = 0; // Filter Check 초기화
}

CWaveletTransformDlg::~CWaveletTransformDlg()
{
}

void CWaveletTransformDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_Error);
	DDX_Text(pDX, IDC_EDIT3, m_SNR);
	DDX_Radio(pDX, IDC_RADIO1, m_FilterCheck);
	DDX_Text(pDX, IDC_EDIT1, m_Level);
}


BEGIN_MESSAGE_MAP(CWaveletTransformDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_UPDATE, &CWaveletTransformDlg::OnButtonUpdate)
	ON_BN_CLICKED(IDC_BUTTON_ARRANGE, &CWaveletTransformDlg::OnButtonArrange)
	ON_BN_CLICKED(IDC_BUTTON_END, &CWaveletTransformDlg::OnButtonEnd)
END_MESSAGE_MAP()


// CWaveletTransformDlg 메시지 처리기


void CWaveletTransformDlg::OnButtonUpdate()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_pDoc->m_Level = m_Level;
	// 대화상자에서 입력받은 레벨 값을 Doc 클래스에 전달
	m_pDoc->OnWaveletEncode(); // 웨이브렛 변환

	m_pDoc->OnWaveletDecode(); // 웨이브렛 역변환
	m_pDoc->OnSNR(); // 신호 대 잡음비

	UpdateData(FALSE); // 결과 업데이트

}


void CWaveletTransformDlg::OnButtonArrange()
{
	// 버튼을 누르면 정렬 영상 출력
	CArrangeDlg dlg;

	dlg.Width = m_pDoc->m_Width;
	dlg.Height = m_pDoc->m_Height;
	dlg.m_tempImage = m_pDoc->m_ArrangeImage;

	UpdateData(TRUE);

	dlg.DoModal(); // 정렬 영상을 위한 대화상자 출력

}


void CWaveletTransformDlg::OnButtonEnd()
{
	CDialog::OnOK();
}
