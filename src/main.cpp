#include "Luz.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
    switch (uMsg){
        case WM_DESTROY:
            exit(0);

        case WM_PAINT:
            LWinAPI::DrawWindowBG::BG_WHITE(hwnd);
    }
    
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int main(){
    HWND window = LWinAPI::LCreateWindow("Title", 700, 500, GetModuleHandle(0), WndProc);
    
    while (LWinAPI::WindowOpen(window)){
        LWinAPI::WindowMessageLoop(window);
    }
}