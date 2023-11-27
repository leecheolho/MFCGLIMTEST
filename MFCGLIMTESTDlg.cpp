
// MFCGLIMTESTDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFCGLIMTEST.h"
#include "MFCGLIMTESTDlg.h"
#include "afxdialogex.h"
#include<iostream>
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CMFCGLIMTESTDlg 대화 상자



CMFCGLIMTESTDlg::CMFCGLIMTESTDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCGLIMTEST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCGLIMTESTDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCGLIMTESTDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BTN_CREATE_CIRCLE, &CMFCGLIMTESTDlg::OnBnClickedBtnCreateCircle)
	ON_BN_CLICKED(IDC_BTN_CHANGE_COLOR, &CMFCGLIMTESTDlg::OnBnClickedBtnChangeColor)
	ON_BN_CLICKED(IDC_BTN_CHANGE_CROSS, &CMFCGLIMTESTDlg::OnBnClickedBtnChangeCross)
END_MESSAGE_MAP()


// CMFCGLIMTESTDlg 메시지 처리기

BOOL CMFCGLIMTESTDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	int ParentWidth = 1280;    //부모 다이얼로그 넓이
	int ParentHeight = 700;    //부모 다이얼로그 높이

	srand((unsigned int)(time(NULL)));

	MoveWindow(0, 0, ParentWidth, ParentHeight);   // 부모 다이얼로그 크기 설정
	m_pDlgImage = new CDlgImage;  // 자식 클래스 객체 생성
	m_pDlgImage->Create(IDD_CDlgImage, this); // 포인터로 접근해서 자식 다이얼로그 서로 접근 가능 
	m_pDlgImage->ShowWindow(SW_SHOW);  // 화면에 보여주기

	CFont font;
	font.CreatePointFont(130, _T("맑은 고딕")); // 폰트 및 글자 크기 설정

	// 스태틱 텍스트
	GetDlgItem(IDC_STATIC_RADIUS)->SetFont(&font);
	GetDlgItem(IDC_STATIC_TITLEX)->SetFont(&font);
	GetDlgItem(IDC_STATIC_TITLEY)->SetFont(&font);
	GetDlgItem(IDC_STATIC_CENTERX)->SetFont(&font);
	GetDlgItem(IDC_STATIC_CENTERY)->SetFont(&font);

	GetDlgItem(IDC_STATIC_TITLERED)->SetFont(&font);
	GetDlgItem(IDC_STATIC_TITLEGREEN)->SetFont(&font);
	GetDlgItem(IDC_STATIC_TITLEBLUE)->SetFont(&font);
	GetDlgItem(IDC_STATIC_BACKGROUND)->SetFont(&font);

	GetDlgItem(IDC_STATIC_CROSSRED)->SetFont(&font);
	GetDlgItem(IDC_STATIC_CROSSGREEN)->SetFont(&font);
	GetDlgItem(IDC_STATIC_CROSSBLUE)->SetFont(&font);
	GetDlgItem(IDC_STATIC_CROSS)->SetFont(&font);

	// 버튼
	GetDlgItem(IDC_BTN_CREATE_CIRCLE)->SetFont(&font);
	GetDlgItem(IDC_BTN_CHANGE_COLOR)->SetFont(&font);
	GetDlgItem(IDC_BTN_CHANGE_CROSS)->SetFont(&font);

	// 에디트 텍스트
	GetDlgItem(IDC_EDIT_RADIUS)->SetFont(&font);
	GetDlgItem(IDC_EDIT_RED)->SetFont(&font);
	GetDlgItem(IDC_EDIT_GREEN)->SetFont(&font);
	GetDlgItem(IDC_EDIT_BLUE)->SetFont(&font);

	GetDlgItem(IDC_EDIT_CROSSRED)->SetFont(&font);
	GetDlgItem(IDC_EDIT_CROSSGREEN)->SetFont(&font);
	GetDlgItem(IDC_EDIT_CROSSBLUE)->SetFont(&font);

	font.Detach();

	// 컨트롤과 멤버 변수 연결
	TextCenterX.SubclassDlgItem(IDC_STATIC_CENTERX, this);
	TextCenterY.SubclassDlgItem(IDC_STATIC_CENTERY, this);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCGLIMTESTDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCGLIMTESTDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCGLIMTESTDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCGLIMTESTDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.

	delete m_pDlgImage;
}


void CMFCGLIMTESTDlg::OnBnClickedBtnCreateCircle()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString Radius;
	GetDlgItemText(IDC_EDIT_RADIUS, Radius);

	if (Radius.IsEmpty())
	{
		// 하나라도 비어 있다면 메시지를 표시하고 리턴
		AfxMessageBox(_T("Radius 값을 입력하세요."), MB_OK | MB_ICONWARNING);
		return;
	}

	// CString을 정수로 변환
	nRadius = _ttoi(Radius);

	m_pDlgImage->InitImage();
	DrawCircle();
	Crosschange();
}

// 원 생성(노란색)
void CMFCGLIMTESTDlg::DrawCircle()
{
	if (nRadius <= 0)  // 반지름이 0이하 일 때
	{
		return;
	}

	unsigned char* fm = (unsigned char*)m_pDlgImage->m_image.GetBits();
	int nWidth = m_pDlgImage->m_image.GetWidth();
	int nHeight = m_pDlgImage->m_image.GetHeight();
	int nPitch = m_pDlgImage->m_image.GetPitch();
	int WhiteRGB = 255;  // 처음 배경 화면(흰색)


	// 노란색 원이 이미지 안에 생성되게 하게끔 중심좌표(X, Y) 설정
	nCenterX = rand() % (nWidth - 2 * nRadius) + nRadius;  
	nCenterY = rand() % (nHeight - 2 * nRadius) + nRadius;


	// 중심좌표를 해당 에디터 컨트롤에 나타낸다.
	CString strCenterX, strCenterY;
	strCenterX.Format(_T("%d"), nCenterX);
	strCenterY.Format(_T("%d"), nCenterY);
	TextCenterX.SetWindowText(strCenterX);
	TextCenterY.SetWindowText(strCenterY);

	std::cout << "중심좌표X:" << nCenterX << std::endl;
	std::cout << "중심좌표Y:" << nCenterY << std::endl;

	CDC* pDC = m_pDlgImage->GetDC();
	CPen pen;
	pen.CreatePen(PS_SOLID, 10, RGB(0xff, 0xff, 0x00));
	pDC->SelectObject(&pen);

	//  처음 배경을 하얀색 배경으로 하기 위함
	if (colorcnt == 1)
	{
		pDC->FillSolidRect(0, 0, m_pDlgImage->m_image.GetWidth(), m_pDlgImage->m_image.GetHeight(), RGB(WhiteRGB, WhiteRGB, WhiteRGB));   // 흰색 화면으로 초기화
	}

	// 배경 이미지가 변경될 때
	else if (colorcnt == 2)
	{
		pDC->FillSolidRect(0, 0, m_pDlgImage->m_image.GetWidth(), m_pDlgImage->m_image.GetHeight(), RGB(nRed, nGreen, nBlue));   // 흰색 화면으로 초기화
	}
	pDC->Ellipse(nCenterX - nRadius, nCenterY - nRadius, nCenterX + nRadius, nCenterY + nRadius);
	m_pDlgImage->ReleaseDC(pDC);
}

// 이미지 색 변경 이벤트 함수
void CMFCGLIMTESTDlg::OnBnClickedBtnChangeColor()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CString TextRed;
	CString TextGreen;
	CString TextBlue;
	GetDlgItemText(IDC_EDIT_RED, TextRed);
	GetDlgItemText(IDC_EDIT_GREEN, TextGreen);
	GetDlgItemText(IDC_EDIT_BLUE, TextBlue);

	if (TextRed.IsEmpty() || TextGreen.IsEmpty() || TextBlue.IsEmpty())
	{
		// 하나라도 비어 있다면 메시지를 표시하고 리턴
		AfxMessageBox(_T("Red, Green, Blue의 값을 모두 입력하세요."), MB_OK | MB_ICONWARNING);
		return;
	}

	// CString을 정수로 변환
	nRed = _ttoi(TextRed);
	nGreen = _ttoi(TextGreen);
	nBlue = _ttoi(TextBlue);

	
	CDC* pDC = m_pDlgImage->GetDC();
	pDC->FillSolidRect(0, 0, m_pDlgImage->m_image.GetWidth(), m_pDlgImage->m_image.GetHeight(), RGB(nRed, nGreen, nBlue));   // 흰색 화면으로 초기화
	m_pDlgImage->ReleaseDC(pDC);
	colorcnt = 2;
	BackCircle();
	Crosschange();
}

// 십자가 색 변경 이벤트 함수
void CMFCGLIMTESTDlg::OnBnClickedBtnChangeCross()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	GetDlgItemText(IDC_EDIT_CROSSRED, CrossRed);
	GetDlgItemText(IDC_EDIT_CROSSGREEN, CrossGreen);
	GetDlgItemText(IDC_EDIT_CROSSBLUE, CrossBlue);

	// CString을 정수로 변환
	nCrossRed = _ttoi(CrossRed);
	nCrossGreen = _ttoi(CrossGreen);
	nCrossBlue = _ttoi(CrossBlue);

	if (CrossRed.IsEmpty() || CrossGreen.IsEmpty() || CrossBlue.IsEmpty())
	{
		// 하나라도 비어 있다면 메시지를 표시하고 리턴
		AfxMessageBox(_T("Red, Green, Blue의 값을 모두 입력하세요."), MB_OK | MB_ICONWARNING);
		return;
	}
	CDC* pDC = m_pDlgImage->GetDC();
	CPen pen;
	pen.CreatePen(PS_SOLID, nSize, RGB(nCrossRed, nCrossGreen, nCrossBlue));
	pDC->SelectObject(&pen);
	pDC->MoveTo(nCenterX - nDistance, nCenterY);
	pDC->LineTo(nCenterX + nDistance + 1, nCenterY);
	pDC->MoveTo(nCenterX, nCenterY - nDistance);
	pDC->LineTo(nCenterX, nCenterY + nDistance + 1);
	m_pDlgImage->ReleaseDC(pDC);
}


// 배경 이미지를 변경할 때 생성된 십자가가 그대로 남아있게 하기 위함
void CMFCGLIMTESTDlg::Crosschange()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	GetDlgItemText(IDC_EDIT_CROSSRED, CrossRed);
	GetDlgItemText(IDC_EDIT_CROSSGREEN, CrossGreen);
	GetDlgItemText(IDC_EDIT_CROSSBLUE, CrossBlue);
	// CString을 정수로 변환
	nCrossRed = _ttoi(CrossRed);
	nCrossGreen = _ttoi(CrossGreen);
	nCrossBlue = _ttoi(CrossBlue);

	CDC* pDC = m_pDlgImage->GetDC();
	CPen pen;
	pen.CreatePen(PS_SOLID, nSize, RGB(nCrossRed, nCrossGreen, nCrossBlue));
	pDC->SelectObject(&pen);
	pDC->MoveTo(nCenterX - nDistance, nCenterY);
	pDC->LineTo(nCenterX + nDistance + 1, nCenterY);
	pDC->MoveTo(nCenterX, nCenterY - nDistance);
	pDC->LineTo(nCenterX, nCenterY + nDistance + 1);
	m_pDlgImage->ReleaseDC(pDC);
}



// 배경 이미지를 변경할 때 생성된 원 그대로 남아있게 하기 위함
void CMFCGLIMTESTDlg::BackCircle()
{
	unsigned char* fm = (unsigned char*)m_pDlgImage->m_image.GetBits();
	int nWidth = m_pDlgImage->m_image.GetWidth();
	int nHeight = m_pDlgImage->m_image.GetHeight();
	int nPitch = m_pDlgImage->m_image.GetPitch();
	int WhiteRGB = 255;  // 처음 배경 화면(흰색)

	
	// 중심좌표를 해당 에디터 컨트롤에 나타낸다.
	CString strCenterX, strCenterY;
	strCenterX.Format(_T("%d"), nCenterX);
	strCenterY.Format(_T("%d"), nCenterY);
	TextCenterX.SetWindowText(strCenterX);
	TextCenterY.SetWindowText(strCenterY);



	CDC* pDC = m_pDlgImage->GetDC();
	CPen pen;
	pen.CreatePen(PS_SOLID, 10, RGB(0xff, 0xff, 0x00));
	pDC->SelectObject(&pen);

	//  처음 배경을 하얀색 배경으로 하기 위함
	if (colorcnt == 1)
	{
		pDC->FillSolidRect(0, 0, m_pDlgImage->m_image.GetWidth(), m_pDlgImage->m_image.GetHeight(), RGB(WhiteRGB, WhiteRGB, WhiteRGB));   // 흰색 화면으로 초기화
	}

	// 배경 이미지가 변경될 때
	else if (colorcnt == 2)
	{
		pDC->FillSolidRect(0, 0, m_pDlgImage->m_image.GetWidth(), m_pDlgImage->m_image.GetHeight(), RGB(nRed, nGreen, nBlue));   // 흰색 화면으로 초기화
	}
	pDC->Ellipse(nCenterX - nRadius, nCenterY - nRadius, nCenterX + nRadius, nCenterY + nRadius);
	m_pDlgImage->ReleaseDC(pDC);
}