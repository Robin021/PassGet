
// RPWDDlg.h : ͷ�ļ�
//

#pragma once


// CRPWDDlg �Ի���
class CRPWDDlg : public CDHtmlDialog
{
// ����
public:
	CRPWDDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_RPWD_DIALOG, IDH = IDR_HTML_RPWD_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

	HRESULT OnButtonOK(IHTMLElement *pElement);
	HRESULT OnButtonCancel(IHTMLElement *pElement);

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
