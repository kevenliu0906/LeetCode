
// List_AddTwoNumDlg.cpp : implementation file
//

#include "stdafx.h"
#include "List_AddTwoNum.h"
#include "List_AddTwoNumDlg.h"
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


// CList_AddTwoNumDlg dialog



CList_AddTwoNumDlg::CList_AddTwoNumDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_LIST_ADDTWONUM_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CList_AddTwoNumDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CList_AddTwoNumDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CList_AddTwoNumDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CList_AddTwoNumDlg message handlers

BOOL CList_AddTwoNumDlg::OnInitDialog()
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

void CList_AddTwoNumDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CList_AddTwoNumDlg::OnPaint()
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
HCURSOR CList_AddTwoNumDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CList_AddTwoNumDlg::OnBnClickedButton1()
{
	//----- Initial ...
	CString     Msg_cstr = _T("");
	struct ListNode *P1 = NULL;
	struct ListNode *P2 = NULL;
	struct ListNode *P3 = NULL;
	struct ListNode *NewListNode_pr = NULL;
	struct ListNode *Head_pr = NULL;
	struct ListNode *Tail_pr = NULL;

	//-------------------------

	//--> create P1 list data
	NewListNode_pr = new struct ListNode();
	NewListNode_pr->next = NULL;
	NewListNode_pr->val = 9;
	P1 = NewListNode_pr;

	//--> create P2 listdata
	for (int i_i = 1; i_i <= 10; i_i++)
	{
		NewListNode_pr = new struct ListNode();
		NewListNode_pr->next = NULL;
		if (i_i == 1)
		{
			NewListNode_pr->val = 1;
			Head_pr = NewListNode_pr;
			Tail_pr = NewListNode_pr;
		}
		else
		{
			NewListNode_pr->val = 9;
			Tail_pr->next = NewListNode_pr;
			Tail_pr = NewListNode_pr;
		}
	}

	P2 = Head_pr;

	struct ListNode *TempData_pr = NULL;
	int TempDataValue_i = 0;
	TempData_pr = P2;
	for (int i_i = 1; i_i <= 10; i_i++)
	{
		TempDataValue_i = TempData_pr->val;
		TempData_pr = TempData_pr->next;
	}
	
	P3 = addTwoNumbers(P1, P2);

	delete (P1);
	
}
