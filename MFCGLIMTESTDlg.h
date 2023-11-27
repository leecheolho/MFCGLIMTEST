
// MFCGLIMTESTDlg.h: 헤더 파일
//
#include "CDlgImage.h"
#pragma once


// CMFCGLIMTESTDlg 대화 상자
class CMFCGLIMTESTDlg : public CDialogEx
{
// 생성입니다.
public:
	CMFCGLIMTESTDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

	CDlgImage* m_pDlgImage;   //자식 인스턴스 만들기
	CStatic TextCenterX;  // 원의 중심 좌표(X)에 대한 멤버 변수
	CStatic TextCenterY;  // 원의 중심 좌표(Y)에 대한 멤버 변수

	int nCenterX;   // 원의 중심좌표X
	int nCenterY;	// 원의 중심좌표Y

	int nRed;    // 배경(빨간색)
	int nGreen;  // 배경(초록색)
	int nBlue;   // 배경(파란색)

	int nCrossRed;   // 십자가(빨간색)
	int nCrossGreen; // 십자가(초록색)
	int nCrossBlue;  // 십자가(파란색)

	int nRadius;   // 반지름

	int colorcnt = 1;   // 처음 백그라운드 이미지는 흰색

	int nDistance = 8;  // 중심좌표로부터 거리
	int nSize = 3; // 십자가 크기

	// 십자가 색깔(빨강, 초록, 파란)
	CString CrossRed;
	CString CrossGreen;
	CString CrossBlue;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCGLIMTEST_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedBtnCreateCircle();

private:
	void DrawCircle();
	void BackCircle();
	void Crosschange();

public:
	afx_msg void OnBnClickedBtnChangeColor();
	afx_msg void OnBnClickedBtnChangeCross();
};
