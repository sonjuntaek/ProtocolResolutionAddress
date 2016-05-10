// proxyDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "DC_ARP_01.h"
#include "proxyDlg.h"
#include "afxdialogex.h"


// proxyDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(proxyDlg, CDialogEx)

proxyDlg::proxyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(proxyDlg::IDD, pParent)
{

}

proxyDlg::~proxyDlg()
{
}

void proxyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROXY_INTERFACE_COMBO, device);
	DDX_Control(pDX, IDC_PROXY_IPADDRESS_BOX, proxyIPAddr);
	DDX_Control(pDX, IDC_PROXY_ETHERNET_ADDRESS_EDIT, proxyEthAddr);
}


BEGIN_MESSAGE_MAP(proxyDlg, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &proxyDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &proxyDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// proxyDlg 메시지 처리기입니다.


void proxyDlg::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnCancel();
}


void proxyDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int n = device.GetCurSel();
	device.GetLBText(n,selectedDevice);
	proxyIPAddr.GetAddress(proxyIPAddrString[0],proxyIPAddrString[1],proxyIPAddrString[2],proxyIPAddrString[3]);
	proxyEthAddr.GetWindowText(proxyMACAddr);
	CDialogEx::OnOK();
}
