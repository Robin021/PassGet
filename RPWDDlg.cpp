
// RPWDDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "RPWD.h"
#include "RPWDDlg.h"
#include "afxdialogex.h"
#include "getRandomPwd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CRPWDDlg 对话框

BEGIN_DHTML_EVENT_MAP(CRPWDDlg)
	DHTML_EVENT_ONCLICK(_T("ButtonOK"), OnButtonOK)
	DHTML_EVENT_ONCLICK(_T("ButtonCancel"), OnButtonCancel)
END_DHTML_EVENT_MAP()


CRPWDDlg::CRPWDDlg(CWnd* pParent /*=NULL*/)
	: CDHtmlDialog(CRPWDDlg::IDD, CRPWDDlg::IDH, pParent)
	, length(0)
	, edit_result(_T(""))
	, check_upcaps(FALSE)
	, check_lowcaps(FALSE)
	, check_numbers(FALSE)
	, check_special(FALSE)
	
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRPWDDlg::DoDataExchange(CDataExchange* pDX)
{
	CDHtmlDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, length);
	DDV_MinMaxInt(pDX, length, 1, 16);
	DDX_Text(pDX, IDC_EDIT2, edit_result);
	DDX_Check(pDX, IDC_CHECK2, check_lowcaps);
	DDX_Check(pDX, IDC_CHECK3, check_numbers);
	DDX_Check(pDX, IDC_CHECK4, check_special);
	DDX_Check(pDX, IDC_CHECK1, check_upcaps);
}

BEGIN_MESSAGE_MAP(CRPWDDlg, CDHtmlDialog)
	ON_WM_SYSCOMMAND()
	ON_BN_CLICKED(IDC_BUTTON1, &CRPWDDlg::OnBnClickedButton1)

END_MESSAGE_MAP()


// CRPWDDlg 消息处理程序

BOOL CRPWDDlg::OnInitDialog()
{
	CDHtmlDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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
	length = 16;
	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CRPWDDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDHtmlDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CRPWDDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDHtmlDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CRPWDDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

HRESULT CRPWDDlg::OnButtonOK(IHTMLElement* /*pElement*/)
{
	OnOK();
	return S_OK;
}

HRESULT CRPWDDlg::OnButtonCancel(IHTMLElement* /*pElement*/)
{
	OnCancel();
	return S_OK;
}


void CRPWDDlg::OnBnClickedButton1()
{
	CButton* pBtn = (CButton*)GetDlgItem(IDC_CHECK1);
	check_upcaps = pBtn->GetCheck();

	pBtn = (CButton*)GetDlgItem(IDC_CHECK2);
	check_lowcaps = pBtn->GetCheck();

	pBtn = (CButton*)GetDlgItem(IDC_CHECK3);
	check_numbers = pBtn->GetCheck();

	pBtn = (CButton*)GetDlgItem(IDC_CHECK4);
	check_special = pBtn->GetCheck();

	UpdateData(TRUE);

	int pwdType = 0;

	if (check_upcaps ==1)
	{
		if (check_lowcaps == 0 && check_numbers == 0 && check_special ==0 )
		{
			pwdType = 262;
		}
		if (check_lowcaps == 1 && check_numbers == 0 && check_special == 0)
		{
			pwdType = 52;
		}
		if (check_lowcaps == 0 && check_numbers == 1 && check_special==0)
		{
			pwdType = 361;
		}
		if (check_lowcaps == 0 && check_numbers == 0 && check_special == 1)
		{
			pwdType = 351;
		}
		if (check_lowcaps == 1 && check_numbers == 1 && check_special == 0)
		{
			pwdType = 62;
		}
		if (check_lowcaps == 1 && check_numbers == 0 && check_special == 1)
		{
			pwdType = 61;
		}
		if (check_lowcaps == 0 && check_numbers == 1 && check_special == 1)
		{
			pwdType = 452;
		}
		if (check_lowcaps == 1 && check_numbers == 1 && check_special == 1)
		{
			pwdType = 71;
		}
	}
	else
	{
		if (check_lowcaps == 1)
		{
			if (check_numbers == 0 && check_special == 0)
			{
				pwdType = 261;
			}
			if (check_numbers == 1 && check_special == 0)
			{
				pwdType = 362;
			}
			if (check_numbers == 0 && check_special == 1)
			{
				pwdType = 352;
			}
			if (check_numbers == 1 && check_special == 1)
			{
				pwdType = 451;
			}
		}
		else
		{
			if (check_numbers == 1)
			{
				if (check_special == 0)
				{
					pwdType = 10;
				}
				if (check_special == 1)
				{
					pwdType = 19;
				}
			}
			else
			{
				if (check_special ==1)
				{
					pwdType = 9;
				}
				
			}
		}
	}
	bool atLeastOne = false;
	UpdateData(false);
	if (!check_upcaps == 0 || !check_lowcaps == 0 || !check_numbers == 0 || !check_special == 0)
	{
		atLeastOne = true;
	}
	if (atLeastOne)
	{
		edit_result = getCorrectPwd(length, pwdType);
		UpdateData(false);
	}
	else
	{
		CString errorMsg = _T("请至少选择一项!");
			AfxMessageBox(errorMsg);
	}
	
	//TRACE1("%d\n",edit_result.GetLength());
	//TRACE1("%s\n", edit_result);
	//TRACE3("%d,%d,%d\n", check_lowcaps, check_numbers, check_special);
	//AfxMessageBox(check_lowcaps);
	CString source = edit_result;
	if (OpenClipboard())
	{
		//防止非ASCII语言复制到剪切板为乱码
		int buff_size = source.GetLength();
		CStringW strWide = CStringW(source);
		int nLen = strWide.GetLength();
		//将剪切板置空
		::EmptyClipboard();
		HANDLE clipbuffer = ::GlobalAlloc(GMEM_DDESHARE, (nLen + 1) * 2);
		if (!clipbuffer)
		{
			::CloseClipboard();
			return;
		}
		char* buffer = (char*)::GlobalLock(clipbuffer);
		memset(buffer, 0, (nLen + 1) * 2);
		memcpy_s(buffer, nLen * 2, strWide.GetBuffer(0), nLen * 2);
		strWide.ReleaseBuffer();
		::GlobalUnlock(clipbuffer);
		::SetClipboardData(CF_UNICODETEXT, clipbuffer);
		::CloseClipboard();
	}

	
}



