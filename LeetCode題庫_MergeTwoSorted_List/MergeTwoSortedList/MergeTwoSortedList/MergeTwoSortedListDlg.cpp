
// MergeTwoSortedListDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MergeTwoSortedList.h"
#include "MergeTwoSortedListDlg.h"
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


// CMergeTwoSortedListDlg dialog



CMergeTwoSortedListDlg::CMergeTwoSortedListDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MERGETWOSORTEDLIST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMergeTwoSortedListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMergeTwoSortedListDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMergeTwoSortedListDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMergeTwoSortedListDlg message handlers

BOOL CMergeTwoSortedListDlg::OnInitDialog()
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

void CMergeTwoSortedListDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMergeTwoSortedListDlg::OnPaint()
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
HCURSOR CMergeTwoSortedListDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMergeTwoSortedListDlg::OnBnClickedButton1()
{
	//------ Initial ...
	CString     Msg_cstr = _T("");
	struct ListNode *New_cs_pr = NULL;
	struct ListNode *l1 = NULL;
	struct ListNode *H1_cs_pr = NULL;
	struct ListNode *T1_cs_pr = NULL;
	struct ListNode *l2 = NULL;
	struct ListNode *H2_cs_pr = NULL;
	struct ListNode *T2_cs_pr = NULL;
	struct ListNode *l3 = NULL;
	int    DataValue_i = 0;
	//-------------------------------

	for (int i_i = 1; i_i <= 3; i_i++)
	{
		New_cs_pr = new struct ListNode();
		New_cs_pr->next = NULL;
		if (i_i == 1)
			DataValue_i = 1;
		else if (i_i == 2)
			DataValue_i = 2;
		else if (i_i == 3)
			DataValue_i = 4;
		New_cs_pr->val = DataValue_i;
		
		if (H1_cs_pr == NULL)
		{
			H1_cs_pr = New_cs_pr;
			T1_cs_pr = New_cs_pr;
		}
		else
		{
			T1_cs_pr->next = New_cs_pr;
			T1_cs_pr = New_cs_pr;
		}
	}
	l1 = H1_cs_pr;
	

	for (int i_i = 1; i_i <= 1; i_i++)
	{
		New_cs_pr = new struct ListNode();
		New_cs_pr->next = NULL;
		if (i_i == 1)
			DataValue_i = 0;
		else if (i_i == 2)
			DataValue_i = 3;
		else if (i_i == 3)
			DataValue_i = 4;
		New_cs_pr->val = DataValue_i;

		if (H2_cs_pr == NULL)
		{
			H2_cs_pr = New_cs_pr;
			T2_cs_pr = New_cs_pr;
		}
		else
		{
			T2_cs_pr->next = New_cs_pr;
			T2_cs_pr = New_cs_pr;
		}
	}
	l2 = H2_cs_pr;

	l1 = NULL;
	l3 = mergeTwoLists(l1, l2);
}
