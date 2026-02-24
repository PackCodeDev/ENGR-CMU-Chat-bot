#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

// 1. ฟังก์ชันเช็คคำสำคัญ (เหมือนในตัวอย่าง)
bool hasKeyword(string input, string keyword) {
    return input.find(keyword) != string::npos;
}

// 2. ฟังก์ชันเช็คประวัติการคุย
bool checkHistory(const vector<string>& history, string topic) {
    for (const string& item : history) {
        if (item == topic) return true;
    }
    return false;
}

// --- ฟังก์ชันย่อยที่สุด: แสดงรายละเอียดทุนแต่ละประเภท ---
void handleScholarshipDetails(int choice) {
    if (choice == 1) {
        cout << "AI: [ทุนเตรียมความพร้อม] มอบให้ 10,000 บาท สำหรับนักศึกษาที่ขาดแคลนทุนทรัพย์ในปีแรกครับ" << endl;
    } else if (choice == 2) {
        cout << "AI: [ทุนส่วนกลาง] มีประมาณ 600 ทุนต่อปี ครอบคลุมหลายสาขาวิชาครับ" << endl;
    } else if (choice == 3) {
        cout << "AI: [ทุนอธิการบดี] เป็นทุนสูงสุด ครอบคลุมค่าเล่าเรียนและมีค่าใช้จ่ายรายเดือนให้ด้วยครับ" << endl;
    }
}

// --- ฟังก์ชันเจาะลึก: เลือกประเภททุน ---
void handleScholarshipLogic() {
    string input;
    cout << "AI: ตอนนี้มีทุนที่น่าสนใจ 3 ประเภทครับ:\n1) ทุนเตรียมความพร้อม\n2) ทุนส่วนกลาง\n3) ทุนอธิการบดี\nคุณสนใจรายละเอียดของทุนไหนเป็นพิเศษไหมครับ? (พิมพ์ชื่อทุนหรือหมายเลข)" << endl;
    cout << "User: ";
    getline(cin, input);

    if (hasKeyword(input, "1") || hasKeyword(input, "เตรียม")) {
        handleScholarshipDetails(1);
    } 
    else if (hasKeyword(input, "2") || hasKeyword(input, "ส่วนกลาง")) {
        handleScholarshipDetails(2);
    }
    else if (hasKeyword(input, "3") || hasKeyword(input, "อธิการ")) {
        handleScholarshipDetails(3);
    }
    else {
        cout << "AI: ขออภัยครับ ผมยังไม่มีข้อมูลเชิงลึกของทุนนี้" << endl;
    }
}

// --- ฟังก์ชันจัดการหัวข้อหลัก (จัดการประวัติ) ---
void handleTopic(vector<string>& history, string topicName, string firstTimeMsg, string repeatMsg) {
    if (checkHistory(history, topicName)) {
        cout << "AI: " << repeatMsg << endl;
    } else {
        cout << "AI: " << firstTimeMsg << endl;
        history.push_back(topicName);
    }

    if (topicName == "ทุนการศึกษา") {
        handleScholarshipLogic();
    }
}

int main() {
    // ตั้งค่าภาษาไทย
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    string input;
    bool keepRunning = true;
    vector<string> history;

    cout << "AI: สวัสดีครับ ผมเป็นระบบช่วยค้นหาทุนการศึกษา มีอะไรให้ผมช่วยไหมครับ?" << endl;

    while (keepRunning) {
        cout << "\nUser: ";
        getline(cin, input);

        bool found = false;

        // เช็ค Keyword เกี่ยวกับทุน
        if (hasKeyword(input, "ทุน") || hasKeyword(input, "สน") || hasKeyword(input, "อยาก")) {
            handleTopic(history, "ทุนการศึกษา", 
                        "ยินดีครับ! เรื่องทุนการศึกษาเรามีข้อมูลที่อัปเดตพอดีเลย", 
                        "คุณเคยถามเรื่องทุนไปแล้วนะ อยากดูรายละเอียดทุนไหนเพิ่มเติมอีกไหม?");
            found = true;
        } 

        // เช็คคำสั่งลา
        if (hasKeyword(input, "ลา") || hasKeyword(input, "พอแล้ว") || hasKeyword(input, "ออก") || hasKeyword(input, "exit")) {
            cout << "AI: ขอบคุณที่มาปรึกษาครับ ขอให้ได้รับทุนตามที่ตั้งใจนะ! 😊" << endl;
            keepRunning = false;
            break;
        }

        if (!found) {
            cout << "AI: ผมตอบได้เฉพาะเรื่องทุนการศึกษานะครับ ลองพิมพ์คำว่า 'ทุน' ดูครับ" << endl;
        }

        if (keepRunning) {
            cout << "\nAI: มีเรื่องอื่นที่อยากทราบอีกไหมครับ?" << endl;
        }
    }
    return 0;
}