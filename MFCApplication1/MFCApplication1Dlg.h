
// MFCApplication1Dlg.h : header file
//

#pragma once


// CMFCApplication1Dlg dialog
class CMFCApplication1Dlg : public CDialogEx
{
// Construction
public:
	CMFCApplication1Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;
	//변수에 대한 포인터
	CBitmapButton	*m_pBtnOnOff;
	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
private:
	CImage	m_image;
	BOOL	validImgPos(int x, int y);
public:
	afx_msg void OnBnClickedButtonSave();
	afx_msg void OnBnClickedButtonLoad();
	void	UpdateDisplay();
	void	moveRect();
	afx_msg void OnBnClickedButtonAction();
	void drawCircle(unsigned char* fm, int i, int j, int nRadius, int nGray);
	BOOL IsInCircle(int i, int j, int nCenterX, int nCenterY, int nRadius);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};
