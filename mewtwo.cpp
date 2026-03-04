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
                if(hasKeyword(input, "Software") || hasKeyword(input, "คอมพิวเตอร์") || hasKeyword(input, "คอม")){        
                    if(selectedMajor == "คอมพิวเตอร์"){
                    //Computer
                        if(selectedProgram == "ปกติ"){
                        reply("● ปี 1: ปูพื้นฐาน Calculus, Physics และ Computer Programming (C/Python) ฝึก Logic เบื้องต้น\n"
                            "● ปี 2: เข้าสู่แกนหลัก Computer Engineering เจอ Data Structures, Discrete Math, Digital Logic และเริ่ม Circuit\n"
                            "● ปี 3: ปีมหาโหด! เรียน Operating Systems, Database, Network, Software Engineering และ Microprocessors\n"
                            "● ปี 4: เลือกวิชาเลือกเฉพาะทาง (AI, Security, Cloud) และทำ Senior Project ตลอดทั้งปี");
                        }else if(selectedProgram == "พิเศษ"){
                            reply("none");
                        }else if(selectedProgram == "นานาชาติ"){
                            reply("none");
                        }
                    //Mechanical
                    }else if(hasKeyword(input, "Mech") || hasKeyword(input, "วิศวกรรมเครื่องกล"))
                    if(selectedMajor == "เครื่องกล"){
                        if(selectedProgram == "ปกติ"){
                            reply("● ปี 1: เน้น Physics, Calculus และวิชา Engineering Drawing (หัดวาดแบบวิศวกรรมทั้งมือและ CAD)\n"
                                "● ปี 2: เริ่มวิชาคำนวณแรงหลัก Statics, Dynamics, Thermodynamics และพื้นฐานวัสดุวิศวกรรม\n"
                                "● ปี 3: เจาะลึก Fluid Mechanics, Heat Transfer, Machine Design และเครื่องจักรกลความร้อน\n"
                                "● ปี 4: เลือกสายเจาะลึก (Automotive/Energy) และทำโครงงานวิศวกรรมเครื่องกล\n");
                        }else if(selectedProgram == "พิเศษ"){
                            reply(" ");
                        }else if(selectedProgram == "นานาชาติ"){
                            reply(" ");
                        }
                    }
                    //Semiconductor
                    }else if(hasKeyword(input, "Semiconductor") || hasKeyword(input, "Chip"))
                    if(selectedMajor == "เซมิคอนดักเตอร์"){
                        if(selectedProgram == "ปกติ"){
                        reply(" ● ปี 1: Physics of Semiconductor"
                            "● ปี 2: IC Design, VLSI\n"
                            "● ปี 3: Semiconductor Fabrication\n"
                            "● ปี 4: Internship ในอุตสาหกรรมชิปประมวลผล");
                        }else if(selectedProgram == "พิเศษ"){
                        reply("none");
                        }else if(selectedProgram == "นานาชาติ"){
                        reply("none");
                        }
                    //Integrated
                    }else if(hasKeyword(input, "เรียนรู้ข้ามศาสตร์") || hasKeyword(input, "ตัวอย่างคำถาม"))
                    if(selectedMajor == "บูรณาการณ์"){                    
                        if(selectedProgram == "ปกติ"){
                        reply("● ปี 1-4: เน้นการเรียนแบบโมดูล (Module) และ Project-based Learning\n"
                            "(เรียนรู้ข้ามศาสตร์ระหว่างสาขาต่างๆ เช่นคอมพิวเตอร์ ไฟฟ้า และเครื่องกล)");
                        }else if(selectedProgram == "พิเศษ"){
                        reply("none");
                        }else if(selectedProgram == "นานาชาติ"){
                        reply(" ");
                        }
                    //Electrical
                    }else if(hasKeyword(input, "Circuit") || hasKeyword(input, "กำลังไฟฟ้า"))
                    if(selectedMajor == "ไฟฟ้า"){
                        if(selectedProgram == "ปกติ"){
                        reply("● ปี 1: พื้นฐานวิศวกรรม เน้นฟิสิกส์ไฟฟ้าและแม่เหล็ก และคณิตศาสตร์วิศวกรรม\n"
                            "● ปี 2: เข้าสู่หัวใจอย่าง Circuit Analysis 1-2, Digital Circuit และสัญญาณและระบบ (Signals)\n"
                            "● ปี 3: เรียน Electromagnetic Fields, Machines, ระบบควบคุม และการส่งจ่ายกำลังไฟฟ้า\n"
                            "● ปี 4: แยกสายกำลังหรืออิเล็กทรอนิกส์ขั้นสูง และทำ Senior Project");
                        }else if(selectedProgram == "พิเศษ"){
                        reply(" ");
                        }else if(selectedProgram == "นานาชาติ"){
                        reply(" ");
                        }
                    //Civil
                    }else if(hasKeyword(input, "โครงสร้างเหล็ก") || hasKeyword(input, "บริหารงานก่อสร้าง"))
                    if(selectedMajor == "โยธา"){
                        if(selectedProgram == "ปกติ"){
                        reply("● ปี 1: พื้นฐานวิศวกรรมและ Drawing เพื่อหัดอ่านและวาดแบบแปลนก่อสร้าง\n"
                            "● ปี 2: เริ่มคำนวณ Mechanics of Solids และออกฝึกสำรวจ (Surveying) กลางแจ้ง\n"
                            "● ปี 3: ออกแบบคอนกรีตเสริมเหล็ก (RC Design), โครงสร้างเหล็ก และวิศวกรรมฐานราก (Soil Mech)\n"
                            "● ปี 4: การบริหารงานก่อสร้าง, ชลศาสตร์ และทำโครงการจบวิศวกรรมโยธา");
                        }else if(selectedProgram == "พิเศษ"){
                        reply("none");
                        }else if(selectedProgram == "นานาชาติ"){
                        reply(" ");
                        }
                    //Environmental
                    }else if(hasKeyword(input, "Environment") || hasKeyword(input, "ตัวอย่างคำถาม"))
                    if(selectedMajor == "สิ่งแวดล้อม"){                   
                        if(selectedProgram == "ปกติ"){
                        reply("● ปี 1: เน้นพื้นฐานเคมีสิ่งแวดล้อมและชีววิทยามากเป็นพิเศษ\n"
                            "● ปี 2: ระบบประปา, ระบบระบายน้ำ, จุลชีววิทยาสิ่งแวดล้อม และกลศาสตร์ของไหล\n"
                            "● ปี 3: ระบบบำบัดน้ำเสียขั้นสูง, มลพิษทางอากาศ และการจัดการขยะมูลฝอยและของเสียอันตราย\n"
                            "● ปี 4: การประเมินผลกระทบสิ่งแวดล้อม (EIA), พลังงานสะอาด และ Senior Project");
                        }else if(selectedProgram == "พิเศษ"){
                        reply("none");
                        }else if(selectedProgram == "นานาชาติ"){
                        reply("none");
                        }
                    //REAI
                    }else if(hasKeyword(input, "AI") || hasKeyword(input, "ตัวอย่างคำถาม"))
                    if(selectedMajor == "REAI"){                    
                        if(selectedProgram == "ปกติ"){
                        reply("● ปี 1: เริ่มฝึก Robotics Programming ทันทีควบคู่ไปกับพื้นฐาน Physics/Math\n"
                            "● ปี 2: เรียนเรื่อง Sensor, Actuators, Embedded Systems และระบบควบคุมหุ่นยนต์\n"
                            "● ปี 3: เจาะลึก AI for Robotics, Machine Vision, Kinematics และการออกแบบกลไกแขนกล\n"
                            "● ปี 4: เน้นการทำ Project-Based ร่วมกับภาคอุตสาหกรรมนวัตกรรมหุ่นยนต์สมัยใหม่");
                        }else if(selectedProgram == "พิเศษ"){
                        reply("none");
                        }else if(selectedProgram == "นานาชาติ"){
                        reply("none");
                        }
                    //Mining&Petroleum
                    }else if(hasKeyword(input, "Mining") || hasKeyword(input, "ตัวอย่างคำถาม"))
                    if(selectedMajor == "เหมืองแร่"){                   
                        if(selectedProgram == "ปกติ"){
                        reply("● ปี 1: พื้นฐานธรณีวิทยา (Physical Geology) และพื้นฐานวิศวกรรม\n"
                            "● ปี 2: การทำเหมืองเปิด, เหมืองใต้ดิน, การวิเคราะห์สินแร่ และการสำรวจธรณี\n"
                            "● ปี 3: การระเบิดหิน, Rock Mechanics, การแต่งแร่ และเศรษฐศาสตร์ทรัพยากรธรณี\n"
                            "● ปี 4: ออกแบบเหมือง, วิศวกรรมปิโตรเลียมเบื้องต้น และโครงงานจบการศึกษา");
                        }else if(selectedProgram == "พิเศษ"){
                        reply("none");
                        }else if(selectedProgram == "นานาชาติ"){
                        reply("none");
                        }
                    //Industrial
                    }else if(hasKeyword(input, "IE") || hasKeyword(input, "ตัวอย่างคำถาม"))
                    if(selectedMajor == "อุตสาหการ"){                    
                        if(selectedProgram == "ปกติ"){
                        reply("● ปี 1: พื้นฐานวิศวกรรมทั่วไป และวิชาเคมีสำหรับวิศวกร\n"
                            "● ปี 2: สถิติวิศวกรรม (Engineering Stat), กรรมวิธีการผลิต และพื้นฐานความปลอดภัย\n"
                            "● ปี 3: ปีแห่งการวางแผน! เรียน Operations Research (OR), คุมคุณภาพ (QC), เศรษฐศาสตร์วิศวกรรม\n"
                            "● ปี 4: การจัดการโลจิสติกส์, การออกแบบโรงงาน และ Senior Project");
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