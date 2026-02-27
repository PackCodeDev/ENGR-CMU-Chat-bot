#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <algorithm>

using namespace std;

struct Major {
    string key;
    string displayName;
    string description;
    string imageSuffix;
    string deepDetail; 
};

void openImage(string path) {
    HINSTANCE result = ShellExecuteA(NULL, "open", path.c_str(), NULL, NULL, SW_SHOWNORMAL);
    if ((INT_PTR)result <= 32) {
        cout << "AI: ขออภัยครับ หากติดตรงนี้สามารถแจ้งผ่านทางแอดมินได้เลยครับ" << endl;
    } else {
        cout << "AI: เรียบร้อยครับ! ผมเปิดรูปแผนการเรียนให้ดูแล้วนะ" << endl;
    }
}

// ไม่สนใจอักษรเล็กใหญ่ ภาษาอังกฤษ
bool hasKeyword(string input, string keyword) {
    if (input.empty() || keyword.empty()) return false;
    return input.find(keyword) != string::npos;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // 1. ภาคปกติ (Regular Majors)
    vector<Major> regularMajors = {
        {"คอมพิวเตอร์", "Computer Engineering", "Software, AI, Cloud, และ Data Science", "_reg.jpg", 
         "● ปี 1: ปูพื้นฐาน Calculus, Physics และ Computer Programming (C/Python) ฝึก Logic เบื้องต้น\n"
         "● ปี 2: เข้าสู่แกนหลัก Computer Engineering เจอ Data Structures, Discrete Math, Digital Logic และเริ่ม Circuit\n"
         "● ปี 3: ปีมหาโหด! เรียน Operating Systems, Database, Network, Software Engineering และ Microprocessors\n"
         "● ปี 4: เลือกวิชาเลือกเฉพาะทาง (AI, Security, Cloud) และทำ Senior Project ตลอดทั้งปี"},
        {"เครื่องกล", "Mechanical Engineering", "พลังงาน, ยานยนต์, และการออกแบบเครื่องจักร", "_reg.jpg", 
         "● ปี 1: เน้น Physics, Calculus และวิชา Engineering Drawing (หัดวาดแบบวิศวกรรมทั้งมือและ CAD)\n"
         "● ปี 2: เริ่มวิชาคำนวณแรงหลัก Statics, Dynamics, Thermodynamics และพื้นฐานวัสดุวิศวกรรม\n"
         "● ปี 3: เจาะลึก Fluid Mechanics, Heat Transfer, Machine Design และเครื่องจักรกลความร้อน\n"
         "● ปี 4: เลือกสายเจาะลึก (Automotive/Energy) และทำโครงงานวิศวกรรมเครื่องกล"},
        {"ไฟฟ้า", "Electrical Engineering", "ระบบไฟฟ้ากำลัง, อิเล็กทรอนิกส์ และสมาร์ทคอนโทรล", "_reg.jpg", 
         "● ปี 1: พื้นฐานวิศวกรรม เน้นฟิสิกส์ไฟฟ้าและแม่เหล็ก และคณิตศาสตร์วิศวกรรม\n"
         "● ปี 2: เข้าสู่หัวใจอย่าง Circuit Analysis 1-2, Digital Circuit และสัญญาณและระบบ (Signals)\n"
         "● ปี 3: เรียน Electromagnetic Fields, Machines, ระบบควบคุม และการส่งจ่ายกำลังไฟฟ้า\n"
         "● ปี 4: แยกสายกำลังหรืออิเล็กทรอนิกส์ขั้นสูง และทำ Senior Project"},
        {"โยธา", "Civil Engineering", "ออกแบบโครงสร้าง, ถนน, การสำรวจ และงานฐานราก", "_reg.jpg", 
         "● ปี 1: พื้นฐานวิศวกรรมและ Drawing เพื่อหัดอ่านและวาดแบบแปลนก่อสร้าง\n"
         "● ปี 2: เริ่มคำนวณ Mechanics of Solids และออกฝึกสำรวจ (Surveying) กลางแจ้ง\n"
         "● ปี 3: ออกแบบคอนกรีตเสริมเหล็ก (RC Design), โครงสร้างเหล็ก และวิศวกรรมฐานราก (Soil Mech)\n"
         "● ปี 4: การบริหารงานก่อสร้าง, ชลศาสตร์ และทำโครงการจบวิศวกรรมโยธา"},
        {"อุตสาหการ", "Industrial Engineering", "การเพิ่มประสิทธิภาพการผลิต, บริหารจัดการ และโลจิสติกส์", "_reg.jpg", 
         "● ปี 1: พื้นฐานวิศวกรรมทั่วไป และวิชาเคมีสำหรับวิศวกร\n"
         "● ปี 2: สถิติวิศวกรรม (Engineering Stat), กรรมวิธีการผลิต และพื้นฐานความปลอดภัย\n"
         "● ปี 3: ปีแห่งการวางแผน! เรียน Operations Research (OR), คุมคุณภาพ (QC), เศรษฐศาสตร์วิศวกรรม\n"
         "● ปี 4: การจัดการโลจิสติกส์, การออกแบบโรงงาน และ Senior Project"},
        {"สิ่งแวดล้อม", "Environmental Engineering", "การจัดการน้ำ, อากาศ, มลพิษ และสิ่งแวดล้อมยั่งยืน", "_reg.jpg", 
         "● ปี 1: เน้นพื้นฐานเคมีสิ่งแวดล้อมและชีววิทยามากเป็นพิเศษ\n"
         "● ปี 2: ระบบประปา, ระบบระบายน้ำ, จุลชีววิทยาสิ่งแวดล้อม และกลศาสตร์ของไหล\n"
         "● ปี 3: ระบบบำบัดน้ำเสียขั้นสูง, มลพิษทางอากาศ และการจัดการขยะมูลฝอยและของเสียอันตราย\n"
         "● ปี 4: การประเมินผลกระทบสิ่งแวดล้อม (EIA), พลังงานสะอาด และ Senior Project"},
        {"เหมืองแร่", "Mining & Petroleum Engineering", "ทรัพยากรธรณี, การขุดเจาะ และวิศวกรรมปิโตรเลียม", "_reg.jpg", 
         "● ปี 1: พื้นฐานธรณีวิทยา (Physical Geology) และพื้นฐานวิศวกรรม\n"
         "● ปี 2: การทำเหมืองเปิด, เหมืองใต้ดิน, การวิเคราะห์สินแร่ และการสำรวจธรณี\n"
         "● ปี 3: การระเบิดหิน, Rock Mechanics, การแต่งแร่ และเศรษฐศาสตร์ทรัพยากรธรณี\n"
         "● ปี 4: ออกแบบเหมือง, วิศวกรรมปิโตรเลียมเบื้องต้น และโครงงานจบการศึกษา"},
        {"หุ่นยนต์", "REAI (Robotics & AI)", "บูรณาการหุ่นยนต์, ปัญญาประดิษฐ์ และระบบอัตโนมัติ", "_reg.jpg", 
         "● ปี 1: เริ่มฝึก Robotics Programming ทันทีควบคู่ไปกับพื้นฐาน Physics/Math\n"
         "● ปี 2: เรียนเรื่อง Sensor, Actuators, Embedded Systems และระบบควบคุมหุ่นยนต์\n"
         "● ปี 3: เจาะลึก AI for Robotics, Machine Vision, Kinematics และการออกแบบกลไกแขนกล\n"
         "● ปี 4: เน้นการทำ Project-Based ร่วมกับภาคอุตสาหกรรมนวัตกรรมหุ่นยนต์สมัยใหม่"},
        {"บูรณาการ", "Integrated Engineering", "การเรียนรู้แบบพหุวิทยาการเพื่อตอบโจทย์นวัตกรรม", "_reg.jpg", 
         "● ปี 1-4: เน้นการเรียนแบบโมดูล (Module) และ Project-based Learning \nเรียนรู้ข้ามศาสตร์ระหว่างคอมพิวเตอร์ ไฟฟ้า และเครื่องกล"}
    };

    // 2. ภาคพิเศษ (Special Programs)
    vector<Major> specialMajors = {
        {"เครื่องกล", "Mechanical & Project Management", "เครื่องกลและการบริหารโครงการวิศวกรรม", "_spec.jpg", 
         "● ปี 1-2: เน้นวิชาแกนวิศวกรรมเครื่องกล (Thermo, Fluid, Statics)\n● ปี 3-4: เสริมทักษะบริหารจัดการโครงการ (Project Management)"},
        {"โยธา", "Civil Engineering (Special)", "วิศวกรรมโยธา (ภาคพิเศษ)", "_spec.jpg", 
         "● ปี 1-4: หลักสูตรเหมือนภาคปกติทุกประการ แต่เน้นคาบเรียนที่ยืดหยุ่น"},
        {"อุตสาหการ", "IE & Logistics Management", "อุตสาหการและการจัดการโลจิสติกส์", "_spec.jpg", 
         "● ปี 1-2: แกนวิศวกรรมอุตสาหการ\n● ปี 3-4: เจาะลึกการบริหารคลังสินค้า และระบบขนส่งอัจฉริยะ"},
        {"ไฟฟ้า", "Smart Grid Technology", "ไฟฟ้าและเทคโนโลยีโครงข่ายไฟฟ้าอัจฉริยะ", "_spec.jpg", 
         "● ปี 1-2: พื้นฐานไฟฟ้าและอิเล็กทรอนิกส์\n● ปี 3-4: เน้นระบบ Smart Grid และพลังงานทดแทน"}
    };

    // 3. ภาคนานาชาติ (International Programs)
    vector<Major> interMajors = {
        {"ระบบสารสนเทศ", "ISNE & Cyber Security", "ระบบสารสนเทศและความปลอดภัยไซเบอร์ (Inter)", "_inter.jpg", 
         "● ปี 1: Computing Fundamentals\n● ปี 2: Cyber Security\n● ปี 3: Network Security, Cloud Infrastructure\n● ปี 4: International Internship"},
        {"บูรณาการ", "Inter & Multi-disciplinary", "บูรณาการและพหุวิทยาการ (International)", "_inter.jpg", 
         "● ปี 1-4: เรียนเป็นภาษาอังกฤษทั้งหมด เน้น Systems Thinking และงานวิจัยข้ามศาสตร์"},
        {"เซมิคอนดักเตอร์", "Semiconductor Engineering", "วิศวกรรมเซมิคอนดักเตอร์ (Inter)", "_inter.jpg", 
         "● ปี 1: Physics of Semiconductor\n● ปี 2: IC Design, VLSI\n● ปี 3: Semiconductor Fabrication\n● ปี 4: Internship ในอุตสาหกรรมชิปประมวลผล"}
    };

    string input, userName;
    string currentMode = "SELECT_PROGRAM";
    vector<Major>* currentList = nullptr;
    string programName = "";
    Major* selectedMajor = nullptr;

    cout << "AI: สวัสดีครับ! ผมเป็น AI ผู้ช่วยแนะนำหลักสูตรวิศวกรรมศาสตร์ มช. นะครับ" << endl;
    cout << "AI: ก่อนที่เราจะเริ่มกัน ไม่ทราบว่าคุณชื่ออะไรครับ?" << endl;
    cout << "คุณ: "; getline(cin, userName);
    if(userName.empty()) userName = "คุณผู้ใช้งาน";

    cout << "\nAI: ยินดีที่ได้รู้จักครับคุณ " << userName << "!" << endl;
    cout << "AI: ตอนนี้คุณสนใจดูข้อมูลภาคไหนอยู่ครับ? (ปกติ / พิเศษ / นานาชาติ)" << endl;

    while (true) {
        cout << "\n" << userName << ": ";
        if (!getline(cin, input) || input.empty()) continue;

        if (hasKeyword(input, "ออก") || hasKeyword(input, "พอแล้ว") || hasKeyword(input, "จบ")) {
            cout << "AI: ขอบคุณมากครับคุณ " << userName << " ที่มาพูดคุยกับผม ขอให้โชคดีกับเส้นทาง Entaneer นะครับ!" << endl;
            break;
        }

        if (hasKeyword(input, "เริ่มใหม่") || hasKeyword(input, "เปลี่ยนภาค")) {
            currentMode = "SELECT_PROGRAM";
            currentList = nullptr;
            cout << "AI: ได้เลยครับ ย้อนกลับมาให้เลือกภาคใหม่แล้ว คุณสนใจภาคไหนครับ? (ปกติ/พิเศษ/นานาชาติ(อินเตอร์))" << endl;
            continue;
        }

        if (currentMode == "SELECT_PROGRAM") {
            if (hasKeyword(input, "ปกติ") || (hasKeyword(input, "ภาคปกติ")) {
                currentList = &regularMajors; programName = "ภาคปกติ"; currentMode = "SELECT_MAJOR";
                cout << "AI: ภาคปกติมีสาขาเยอะเลยครับ เช่น คอม, เครื่องกล, ไฟฟ้า, โยธา, หุ่นยนต์... อยากดูสาขาไหนก่อนดีครับ?" << endl;
            } else if (hasKeyword(input, "พิเศษ") || (hasKeyword(input, "ภาคพิเศษ")) {
                currentList = &specialMajors; programName = "ภาคพิเศษ"; currentMode = "SELECT_MAJOR";
                cout << "AI: ภาคพิเศษจะมี เครื่องกล, โยธา, อุตสาหการ และไฟฟ้าครับ สนใจสาขาไหนแจ้งได้เลย" << endl;
            } else if (hasKeyword(input, "นานาชาติ") || hasKeyword(input, "อินเตอร์")) {
                currentList = &interMajors; programName = "นานาชาติ"; currentMode = "SELECT_MAJOR";
                cout << "AI: ภาคนานาชาติมี ISNE, บูรณาการ และเซมิคอนดักเตอร์ครับ อยากดูตัวไหนดี?" << endl;
            } else {
                cout << "AI: ผมเข้าใจแค่ 'ปกติ', 'พิเศษ' หรือ 'นานาชาติ(อินเตอร์)' ครับ ลองระบุใหม่อีกทีนะ" << endl;
            }
        }
        else if (currentMode == "SELECT_MAJOR") {
            bool found = false;
            for (auto& m : *currentList) {
                if (hasKeyword(input, m.key)) {
                    selectedMajor = &m;
                    cout << "\nAI: ได้เลยครับ ข้อมูลของสาขา " << m.displayName << " คือ..." << endl;
                    cout << "AI: " << m.description << endl;

                    string fullPath = "studyplan_photo\\" + m.displayName + m.imageSuffix;
                    openImage(fullPath);

                    cout << "\nAI: คุณ " << userName << " อยากให้ผม 'เจาะลึก' Roadmap วิชาเรียน 4 ปีของสาขานี้ไหมครับ?" << endl;
                    currentMode = "CONFIRM_DEEP_DIVE"; found = true; break;
                }
            }
            if (!found) cout << "AI: ผมหาชื่อสาขาไม่เจอเลยครับ ลองพิมพ์ชื่อหลัก เช่น 'คอม' หรือ 'โยธา' ดูนะครับ" << endl;
        }
        else if (currentMode == "CONFIRM_DEEP_DIVE") {
            if (hasKeyword(input, "ใช่") || hasKeyword(input, "สนใจ") || hasKeyword(input, "จัดมา")) {
                cout << "\n--- [ ข้อมูลเจาะลึกวิชาเรียน: " << selectedMajor->displayName << " ] ---" << endl;
                cout << selectedMajor->deepDetail << endl;
                cout << "------------------------------------------------------------" << endl;
                cout << "\nAI: หวังว่าข้อมูลนี้จะช่วยได้นะ! สนใจดูสาขาอื่นใน" << programName << " ต่อไหม? หรือจะ 'เริ่มใหม่' ดีครับ?" << endl;
                currentMode = "SELECT_MAJOR";
            } else {
                cout << "AI: รับทราบครับ งั้นเลือกดูสาขาอื่นใน" << programName << " ต่อได้เลยนะ" << endl;
                currentMode = "SELECT_MAJOR";
            }
        }
    }
    return 0;
}