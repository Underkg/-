
// MFCApplication1Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"
#include <math.h>

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


// CMFCApplication1Dlg 대화 상자



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
    : CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
{
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

    Sign = 0; // Sign 변수를 0으로 초기화
    tempSign = 0;
    lastResult = 0.0;    // 초기에는 이전 결과가 없으므로 0으로 초기화합니다.
    isFraction = false; // 초기에는 소수점 형태의 결과이므로 false로 초기화합니다.
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
    ON_WM_SYSCOMMAND()
    ON_WM_PAINT()
    ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_BUTTON0, &CMFCApplication1Dlg::OnBnClickedButton0)
    ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication1Dlg::OnBnClickedButton1)
    ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication1Dlg::OnBnClickedButton2)
    ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication1Dlg::OnBnClickedButton3)
    ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication1Dlg::OnBnClickedButton4)
    ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication1Dlg::OnBnClickedButton5)
    ON_BN_CLICKED(IDC_BUTTON6, &CMFCApplication1Dlg::OnBnClickedButton6)
    ON_BN_CLICKED(IDC_BUTTON7, &CMFCApplication1Dlg::OnBnClickedButton7)
    ON_BN_CLICKED(IDC_BUTTON8, &CMFCApplication1Dlg::OnBnClickedButton8)
    ON_BN_CLICKED(IDC_BUTTON9, &CMFCApplication1Dlg::OnBnClickedButton9)
    ON_STN_CLICKED(IDC_STATIC_VIEW, &CMFCApplication1Dlg::OnStnClickedStaticView)
    ON_BN_CLICKED(IDC_BUTTON_PLUS, &CMFCApplication1Dlg::OnBnClickedButtonPlus)
    ON_BN_CLICKED(IDC_BUTTON_MINUS, &CMFCApplication1Dlg::OnBnClickedButtonMinus)
    ON_BN_CLICKED(IDC_BUTTON_MULTI, &CMFCApplication1Dlg::OnBnClickedButtonMulti)
    ON_BN_CLICKED(IDC_BUTTON_DIV, &CMFCApplication1Dlg::OnBnClickedButtonDiv)
    ON_BN_CLICKED(IDC_BUTTON_1004, &CMFCApplication1Dlg::OnBnClickedButton1004)
    ON_BN_CLICKED(IDC_BUTTON_RESET, &CMFCApplication1Dlg::OnBnClickedButtonReset)
    ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CMFCApplication1Dlg::OnBnClickedButtonClear)

    ON_BN_CLICKED(IDC_BUTTON_RESUL2, &CMFCApplication1Dlg::OnBnClickedButtonResul2)
    ON_BN_CLICKED(IDC_BUTTON_rute, &CMFCApplication1Dlg::OnBnClickedButtonrute)

    ON_BN_CLICKED(IDC_BUTTON_ZEGOPS, &CMFCApplication1Dlg::OnBnClickedButtonZegops)
    ON_BN_CLICKED(IDC_BUTTON__DECIMAL, &CMFCApplication1Dlg::OnBnClickedButton)
    ON_BN_CLICKED(IDC_BUTTON_Decimal, &CMFCApplication1Dlg::OnBnClickedButtonDecimal)
    ON_BN_CLICKED(IDC_BUTTON_pusel, &CMFCApplication1Dlg::OnBnClickedButtonpusel)
    ON_BN_CLICKED(IDC_BUTTON_BOONSU, &CMFCApplication1Dlg::OnBnClickedButtonBoonsu)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 메시지 처리기

BOOL CMFCApplication1Dlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();
    CFont font;
    //this->SetWindowText("계산기"); //제목 이름 

    font.CreatePointFont(170, "굴림");
    GetDlgItem(IDC_STATIC_VIEW)->SetFont(&font);
    font.Detach();


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
    SetIcon(m_hIcon, TRUE);         // 큰 아이콘을 설정합니다.
    SetIcon(m_hIcon, FALSE);      // 작은 아이콘을 설정합니다.

    // TODO: 여기에 추가 초기화 작업을 추가합니다.
    // 내가 작성
    PGSTART();


    return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCApplication1Dlg::OnPaint()
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
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
    return static_cast<HCURSOR>(m_hIcon);
}
void CMFCApplication1Dlg::PGSTART() {
    result = 0;
    angelCount = 0;
    OneData = 0;
    TwoData = 0;
    calCount = 0;
    min = 0;
    //////여기에 작성 하는게 맞나?? 작성하는거 두개 뿐임 
    ViewStrData = "";
    changCheck = false;



    ResultViewFn(0, 0);
}


void CMFCApplication1Dlg::OnBnClickedButton1()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

    ResultViewFn(1);
}


void CMFCApplication1Dlg::OnBnClickedButton2()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

    ResultViewFn(2);
}


void CMFCApplication1Dlg::OnBnClickedButton3()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

    ResultViewFn(3);
}


void CMFCApplication1Dlg::OnBnClickedButton4()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

    ResultViewFn(4);
}


void CMFCApplication1Dlg::OnBnClickedButton5()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

    ResultViewFn(5);
}


void CMFCApplication1Dlg::OnBnClickedButton6()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

    ResultViewFn(6);
}


void CMFCApplication1Dlg::OnBnClickedButton7()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

    ResultViewFn(7);
}


void CMFCApplication1Dlg::OnBnClickedButton8()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

    ResultViewFn(8);
}


void CMFCApplication1Dlg::OnBnClickedButton9()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

    ResultViewFn(9);
}

void CMFCApplication1Dlg::OnBnClickedButton0()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

    ResultViewFn(0);
}





void CMFCApplication1Dlg::OnStnClickedStaticView()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

}


void CMFCApplication1Dlg::ResultViewFn(int numberDate, int Mode) {  //숫자 버튼 눌렀을때 숫자 표시
    CString Temp;
    if (Mode == 0) {
        // 처음 입력 시 받는 시작하는 식
        Temp.Format("%d", numberDate);
    }
    else {
        GetDlgItem(IDC_STATIC_VIEW)->GetWindowTextA(Temp);
        if (Temp == "0" || changCheck == true) {
            changCheck = false;
            Temp.Format("%d", numberDate);
        }
        else {
            Temp.AppendFormat("%d", numberDate);
        }
    }

    // Check if it's a decimal number and limit it to 16 decimal places
    int decimalPos = Temp.Find('.');
    if (decimalPos != -1 && Temp.GetLength() - decimalPos - 1 > 16) {
        Temp = Temp.Left(decimalPos + 17);
    }

    // Check if it's an integer and limit it to 16 digits
    if (Temp.Find('.') == -1 && Temp.GetLength() > 16) {
        Temp = Temp.Left(16);
    }

    if (Sign == 0) {
        // 부호 선택 전 값
        OneData = atof(Temp);
    }
    else {
        TwoData = atof(Temp);
    }
    if (isOverflow) {
        // 오버플로우 메시지가 보이는 경우에는 숫자를 입력하면 오버플로우 메시지가 사라집니다.
        Temp.Format("%d", numberDate); // 템프에 넣는다.
        isOverflow = false; // 오버플로우 플래그를 다시 false로 설정합니다.
    }
    GetDlgItem(IDC_STATIC_VIEW)->SetWindowTextA(Temp);
}


void CMFCApplication1Dlg::OnBnClickedButtonPlus()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    Sign = 1;
    changCheck = true;
    prevSign = Sign;
    GetDlgItem(IDC_STATIC_VIEW)->GetWindowTextA(ViewStrData);
    CString temp;

    if (OneData != 0 && TwoData != 0  ) {
        if (calCount == 0 && angelCount == 0 && tempSign == 0) { // 0은 계산은 안했다는 경우 
            result = OneData + TwoData;
            //여기에 칼 ++이있었는데 10*2+ 했을때 10*2 하고 더해줘야되는데 
        } 
        else { // 전에 계산 된게 +
            cal();
        }
       

        if (result == static_cast<int>(result)) {
            temp.Format("%.0f", result); // 결과가 정수인 경우 정수 형식
            //printf("%.0f", 12.34);라고 하면, 출력 결과는 12가 된다.
            //소수점 이하 자릿수를 0으로 설정하여 실수를 정수 형태로 출력함
        }
        else {
            temp.Format("%.2f", result); // 그렇지 않은 경우 소수점 이하 두 자리로 서식 지정
            // 코드에서 printf("%.2f", 12.345);라고 하면, 출력 결과는 12.35가 되는데
            //소수점 이하 두 자리까지만 표시하여 숫자를 반올림하게 된다
        }
        /*
        
        */
        SetDlgItemText(IDC_STATIC_VIEW, temp);
    }
    else {
        // 이전 연산을 위해 beforeData를 결과 값으로 설정
        CString temp;
        GetDlgItemText(IDC_STATIC_VIEW, temp);
        OneData = atof(temp);
    }
    TwoData = 0;
    tempSign = 1;  //1 플러스 2 마이너스
    calCount++;// 다끝나고하게
}

void CMFCApplication1Dlg::cal() {
    if (tempSign == 1) {
        if (calCount <= 1) {  //원 +투 해야만 칼이 올라가는데 누르기만해도 올라가니까 0이 될수 없다.
            result = OneData + TwoData;
            calCount++;  //
        }
        else {
            result += TwoData;
        }
    }
    else if (tempSign == 2) {
        if (calCount <= 1) {
            result = OneData - TwoData;
            calCount++;
        }
        else {
            result -= TwoData;
        }
    }
    else if (tempSign == 3) {
        if (calCount <= 1) {
            result = OneData * TwoData;
            calCount++;
        }
        else {
            result *= TwoData;
        }
    }
    else if (tempSign == 4) {
        if (calCount <= 1) {
            result = OneData / TwoData;
            calCount++;
        }
        else {
            result /= TwoData;
        }
    }
} 





// 나머지 연산자 버튼(Minus, Multi, Div)에 대해서도 OnBnClickedButtonPlus()와 비슷한 방식으로 수정해주어야 합니다.
void CMFCApplication1Dlg::OnBnClickedButtonMinus()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    Sign = 2;
    changCheck = true;
    prevSign = Sign;
    GetDlgItem(IDC_STATIC_VIEW)->GetWindowTextA(ViewStrData);
    CString temp;

    if (OneData != 0 && TwoData != 0) {
        if (calCount == 0 && angelCount == 0 && tempSign == 0) {
            result = OneData - TwoData;
           
        }
        else { // 전에 계산 된게 +
            cal();
        }

        if (result == static_cast<int>(result)) {
            temp.Format("%.0f", result); // 결과가 정수인 경우 정수 형식
        }
        else {
            temp.Format("%.2f", result); // 그렇지 않은 경우 소수점 이하 두 자리로 서식 지정
        }
        SetDlgItemText(IDC_STATIC_VIEW, temp);
    }
    else {
        // 이전 연산을 위해 beforeData를 결과 값으로 설정
        CString temp;
        GetDlgItemText(IDC_STATIC_VIEW, temp);
        OneData = atof(temp);
    }
    TwoData = 0;
    tempSign = 2;
    calCount++;
}

void CMFCApplication1Dlg::OnBnClickedButtonMulti()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    Sign = 3;
    changCheck = true;
    prevSign = Sign;
    GetDlgItem(IDC_STATIC_VIEW)->GetWindowTextA(ViewStrData);
    CString temp;

    if (OneData != 0 && TwoData != 0) {
        if (calCount == 0 && angelCount == 0) {
            result = OneData * TwoData; // 수정된 부분: 곱셈 연산 추가
          
        }
        else {
            cal();
        }


        if (result == static_cast<int>(result)) {
            temp.Format("%.0f", result); // 결과가 정수인 경우 정수 형식
        }
        else {
            temp.Format("%0.16G", result); // 그렇지 않은 경우 소수점 이하 두 자리로 서식 지정
        }
        SetDlgItemText(IDC_STATIC_VIEW, temp);
    }
    else {
        // 이전 연산을 위해 beforeData를 결과 값으로 설정
        CString temp;
        GetDlgItemText(IDC_STATIC_VIEW, temp);
        OneData = atof(temp);
    }
    TwoData = 0;
    tempSign = 3;
    calCount++;
}

void CMFCApplication1Dlg::OnBnClickedButtonDiv()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    Sign = 4;
    changCheck = true;
    prevSign = Sign;
    GetDlgItem(IDC_STATIC_VIEW)->GetWindowTextA(ViewStrData);
    CString temp;

    if (OneData != 0 && TwoData != 0) {
        if (calCount == 0 && angelCount == 0) {
            result = OneData / TwoData; // 수정된 부분: 나눗셈 연산 추가

        }
        else {
            cal();
        }

        if (result == static_cast<int>(result)) {
            temp.Format("%.0f", result); // 결과가 정수인 경우 정수 형식
        }
        else {
            temp.Format("%0.16g", result); // 그렇지 않은 경우 소수점 이하 두 자리로 서식 지정
        }
        SetDlgItemText(IDC_STATIC_VIEW, temp);
    }
    else {
        // 이전 연산을 위해 beforeData를 결과 값으로 설정
        CString temp;
        GetDlgItemText(IDC_STATIC_VIEW, temp);
        OneData = atof(temp);
    }

    TwoData = 0;
    tempSign = 4;
    calCount++;
}


//void CMFCApplication1Dlg::OnBnClickedButton1004()
//{
//   CString temp;
//   GetDlgItemText(IDC_STATIC_VIEW, temp);
//   double result = 0.0;
//
//   beforeData = atof(ViewStrData);
//   AfterData = atof(temp);
//
//   switch (Sign) {
//   case 1:
//      // Addition
//      result = beforeData + AfterData;
//      break;
//   case 2:
//      // Subtraction
//      result = beforeData - AfterData;
//      break;
//   case 3:
//      // Multiplication
//      result = beforeData * AfterData;
//      break;
//   case 4:
//      // Division
//      if (AfterData == 0) {
//         SetDlgItemText(IDC_STATIC_VIEW, "0으로 나눌 수 없습니다");   // X/0 == 나눌수 없다
//         return;      
//      }
//
//      result = static_cast<double>(beforeData) / AfterData;
//      break;
//   }
//
//   if (result == static_cast<int>(result)) {
//      temp.Format("%d", static_cast<int>(result)); // 결과가 정수인 경우 정수 형식
//   }
//   else {                     // 원래 %0.2F를 사용 하면 소수점 2자리 까지 출력 했지만 G를 쓰면서 과학적 표기로 변경 됨         
//      temp.Format("%g", result); // 그렇지 않은 경우  소수점 이하 두 자리로 서식 지정
//   }
//
//   SetDlgItemText(IDC_STATIC_VIEW, temp);
//}




void CMFCApplication1Dlg::OnBnClickedButton1004()
{
    CString temp;
    GetDlgItemText(IDC_STATIC_VIEW, temp);

    switch (Sign) {
    case 1:
        // Addition
        if (result == 0 || result > DBL_MAX) {
            result = OneData + TwoData;

        }
        else {
            result += TwoData;

        }

        break;
    case 2:
        // Subtraction
        if (result == 0 && angelCount == 0 || result > DBL_MAX) {
            result = OneData - TwoData;
            isOverflow = true;
        }
        else {
            result -= TwoData;
        }
        break;
    case 3:
        // Multiplication
        if (result == 0 || result > DBL_MAX) {
            result = OneData * TwoData;
            isOverflow = true;
        }
        else {
            result *= TwoData;

        }

        break;
    case 4:
        // Division
        if (TwoData == 0 || result > DBL_MAX) {
            if (OneData == 0) {
                temp = "값이 정의 되지 않음";
            }
            else {
                temp = "0으로 나눌 수 없음";
            }
            SetDlgItemText(IDC_STATIC_VIEW, temp);
            return;
        }
        if (result == 0 || result > DBL_MAX) {
            result = static_cast<double>(OneData) / TwoData;
            isOverflow = true;
        }
        else {
            result /= TwoData;
        }

        break;


    }

    if (result == static_cast<int>(result)) {
        temp.Format("%.0f", result); // 결과가 정수인 경우 정수 형식
    }
    else {
        temp.Format("%0.16g", result); // 그렇지 않은 경우 소수점 이하 두 자리로 서식 지정  0.16
    }
    angelCount++;
    calCount = 0;
   // TwoData = 0;
    tempSign = 0;//이거 추가함 이걸 내가 추가 한 이유는 저걸 추가 안하니까 부호가 초기화가 안되서 전에 부호가 계산됨
    //result = atof(temp);

    SetDlgItemText(IDC_STATIC_VIEW, temp);
}

void CMFCApplication1Dlg::OnBnClickedButtonReset()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    OneData = 0;
    TwoData = 0;
    result = 0;
    angelCount = 0;
    calCount = 0;
    ViewStrData = "0";
    changCheck = false;



    ResultViewFn(0, 0);
}


void CMFCApplication1Dlg::OnBnClickedButtonResul2()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    OneData = 0;
    TwoData = 0;
    ViewStrData = "0";
    changCheck = false;



    ResultViewFn(0, 0);
}


void CMFCApplication1Dlg::OnBnClickedButtonClear()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    CString str;
    GetDlgItemText(IDC_STATIC_VIEW, str);

    if (str.GetLength() > 1) {
        // 문자열의 길이가 1보다 큰 경우에만 마지막 글자를 삭제합니다.
        str.Delete(str.GetLength() - 1, 1);
    }
    else {
        // 문자열이 "0"인 경우에는 삭제하지 않고 그대로 유지합니다.
        str = "0";
    }

    SetDlgItemText(IDC_STATIC_VIEW, str);
}





void CMFCApplication1Dlg::OnBnClickedButtonrute() // 루트 만드는법
{
    CStringA str;
    GetDlgItemTextA(IDC_STATIC_VIEW, str);

    double value = atof(str);

    double result = sqrt(value);
    str.Format("%g", result);

    SetDlgItemTextA(IDC_STATIC_VIEW, str);

    //이렇게 계속 오류 나왔는데 오류 나온이유가  유니코드(wchar_t)인 반면, CString 객체는 멀티바이트(char)
    //문자열 형식을 사용하고 있기 때문에 오류 발생   L 빼야됨......

    /*
    CString str;
       GetDlgItemText(IDC_STATIC_VIEW, str);

    double value = _wtof(str);

    double result = sqrt(value);
    str.Format(L"%.2f", result);

    SetDlgItemText(IDC_STATIC_VIEW, str);
    */

}



void CMFCApplication1Dlg::OnBnClickedButtonZegops()
{
    CString temp;
    GetDlgItemText(IDC_STATIC_VIEW, temp);
    double value = atof(temp);

    double result = value * value;
    if (result > DBL_MAX) {
        temp = "오버플로우";
        isOverflow = true;
    }
    else {
        temp.Format("%0.16g", result);
    }

    SetDlgItemText(IDC_STATIC_VIEW, temp);
}

// 여기를 수정 하면 될꺼 같은 일단 - 부호가 Sing 2 니까 이 버튼이 누르고
// 숫자를 입력후 - 를 누르면 +로 변환 -누르고 숫자 입력하면 -로 계속 

void CMFCApplication1Dlg::OnBnClickedButton()  //+- 변환 해주는 버튼

{
    CString str;

    GetDlgItemText(IDC_STATIC_VIEW, str);

    if (str.IsEmpty() || str == "0")
        return;

    if (str[0] == '-')
        str = str.Right(str.GetLength() - 1);
    else
        str = "-" + str;

    SetDlgItemText(IDC_STATIC_VIEW, str);


    //TwoData 더블형이고 str= CString 형이므로 변경 해야됨 
    // double TwoData
    // CString ViewStrData;

    if (str[0] == '-') {
        TwoData = atof(str); // 이거의 용어는 atof 를 사용해서 변환 하는 거임
    }

}


void CMFCApplication1Dlg::OnBnClickedButtonDecimal() // 소수점을 만들어주는 코드
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    CString str;
    GetDlgItemText(IDC_STATIC_VIEW, str);

    // 이미 소수점이 있는 경우 무시
    if (str.Find('.') != -1)
        return;

    str += '.';
    SetDlgItemText(IDC_STATIC_VIEW, str);
}


void CMFCApplication1Dlg::OnBnClickedButtonpusel()    // 퍼센트 계산
{
    CString temp;
    GetDlgItemText(IDC_STATIC_VIEW, temp);
    double value = atof(temp);


    double result = value * 0.01;  //퍼센트 계산에서는 0.01을 곱해서 만든다.

    if (result == 0)
        temp = "0";
    else
        temp.Format("%0.2f", result);

    SetDlgItemText(IDC_STATIC_VIEW, temp);

}

void CMFCApplication1Dlg::OnBnClickedButtonBoonsu()
{
    CString temp;
    GetDlgItemText(IDC_STATIC_VIEW, temp);
    double value = atof(temp);

    if (value == 0) {
        temp = "분모는 0이 될 수 없습니다.";
        SetDlgItemText(IDC_STATIC_VIEW, temp);
        return;
    }

    double result = 1 / value; // 분수를 계산하기 위해 1을 값으로 나눕니다.

    if (isFraction) {
        // 이전 결과가 분수 형태였다면, 이번에는 정수 부분만 표시합니다.
        temp.Format("%0.0f", result);
    }
    else {
        // 이전 결과가 소수점 형태였다면, 이번에는 분수 형태로 표시합니다.
        temp.Format("%0.16g", result);
    }

    // 이전 결과가 분수인지 소수점인지 토글합니다.
    isFraction = !isFraction;
    lastResult = result;

    SetDlgItemText(IDC_STATIC_VIEW, temp);
}