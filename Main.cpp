#include <Windows.h>

#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "user32.lib")

LPCWSTR className = (LPCWSTR)"Round Corner Window";

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR nCmdLine, int nCmdShow)
{
    WNDCLASSEXW windowClass;
    windowClass.cbClsExtra = 0;
    windowClass.cbSize = sizeof(windowClass);
    windowClass.cbWndExtra = 0;
    windowClass.hbrBackground = CreateSolidBrush(RGB(0, 0, 0));
    windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    windowClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    windowClass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    windowClass.hInstance = hInstance;
    windowClass.lpfnWndProc = WndProc;
    windowClass.lpszClassName = className;
    windowClass.lpszMenuName = 0;
    windowClass.style = CS_HREDRAW | CS_VREDRAW;

    if (!RegisterClassExW(&windowClass))
    {
        MessageBoxA(NULL, (LPCSTR)"Failed to register window class", (LPCSTR)"Error", MB_OK | MB_ICONERROR);
        return -1;
    }

    HWND window = CreateWindowExW(WS_EX_APPWINDOW, className, (LPCWSTR)"Round Corners", WS_POPUP | WS_VISIBLE, 200, 200, 500, 500, NULL, NULL, hInstance, NULL);

    MSG msg;

    while (GetMessage(&msg, window, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch(message)
    {
        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hDC = BeginPaint(hWnd, &ps);

            HBRUSH backgroundBrush = CreateSolidBrush(RGB(255, 255, 255));
            FillRect(hDC, &ps.rcPaint, backgroundBrush);

            HRGN windowRgn = CreateRoundRectRgn(0, 0, 500, 500, 20, 20);

            SetWindowRgn(hWnd, windowRgn, TRUE);

            DeleteObject(backgroundBrush);

            EndPaint(hWnd, &ps);

            break;
        }
        case WM_DESTROY:
        {
            PostQuitMessage(0);
            return 0;
        }

        default:
            break;
    }

    return DefWindowProc(hWnd, message, wParam, lParam);
}
