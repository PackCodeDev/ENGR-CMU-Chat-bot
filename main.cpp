// =====================================================================
// [ZONE 1] นำเข้าไลบรารีและไฟล์ส่วนขยาย (Includes & Setup)
// =====================================================================
#include <iostream>
#include <string>
#include <vector>

// บังคับให้ Windows ใช้งานการ์ดจอแยก (ถ้ามี) เพื่อให้ UI แสดงผลลื่นไหล 60FPS
#ifdef _WIN32
#include <windows.h>
extern "C" { __declspec(dllexport) DWORD NvOptimusEnablement = 0x00000001; }
#endif

// นำเข้าไลบรารี ImGui สำหรับสร้างหน้าต่าง UI
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>

// --- ไฟล์สมองส่วนขยาย (Plugins) ---
// ไฟล์เหล่านี้คือไฟล์ Header (.h) ที่เก็บระบบย่อยอื่นๆ ไว้
#include "Admission.h"      // ไฟล์ส่วนที่ 1: รับเข้าศึกษา (มีแล้ว)
#include "Freshman.h"       // ไฟล์ส่วนที่ 2: นักศึกษาใหม่ปี 1
#include "General.h"        // ไฟล์ส่วนที่ 3: ถามตอบทั่วไป


// =====================================================================
// [ZONE 2] สมองคุมงานหลัก (Main Controller - สับรางรถไฟ)
// =====================================================================
// คลาส ChatbotLogic ทำหน้าที่เป็น "ผู้จัดการศูนย์กลาง" คอยรับข้อความและส่งต่อให้ระบบย่อย
class ChatbotLogic {
public:
    int state = -1;                          // สถานะการทำงาน (-1=ถามชื่อ, 0=เมนูหลัก, 1=รับเข้า, 2=ปี1, 3=ทั่วไป)
    std::string userName = "";               // เก็บชื่อผู้ใช้
    std::vector<std::string> chatHistory;    // เก็บประวัติข้อความแชททั้งหมดบนหน้าจอ

    // นำระบบย่อยมาเตรียมพร้อมไว้ที่นี่
    AdmissionHandler admissionSystem; 
    FreshmanHandler freshmanSystem;       
    GeneralQAHandler generalQASystem;     

    // ฟังก์ชันเริ่มต้น (Constructor - ทำงานครั้งแรกเมื่อเปิดโปรแกรม)
    ChatbotLogic() {
        chatHistory.push_back("Chatbot: สวัสดีครับ! ขอทราบชื่อของคุณหน่อยครับ");
    }

    // ฟังก์ชันประมวลผลหลัก ทำงานทุกครั้งที่ผู้ใช้พิมพ์ข้อความแล้วกดส่ง
    void processInput(std::string input) {
        if (input.empty()) return;                   // ถ้าพิมพ์ว่างเปล่ามา ให้ข้ามไป
        chatHistory.push_back("User: " + input);     // แสดงข้อความของผู้ใช้บนหน้าจอ

        // ------------------------------------
        // สถานะ -1: โหมดถามชื่อ (ทำงานครั้งแรกครั้งเดียว)
        // ------------------------------------
        if (state == -1) {
            userName = input;
            state = 0; // ย้ายไปสถานะเมนูหลัก
            chatHistory.push_back("Chatbot: ยินดีที่ได้รู้จักครับ คุณ " + userName + "!");
            addMenuMessage();
            return;
        }

        // ------------------------------------
        // สถานะ 0: โหมดเมนูหลัก (คอยสับราง)
        // ------------------------------------
        if (state == 0) {
            if (input == "1") { 
                state = 1; // สับรางไปให้ Admission.h
                chatHistory.push_back("Chatbot: --- เข้าสู่โหมด Admission ---");
                chatHistory.push_back("Chatbot: ที่วิศวฯ มช. มีทั้งภาคปกติ ภาคพิเศษ และหลักสูตรนานาชาติ\nสนใจดูเกณฑ์ของหลักสูตรไหนเป็นพิเศษไหมครับ?");
                admissionSystem.currentState = ADM_STATE_SELECT_PROGRAM; // สั่งรีเซ็ตให้ Admission เริ่มใหม่เสมอ
            } 
            else if (input == "2") { 
                state = 2; // สับรางไปให้ Freshman.h
                chatHistory.push_back("Chatbot: --- เข้าสู่โหมดข้อมูลหลักสูตร (นักศึกษาปี 1) ---");
                chatHistory.push_back("Chatbot: ยินดีต้อนรับครับ! กรุณาเลือกภาคที่สนใจเพื่อดูข้อมูลวิชาเรียนได้เลยครับ\n(พิมพ์: ปกติ, พิเศษ, หรือ นานาชาติ)");
                freshmanSystem.currentState = FRESH_STATE_SELECT_PROGRAM; 
            }
            else if (input == "3") { 
                state = 3; // สับรางไปให้ GeneralQA.h
                chatHistory.push_back("Chatbot: --- เข้าสู่โหมดถามตอบทั่วไป ---");
                chatHistory.push_back("Chatbot: มีเรื่องทั่วไปอะไรเกี่ยวกับคณะวิศวะ มช. ที่อยากรู้ไหมครับ?\n(เช่น วันขึ้นดอย , วันหยุด , วันดรอป , ลงทะเบียน , เบอร์ติดต่อฉุกเฉิน , wifi , ข่าว)");
                generalQASystem.currentState = QA_STATE_MAIN; // สั่งรีเซ็ตสถานะเริ่มต้น
            } 
            else {
                chatHistory.push_back("Chatbot: กรุณาเลือกตัวเลข 1, 2 หรือ 3 เท่านั้นครับ");
            }
            return;
        }

        // ------------------------------------
        // สถานะ 1: โหมดทำงานของ Admission.h
        // ------------------------------------
        if (state == 1) {
            bool stayInAdmission = admissionSystem.processAdmission(input, chatHistory);
            // ถ้าไฟล์ย่อยบอกว่า false (ผู้ใช้พิมพ์ 'ออก') ให้ดึงกลับหน้าหลัก
            if (!stayInAdmission) {
                state = 0; 
                chatHistory.push_back("Chatbot: กลับสู่เมนูหลักครับ");
                addMenuMessage();
            }
        }

        // ------------------------------------
        // สถานะ 2: โหมดทำงานของ Freshman.h 
        // ------------------------------------
        if (state == 2) {
            bool stayInFreshman = freshmanSystem.processFreshman(input, chatHistory);
            if (!stayInFreshman) {
                state = 0; 
                chatHistory.push_back("Chatbot: กลับสู่เมนูหลักครับ");
                addMenuMessage();
            }
        }

        // ------------------------------------
        // สถานะ 3: โหมดทำงานของ GeneralQA.h 
        // ------------------------------------
        if (state == 3) {
            bool stayInQA = generalQASystem.processQA(input, chatHistory);
            if (!stayInQA) {
                state = 0; 
                chatHistory.push_back("Chatbot: กลับสู่เมนูหลักครับ");
                addMenuMessage();
            }
        }
    }

private:
    // ฟังก์ชันย่อย (Private) ช่วยพิมพ์เมนูหลัก เพื่อลดความซ้ำซ้อนในโค้ด
    void addMenuMessage() {
        chatHistory.push_back("Chatbot: กรุณาเลือกสถานะของคุณ:\n[1] สนใจเข้าเรียน (Admission)\n[2] นักศึกษาใหม่ปี 1 (Freshman)\n[3] ถามตอบทั่วไป (General Q&A)");
    }
};


// =====================================================================
// [ZONE 3] การวาดหน้าตาโปรแกรม (UI Drawings)
// ส่วนนี้ใช้ ImGui ในการจัดการกราฟิกทั้งหมด
// =====================================================================

// ฟังก์ชันวาดปุ่มลูกศรส่งข้อความ (Custom Button)
bool DrawCustomSendButton(const char* id, float btnSize) {
    // กำหนดสีของปุ่ม (ปกติ, ตอนเอาเมาส์ชี้, ตอนคลิก) และความโค้งมน
    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.22f, 0.22f, 0.26f, 1.0f)); 
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.32f, 0.32f, 0.38f, 1.0f)); 
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.15f, 0.15f, 0.18f, 1.0f)); 
    ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, btnSize / 2.0f);
    
    ImVec2 btnPos = ImGui::GetCursorScreenPos();
    bool pressed = ImGui::Button(id, ImVec2(btnSize, btnSize)); // สร้างปุ่ม
    
    // คืนค่าสไตล์กลับ เพื่อไม่ให้กระทบ UI ส่วนอื่น
    ImGui::PopStyleVar();
    ImGui::PopStyleColor(3);

    // วาดไอคอนลูกศรสีขาวบนปุ่ม
    ImDrawList* drawList = ImGui::GetWindowDrawList();
    ImVec2 center = ImVec2(btnPos.x + (btnSize / 2.0f) - 1.0f, btnPos.y + (btnSize / 2.0f));
    
    float arrowWidth = 5.0f;
    float arrowHeight = 7.0f;
    float lineThickness = 3.0f; 
    
    ImVec2 p1 = ImVec2(center.x - arrowWidth + 2.0f, center.y - arrowHeight); 
    ImVec2 p2 = ImVec2(center.x + arrowWidth, center.y);                      
    ImVec2 p3 = ImVec2(center.x - arrowWidth + 2.0f, center.y + arrowHeight); 

    drawList->AddLine(p1, p2, IM_COL32(255, 255, 255, 255), lineThickness);
    drawList->AddLine(p2, p3, IM_COL32(255, 255, 255, 255), lineThickness);

    return pressed; // คืนค่า true ถ้าปุ่มถูกคลิก
}

// ฟังก์ชันวาดหน้าแรก (Welcome Screen) - โหมดถามชื่อ
void DrawWelcomeLayout(ChatbotLogic* brain, char* inputBuffer, ImFont* font) {
    ImVec2 centerPos = ImGui::GetMainViewport()->GetCenter();
    float windowWidth = ImGui::GetMainViewport()->Size.x;

    if (font) { ImGui::PushFont(font); ImGui::SetWindowFontScale(0.5f); }

    // หัวข้อด้านซ้ายบน
    ImGui::SetCursorPos(ImVec2(50, 50));
    ImGui::TextDisabled("ENGR-CMU Chatbot");

    // ข้อความทักทายกลางหน้าจอ
    float startX = centerPos.x - (windowWidth * 0.35f); 
    ImGui::SetWindowFontScale(0.65f); 

    ImGui::SetCursorPos(ImVec2(startX, centerPos.y - 180));
    ImGui::TextColored(ImVec4(0.4f, 0.7f, 1.0f, 1.0f), "*"); 
    ImGui::SameLine(); ImGui::Text("สวัสดีครับ");
    
    ImGui::SetCursorPos(ImVec2(startX, centerPos.y - 120));
    ImGui::Text("ผมขอทราบชื่อคุณหน่อยนะครับ...");

    // จัดการช่องพิมพ์ข้อความ (Input Box)
    ImGui::SetWindowFontScale(0.5f); 
    float inputWidth = windowWidth * 0.7f;
    float boxHeight = 70.0f; 
    float btnSize = 50.0f; 
    
    ImGui::SetCursorPos(ImVec2(centerPos.x - (inputWidth / 2), centerPos.y - 20));
    ImVec2 screenPos = ImGui::GetCursorScreenPos(); 

    // วาดพื้นหลังกล่องข้อความ
    ImGui::GetWindowDrawList()->AddRectFilled(
        screenPos, ImVec2(screenPos.x + inputWidth, screenPos.y + boxHeight), IM_COL32(31, 31, 36, 255), 35.0f 
    );

    float padY = (boxHeight - ImGui::GetFontSize()) / 2.0f; 
    if (padY < 0.0f) padY = 0.0f;

    ImGui::SetCursorScreenPos(ImVec2(screenPos.x + 10.0f, screenPos.y - 6.0f));
    ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(20.0f, padY)); 
    ImGui::PushStyleColor(ImGuiCol_FrameBg, ImVec4(0, 0, 0, 0)); 
    
    ImGui::PushItemWidth(inputWidth - btnSize - 30.0f); 
    if (ImGui::IsWindowAppearing()) ImGui::SetKeyboardFocusHere(); // ให้เคอร์เซอร์กระพริบรอพิมพ์ทันที
    
    // รับค่าจากคีย์บอร์ด
    bool enterPressed = ImGui::InputTextWithHint("##WelcomeIn", "ASK ENGR-CMU Chatbot", inputBuffer, 256, ImGuiInputTextFlags_EnterReturnsTrue);
    ImGui::PopItemWidth();
    ImGui::PopStyleColor();
    ImGui::PopStyleVar();

    ImGui::SameLine();
    ImGui::SetCursorScreenPos(ImVec2(screenPos.x + inputWidth - btnSize - 10.0f, screenPos.y + 10.0f));
    
    bool btnPressed = DrawCustomSendButton("##WelcomeBtn", btnSize);

    // หากกดปุ่ม Enter หรือคลิกปุ่มส่งข้อความ ให้นำข้อความไปประมวลผล
    if (enterPressed || btnPressed) {
        brain->processInput(inputBuffer);
        inputBuffer[0] = '\0'; // ล้างกล่องข้อความหลังส่ง
    }

    if (font) { ImGui::SetWindowFontScale(1.0f); ImGui::PopFont(); }
}

// ฟังก์ชันวาดหน้าต่างแชทหลัก (เมื่อเข้าสู่โหมดเมนูแล้ว)
void DrawChatLayout(ChatbotLogic* brain, char* inputBuffer, ImFont* font) {
    ImVec2 viewportSize = ImGui::GetMainViewport()->Size;
    float windowWidth = viewportSize.x;
    float windowHeight = viewportSize.y;
    
    if (font) ImGui::PushFont(font);

    // หัวข้อด้านซ้ายบน
    ImGui::SetCursorPos(ImVec2(50, 50)); 
    ImGui::SetWindowFontScale(0.5f); 
    ImGui::TextDisabled("ENGR-CMU Chatbot");

    float chatAreaStartY = 140.0f; 
    float inputBarSpace = 160.0f;  
    
    ImGui::SetCursorPos(ImVec2(0, chatAreaStartY));
    ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0, 0, 0, 0)); 
    
    // สร้าง Child Window สำหรับพื้นที่แชท (เพื่อให้มี Scrollbar เลื่อนขึ้นลงได้)
    ImGui::BeginChild("ChatArea", ImVec2(0, windowHeight - chatAreaStartY - inputBarSpace), false, 0); 
    
    float chatScale = 0.50f; 
    ImGui::SetWindowFontScale(chatScale); 
    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 20)); 

    // ลูปวาดข้อความประวัติแชททั้งหมดใน Vector `chatHistory`
    for (const auto& msg : brain->chatHistory) {
        bool isUser = (msg.find("User: ") == 0);
        bool isChatbot = (msg.find("Chatbot: ") == 0);
        
        std::string displayText = msg;
        if (isUser) displayText = msg.substr(6);      // ตัดคำว่า "User: " ออกก่อนแสดงผล
        else if (isChatbot) displayText = msg.substr(9); // ตัดคำว่า "Chatbot: " ออกก่อนแสดงผล

        float wrapWidth = windowWidth * 0.60f; 
        if (wrapWidth < 300.0f) wrapWidth = 300.0f; 

        // คำนวณขนาดของกล่องข้อความ (Bubble)
        ImVec2 textSize = ImGui::CalcTextSize(displayText.c_str(), NULL, false, wrapWidth);
        float paddingX = 20.0f; 
        float paddingY = 18.0f; 
        float bubbleWidth = textSize.x + (paddingX * 2);
        float bubbleHeight = textSize.y + (paddingY * 2);

        // จัดกล่องข้อความ: ถ้าเป็น User ให้อยู่ชิดขวา, ถ้าเป็น Chatbot ให้อยู่ชิดซ้าย
        if (isUser) ImGui::SetCursorPosX(windowWidth - bubbleWidth - 50.0f);
        else ImGui::SetCursorPosX(50.0f);

        ImVec2 startPos = ImGui::GetCursorScreenPos();
        ImGui::Dummy(ImVec2(bubbleWidth, bubbleHeight)); // จองพื้นที่ว่างให้ Bubble
        float nextY = ImGui::GetCursorPosY(); 

        // วาดสีพื้นหลังกล่องข้อความ
        ImU32 bgColor = isUser ? IM_COL32(45, 45, 50, 255) : IM_COL32(31, 31, 36, 255);
        ImGui::GetWindowDrawList()->AddRectFilled(startPos, ImVec2(startPos.x + bubbleWidth, startPos.y + bubbleHeight), bgColor, 20.0f);

        // พิมพ์ข้อความลงในกล่อง
        ImGui::SetCursorScreenPos(ImVec2(startPos.x + paddingX, startPos.y + paddingY));
        ImGui::PushTextWrapPos(startPos.x + paddingX + wrapWidth);
        ImGui::Text("%s", displayText.c_str());
        ImGui::PopTextWrapPos();

        ImGui::SetCursorPosY(nextY); 
        ImGui::Dummy(ImVec2(0.0f, 0.0f)); 
    }
    ImGui::PopStyleVar();

    // ระบบเลื่อนหน้าจออัตโนมัติ: ถ้ามีข้อความใหม่เข้ามา ให้ Scroll ลงมาล่างสุด
    static size_t lastChatCount = 0;
    if (lastChatCount != brain->chatHistory.size()) {
        ImGui::SetScrollHereY(1.0f); 
        lastChatCount = brain->chatHistory.size();
    }
    ImGui::EndChild();
    ImGui::PopStyleColor();

    // ==========================================
    // ส่วนกล่องพิมพ์ข้อความ (Input Bar) ด้านล่าง
    // ==========================================
    ImGui::SetWindowFontScale(chatScale); 
    float inputWidth = windowWidth * 0.65f;
    float boxHeight = 60.0f; 
    float btnSize = 42.0f; 
    
    ImGui::SetCursorPos(ImVec2((windowWidth - inputWidth) / 2.0f, windowHeight - boxHeight - 75.0f));
    ImVec2 screenPos = ImGui::GetCursorScreenPos(); 

    ImGui::GetWindowDrawList()->AddRectFilled(screenPos, ImVec2(screenPos.x + inputWidth, screenPos.y + boxHeight), IM_COL32(31, 31, 36, 255), 30.0f);

    float padY = (boxHeight - ImGui::GetFontSize()) / 2.0f; 
    ImGui::SetCursorScreenPos(ImVec2(screenPos.x + 10.0f, screenPos.y - 6.0f));
    ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(20.0f, padY)); 
    ImGui::PushStyleColor(ImGuiCol_FrameBg, ImVec4(0, 0, 0, 0)); 
    
    ImGui::PushItemWidth(inputWidth - btnSize - 30.0f);
    if (ImGui::IsWindowAppearing()) ImGui::SetKeyboardFocusHere();
    
    bool enterPressed = ImGui::InputTextWithHint("##ChatIn", "Ask ENGR-CMU Chatbot", inputBuffer, 256, ImGuiInputTextFlags_EnterReturnsTrue);
    ImGui::PopItemWidth();
    ImGui::PopStyleColor();
    ImGui::PopStyleVar();

    ImGui::SameLine();
    ImGui::SetCursorScreenPos(ImVec2(screenPos.x + inputWidth - btnSize - 9.0f, screenPos.y + 9.0f));
    bool btnPressed = DrawCustomSendButton("##ChatBtn", btnSize);

    // ส่งข้อความและล้างกล่องเมื่อพิมพ์เสร็จ
    if (enterPressed || btnPressed) {
        brain->processInput(inputBuffer);
        inputBuffer[0] = '\0';
        ImGui::SetKeyboardFocusHere(-1);  // ให้เคอร์เซอร์กลับมาที่กล่องพิมพ์อัตโนมัติ
    }

    if (font) { ImGui::SetWindowFontScale(1.0f); ImGui::PopFont(); } 
}


// =====================================================================
// [ZONE 4] ระบบเริ่มโปรแกรม (Engine Startup & Main Loop)
// =====================================================================
int main() {
    // 1. จัดการความคมชัดของหน้าต่างสำหรับ Windows (ไม่ให้เบลอเมื่อสเกลจอ)
    #ifdef _WIN32
    SetProcessDPIAware(); 
    #endif

    // 2. สร้างหน้าต่างโปรแกรมแบบเต็มจอด้วย GLFW
    if (!glfwInit()) return 1;
    glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);
    GLFWwindow* window = glfwCreateWindow(1920, 1080, "ENGR CMU Chatbot", NULL, NULL);
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // เปิด V-Sync กันภาพฉีก

    // 3. เริ่มต้นระบบ ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    ImGui::GetStyle().Colors[ImGuiCol_WindowBg] = ImVec4(0.05f, 0.05f, 0.06f, 1.0f); // เซ็ตสีพื้นหลังแอป

    // 4. โหลดฟอนต์ภาษาไทยและจัดการสระ/วรรณยุกต์ (Sarabun)
    ImFontConfig cfgBase;
    cfgBase.OversampleH = 2; 
    cfgBase.OversampleV = 2;
    cfgBase.GlyphOffset.y = 5.0f; // ดึงชั้นแรก (สระ/พยัญชนะ) ลงมาให้พอดี

    static const ImWchar base_ranges[] = { 0x0020, 0x00FF, 0x0E00, 0x0E47, 0x0E4D, 0x0E7F, 0 };
    ImFont* fontThai = io.Fonts->AddFontFromFileTTF("Sarabun/Sarabun-Regular.ttf", 64.0f, &cfgBase, base_ranges);
    
    ImFontConfig cfgTone;
    cfgTone.OversampleH = 2; 
    cfgTone.OversampleV = 2;
    cfgTone.MergeMode = true;    
    cfgTone.GlyphOffset.y = 0.0f; // ไม่ดึงชั้นสอง (วรรณยุกต์) ลง เพื่อให้มันลอยเหนือสระ
    
    static const ImWchar tone_ranges[] = { 0x0E48, 0x0E4C, 0 };
    io.Fonts->AddFontFromFileTTF("Sarabun/Sarabun-Regular.ttf", 64.0f, &cfgTone, tone_ranges);
    if (!fontThai) fontThai = io.Fonts->AddFontDefault();

    // 5. เชื่อมต่อ ImGui เข้ากับระบบกราฟิก OpenGL
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");

    // 6. สร้างสมองส่วนกลางให้บอทเริ่มทำงาน (สร้าง Object ของ ChatbotLogic)
    ChatbotLogic* brain = new ChatbotLogic();
    char inputBuffer[256] = ""; // ตัวแปรเก็บข้อความดิบจากคีย์บอร์ด

    // 7. ลูปการทำงานหลัก (Main Loop - วนเรื่อยๆ จนกว่าจะกดปิดหน้าต่าง X)
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents(); // คอยเช็คการกดคีย์บอร์ดหรือคลิกเมาส์
        
        // เริ่มวาดเฟรมใหม่
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // สร้าง Canvas ใสๆ ให้เต็มจอ เพื่อให้เราวาด UI อิสระได้
        ImGui::SetNextWindowPos(ImVec2(0, 0));
        ImGui::SetNextWindowSize(io.DisplaySize);
        ImGui::Begin("Canvas", NULL, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoBackground);

        // ตรวจสอบว่าควารวาดหน้า "ถามชื่อ" หรือ "หน้าแชทหลัก"
        if (brain->chatHistory.size() <= 1) {
            DrawWelcomeLayout(brain, inputBuffer, fontThai); // หน้าแรก (ยังไม่กรอกชื่อ)
        } else {
            DrawChatLayout(brain, inputBuffer, fontThai);    // หน้าแชทหลัก (เข้าสู่ระบบแล้ว)
        }

        ImGui::End();
        ImGui::Render(); // สั่งให้ ImGui เตรียมข้อมูลวาด

        // 8. นำภาพที่วาดไปแสดงขึ้นจอจริงๆ ด้วยคำสั่งของ OpenGL
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(0.05f, 0.05f, 0.06f, 1.0f); // ล้างหน้าจอเก่าเป็นสีเทาเข้ม
        glClear(GL_COLOR_BUFFER_BIT);

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(window); // สลับเฟรมที่วาดเสร็จแล้วขึ้นหน้าจอ
    }

    // 9. ปิดโปรแกรมและคืนหน่วยความจำให้คอมพิวเตอร์ (ป้องกัน Memory Leak)
    delete brain;
    ImGui_ImplOpenGL3_Shutdown(); 
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwTerminate();
    
    return 0;
}