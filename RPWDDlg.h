
// RPWDDlg.h : 头文件
//

#pragma once


// CRPWDDlg 对话框
class CRPWDDlg : public CDHtmlDialog
{
// 构造
public:
	CRPWDDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_RPWD_DIALOG, IDH = IDR_HTML_RPWD_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

	HRESULT OnButtonOK(IHTMLElement *pElement);
	HRESULT OnButtonCancel(IHTMLElement *pElement);

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	DECLARE_DHTML_EVENT_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	// 16
	int length;
	afx_msg void OnEnChangeEdit2();
	CString edit_result;
	afx_msg void OnBnClickedButton1();
	
	int check_lowcaps;
	int check_numbers;
	int check_special;
	int check_upcaps;
};
