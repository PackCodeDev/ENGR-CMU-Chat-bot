#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

// ฟังก์ชันเช็ค keyword
bool hasKeyword(string input, string keyword) {
    return input.find(keyword) != string::npos;
}

// ฟังก์ชันเช็คประวัติ
bool checkHistory(const vector<string>& history, string topic) {
    for (const string& item : history) {
        if (item == topic) return true;
    }
    return false;
}

// แสดงรายละเอียดทุน
void showMeritScholarship(double gpa) {
    cout << "AI: 🎓 ทุนเรียนดี (Merit-based scholarship)" << endl;
    cout << "- GPA ที่ต้องการ: ≥ 3.00 – 3.50" << endl;
    cout << "- จำนวนเงิน: 5,000 – 20,000 บาท/ปี" << endl;
    cout << "- แหล่งทุน: คณะวิศวะ, มช., บริษัทเอกชน" << endl;

    if (gpa >= 3.50)
        cout << "AI: GPA ของคุณมีโอกาสได้รับทุนนี้สูงมากครับ ✅" << endl;
    else if (gpa >= 3.00)
        cout << "AI: GPA ของคุณสามารถสมัครทุนนี้ได้ครับ" << endl;
    else
        cout << "AI: GPA อาจยังไม่ถึงเกณฑ์ของทุนเรียนดีครับ" << endl;
}

void showNeedScholarship(double gpa) {
    cout << "AI: 🎓 ทุนขาดแคลนทุนทรัพย์" << endl;
    cout << "- GPA ขั้นต่ำ: ≥ 2.00" << endl;
    cout << "- จำนวนเงิน: 5,000 – 30,000 บาท/ปี" << endl;
    cout << "- บางทุนให้ 1,000 – 3,000 บาท/เดือน" << endl;
    cout << "- ใช้เอกสารรับรองรายได้ผู้ปกครอง" << endl;

    if (gpa >= 2.00)
        cout << "AI: คุณมีคุณสมบัติสมัครทุนนี้ได้ครับ ✅" << endl;
    else
        cout << "AI: GPA ยังต่ำกว่าเกณฑ์ขั้นต่ำครับ" << endl;
}

void showCorporateScholarship() {
    cout << "AI: 🎓 ทุนจากบริษัท (SCG, PTT, AIS ฯลฯ)" << endl;
    cout << "- จำนวนเงิน: 20,000 – 100,000 บาท/ปี" << endl;
    cout << "- บางทุนต้องทำงานกับบริษัทหลังจบ 2–3 ปี" << endl;
}

void showActivityScholarship() {
    cout << "AI: 🎓 ทุนกิจกรรม / ความสามารถพิเศษ" << endl;
    cout << "- สำหรับคนที่แข่งขัน Robot, Programming, กีฬา" << endl;
    cout << "- จำนวนเงิน: 5,000 – 30,000 บาท" << endl;
}

// ฟังก์ชันเจาะลึกทุน
void handleScholarshipLogic() {

    string input;

    cout << "AI: ทุนของวิศวะ มช. มี 4 ประเภทหลักครับ:" << endl;
    cout << "1) ทุนเรียนดี" << endl;
    cout << "2) ทุนขาดแคลนทุนทรัพย์" << endl;
    cout << "3) ทุนจากบริษัท" << endl;
    cout << "4) ทุนกิจกรรม / ความสามารถพิเศษ" << endl;
    cout << "AI: คุณสนใจทุนประเภทไหน?" << endl;

    cout << "User: ";
    getline(cin, input);

    if (hasKeyword(input,"1") || hasKeyword(input,"เรียนดี")) {

        cout << "AI: กรุณาใส่ GPA ของคุณ:" << endl;
        cout << "User: ";
        getline(cin, input);

        double gpa = stod(input);
        showMeritScholarship(gpa);
    }

    else if (hasKeyword(input,"2") || hasKeyword(input,"ขาดแคลน")) {

        cout << "AI: กรุณาใส่ GPA ของคุณ:" << endl;
        cout << "User: ";
        getline(cin, input);

        double gpa = stod(input);
        showNeedScholarship(gpa);
    }

    else if (hasKeyword(input,"3") || hasKeyword(input,"บริษัท")) {

        showCorporateScholarship();
    }

    else if (hasKeyword(input,"4") || hasKeyword(input,"กิจกรรม")) {

        showActivityScholarship();
    }

    else {
        cout << "AI: ขออภัยครับ กรุณาเลือก 1-4" << endl;
    }

    cout << "\nAI: 📅 ทุนส่วนใหญ่เปิดสมัคร:" << endl;
    cout << "- เทอม 1: ส.ค. – ก.ย." << endl;
    cout << "- เทอม 2: ม.ค. – ก.พ." << endl;
}

// จัดการหัวข้อ
void handleTopic(vector<string>& history,
                 string topicName,
                 string firstTimeMsg,
                 string repeatMsg) {

    if (checkHistory(history, topicName)) {
        cout << "AI: " << repeatMsg << endl;
    }
    else {
        cout << "AI: " << firstTimeMsg << endl;
        history.push_back(topicName);
    }

    if (topicName == "ทุนการศึกษา") {
        handleScholarshipLogic();
    }
}

int main() {

    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    string input;
    string name;
    bool keepRunning = true;

    vector<string> history;

    cout << "AI: สวัสดีครับ ยินดีต้อนรับสู่ ENGR CMU bot 🙂" << endl;
    cout << "AI: ขอทราบชื่อของคุณ:" << endl;

    cout << "User: ";
    getline(cin, name);

    cout << "AI: ยินดีที่ได้รู้จักครับ คุณ "
         << name
         << endl;

    while (keepRunning) {

        cout << "\nUser: ";
        getline(cin, input);

        bool found = false;

        if (hasKeyword(input,"ทุน")) {

            handleTopic(
                history,
                "ทุนการศึกษา",
                "ผมสามารถแนะนำทุนที่เหมาะกับคุณได้ครับ",
                "เราคุยเรื่องทุนไปแล้ว ต้องการดูเพิ่มเติมไหม?"
            );

            found = true;
        }

        if (hasKeyword(input,"exit")
        || hasKeyword(input,"ออก")
        || hasKeyword(input,"ลา")) {

            cout << "AI: ลาก่อนครับ ขอให้ได้ทุนที่ต้องการ 🙂" << endl;
            break;
        }

        if (!found) {
            cout << "AI: ผมตอบได้เกี่ยวกับ 'ทุน' เท่านั้นครับ" << endl;
        }

        if (keepRunning) {
            cout << "AI: มีอะไรอยากถามเพิ่มเติมไหม?" << endl;
        }
    }

    return 0;
}