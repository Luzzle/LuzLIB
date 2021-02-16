#pragma once

#include <Windows.h>
#include <stdio.h>

namespace LuzMath{

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


namespace LWinAPI{

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
}
