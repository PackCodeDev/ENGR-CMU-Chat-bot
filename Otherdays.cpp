#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

bool hasKeyword(string input, string keyword) {
    return input.find(keyword) != string::npos;
}

int main() {

    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    string input;
    string name;
    bool keepRunning = true;

    vector<string> history;

    // ===== ข้อมูลขึ้นดอย =====
    bool hasDoiSchedule = false;
    string doiDate = "15 พฤศจิกายน 2569";

    // ===== เปิด / ปิดเรียน =====
    string openDate = "1 มิถุนายน 2569";
    string closeDate = "30 มีนาคม 2570";

    // ===== วันดรอป (ติด W) =====
    bool hasDropDate = true;
    string dropDateTerm1 = "31 สิงหาคม 2569";
    string dropDateTerm2 = "15 มกราคม 2570";

    // ===== ข่าวสาร =====
    string newsLink = "https://eng.cmu.ac.th/?page_id=21937";

    // ===== วันหยุดราชการ =====
    vector<vector<string>> monthKeywords = {
        {"มกราคม","มกรา","ม.ค"},
        {"กุมภาพันธ์","กุมภา","ก.พ"},
        {"มีนาคม","มีนา","มี.ค"},
        {"เมษายน","เมษา","เม.ย"},
        {"พฤษภาคม","พฤษภา","พ.ค"},
        {"มิถุนายน","มิถุนา","มิ.ย"},
        {"กรกฎาคม","กรกฎา","ก.ค"},
        {"สิงหาคม","สิงหา","ส.ค"},
        {"กันยายน","กันยา","ก.ย"},
        {"ตุลาคม","ตุลา","ต.ค"},
        {"พฤศจิกายน","พฤศจิกา","พ.ย"},
        {"ธันวาคม","ธันวา","ธ.ค"}
    };

    vector<string> holidays = {
        "1 ม.ค. วันขึ้นปีใหม่",
        "ไม่มีวันหยุดราชการ",
        "ไม่มีวันหยุดราชการ",
        "6 เม.ย. วันจักรี\n13–15 เม.ย. วันสงกรานต์",
        "1 พ.ค. วันแรงงานแห่งชาติ\n4 พ.ค. วันฉัตรมงคล",
        "3 มิ.ย. วันเฉลิมพระชนมพรรษาสมเด็จพระราชินี",
        "28 ก.ค. วันเฉลิมพระชนมพรรษาพระบาทสมเด็จพระเจ้าอยู่หัว",
        "12 ส.ค. วันแม่แห่งชาติ",
        "ไม่มีวันหยุดราชการ",
        "13 ต.ค. วันนวมินทรมหาราช\n23 ต.ค. วันปิยมหาราช",
        "ไม่มีวันหยุดราชการ",
        "5 ธ.ค. วันพ่อแห่งชาติ\n10 ธ.ค. วันรัฐธรรมนูญ\n31 ธ.ค. วันสิ้นปี"
    };

    cout << "กรุณาพิมพ์ชื่อของคุณ: ";
    getline(cin, name);
    cout << "สวัสดี " << name << endl;

    while (keepRunning) {

        cout << "\nอยากถามอะไรเพิ่มเติม (หรือพิมพ์ exit เพื่อออก): ";
        getline(cin, input);
        history.push_back(input);

        if (input == "exit") {
            keepRunning = false;
        }

        else {

            // ===== ตรวจเดือน =====
            bool foundMonth = false;

            for (int i = 0; i < 12; i++) {
                for (string keyword : monthKeywords[i]) {
                    if (hasKeyword(input, keyword)) {
                        cout << "วันหยุดราชการเดือน"
                             << monthKeywords[i][0] << ":\n"
                             << holidays[i] << endl;
                        foundMonth = true;
                        break;
                    }
                }
                if (foundMonth) break;
            }

            if (foundMonth) continue;

            // ===== วันขึ้นดอย =====
            if (hasKeyword(input, "ขึ้นดอย")) {

                if (hasDoiSchedule)
                    cout << "วันขึ้นดอยคือ " << doiDate << endl;
                else
                    cout << "ยังไม่ประกาศวันแน่นอน" << endl;
            }

            // ===== เปิด / ปิดเรียน =====
            else if (hasKeyword(input, "เปิดเรียน") || hasKeyword(input, "ปิดเรียน")) {

                cout << "วันเปิดเรียน: " << openDate << endl;
                cout << "วันปิดเรียน: " << closeDate << endl;
            }

            // ===== วันดรอป (รองรับ ภาคเรียน) =====
            else if (hasKeyword(input, "ดรอป") || hasKeyword(input, "W")) {

                if (!hasDropDate) {
                    cout << "ยังไม่ประกาศวันดรอปวิชา" << endl;
                }

                else if (hasKeyword(input, "1") ||
                         hasKeyword(input, "เทอม1") ||
                         hasKeyword(input, "เทอม 1") ||
                         hasKeyword(input, "ภาคเรียน1") ||
                         hasKeyword(input, "ภาคเรียน 1")) {

                    cout << "วันสุดท้ายดรอปวิชา (ติด W) ภาคเรียนที่ 1 คือ "
                         << dropDateTerm1 << endl;
                }

                else if (hasKeyword(input, "2") ||
                         hasKeyword(input, "เทอม2") ||
                         hasKeyword(input, "เทอม 2") ||
                         hasKeyword(input, "ภาคเรียน2") ||
                         hasKeyword(input, "ภาคเรียน 2")) {

                    cout << "วันสุดท้ายดรอปวิชา (ติด W) ภาคเรียนที่ 2 คือ "
                         << dropDateTerm2 << endl;
                }

                else {
                    cout << "วันดรอปวิชา (ติด W)\n";
                    cout << "ภาคเรียนที่ 1: " << dropDateTerm1 << endl;
                    cout << "ภาคเรียนที่ 2: " << dropDateTerm2 << endl;
                }
            }

            // ===== ข่าวสาร =====
            else if (hasKeyword(input, "ข่าว") ||
                     hasKeyword(input, "ข่าวสาร") ||
                     hasKeyword(input, "เว็บไซต์")) {

                cout << "สามารถติดตามข้อมูลข่าวสารได้ที่:\n"
                     << newsLink << endl;
            }

            else {
                cout << "ขออภัย ไม่พบข้อมูล" << endl;
            }
        }
    }

    cout << "\nประวัติการถาม:\n";
    for (string h : history)
        cout << "- " << h << endl;

    return 0;
}