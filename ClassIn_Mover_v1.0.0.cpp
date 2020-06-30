#include <cstdio>
#include <ctime>
#include <windows.h>

HWND ClassroomHwnd;
bool FoundWindow;

BOOL CALLBACK RefreshWindow(HWND hwnd, LPARAM Title)
{
    time_t tmp = time(0);
    tm *now = localtime(&tmp);
    TCHAR caption[1024];
    memset(caption, 0, sizeof(caption));
    GetWindowText(hwnd, caption, 1024);
    if(strlen(caption) && strstr(caption, "Classroom_") && !FoundWindow)
    {
        char FormattedTime[9];
        strftime(FormattedTime, 9, "%H:%M:%S", now);
        printf("[%s] Classroom window is found: HWND=%d title=%s\n", FormattedTime, hwnd, caption);
        ClassroomHwnd = hwnd;
        FoundWindow = true;
    }
    return TRUE;
}

int main()
{
    puts("ClassIn Mover v1.0.0\nMade by GWQ GJZ\nVisit https://github.com/CarlGao4/ClassIn-Mover for more infomation.\n");
    RECT rect;
    HWND hwnd = GetDesktopWindow();
    GetWindowRect(hwnd, &rect);
    WINDOWPLACEMENT wp;
    wp.length = sizeof(WINDOWPLACEMENT);
    while(true)
    {
        FoundWindow = false;
        EnumWindows(RefreshWindow, NULL);
        time_t tmp = time(0);
        tm *now = localtime(&tmp);
        if(!FoundWindow)
        {
            char FormattedTime[9];
            strftime(FormattedTime, 9, "%H:%M:%S", now);
            printf("[%s] Cannot find classroom window\n", FormattedTime);
            Sleep(1000);
            continue;
        }
        for(int i = 0; i < 10; i++)
        {
            GetWindowRect(ClassroomHwnd, &rect);
            SetWindowPos(ClassroomHwnd, HWND_NOTOPMOST, rect.left, rect.top,
                rect.right - rect.left, rect.bottom - rect.top, SWP_NOSENDCHANGING);
            GetWindowPlacement(ClassroomHwnd, &wp);
            if (wp.showCmd != SW_MAXIMIZE && wp.showCmd != SW_MINIMIZE)
            {
                ShowWindow(ClassroomHwnd, SW_MINIMIZE);
                ShowWindow(ClassroomHwnd, SW_MAXIMIZE);
            }
            Sleep(100);
        }
    }
}
