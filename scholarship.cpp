#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

bool hasKeyword(string input, string keyword) {
    return input.find(keyword) != string::npos;
}

int main() {
    system("chcp 65001");
    string input;
    string selectedScholarship = "";

    while(true) {


        cout << "\nAI: สนใจทุนการศึกษาไหมครับ?\n";
        cout << "You: ";
        getline(cin, input);

        if(hasKeyword(input, "exit")) {
            cout << "AI: ขอบคุณที่ใช้บริการครับ 😊\n";
            break;
        }

        if(hasKeyword(input, "อยาก") ||
           hasKeyword(input, "ทุน") ||
           hasKeyword(input, "สนใจ")){

            cout << "\nAI: มีทุนดังนี้\n";
            cout << "1) ทุนเตรียมความพร้อม\n";
            cout << "2) ทุนส่วนกลาง\n";
            cout << "3) ทุนอธิการบดี\n";

            cout << "\nAI: สนใจทุนไหน?\n";
            cout << "You: ";
            getline(cin, input);

            if(input == "1" || input.find("เตรียม") != string::npos) {
                selectedScholarship = "ทุนเตรียมความพร้อม";
                cout << "-> ให้ 10,000 บาท สำหรับผู้ขาดแคลนทุนทรัพย์\n";
            }
            else if(input == "2" || input.find("ส่วนกลาง") != string::npos) {
                selectedScholarship = "ทุนส่วนกลาง";
                cout << "-> ประมาณ 600 ทุนต่อปี\n";
            }
            else if(input == "3" || input.find("อธิการ") != string::npos) {
                selectedScholarship = "ทุนอธิการบดี";
                cout << "-> ครอบคลุมค่าเล่าเรียนและค่าใช้จ่าย\n";
            }
            else {
                cout << "AI: ไม่พบทุนที่ระบุ\n";
                continue;
            }
        }
        else {
            cout << "AI: ผมตอบได้เฉพาะเรื่องทุนการศึกษานะครับ 😊\n";
        }
    }

    return 0;
}