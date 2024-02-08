// WindowsProject1.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "WindowsProject1.h"
#include <deque>


#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
HBRUSH redBrush, yellowBrush, greenBrush, blackBrush, greyBrush, whiteBrush, pinkBrush;
int trafikkLys = 0;
std::deque<car> bilKoe1;
std::deque<car> bilKoe2;


// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINDOWSPROJECT1, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT1));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}
// Rectangle(hdc, 5, 510, 60, 540);

class car {
public:
    const int topPosisjon = 510;
    const int botPosisjon = 540;
    int venstre = 5;
    int hoyre = 60;
    int plass = 0;
};

//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT1);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

void tegnBiler(HWND hWnd, HDC vdc, int vei) {
    if (vei == 1) {
        bilKoe1.push_front(car());
        Rectangle(vdc, )
    }
    else if (vei == 2) {

    }


}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
static void oppdaterTrafikklys() {
    if (trafikkLys >= 3) {
        trafikkLys = 0;
    }
    else {
        trafikkLys = trafikkLys + 1;
    }
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{

    switch (message)
    {

    case WM_CREATE:
        SetTimer(hWnd, 0, 3000, 0);
        redBrush = CreateSolidBrush(RGB(255, 0, 0));
        yellowBrush = CreateSolidBrush(RGB(255, 255, 0));
        greenBrush = CreateSolidBrush(RGB(0, 255, 0));
        blackBrush = CreateSolidBrush(RGB(0, 0, 0));
        greyBrush = CreateSolidBrush(RGB(128, 128, 128));
        whiteBrush = CreateSolidBrush(RGB(255, 255, 255));
        pinkBrush = CreateSolidBrush(RGB(255, 20, 147));
        break;
    case WM_TIMER:
        oppdaterTrafikklys();
        InvalidateRect(hWnd, 0, true);
        break;
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // Parse the menu selections:
        switch (wmId)
        {
        case IDM_ABOUT:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            break;
        case IDM_EXIT:
            DestroyWindow(hWnd);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        // TODO: Add any drawing code that uses hdc here...

        HGDIOBJ hOrg = SelectObject(hdc, blackBrush);
        Rectangle(hdc, 400, 100, 550, 450);
        Rectangle(hdc, 700, 600, 1050, 750);

        // Lager hdc for nord - sør
        hOrg = SelectObject(hdc, greyBrush);
        Ellipse(hdc, 420, 100, 525, 216);
        Ellipse(hdc, 420, 216, 525, 332);
        Ellipse(hdc, 420, 332, 525, 448);

        // Lager lysene for vest - øst
        Ellipse(hdc, 700, 620, 816, 730);
        Ellipse(hdc, 816, 620, 932, 730);
        Ellipse(hdc, 932, 620, 1050, 730);

        // Lager vei
        Rectangle(hdc, 0, 470, 2000, 580);
        Rectangle(hdc, 570, 0, 680, 2000);


        switch (trafikkLys) {
        case 0:
            // Nord lys
            SelectObject(hdc, redBrush);
            Ellipse(hdc, 420, 100, 525, 216);

            // Vest lys
            SelectObject(hdc, greenBrush);
            Ellipse(hdc, 700, 620, 816, 730);
            break;
        case 1:
            // Nord lys
            SelectObject(hdc, redBrush);
            Ellipse(hdc, 420, 100, 525, 216);
            SelectObject(hdc, yellowBrush);
            Ellipse(hdc, 420, 216, 525, 332);

            // Vest lys
            Ellipse(hdc, 816, 620, 932, 730);
            break;
        case 2:
            // Nord lys
            SelectObject(hdc, greenBrush);
            Ellipse(hdc, 420, 332, 525, 448);

            // Vest lys
            SelectObject(hdc, redBrush);
            Ellipse(hdc, 932, 620, 1050, 730);
            break;
        case 3:
            // Nord lys
            SelectObject(hdc, yellowBrush);
            Ellipse(hdc, 420, 216, 525, 332);
            // Vest lys
            Ellipse(hdc, 816, 620, 932, 730);

            SelectObject(hdc, redBrush);
            Ellipse(hdc, 932, 620, 1050, 730);
            break;
        }

        // Lager svart rektangel
        /*
        HDC vdc = CreateCompatibleDC(hdc);

        RECT screen;
        GetClientRect(hWnd, &screen);

        HBITMAP bmp = CreateCompatibleBitmap(hdc, screen.right, screen.bottom);
        SelectObject(vdc, bmp);
        */
        SelectObject(hdc, pinkBrush);
        Rectangle(hdc, 5, 510, 60, 540);

        /*
        BitBlt(hdc, 0, 0, screen.right, screen.bottom, vdc, 0, 0, SRCCOPY);

        DeleteDC(vdc);
        DeleteObject(bmp);
        */
        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
        PostQuitMessage(0);
        DeleteObject(blackBrush);
        DeleteObject(redBrush);
        DeleteObject(greenBrush);
        DeleteObject(yellowBrush);
        DeleteObject(greyBrush);

        break;
    case WM_LBUTTONDOWN:
        
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
