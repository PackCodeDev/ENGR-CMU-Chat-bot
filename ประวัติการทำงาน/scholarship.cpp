#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

class Chatbot {

private:

    vector<string> history;

public:

    bool hasKeyword(string input,string keyword) {
        return input.find(keyword) != string::npos;
    }

    bool checkHistory(string topic) {

        for(string item : history){
            if(item == topic)
                return true;
        }

        return false;
    }

    void addHistory(string topic){
        history.push_back(topic);
    }

    int checkCommand(string input){

        if(hasKeyword(input,"ทุน"))
            return 1;

        if(hasKeyword(input,"exit") || hasKeyword(input,"ออก") || hasKeyword(input,"ลา"))
            return 2;

        return 0;
    }

    void showMerit(double gpa){

        cout << "AI: ทุนเรียนดี\n";
        cout << "- GPA ≥ 3.00\n";
        cout << "- เงินทุน 5,000 – 20,000 บาท\n";

        if(gpa >= 3.50)
            cout << "AI: คุณมีโอกาสได้ทุนสูงมาก\n";
        else if(gpa >= 3.00)
            cout << "AI: คุณสามารถสมัครได้\n";
        else
            cout << "AI: GPA อาจยังไม่ถึงเกณฑ์\n";
    }

    void showNeed(double gpa){

        cout << "AI: ทุนขาดแคลนทุนทรัพย์\n";
        cout << "- GPA ≥ 2.00\n";
        cout << "- เงินทุน 5,000 – 30,000 บาท\n";

        if(gpa >= 2.00)
            cout << "AI: คุณมีสิทธิ์สมัครได้\n";
        else
            cout << "AI: GPA ต่ำกว่าเกณฑ์\n";
    }

    void showCorporate(){

        cout << "AI: ทุนจากบริษัท\n";
        cout << "- SCG / PTT / AIS\n";
        cout << "- 20,000 – 100,000 บาทต่อปี\n";
    }

    void showActivity(){

        cout << "AI: ทุนกิจกรรม\n";
        cout << "- Robot / Programming / กีฬา\n";
        cout << "- 5,000 – 30,000 บาท\n";
    }

    void scholarshipMenu(){

        string input;

        cout << "AI: ทุนของวิศวะ มช. มี 4 ประเภท\n";
        cout << "1 ทุนเรียนดี\n";
        cout << "2 ทุนขาดแคลน\n";
        cout << "3 ทุนบริษัท\n";
        cout << "4 ทุนกิจกรรม\n";

        cout << "User: ";
        getline(cin,input);

        int choice = 0;

        if(hasKeyword(input,"1") || hasKeyword(input,"เรียนดี"))
            choice = 1;

        else if(hasKeyword(input,"2") || hasKeyword(input,"ขาดแคลน"))
            choice = 2;

        else if(hasKeyword(input,"3") || hasKeyword(input,"บริษัท"))
            choice = 3;

        else if(hasKeyword(input,"4") || hasKeyword(input,"กิจกรรม"))
            choice = 4;

        switch(choice){

            case 1:{

                cout << "AI: ใส่ GPA: ";
                getline(cin,input);

                double gpa = stod(input);

                showMerit(gpa);

                break;
            }

            case 2:{

                cout << "AI: ใส่ GPA: ";
                getline(cin,input);

                double gpa = stod(input);

                showNeed(gpa);

                break;
            }

            case 3:

                showCorporate();
                break;

            case 4:

                showActivity();
                break;

            default:

                cout << "AI: กรุณาเลือก 1-4\n";
        }

        cout << "\nAI: ทุนส่วนใหญ่เปิดสมัคร\n";
        cout << "- เทอม1 : ส.ค.-ก.ย.\n";
        cout << "- เทอม2 : ม.ค.-ก.พ.\n";
    }

    bool answer(string input){

        int cmd = checkCommand(input);

        switch(cmd){

            case 1:

                if(checkHistory("ทุนการศึกษา")){

                    cout << "AI: เราคุยเรื่องทุนไปแล้ว ต้องการดูเพิ่มเติมไหม?\n";
                }
                else{

                    cout << "AI: ผมสามารถแนะนำทุนที่เหมาะกับคุณได้\n";
                    addHistory("ทุนการศึกษา");
                }

                scholarshipMenu();
                break;

            case 2:

                cout << "AI: ลาก่อนครับ ขอให้ได้ทุนที่ต้องการ\n";
                return false;

            default:

                cout << "AI: ผมตอบได้เฉพาะเรื่องทุนครับ\n";
        }

        cout << "AI: มีอะไรอยากถามเพิ่มเติมไหม?\n";

        return true;
    }

};

int main(){

    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    Chatbot bot;

    string name;
    string input;

    cout << "AI: สวัสดีครับ ยินดีต้อนรับ ENGR CMU bot\n";
    cout << "AI: ขอทราบชื่อของคุณ\n";

    cout << "User: ";
    getline(cin,name);

    cout << "AI: ยินดีที่ได้รู้จักครับ คุณ " << name << endl;

    while(true){

        cout << "\nUser: ";
        getline(cin,input);

        if(!bot.answer(input))
            break;
    }

    return 0;
}