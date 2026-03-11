#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

// Function Prototypes
void selectUserStatus(int *statusPtr); 
void handleAdmission();
void handleFreshman();
void handleGeneral();

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    int select = 0; 
    string name;

    cout << "Chatbot : สวัสดีครับ! ขอทราบชื่อของคุณหน่อยครับ: " << "\n";
    cout << "User : ";
    getline(cin, name);
    cout << "Chatbot : ยินดีที่ได้รู้จักครับ คุณ " << name << "!" << endl;

    while (true) {
        selectUserStatus(&select); // ฟังก์ชันนี้จะวนลูปจนกว่าจะได้ 1-3
        cin.ignore(); // ล้าง Newline ที่ค้างอยู่จากการกด Enter ใน selectUserStatus

        if (select == 1) handleAdmission();
        else if (select == 2) handleFreshman();
        else if (select == 3) handleGeneral();
        
        // หมายเหตุ: หลังจาก Handler จบ (เช่น พิมพ์ 'ออก') 
        // มันจะวนกลับไปที่ selectUserStatus ใหม่โดยอัตโนมัติ
    }
    return 0;
}

void selectUserStatus(int *statusPtr) {
    const char *menu[] = {
        "สนใจเข้าเรียน (Admission)",
        "นักศึกษาใหม่ปี 1 (Freshman)",
        "ถามตอบทั่วไป (General Q&A)"
    };

    int choice;
    while (true) {
        cout << "-------------------------" << endl;
        cout << "Chatbot : กรุณาเลือกสถานะของคุณหน่อยนะครับ:" << endl;
        for (int i = 0; i < 3; i++) {
            cout << "[" << i + 1 << "] " << *(menu + i) << endl;
        }
        cout << "-------------------------" << endl;
        cout << "User (เลือกเลข 1-3): ";
        
        if (cin >> choice) {
            *statusPtr = choice;
            break; 
        } else {
            cout << "กรุณากรอกเฉพาะตัวเลข 1, 2 หรือ 3 เท่านั้นครับ" << endl;
            cin.clear(); // ล้างสถานะ Error ของ cin
            cin.ignore(1000, '\n'); // ข้ามขยะที่ User พิมพ์ค้างไว้ (ได้สูงสุด 1000 ตัวอักษร)
        }
    }
}

#include <vector>

void handleAdmission() {
    // ใช้ Vector เก็บ Keyword (Lecture 17)
    vector<string> keywords = {"รอบรับ", "คะแนน", "เครื่องกล", "คอมพิวเตอร์", "ออก"};
    
    // คำตอบยังคงใช้ Array of Pointers เพื่อความประหยัด RAM (Lecture 16) [cite: 617]
    const char *responses[] = {
        "คณะเราเปิดรับ 3 รอบหลักครับ...",
        "คะแนนย้อนหลังดูได้ที่เว็บไซต์...",
        "วิศวะเครื่องกลเน้นการออกแบบเครื่องจักร...",
        "วิศวะคอมฯ เรียนทั้ง Soft/Hard...",
        "ลาก่อนครับ!"
    };

    string userInput;
    cout << "\n--- เข้าสู่โหมด Admission ---" << endl;
    cout << "Chatbot: ยินดีมากเลยครับที่คุณสนใจมาเป็นครอบครัว Entaneer CMU!" << endl;
    cout << "คณะเรามีสาขาที่น่าสนใจเพียบเลย คุณอยากทราบข้อมูลส่วนไหนครับ?" << endl;
    cout << "เช่น 'รอบรับเข้า', 'คะแนนย้อนหลัง' หรือ 'สาขาที่เปิดรับ'" << endl;
    
    while(true) {
        cout << "User: ";
        getline(cin, userInput);

        bool found = false;
        for(size_t i = 0; i < keywords.size(); i++) {
            if (userInput.find(keywords[i]) != string::npos) {
                cout << "Chatbot: " << *(responses + i) << endl;
                if (i == 4) return; // ออกจากฟังก์ชัน
                found = true;
                cout << "\n**(พิมพ์ 'ออก' เพื่อกลับเมนูหลัก)** \nUser: ";
                break;
            }
        }
        if(!found) cout << "ไม่พบข้อมูล ลองถามใหม่อีกครั้งครับ" << endl;
    }
}

void handleFreshman() {
    cout << "\nChatbot: ยินดีด้วยนะลูกช้างใหม่! ข้อมูลตารางสอนจะประกาศเร็ว ๆ นี้ครับ" << endl;
}

void handleGeneral() {
    cout << "\nChatbot: มีเรื่องอะไรที่อยากทราบเป็นพิเศษไหมครับ? พิมพ์ถามผมได้เลย!" << endl;
}
