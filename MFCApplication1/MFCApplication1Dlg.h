// MFCApplication1Dlg.h: 헤더 파일
//

#pragma once

#include "afxwin.h" // MFC 관련 헤더 파일을 포함합니다.

// CMFCApplication1Dlg 대화 상자
class CMFCApplication1Dlg : public CDialogEx
{
	// 생성입니다.
public:
	CMFCApplication1Dlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.

private:
	double resultValue;
	bool isOverflow = false;
	bool isOperatorClickable;
	//7/31
	double lastResult; // 이전에 계산된 결과를 저장할 변수
	bool isFraction;  // 현재 결과가 분수 형태인지 여부를 저장하는 변수
	double Calculate(double num1, double num2, int sign);



	// 대화 상자 데이터입니다.
protected: // 이유 알기
	// ... (이전에 있는 코드들)
	double previousResult = 0.0;// 이유 알기
	bool isPreviousResult = false;// 이유 알기
	double secondInputValue = 0.0; // 두 번째 입력한 값을 저장하는 변수// 이유 알기
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);   // DDX/DDV 지원입니다.


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
	int angelCount;  // = 을 눌렀을때 
	int calCount;  // 플러스 마이너스 곱하기 나누기
	double result;
	double OneData;  //int 형이 내가 숫자형이여서 소수점 출력이 안됨 그래서 더블을 사용해씅ㅁ
	double TwoData;
	int Sign;   // 1= 플러스, 2 = 마이너스, 3 = 곱하기 ,4 = 나누기
	int tempSign;     //  사인이랑 똑같이 1= 플러스, 2 = 마이너스, 3 = 곱하기 ,4 = 나누기
	bool changCheck;
	CString ViewStrData;
	double min;
	//7월31일
	int prevSign; //	이전 연산자의 기호를 추적하기 위한 변수
public:
	void PGSTART();
	void ResultViewFn(int numberDate, int  Mode = 1); //Mode = 0일때는 초기화





public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton0();
	//여기까지는 숫자

	afx_msg void OnStnClickedStaticView();
	//결과값 화면 텍스트
	afx_msg void OnBnClickedButtonPlus();
	afx_msg void OnBnClickedButtonMinus();
	afx_msg void OnBnClickedButtonMulti();
	afx_msg void OnBnClickedButtonDiv();
	// 나누기 더하기 빼기 플러스  
	afx_msg void OnBnClickedButton1004();
	// 결과과 도출 버튼

	afx_msg void OnBnClickedButtonReset();
	//초기화 버튼
	afx_msg void OnBnClickedButtonClear();
	//초기화 버튼 만들기 


	afx_msg void OnBnClickedButtonResul2();
	afx_msg void OnBnClickedButtonrute();


	afx_msg void OnBnClickedButtonZegops();
	afx_msg void OnBnClickedButton();
	afx_msg void OnBnClickedButtonDecimal();
	afx_msg void OnBnClickedButtonpusel();
	afx_msg void OnBnClickedButtonBoonsu();


	afx_msg void cal();

};