
// RPWDDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "RPWD.h"
#include "RPWDDlg.h"
#include "afxdialogex.h"
#include "getRandomPwd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CRPWDDlg �Ի���

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


// CRPWDDlg ��Ϣ�������

BOOL CRPWDDlg::OnInitDialog()
{
	CDHtmlDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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
	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CRPWDDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDHtmlDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
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
		CString errorMsg = _T("������ѡ��һ��!");
			AfxMessageBox(errorMsg);
	}
	
	//TRACE1("%d\n",edit_result.GetLength());
	//TRACE1("%s\n", edit_result);
	//TRACE3("%d,%d,%d\n", check_lowcaps, check_numbers, check_special);
	//AfxMessageBox(check_lowcaps);
	CString source = edit_result;
	if (OpenClipboard())
	{
		//��ֹ��ASCII���Ը��Ƶ����а�Ϊ����
		int buff_size = source.GetLength();
		CStringW strWide = CStringW(source);
		int nLen = strWide.GetLength();
		//�����а��ÿ�
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



