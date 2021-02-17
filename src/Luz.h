#pragma once

#include <wingdi.h>
#include <Windows.h>
#include <stdio.h>
#include <cmath>

namespace LuzMath{

    namespace Misc{

         /// Populates an Array of Size N with a sequence of N triangle numbers
        void GenerateNTriangularNumbers(int n, int* array){
            int current = 0;
            int toAdd = 1;
        
            for (int i = 0; i < n; i++){
                current += toAdd;
                array[i] = current;
                toAdd++;
            }
        }

        /// Returns the Nth Triangular Number
        int GetNthTriangularNumber(int n){
            return (n * (n + 1)) / 2;
        }
    }
}

namespace LWinAPI{

    // Returns 0 when the window could not be found, otherwise returns a handle to the process matched by the window title.
    HANDLE GetHandleFromTitle(const char* title){
        HWND hWnd = FindWindowA(NULL, (LPCSTR)title);
        DWORD PID;
        GetWindowThreadProcessId(hWnd, &PID);

        HANDLE proc = OpenProcess(PROCESS_ALL_ACCESS, 0, PID);

        if (proc){
            return proc;
        }else{
            return 0;
        }
    }

    // Returns 0 if the Window could not be found.
    DWORD GetPIDFromTitle(const char* title){
        HWND hWnd = FindWindowA(NULL, (LPCSTR)title);
        DWORD PID = 0;

        GetWindowThreadProcessId(hWnd, &PID);

        if (PID){
            return PID;
        }else{
            return 0;
        }


    }

    // Returns a handle to a window. Allows for customization with Window Messages
    HWND LCreateWindow(const char* title, int width, int height, HINSTANCE hInstance, WNDPROC wndProc){
        
        WNDCLASSW windowClass = {0};
        windowClass.lpszClassName = L"WindowClass";
        windowClass.hInstance = hInstance;
        windowClass.lpfnWndProc = wndProc;
        RegisterClassW(&windowClass);

        HWND window = CreateWindowW(L"WindowClass", (LPCWSTR)title, (WS_BORDER | WS_SIZEBOX | WS_SYSMENU | WS_VISIBLE | WS_MAXIMIZEBOX | WS_MINIMIZEBOX), CW_USEDEFAULT, CW_USEDEFAULT, width, height, NULL, NULL, hInstance, NULL);

        return window;
    }

    // Initiates the message loop, customise in the WNDPROC function. Ensure this function is called last
    int WindowMessageLoop(HWND hWindow){
         MSG msg;
        GetMessage(&msg, hWindow, 0, 0);
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    
       return 0; 
    }

    bool WindowOpen(HWND window){
        return IsWindow(window);
    }

    
    namespace Widgets{
        // Return Window Handle for a button
        HWND LCreateButton(HWND parentWindow, HINSTANCE hInstance, const char* ButtonText, int x, int y){
            return CreateWindowA((LPCSTR)"Button", (LPCSTR)ButtonText, (WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON), x, y, 100, 30, parentWindow, NULL, hInstance, NULL);
        }
    }


    namespace DrawWindowBG{
    
        // Background White
        void BG_WHITE(HWND hwnd){
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
        
            FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW));
            EndPaint(hwnd, &ps);
        }

        // Background Red
        void BG_RED(HWND hwnd){
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            FillRect(hdc, &ps.rcPaint, (HBRUSH)CreateSolidBrush(RGB(255, 0, 0)));
            EndPaint(hwnd, &ps);
        }        
    }
}

namespace Sorts{   
}

