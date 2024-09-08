#include <iostream>
#include <fstream>
#include <windows.h>
#include <TlHelp32.h>
#include <cstdio>

void title() {
    SetConsoleTitle(L"The Casting of Frank Stone [CRACK]");
    std::wcout << L"Developer (discord): smirkzyy\n\n";
}

void SetConsoleColor(WORD color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

bool IsProcessRunning(const std::wstring& processName) {
    PROCESSENTRY32 entry;
    entry.dwSize = sizeof(PROCESSENTRY32);

    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snapshot == INVALID_HANDLE_VALUE) {
        return false;
    }

    Process32First(snapshot, &entry);
    do {
        if (processName == entry.szExeFile) {
            CloseHandle(snapshot);
            return true;
        }
    } while (Process32Next(snapshot, &entry));

    CloseHandle(snapshot);
    return false;
}

bool CheckFileExists(const std::wstring& filePath) {
    std::ifstream file(filePath);
    return file.good();
}

void CreateFile(const std::wstring& filePath, const std::string& content) {
    std::ofstream file(filePath);
    file << content;
}

int main() {
    // colours bc i cannot remember them lol
    const WORD white = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
    const WORD red = FOREGROUND_RED;
    const WORD green = FOREGROUND_GREEN;

    title(); // set the title

    // check Steam
    SetConsoleColor(white);
    std::wcout << L"[*] Checking Steam...\n";
    while (!IsProcessRunning(L"steam.exe")) {
        SetConsoleColor(red);
        std::wcout << L"[!] Steam is not open. Please launch Steam...\n";
        SetConsoleColor(white);
        std::wcout << L"[*] Press any key to continue...\n";
        system("pause >nul");
    }
    SetConsoleColor(green);
    std::wcout << L"[+] Steam OK\n";

    // check steam_appid
    SetConsoleColor(white);
    std::wcout << L"[*] Checking Steam crack...\n";
    if (CheckFileExists(L"SMG037UE5\\Binaries\\Win64\\steam_appid.txt")) {
        SetConsoleColor(green);
        std::wcout << L"[+] Steam crack OK\n";
    }
    else {
        while (!CheckFileExists(L"SMG037UE5\\Binaries\\Win64\\steam_appid.txt")) {
            SetConsoleColor(red);
            std::wcout << L"[!] Steam crack not found\n";
            SetConsoleColor(white);
            std::wcout << L"[*] Applying Steam crack...\n";
            CreateFile(L"SMG037UE5\\Binaries\\Win64\\steam_appid.txt", "480"); // create steam_appid.txt to disguise the game as spacewar
            Sleep(1000); // sleep for 1 second
        }
        SetConsoleColor(green);
        std::wcout << L"[+] Steam crack OK\n";
        SetConsoleColor(white);
    }

    // launch frank stone
    SetConsoleColor(green);
    std::wcout << L"[+] Launching CastingFrankStone Crack...\n";
    system("SMG037UE5\\Binaries\\Win64\\CastingFrankStone-Win64-Shipping.exe");

    Sleep(3000);  // sleep for 3 seconds

    return 0;
}