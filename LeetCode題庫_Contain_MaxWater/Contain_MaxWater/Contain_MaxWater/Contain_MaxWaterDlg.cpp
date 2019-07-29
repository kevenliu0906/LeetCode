
// Contain_MaxWaterDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Contain_MaxWater.h"
#include "Contain_MaxWaterDlg.h"
#include "afxdialogex.h"
#include "PersonalOther.h"

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


// CContain_MaxWaterDlg dialog



CContain_MaxWaterDlg::CContain_MaxWaterDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CONTAIN_MAXWATER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CContain_MaxWaterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CContain_MaxWaterDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CContain_MaxWaterDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CContain_MaxWaterDlg message handlers

BOOL CContain_MaxWaterDlg::OnInitDialog()
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

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CContain_MaxWaterDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CContain_MaxWaterDlg::OnPaint()
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
HCURSOR CContain_MaxWaterDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CContain_MaxWaterDlg::OnBnClickedButton1()
{
	//----- Initial ...
	CString      Msg_cstr = _T("");
	int          InputValue_i_ay[] = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
	int          InputArrayNum_i = sizeof(InputValue_i_ay) / sizeof(InputValue_i_ay[0]);
	CString      TempData_cstr = _T("");
	CString      Data_cstr = _T("");
	int          MaxWater_Area_i = 0;

	//------------------------------
	MaxWater_Area_i = maxArea(InputValue_i_ay, InputArrayNum_i);
	CString   MaxWater_Aera_cstr = _T("");
	MaxWater_Aera_cstr.Format(_T("%d"), MaxWater_Area_i);

	Msg_cstr.Format(_T("InputValue[%d]={"), InputArrayNum_i);
	for (int i_i = 0; i_i < InputArrayNum_i; i_i++)
	{
		if (i_i != InputArrayNum_i - 1)
			TempData_cstr.Format(_T("%d,"), InputValue_i_ay[i_i]);
		else
			TempData_cstr.Format(_T("%d}"), InputValue_i_ay[i_i]);
		Data_cstr = Data_cstr + TempData_cstr;
	}
	Msg_cstr = Msg_cstr + Data_cstr + _T("  MaxWater:") + MaxWater_Aera_cstr;
	MessageBox(Msg_cstr);
}
