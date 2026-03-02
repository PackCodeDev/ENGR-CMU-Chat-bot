#include<iostream>
#include<string>
#include<vector>
#include <windows.h>

using namespace std;

enum ShowState {
    SELECT_PROGRAM, //เลือกภาค
    SELECT_MAJORS, //เลือกเจอร์
    SELECT_DETAIL //คำถาม
};

class WaitSelect{
    public:
        ShowState currentState = SELECT_PROGRAM;
        std::string selectedProgram = "";
        std::string selectedMajor = "";
        std::string selectedDetail = "";

    bool hasKeyword(std::string input, std::string keyword) {
        return input.find(keyword) != std::string::npos;
    };
    
    bool processAdmission(std::string input, std::vector<std::string>& chatHistory){
        auto reply = [&](std::string text) {
            chatHistory.push_back("Chatbot: " + text);
        };

        if(hasKeyword(input, "ออก") || hasKeyword(input, "เมนูหลัก")){
            reply(" ");
            currentState = SELECT_PROGRAM;
            selectedMajor = ""; selectedDetail = "";
            return false;
        };

        switch(currentState){
            case SELECT_PROGRAM:
                if(hasKeyword(input, "ปกติ")){
                selectedProgram = "ปกติ";
                reply("เลือกภาคปกติแล้วครับ ต่อไปเลือกสาขาที่สนใจได้เลย");
                currentState = SELECT_MAJORS;
                }else if(hasKeyword(input, "พิเศษ")){
                selectedProgram = "พิเศษ";
                reply("เลือกภาคพิเศษแล้วครับ ต่อไปเลือกสาขาที่สนใจได้เลย");
                currentState = SELECT_MAJORS;
                }else if(hasKeyword(input, "นานาชาติ")){
                selectedProgram = "นานาชาติ";
                reply("เลือกภาคพิเศษแล้วครับ ต่อไปเลือกสาขาที่สนใจได้เลย");
                currentState = SELECT_MAJORS;
                }

//=========================================================================================================================================

//                                                ภาคปกติ

                                                //Computer
            case SELECT_MAJORS:
                if(hasKeyword(input, "คอม") || hasKeyword(input, "คอมพิวเตอร์") && selectedProgram == "ปกติ"){
                    selectedMajor = "คอมพิวเตอร์";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับวิศวกรรมคอมพิวเตอร์ครับ?");
                    currentState = SELECT_DETAIL;
                }
                                                //Mechanical
                else if(hasKeyword(input, "เครื่องกล") && selectedProgram == "ปกติ"){
                    selectedMajor = "เครื่องกล";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับวิศวกรรมเครื่องกลครับ?");
                    currentState = SELECT_DETAIL;
                }
                                                //Electrical
                else if(hasKeyword(input, "ไฟฟ้า") && selectedProgram == "ปกติ"){
                    selectedMajor = "";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับ ครับ?");
                    currentState = SELECT_DETAIL;
                }
                                                //Civil
                else if(hasKeyword(input, "โยธา") && selectedProgram == "ปกติ"){
                    selectedMajor = "";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับ ครับ?");
                    currentState = SELECT_DETAIL;
                }
                                                //Industrial
                else if(hasKeyword(input, "อุตสาหการ") && selectedProgram == "ปกติ"){
                    selectedMajor = "";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับ ครับ?");
                    currentState = SELECT_DETAIL;
                }
                                                //Environmental
                else if(hasKeyword(input, "สิ่งแวดล้อม") && selectedProgram == "ปกติ"){
                    selectedMajor = "";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับ ครับ?");
                    currentState = SELECT_DETAIL;
                }
                                                //Mining & Petroleum
                else if(hasKeyword(input, "เหมืองแร่") && selectedProgram == "ปกติ"){
                    selectedMajor = "";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับ ครับ?");
                    currentState = SELECT_DETAIL;
                }
                                                //REAI (Robotics & AI)
                else if(hasKeyword(input, "REAI") && selectedProgram == "ปกติ"){
                    selectedMajor = "";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับ ครับ?");
                    currentState = SELECT_DETAIL;
                }
                                                //Integrated
                else if(hasKeyword(input, "บูรณาการณ์") && selectedProgram == "ปกติ"){
                    selectedMajor = "";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับ ครับ?");
                    currentState = SELECT_DETAIL;
                }

//                                                ภาคพิเศษ

                                                //Industrial
                else if(hasKeyword(input, "อุตสาหการ") && selectedProgram == "พิเศษ"){
                    selectedMajor = "";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับ ครับ?");
                    currentState = SELECT_DETAIL;
                }
                                                //Electrical
                else if(hasKeyword(input, "ไฟฟ้า") && selectedProgram == "พิเศษ"){
                    selectedMajor = "";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับ ครับ?");
                    currentState = SELECT_DETAIL;
                }
                                                //Mechanical
                else if(hasKeyword(input, "เครื่องกล") && selectedProgram == "พิเศษ"){
                    selectedMajor = "";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับ ครับ?");
                    currentState = SELECT_DETAIL;
                }

//                                                นานาชาติ

                                                //Mechanical
                else if(hasKeyword(input, "เครื่องกล") && selectedProgram == "นานาชาติ"){
                    selectedMajor = "";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับ ครับ?");
                    currentState = SELECT_DETAIL;
                }
                                                //Integrated
                else if(hasKeyword(input, "บูรณาการณ์") && selectedProgram == "นานาชาติ"){
                    selectedMajor = "";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับ ครับ?");
                    currentState = SELECT_DETAIL;
                }
                                                //Electrical
                else if(hasKeyword(input, "ไฟฟ้า") && selectedProgram == "นานาชาติ"){
                    selectedMajor = "";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับ ครับ?");
                    currentState = SELECT_DETAIL;
                }
                                                //Civil
                else if(hasKeyword(input, "โยธา") && selectedProgram == "นานาชาติ"){
                    selectedMajor = "";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับ ครับ?");
                    currentState = SELECT_DETAIL;
                }
                                                //ISNE
                else if(hasKeyword(input, "ISNE") && selectedProgram == "นานาชาติ"){
                    selectedMajor = "";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับ ครับ?");
                    currentState = SELECT_DETAIL;
                }
                                                //Industrial
                else if(hasKeyword(input, "อุตสาหการ") && selectedProgram == "นานาชาติ"){
                    selectedMajor = "";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับ ครับ?");
                    currentState = SELECT_DETAIL;
                }

//=========================================================================================================================================

                else{
                    reply("ลองพิมพ์ชื่อสาขาใหม่ดูนะครับ (เช่น )");
                }
                break;

//=========================================================================================================================================

//                                                คำถาม

            case SELECT_DETAIL:
                if(hasKeyword(input, "ตัวอย่างคำถาม") || hasKeyword(input, "ตัวอย่างคำถาม")){
        
                    if(selectedMajor == "คอมพิวเตอร์"){
                    //แบบที่ 1
                        if(selectedProgram == "ปกติ"){
                        reply(" ");
                        }else if(selectedProgram == "พิเศษ"){
                            reply(" ");
                        }else if(selectedProgram == "นานาชาติ"){
                            reply(" ");
                        }
                    }else if(selectedMajor == "เครื่องกล"){
                        if(selectedProgram == "ปกติ"){
                            reply(" ");
                        }else{
                            reply(" ");
                        }
                    }
                }else if(hasKeyword(input, "ตัวอย่างคำถาม") || hasKeyword(input, "ตัวอย่างคำถาม")){
                    //แบบที่ 2
                    if(selectedProgram == "ปกติ"){
                        reply(" ");
                    }else if(selectedProgram == "พิเศษ"){
                        reply(" ");
                    }else if(selectedProgram == "นานาชาติ"){
                        reply(" ");
                    }
                }
                break;
        }
        return true;
    }
};
WaitSelect chatbot;
std::vector<std::string> chatHistory;

HWND hEditInput, hButtonSend, hEditChat;

#define ID_EDIT_INPUT 101
#define ID_BUTTON_SEND 102
#define ID_EDIT_CHAT 103

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

    switch(uMsg) {

        case WM_CREATE:
            hEditChat = CreateWindowW(L"EDIT", L"",
                WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL | WS_VSCROLL,
                10, 10, 460, 250,
                hwnd, (HMENU)ID_EDIT_CHAT, NULL, NULL);

            hEditInput = CreateWindowW(L"EDIT", L"",
                WS_VISIBLE | WS_CHILD | WS_BORDER,
                10, 270, 360, 25,
                hwnd, (HMENU)ID_EDIT_INPUT, NULL, NULL);

            hButtonSend = CreateWindowW(L"BUTTON", L"Send",
                WS_VISIBLE | WS_CHILD,
                380, 270, 90, 25,
                hwnd, (HMENU)ID_BUTTON_SEND, NULL, NULL);
            break;

        case WM_COMMAND:
            if (LOWORD(wParam) == ID_BUTTON_SEND) {

                wchar_t buffer[256];
                GetWindowTextW(hEditInput, buffer, 256);

                std::wstring winput = buffer;

        // convert wide string → UTF-8 string
        int size_needed = WideCharToMultiByte(CP_UTF8, 0, 
        winput.c_str(), -1, NULL, 0, NULL, NULL);

        std::string input(size_needed, 0);

                WideCharToMultiByte(CP_UTF8, 0,winput.c_str(), -1,&input[0], size_needed,NULL, NULL);

                chatbot.processAdmission(input, chatHistory);

                SetWindowTextW(hEditChat, L"");

                std::wstring allText;
                for (auto &msg : chatHistory) {
                    int size_needed = MultiByteToWideChar(CP_UTF8, 0, msg.c_str(), -1, NULL, 0);

                std::wstring wmsg(size_needed, 0);

                MultiByteToWideChar(CP_UTF8, 0,msg.c_str(), -1,&wmsg[0], size_needed);
                allText += wmsg + L"\r\n";
                }

                SetWindowTextW(hEditChat, allText.c_str());
                SetWindowTextW(hEditInput, L"");
            }
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;
    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int WINAPI wWinMain(HINSTANCE hInstance,
                    HINSTANCE,
                    PWSTR,
                    int nCmdShow)
{
    const wchar_t CLASS_NAME[] = L"ChatbotWindow";

    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        0,
        CLASS_NAME,
        L"Admission Chatbot",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 500, 350,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    ShowWindow(hwnd, nCmdShow);

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}