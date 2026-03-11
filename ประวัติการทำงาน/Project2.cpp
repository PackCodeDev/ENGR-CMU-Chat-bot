#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

// ฟังก์ชันช่วยเช็คคำสำคัญ (Keyword)
bool hasKeyword(string input, string keyword) {
    return input.find(keyword) != string::npos;
}

// --- ฟังก์ชันเจาะลึกรายละเอียดคณะ ---
void handleMajorDetails() {
    string input;
    cout << "AI: อยากทราบเกณฑ์ของคณะไหนดีครับ? (เช่น วิศวะ, บริหาร, วิทยาศาสตร์)" << endl;
    cout << "User: ";
    getline(cin, input);

    if (hasKeyword(input, "วิศวะ")) {
        cout << "AI: คณะวิศวกรรมศาสตร์ รอบนี้รับ 50 คนครับ ใช้คะแนน TGAT และ TPAT3 เกณฑ์ขั้นต่ำ GPAX 3.00 ครับ" << endl;
    } else if (hasKeyword(input, "บริหาร")) {
        cout << "AI: คณะบริหารธุรกิจ รับ 100 คนครับ เน้นคะแนนภาษาอังกฤษและคณิตศาสตร์ครับ" << endl;
    } else {
        cout << "AI: ขออภัยครับ ผมยังไม่มีข้อมูลเกณฑ์คะแนนของคณะนี้" << endl;
    }
}

// --- ฟังก์ชันหลักสำหรับการรับเข้าศึกษา ---
void handleAdmission() {
    string input;
    cout << "AI: คุณสนใจการรับเข้ารอบไหนเป็นพิเศษไหมครับ? (รอบ 1, 2, 3 หรือ 4)" << endl;
    cout << "User: ";
    getline(cin, input);

    if (hasKeyword(input, "1") || hasKeyword(input, "พอร์ต")) {
        cout << "AI: รอบ 1 Portfolio เน้นสะสมผลงานและการทำกิจกรรมครับ" << endl;
        handleMajorDetails(); // ถามลึกลงไปเรื่องคณะต่อ
    } 
    else if (hasKeyword(input, "3") || hasKeyword(input, "แอดมิชชั่น")) {
        cout << "AI: รอบ 3 Admission จะใช้คะแนนสอบส่วนกลางเป็นหลักครับ" << endl;
        handleMajorDetails(); // ถามลึกลงไปเรื่องคณะต่อ
    }
    else {
        cout << "AI: สำหรับรอบอื่นๆ คุณสามารถเช็คกำหนดการได้ที่หน้าเว็บไซต์หลักครับ" << endl;
    }
}

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    string input;
    bool keepRunning = true;

    cout << "AI: สวัสดีครับ ผมคือ AI ผู้ช่วยตอบคำถาม มีอะไรให้ช่วยไหมครับ?" << endl;

    while (keepRunning) {
        cout << "\nUser: ";
        getline(cin, input);

        if (hasKeyword(input, "รับเข้า") || hasKeyword(input, "สมัคร")) {
            handleAdmission(); // เรียกใช้ Function เมื่อ User สนใจเรื่องการรับเข้า
        } 
        else if (hasKeyword(input, "นักศึกษา")) {
            cout << "AI: เรื่องนักศึกษา ติดต่อได้ที่กองพัฒนานักศึกษาครับ" << endl;
        } 
        else if (hasKeyword(input, "ลา") || hasKeyword(input, "พอแล้ว") || hasKeyword(input, "หยุด")|| hasKeyword(input, "ไม่มี")|| hasKeyword(input, "เเล้ว")) {
            cout << "AI: ยินดีที่ได้ช่วยเหลือครับ ขอให้โชคดีกับการเรียนนะครับ ลาก่อน!" << endl;
            keepRunning = false;
            break;
        } 
        else {
            cout << "AI: ผมอาจจะไม่เข้าใจสิ่งที่คุณพิมพ์ กุณาพิมพ์ใหม่อีกครั้งนะครับ" << endl;
        }

        // ส่วนที่ถามว่าต้องการถามอะไรอีกไหม
        if (keepRunning) {
            cout << "\nAI: ต้องการถามอะไรเพิ่มเติมอีกไหมครับ?" << endl;
        }
    }

    return 0;
}