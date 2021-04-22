#include <iostream>
#include <fstream>
#include <Windows.h>
#include <locale>
#include <stdio.h>
#include <sstream>
#include <time.h>

using namespace std;

void pressKeyB(char mK)
{
    HKL kbl = GetKeyboardLayout(0);
    INPUT ip;
    ip.type = INPUT_KEYBOARD;
    ip.ki.time = 0;
    ip.ki.dwFlags = KEYEVENTF_UNICODE;
    if ((int)mK < 65 && (int)mK>90) //for lowercase
    {
        ip.ki.wScan = 0;
        ip.ki.wVk = VkKeyScanEx(mK, kbl);
    }
    else //for uppercase
    {
        if ((int)mK > 0) {
            ip.ki.wScan = mK;
            ip.ki.wVk = 0;
        }
    }
    ip.ki.dwExtraInfo = 0;
    SendInput(1, &ip, sizeof(INPUT));


    ip.ki.dwFlags = KEYEVENTF_UNICODE | KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));

}

void pressEnter()
{
    INPUT ip;
    ip.type = INPUT_KEYBOARD;
    ip.ki.time = 0;
    ip.ki.dwFlags = KEYEVENTF_UNICODE;
    ip.ki.wScan = VK_RETURN; //VK_RETURN is the code of Return key
    ip.ki.wVk = 0;

    ip.ki.dwExtraInfo = 0;
    SendInput(1, &ip, sizeof(INPUT));

    ip.ki.dwFlags = KEYEVENTF_UNICODE | KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));
}

void pressTab()
{
    INPUT ip;
    ip.type = INPUT_KEYBOARD;
    ip.ki.time = 0;
    ip.ki.dwFlags = KEYEVENTF_UNICODE;
    ip.ki.wScan = VK_TAB; //VK_RETURN is the code of Return key
    ip.ki.wVk = 0;

    ip.ki.dwExtraInfo = 0;
    SendInput(1, &ip, sizeof(INPUT));

    ip.ki.dwFlags = KEYEVENTF_UNICODE | KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));
}

wstring GetClipboardText()
{
    if (!OpenClipboard(nullptr))
    {
        CloseClipboard();
        return L"";
    }

    HANDLE hData = GetClipboardData(CF_UNICODETEXT);
    if (hData == nullptr)
    {
        CloseClipboard();
        return L"";
    }

    wchar_t* pszText = static_cast<wchar_t*>(GlobalLock(hData));
    if (pszText == nullptr)
    {
        CloseClipboard();
        return L"";
    }

    wstring text(pszText);

    GlobalUnlock(hData);
    CloseClipboard();

    return text;
}


int main()
{
    srand(time(0));

    wstring clipboardText = GetClipboardText();
    string s(clipboardText.begin(), clipboardText.end());

    while (true) {

        if ((GetAsyncKeyState(VK_F2) & 0x8000)) {
            cout << "writing...\n";
            for (int i = 0; i < s.length(); i++)
            {
                switch (s[i]) {
                    case '\n':
                        pressEnter();
                    case '\t':
                        break;
                        pressTab();
                        break;
                    default:
                        pressKeyB(s[i]);
                        break;
                }

                Sleep(100 + rand() % 200);
            }
        }
        Sleep(1);
    }
    system("PAUSE");
    return 0;
}