#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class Chatbot {
private:
    bool hasDoiSchedule = false;
    string doiDate = "15 พฤศจิกายน 2569";

    string openDate = "1 มิถุนายน 2569";
    string closeDate = "30 มีนาคม 2570";

    string dropTerm1 = "31 สิงหาคม 2569";
    string dropTerm2 = "15 มกราคม 2570";

    string newsLink = "https://eng.cmu.ac.th/?page_id=21937";

public:

    int checkCommand(string input) {

        if (input.find("ขึ้นดอย") != string::npos)
            return 1;

        else if (input.find("เปิดเรียน") != string::npos || input.find("ปิดเรียน") != string::npos)
            return 2;

        else if (input.find("ดรอป") != string::npos ||
                 input.find("drop") != string::npos ||
                 input.find("W") != string::npos ||
                 input.find("w") != string::npos)
            return 3;

        else if (input.find("ข่าว") != string::npos)
            return 4;

        else if (input.find("มกราคม") != string::npos || input.find("มกรา") != string::npos)
            return 5;

        else if (input.find("กุมภาพันธ์") != string::npos || input.find("กุมภา") != string::npos)
            return 6;

        else if (input.find("มีนาคม") != string::npos || input.find("มีนา") != string::npos)
            return 7;

        else if (input.find("เมษายน") != string::npos || input.find("เมษา") != string::npos)
            return 8;

        else if (input.find("พฤษภาคม") != string::npos || input.find("พฤษภา") != string::npos)
            return 9;

        else if (input.find("มิถุนายน") != string::npos || input.find("มิถุนา") != string::npos)
            return 10;

        else if (input.find("กรกฎาคม") != string::npos || input.find("กรกฎา") != string::npos)
            return 11;

        else if (input.find("สิงหาคม") != string::npos || input.find("สิงหา") != string::npos)
            return 12;

        else if (input.find("กันยายน") != string::npos || input.find("กันยา") != string::npos)
            return 13;

        else if (input.find("ตุลาคม") != string::npos || input.find("ตุลา") != string::npos)
            return 14;

        else if (input.find("พฤศจิกายน") != string::npos || input.find("พฤศจิกา") != string::npos)
            return 15;

        else if (input.find("ธันวาคม") != string::npos || input.find("ธันวา") != string::npos)
            return 16;

        return 0;
    }

    void answer(int cmd, string input) {

        switch (cmd) {

        case 1:
            if (hasDoiSchedule)
                cout << "วันขึ้นดอยคือ " << doiDate << endl;
            else
                cout << "ยังไม่ประกาศวันแน่นอน" << endl;
            break;

        case 2:
            cout << "วันเปิดเรียน: " << openDate << endl;
            cout << "วันปิดเรียน: " << closeDate << endl;
            break;

        case 3:

            if (input.find("1") != string::npos)
                cout << "วันดรอปวิชา (ติด W) ภาคเรียนที่ 1: " << dropTerm1 << endl;

            else if (input.find("2") != string::npos)
                cout << "วันดรอปวิชา (ติด W) ภาคเรียนที่ 2: " << dropTerm2 << endl;

            else {
                cout << "วันดรอปวิชา (ติด W)" << endl;
                cout << "ภาคเรียนที่ 1: " << dropTerm1 << endl;
                cout << "ภาคเรียนที่ 2: " << dropTerm2 << endl;
            }

            break;

        case 4:
            cout << "ติดตามข่าวสารได้ที่:\n" << newsLink << endl;
            break;

        case 5:
            cout << "เดือนมกราคม: 1 ม.ค. วันขึ้นปีใหม่" << endl;
            break;

        case 6:
            cout << "เดือนกุมภาพันธ์: ไม่มีวันหยุดราชการ" << endl;
            break;

        case 7:
            cout << "เดือนมีนาคม: ไม่มีวันหยุดราชการ" << endl;
            break;

        case 8:
            cout << "เดือนเมษายน:\n6 เม.ย. วันจักรี\n13-15 เม.ย. วันสงกรานต์" << endl;
            break;

        case 9:
            cout << "เดือนพฤษภาคม:\n1 พ.ค. วันแรงงาน\n4 พ.ค. วันฉัตรมงคล" << endl;
            break;

        case 10:
            cout << "เดือนมิถุนายน: 3 มิ.ย. วันเฉลิมพระชนมพรรษาพระราชินี" << endl;
            break;

        case 11:
            cout << "เดือนกรกฎาคม: 28 ก.ค. วันเฉลิมพระชนมพรรษา ร.10" << endl;
            break;

        case 12:
            cout << "เดือนสิงหาคม: 12 ส.ค. วันแม่แห่งชาติ" << endl;
            break;

        case 13:
            cout << "เดือนกันยายน: ไม่มีวันหยุดราชการ" << endl;
            break;

        case 14:
            cout << "เดือนตุลาคม:\n13 ต.ค. วันนวมินทรมหาราช\n23 ต.ค. วันปิยมหาราช" << endl;
            break;

        case 15:
            cout << "เดือนพฤศจิกายน: ไม่มีวันหยุดราชการ" << endl;
            break;

        case 16:
            cout << "เดือนธันวาคม:\n5 ธ.ค. วันพ่อ\n10 ธ.ค. วันรัฐธรรมนูญ\n31 ธ.ค. วันสิ้นปี" << endl;
            break;

        default:
            cout << "ขออภัย ไม่พบข้อมูล" << endl;
        }
    }
};

int main() {

    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    Chatbot bot;

    string name;
    string input;

    cout << "กรุณาพิมพ์ชื่อของคุณ: ";
    getline(cin, name);

    cout << "สวัสดี " << name << endl;

    while (true) {

        cout << "\nอยากถามอะไรเพิ่มเติม (หรือพิมพ์ exit เพื่อออก): ";
        getline(cin, input);

        if (input == "exit")
            break;

        int cmd = bot.checkCommand(input);

        bot.answer(cmd, input);
    }

    return 0;
}