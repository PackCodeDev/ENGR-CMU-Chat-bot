#include <windows.h>
#include <shellapi.h>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

// data

struct MajorInfo {
    string description;
    string imageFile;
    string keywords;   // NEW
};


string trim(string str) {
    str.erase(str.begin(), find_if(str.begin(), str.end(), [](int ch) {
        return !isspace(ch);
    }));
    str.erase(find_if(str.rbegin(), str.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), str.end());
    return str;
}

bool hasKeyword(const string& text, const string& keyword) {

    string lowerText = text;
    string lowerKeyword = keyword;

    transform(lowerText.begin(), lowerText.end(), lowerText.begin(),
        [](unsigned char c) { return tolower(c); });

    transform(lowerKeyword.begin(), lowerKeyword.end(), lowerKeyword.begin(),
        [](unsigned char c) { return tolower(c); });

    return lowerText.find(lowerKeyword) != string::npos;
}

wstring stringToWstring(const string& str) {
    int size_needed = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, NULL, 0);
    wstring wstr(size_needed, 0);
    MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, &wstr[0], size_needed);
    wstr.pop_back(); // remove null terminator
    return wstr;
}

// img

void openImage(string relativePath) {

    wstring wPath = stringToWstring(relativePath);

    wchar_t fullPath[MAX_PATH];
    GetFullPathNameW(wPath.c_str(), MAX_PATH, fullPath, NULL);

    DWORD attrib = GetFileAttributesW(fullPath);

    if (attrib == INVALID_FILE_ATTRIBUTES || (attrib & FILE_ATTRIBUTE_DIRECTORY)) {
        cout << "❌ ไม่พบไฟล์: " << relativePath << endl;
        return;
    }

    HINSTANCE result = ShellExecuteW(
        NULL,
        L"open",
        fullPath,
        NULL,
        NULL,
        SW_SHOWNORMAL
    );

    if ((INT_PTR)result <= 32) {
        cout << "❌ เปิดรูปไม่สำเร็จ\n";
    }
}

map<string, string> programKeywords = {
    {"Regular", "regular ปกติ weekday"},
    {"Special", "special พิเศษ weekend working เสาร์ อาทิตย์"},
    {"International", "international inter english อินเตอร์ นานาชาติ"}
};


int main() {

    system("chcp 65001 > nul");

    cout << "===== Engineering Chatbot =====\n";

    // database

    map<string, map<string, MajorInfo>> database = {

        {"Regular", {

            {"Computer", {
                "เรียนเกี่ยวกับด้าน Hardware, Software รวมถึงระบบเครือข่ายและการจัดการข้อมูล และการเขียนโปรแกรม",
                "studyplan_photo\\Computer_regular.jpg",
                "com computer เขียนโปรแกรม"
            }},

            {"Mechanical", {
                "เป็นหัวใจของอุตสาหกรรมทุกประเภท เกี่ยวข้องกับการเคลื่อนที่ พลังงาน และการออกแบบเครื่องจักรต่างๆ",
                "studyplan_photo\\Mechanical_regular.jpg",
                "mechanical mech machine เครื่องจักร เครื่องจักรกล เครื่องกล"
            }},

            {"Semiconductor", {
                "เทคโนโลยีชิปและอุปกรณ์อิเล็กทรอนิกส์",
                "studyplan_photo\\Semiconductor_regular.jpg",
                "semiconductor semi chip ชิป"
            }},
            {"Integrated", {
                "เป็นหลักสูตรที่ยืดหยุ่น เน้นการนำองค์ความรู้หลายแขนงมาประยุกต์ใช้เพื่อตอบโจทย์อุตสาหกรรมสมัยใหม่",
                "studyplan_photo\\Integrated_regular.jpg",
                "integrated integrated บูรณาการ หลายสาขา"
            }},
            {"Electrical", {
                "ครอบคลุมตั้งแต่ความรู้ระบบไฟฟ้ากำลังที่ใช้ในเมือง ไปจนถึงระบบสื่อสารและอิเล็กทรอนิกส์ขนาดเล็ก",
                "studyplan_photo\\Electrical_regular.jpg",
                "electrical electric elec ไฟฟ้า"
            }},
            {"Civil", {
                "เน้นการออกแบบและควบคุมการก่อสร้างโครงสร้างพื้นฐาน ตั้งแต่บ้าน อาคารสูง ถนน ไปจนถึงเขื่อนและสะพาน",
                "studyplan_photo\\Civil_regular.jpg",
                "civil โยธา โครงสร้าง ก่อสร้าง ออกแบบ"
            }},
            {"Environmental", {
                "มุ่งเน้นการแก้ปัญหามลพิษและการจัดการทรัพยากรธรรมชาติเพื่อความยั่งยืน",
                "studyplan_photo\\Environmental_regular.jpg",
                "environmental ธรรมชาติ สิ่งแวดล้อม มลพิษ"
            }},
            {"REAI", {
                "รวมเอาเครื่องกล ไฟฟ้า และคอมพิวเตอร์เข้าด้วยกัน เพื่อสร้างระบบอัตโนมัติที่ชาญฉลาด",
                "studyplan_photo\\REAI_regular.jpg",
                "reai robot หุ่นยนต์ AI ai ปัญญาประดิษฐ์"
            }},
            {"Mining&Petroleum", {
                "เรียนเกี่ยวกับการสำรวจ สกัด และแปรรูปทรัพยากรธรณีและพลังงานจากใต้ดิน",
                "studyplan_photo\\Mining&Petroleum_regular.jpg",
                "mining ขุดเจาะ ปิโตรเลียม น้ำมัน"
            }},
            {"Industrial", {
                "เรียนรู้วิธีการบริหารจัดการ คน เครื่องจักร และงบประมาณ ให้ทำงานร่วมกันได้อย่างมีประสิทธิภาพสูงสุด",
                "studyplan_photo\\Industrial_regular.jpg",
                "industrial IE ie โรงงาน อุตสาหการ"
            }}
        }},

        {"Special", {

            {"Industrial", {
                "เน้นการจัดการระบบการผลิตและห่วงโซ่อุปทานที่เชื่อมโยงกันทั่วโลก เรียนวันเสาร์-อาทิตย์ เน้นคนทำงาน",
                "studyplan_photo\\Industrial_special.jpg",
                "industrial IE ie โรงงาน อุตสาหการ"
            }},

            {"Electrical", {
                "ยกระดับวิศวกรรมไฟฟ้าแบบเดิมเข้าสู่ยุคพลังงานสะอาดและระบบดิจิทัล ภาคพิเศษสำหรับผู้ทำงานแล้ว",
                "studyplan_photo\\Electrical_special.jpg",
                "electrical electric elec ไฟฟ้า"
            }},
            {"Mechanical", {
                "เป็นการนำพื้นฐานวิศวกรรมเครื่องกลมาบวกกับทักษะการบริหารจัดการแบบนักบริหาร",
                "studyplan_photo\\Mechanical_special.jpg",
                "mechanical mech machine เครื่องจักร เครื่องจักรกล เครื่องกล"
            }}

            
        }},

        {"International", {

            {"Mechanical", {
                "นอกจากเครื่องกลหลัก (Thermodynamics, Fluid) จะเน้นเรื่องการวางแผนโครงการ, การบริหารความเสี่ยง, และเศรษฐศาสตร์สำหรับวิศวกร",
                "studyplan_photo\\Mechanical_international.jpg",
                "mechanical mech machine เครื่องจักร เครื่องจักรกล เครื่องกล"
            }},

            {"Integrated", {
                "ไม่ได้เจาะจงสาขาเดียว แต่จะเน้นการแก้ปัญหาที่ต้องใช้ความรู้หลายด้าน เช่น หุ่นยนต์การแพทย์ หรือเทคโนโลยีด้านอาหาร",
                "studyplan_photo\\Integrated_international.jpg",
                "integrated integrated บูรณาการ หลายสาขา"
            }},
            {"Electrical", {
                "วิเคราะห์โครงสร้าง, เทคโนโลยีก่อสร้างสมัยใหม่, การจัดการทรัพยากรน้ำ และภาษาอังกฤษทางวิศวกรรม",
                "studyplan_photo\\Electrical_international.jpg",
                "electrical electric elec ไฟฟ้า"
            }},
            {"Civil", {
                "วิศวกรรมโยธาอินเตอร์ เน้นการออกแบบและก่อสร้างโครงสร้างพื้นฐานตามมาตรฐานสากล",
                "studyplan_photo\\Civil_international.jpg",
                "civil โยธา โครงสร้าง ก่อสร้าง ออกแบบ"
            }},
            {"ISNE", {
                "เน้นความปลอดภัยของข้อมูล ซึ่งเป็นหัวใจสำคัญของโลกดิจิทัลปัจจุบัน",
                "studyplan_photo\\ISNE_international.jpg",
                "isne information systems network security ความปลอดภัยข้อมูล"
            }},
            {"Industrial", {
                "การบริหารคลังสินค้า, ระบบขนส่ง, การวิจัยดำเนินงาน (OR), และการปรับปรุงกระบวนการแบบ Lean",
                "studyplan_photo\\Industrial_international.jpg",
                "industrial IE ie โรงงาน อุตสาหการ"
            }}
        }}
    };

    string selectedProgram = "";
    string input;

    while (true) {

        // program

        if (selectedProgram.empty()) {

            cout << "\nChoose Program (Regular / Special / International) or Exit: ";
            getline(cin, input);
            input = trim(input);

            transform(input.begin(), input.end(), input.begin(),
                [](unsigned char c) { return tolower(c); });

        if (input == "exit")
        break;

        bool programFound = false;

        // 🔥 Search directly in database keys (case-insensitive)
    for (auto& prog : database) {

        if (hasKeyword(prog.first, input)) {
            selectedProgram = prog.first;
            programFound = true;
            break;
        }
    }

        // 🔥 Extra keyword support
        if (!programFound) {

            map<string, string> programKeywords = {
            {"Regular", "reg ปกติ ปก weekday"},
            {"Special", "special พิเศษ เสาร์อาทิตย์ weekend working"},
            {"International", "inter international english eng อินเตอร์ นานาชาติ"}
        };

        for (auto& prog : programKeywords) {
            if (hasKeyword(prog.second, input)) {
                selectedProgram = prog.first;
                programFound = true;
                break;
            }
        }
    }

    if (programFound) {

            cout << "\nAvailable Majors:\n";
        for (auto& major : database[selectedProgram]) {
            cout << "- " << major.first << endl;
        }
    }
        else {
        cout << "❌ Invalid Program\n";
    }
}

        // major

        else {

            cout << "\nType Major name or Restart: ";
            getline(cin, input);
            input = trim(input);

            transform(input.begin(), input.end(), input.begin(),
                [](unsigned char c) { return tolower(c); });

            if (input == "exit")
                break;

            if (input == "restart") {
                selectedProgram = "";
            continue;
}

            bool majorFound = false;

    for (auto& major : database[selectedProgram]) {

            // Exact name match (case-insensitive)
        if (hasKeyword(major.first, input) &&
            major.first.size() == input.size()) {

        MajorInfo info = major.second;

            cout << "\n===== RESULT =====\n";
            cout << "Program : " << selectedProgram << endl;
            cout << "Major   : " << major.first << endl;
            cout << "\nDescription:\n";
            cout << info.description << endl;

            cout << "\nOpening study plan image...\n";
            openImage(major.second.imageFile);

            majorFound = true;
        break;
    }
}

    if (!majorFound) {
            cout << "🔎 Searching by keyword...\n";

    for (auto& major : database[selectedProgram]) {

        if (hasKeyword(major.second.description, input) ||
            hasKeyword(major.second.keywords, input) ||
            hasKeyword(major.first, input)) {

            cout << "\nMatched Major: " << major.first << endl;
            cout << major.second.description << endl;
            cout << "\nOpening study plan image...\n";
            openImage(major.second.imageFile);
            majorFound = true;
        }
    }

    if (!majorFound)
        cout << "No matching majors found.\n";

            }
        }
    }
}