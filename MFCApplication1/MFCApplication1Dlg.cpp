
// MFCApplication1Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication1Dlg dialog



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication1Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, &CMFCApplication1Dlg::OnBnClickedButtonSave)
	ON_BN_CLICKED(IDC_BUTTON_LOAD, &CMFCApplication1Dlg::OnBnClickedButtonLoad)
	ON_BN_CLICKED(IDC_BUTTON_ACTION, &CMFCApplication1Dlg::OnBnClickedButtonAction)
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// CMFCApplication1Dlg message handlers

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	CRect rect(0, 0, 200, 150);
	GetDlgItem(IDC_BUTTON_ON)->GetWindowRect(&rect);
	//GetDlgItem(IDC_BUTTON_ON)->GetClientRect(&rect);
	m_pBtnOnOff = new CBitmapButton;
	m_pBtnOnOff->Create(NULL, WS_CHILD | WS_VISIBLE | BS_OWNERDRAW, rect, this, IDC_BUTTON_ON);
	m_pBtnOnOff->LoadBitmaps(IDB_ON, IDB_OFF);
	m_pBtnOnOff->SizeToContent();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication1Dlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int nWidth = 640;
	int nHeight = 480;
	int nBpp = 8;

	if (m_image != NULL) {
		m_image.Destroy();
	}
	m_image.Create(nWidth, -nHeight, nBpp);
	//lookup table
	if (nBpp == 8)
	{
		static RGBQUAD rgb[256];
		for (int i = 0; i < 256; i++)
			rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i;
		m_image.SetColorTable(0, 256, rgb);
	}

	int nPitch = m_image.GetPitch();
	unsigned char* fm = (unsigned char*)m_image.GetBits();

	memset(fm, 0xff, nWidth*nHeight);

	//for (int j = 0; j < nHeight; j++)
	//{
	//	for (int i = 0; i < nWidth; i++)
	//	{
	//		fm[j*nPitch + i] = (i % 0xff);
	//	}
	//}

	/*fm[12 * nPitch + 16] = 0;
	fm[0 * nPitch + 0] = 120;
	fm[0 * nPitch + 1] = 128;
*/

	//for (int j = 0; j < nHeight/2; j++)
	//{
	//	for (int i = 0; i < nWidth/2; i++)
	//	{
	//		fm[j*nPitch + i] = 128;
	//	}
	//}

	CClientDC dc(this);
	m_image.Draw(dc, 0, 0);

	m_image.Save(_T("c:\\image\\save.bmp"));
}

CString g_strFileImage = _T("c:\\image\\save.bmp");

void CMFCApplication1Dlg::OnBnClickedButtonSave()
{
	m_image.Save(g_strFileImage);
	// TODO: Add your control notification handler code here
}


void CMFCApplication1Dlg::OnBnClickedButtonLoad()
{
	if (m_image != NULL) {
		m_image.Destroy();
	}
	m_image.Load(g_strFileImage);

	UpdateDisplay();
}

void CMFCApplication1Dlg::UpdateDisplay()
{
	CClientDC dc(this);
	m_image.Draw(dc, 0, 0);

}

void CMFCApplication1Dlg::moveRect()
{
	static int nSttX = 0;
	static int nSttY = 0;

	int nGray = 120;
	//숫자를 적어 하드코딩하는건 수정할때 오래걸린다. 
	//Get 함수를 써서 가져오는게 효율적이다. 
	int nWidth = m_image.GetWidth();
	int nHeight = m_image.GetHeight();
	int nPitch = m_image.GetPitch();
	int nRadius = 5;
	unsigned char* fm = (unsigned char*)m_image.GetBits();

	memset(fm, 0xff, nWidth*nHeight);

	drawCircle(fm, nSttX++, nSttY++, nRadius, nGray);

	UpdateDisplay();
}


void CMFCApplication1Dlg::OnBnClickedButtonAction()
{
	for (int i = 0; i < 400; i++) {
		moveRect();
		Sleep(10);
	}
}

BOOL CMFCApplication1Dlg::validImgPos(int x, int y) {

	BOOL bRet = false;
	int nWidth = m_image.GetWidth();
	int nHeight = m_image.GetHeight();

	//MFC 특정 영역에 대한 정보
	CRect rect(0, 0, nWidth, nHeight);
	//이 좌표가 이 영역에 들어가는가 Point in REct
	return rect.PtInRect(CPoint(x, y));

/*
	if (x > 0 && x <= nWidth) {
		bRet = TRUE;
	}
	if (y > 0 && y <= nHeight) {
		bRet = TRUE;
	}
	return bRet;*/
}

void CMFCApplication1Dlg::drawCircle(unsigned char* fm, int x, int y, int nRadius, int nGray)
{
	int nCenterX = x + nRadius;
	int nCenterY = y + nRadius;
	int nPitch = m_image.GetPitch();

	for (int j = y; j < y + nRadius * 2; j++) {
		for (int i = x; i < x + nRadius * 2; i++) {
			if(IsInCircle(i, j, nCenterX, nCenterY, nRadius))
				fm[j*nPitch + i] = nGray;
		}
	}
}

//클래스에 포함시키기
BOOL CMFCApplication1Dlg::IsInCircle(int i, int j, int nCenterX, int nCenterY, int nRadius)
{
	bool bRet = false;

	double dX = i - nCenterX;
	double dY = j - nCenterY;
	double dDist = dX * dX + dY * dY;

	if (dDist < nRadius*nRadius) {
		bRet = true;
	}

	return bRet;
}


BOOL CMFCApplication1Dlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default
	CPngImage image;
	image.Load(IDB_BASE, nullptr);

	CDC dc;
	dc.CreateCompatibleDC(pDC);
	CBitmap* pOldBitmap = dc.SelectObject(&image);

	pDC->BitBlt(0, 0, 640, 480, &dc, 0, 0, SRCCOPY);
	dc.SelectObject(pOldBitmap);
	return TRUE;

	return CDialogEx::OnEraseBkgnd(pDC);
}
