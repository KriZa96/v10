// RecView.cpp : implementation of the RecView class
//

#include "stdafx.h"
#include "v10.h"

#include "Set.h"
#include "Doc.h"
#include "RecView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// RecView

IMPLEMENT_DYNCREATE(RecView, CRecordView)

BEGIN_MESSAGE_MAP(RecView, CRecordView)
	//{{AFX_MSG_MAP(RecView)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CRecordView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// RecView construction/destruction

RecView::RecView()
	: CRecordView(RecView::IDD)
{
}

RecView::~RecView()
{
}

void RecView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(RecView)
	//}}AFX_DATA_MAP
    DDX_FieldText(pDX, IDC_EDIT1, m_pSet->m_id, m_pSet);
    DDX_FieldText(pDX, IDC_EDIT2, m_pSet->m_name, m_pSet);
    DDX_FieldCheck(pDX, IDC_CHECK1, m_pSet->m_manager, m_pSet);
}

BOOL RecView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CRecordView::PreCreateWindow(cs);
}

void RecView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_set;
	CRecordView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

/////////////////////////////////////////////////////////////////////////////
// RecView printing

BOOL RecView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void RecView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
}

void RecView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
}

/////////////////////////////////////////////////////////////////////////////
// RecView diagnostics

#ifdef _DEBUG
void RecView::AssertValid() const
{
	CRecordView::AssertValid();
}

void RecView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

Doc* RecView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Doc)));
	return (Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// RecView database support
CRecordset* RecView::OnGetRecordset()
{
	return m_pSet;
}


/////////////////////////////////////////////////////////////////////////////
// RecView message handlers

void RecView::OnPrint(CDC* pDC, CPrintInfo* pInfo) {
  const int page_width = pDC->GetDeviceCaps(HORZRES);

  CFont print_font;
  print_font.CreatePointFont(100, _T("Times New Roman"), pDC);
  CFont* previous_font = pDC->SelectObject(&print_font);

  const CSize sample_text_size = pDC->GetTextExtent("Test");
  const int horizontal_margin = sample_text_size.cx;
  const int row_height = sample_text_size.cy * 3;
  int current_y_position = horizontal_margin * 2;

  const int column_id_x = page_width / 12;
  const int column_name_x = column_id_x * 3;
  const int column_manager_x = column_id_x * 7;

  pDC->DrawText(
      _T("Employee ID"),
      CRect(
          column_id_x, 
          current_y_position, 
          column_name_x,
          current_y_position + row_height
      ),
      DT_LEFT
  );

  pDC->DrawText(
      _T("Full Name"),
      CRect(
          column_name_x, 
          current_y_position, 
          column_manager_x,
          current_y_position + row_height
      ),
      DT_LEFT
  );

  pDC->DrawText(
      _T("Is Manager"),
      CRect(
          column_manager_x, 
          current_y_position,
          page_width - horizontal_margin, 
          current_y_position + row_height
      ),
      DT_LEFT
  );

  current_y_position += row_height;

  pDC->MoveTo(horizontal_margin, current_y_position);
  pDC->LineTo(page_width - horizontal_margin, current_y_position);

  current_y_position += sample_text_size.cy;

  Set record_set;
  record_set.Open();

  while (!record_set.IsEOF()) {
    CString string_id;
    string_id.Format(_T("%d"), record_set.m_id);

    pDC->DrawText(
        string_id,
        CRect(
            column_id_x, 
            current_y_position, column_name_x,
            current_y_position + row_height
        ),
         DT_LEFT
    );

    pDC->DrawText(
        record_set.m_name,
        CRect(
            column_name_x,
            current_y_position,
            column_manager_x,
            current_y_position + row_height
        ),
        DT_LEFT
    );

    CString string_is_manager = record_set.m_manager ? _T("Yes") : _T("No");

    pDC->DrawText(
        string_is_manager,
        CRect(
            column_manager_x,
            current_y_position,
            page_width - horizontal_margin,
            current_y_position + row_height
       ),
        DT_LEFT
    );

    current_y_position += row_height;
    record_set.MoveNext();
  }

  pDC->SelectObject(previous_font);
}
