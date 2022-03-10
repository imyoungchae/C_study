// MFCApplication1View.cpp: CMFCApplication1View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MFCApplication1.h"
#endif

#include "MFCApplication1Doc.h"
#include "MFCApplication1View.h"
#define		STEP 10
#define		R	50 //원의 반지름 설정 가능

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication1View

IMPLEMENT_DYNCREATE(CMFCApplication1View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication1View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_DESTROY()
	ON_WM_LBUTTONDOWN()
	ON_WM_SIZE()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMFCApplication1View 생성/소멸

CMFCApplication1View::CMFCApplication1View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.
	nX = nY = R;
	nMx = nMy = STEP;
	nX = 0;
	nY = 0;
	nMx = 0;
	nMy = 0;
}

CMFCApplication1View::~CMFCApplication1View()
{
}

BOOL CMFCApplication1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMFCApplication1View 그리기

void CMFCApplication1View::OnDraw(CDC* pDC)
{
	CMFCApplication1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Ellipse(nX - R, nY - R, nX + R, nY + R);
	//색 넣기
	CBrush	brush, * oldBrush;
	brush.CreateSolidBrush(RGB(255, 0, 0));//여기서 색상 설정 가능
	oldBrush = pDC->SelectObject(&brush);
	pDC->Ellipse(nX - R, nY - R, nX + R, nY + R);
	pDC->SelectObject(oldBrush);
	brush.DeleteObject();

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CMFCApplication1View 인쇄

BOOL CMFCApplication1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMFCApplication1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMFCApplication1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMFCApplication1View 진단

#ifdef _DEBUG
void CMFCApplication1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication1Doc* CMFCApplication1View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication1Doc)));
	return (CMFCApplication1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication1View 메시지 처리기


void CMFCApplication1View::OnDestroy()
{
	CView::OnDestroy();
	KillTimer(1);
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}


void CMFCApplication1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	SetTimer(1, 100, NULL);
	CView::OnLButtonDown(nFlags, point);
}


void CMFCApplication1View::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);
	GetClientRect(&m_Rect);
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}


void CMFCApplication1View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	nX += nMx;
	nY += nMy;
	if (nY + R >= m_Rect.bottom)
	{
		nMy = -STEP;
	}

	if (nX + R >= m_Rect.right)
	{
		nMx = -STEP;
	}

	if (nY - R <= m_Rect.top)
	{
		nMy = STEP;
	}
	if (nX- R <= m_Rect.left)
	{
		nMx = STEP;
	}
	Invalidate();

	CView::OnTimer(nIDEvent);
}

/*
1.	프로그램에서 사용되는 WM_TIMER, WM_LBUTTONDOWN, WM_SIZE, WM_DESTORY 메세지 기능

WM_XXX로 시작하는 모든 메시지: 윈도우 메시지

1)WM_TIMER
: 원의 중심 좌표를 가지고 신호에 따라 이동할 단위 거리를 계산한다
경계에 원이 충돌했는지를 검사한다
계산된 위치에 원이 출력되게 화면 출력 함수를 호출한다

2)WM_LBUTTONDOWN
: 마우스 왼쪽을 버튼을 누르면 타이머를 동작시킨다

3)WM_SIZE
: 윈도우 뷰 영역의 경계를 저장한다

4)WM_DESTORY
: 윈도우가 종료될 때 타이머를 해제한다

2.	화면의 사각형 안에서 움직이는 동작에 대한 설명
void CMFCApplication1View::OnTimer(UINT_PTR nIDEvent)
{
	nX += nMx;
	nY += nMy;
	if (nY + R >= m_Rect.bottom)
	{
		nMy = -STEP;
	}//아래쪽에 부딪히면 위쪽으로 튕기도록


	if (nX + R >= m_Rect.right)
	{
		nMx = -STEP;
	}//오른쪽에 부딪히면 왼쪽으로 튕기도록

	if (nY - R <= m_Rect.top)
{
		nMy = STEP;
	}//위쪽에 부딪히면 아래쪽에 튕기도록
	if (nX- R <= m_Rect.left)
	{
		nMx = STEP;
	}//왼쪽에 부딪히면 오른쪽으로 튕기도록
	Invalidate();

	CView::OnTimer(nIDEvent);
}


3.	공안의 색을 바꾸기 위해 어떠한 방법을 적용했는지
void CMFCApplication1View::OnDraw(CDC* pDC)
{
	CMFCApplication1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Ellipse(nX - R, nY - R, nX + R, nY + R);

	//이 밑부분을 추가하여 비어있던 원에 색상을 넣어줌

	CBrush	brush, * oldBrush;
	brush.CreateSolidBrush(RGB(255, 0, 0));//여기서 색상 설정 가능
	oldBrush = pDC->SelectObject(&brush);
	pDC->Ellipse(nX - R, nY - R, nX + R, nY + R);
	pDC->SelectObject(oldBrush);
	brush.DeleteObject();

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}

	OnDraw함수에 이 부분을 추가하여 비어있던 원에 색상을 넣어주었다

	brush.CreateSolidBrush(RGB(a, b, c)); 이 줄에서
a = 빨간색
b = 초록색
c = 파란색
a,b,c 부분에 숫자를 넣어서 색상을 고를 수 있다

*/
