#pragma once


// CWaveletTransformDlg 대화 상자
class CWaveletTransformDoc;

class CWaveletTransformDlg : public CDialog
{
	DECLARE_DYNAMIC(CWaveletTransformDlg)

public:
	CWaveletTransformDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CWaveletTransformDlg(); 
	CWaveletTransformDlg(CWaveletTransformDoc *pDoc, CWnd*
		pParent = NULL);


// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	CWaveletTransformDoc *m_pDoc;
	DECLARE_MESSAGE_MAP()
public:
	float m_Error;
	float m_SNR;
	int m_FilterCheck;
	int m_Level;
	afx_msg void OnButtonUpdate();
	afx_msg void OnButtonArrange();
	afx_msg void OnButtonEnd();
};
