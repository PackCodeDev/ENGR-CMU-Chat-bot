#include<iostream>
#include<string>
#include<vector>
using namespace std;

enum ShowState {
    SELECT_PROGRAM, //เลือกภาค
    SELECT_MAJORS, //เลือกเจอร์
    SELECT_DETAIL //คำถาม
};

class WaitSelect{
    public:
        ShowState currentState = SELECT_PROGRAM;
        std::string selectedProgram = "";
        std::string selectedMajor = "";
        std::string selectedDetail = "";

    bool hasKeyword(std::string input, std::string keyword) {
        return input.find(keyword) != std::string::npos;
    };
    bool processAdmission(std::string input, std::vector<std::string>& chatHistory){
        auto reply = [&](std::string text) {
            chatHistory.push_back("Chatbot: " + text);
        };

        if(hasKeyword(input, "ออก") || hasKeyword(input, "เมนูหลัก")){
            reply(" ");
            currentState = SELECT_PROGRAM;
            selectedMajor = ""; selectedDetail = "";
            return false;
        };

        switch(currentState){
            case SELECT_PROGRAM:
                if(hasKeyword(input, "ปกติ")){
                selectedProgram = "ปกติ";
                reply("เลือกภาคปกติแล้วครับ ต่อไปเลือกสาขาที่สนใจได้เลย");
                currentState = SELECT_MAJORS;
                }else if(hasKeyword(input, "พิเศษ")){
                selectedProgram = "พิเศษ";
                reply("เลือกภาคพิเศษแล้วครับ ต่อไปเลือกสาขาที่สนใจได้เลย");
                currentState = SELECT_MAJORS;
                }else if(hasKeyword(input, "นานาชาติ")){
                selectedProgram = "นานาชาติ";
                reply("เลือกภาคพิเศษแล้วครับ ต่อไปเลือกสาขาที่สนใจได้เลย");
                currentState = SELECT_MAJORS;
                }

//=========================================================================================================================================

//                                                ภาคปกติ

                                                //Computer
            case SELECT_MAJORS:
                if(hasKeyword(input, "คอม") || hasKeyword(input, "คอมพิวเตอร์") && selectedProgram == "ปกติ"){
                    selectedMajor = "คอมพิวเตอร์";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับวิศวกรรมคอมพิวเตอร์ครับ?");
                    currentState = SELECT_DETAIL;
                }
                                                //Mechanical
                else if(hasKeyword(input, "เครื่องกล") && selectedProgram == "ปกติ"){
                    selectedMajor = "เครื่องกล";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับวิศวกรรมเครื่องกลครับ?");
                    currentState = SELECT_DETAIL;
                }
                                                //Electrical
                else if(hasKeyword(input, "") && selectedProgram == "ปกติ"){
                    selectedMajor = "";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับ ครับ?");
                    currentState = SELECT_DETAIL;
                }
                                                //Civil
                else if(hasKeyword(input, "") && selectedProgram == "ปกติ"){
                    selectedMajor = "";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับ ครับ?");
                    currentState = SELECT_DETAIL;
                }
                                                //Industrial
                else if(hasKeyword(input, "") && selectedProgram == "ปกติ"){
                    selectedMajor = "";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับ ครับ?");
                    currentState = SELECT_DETAIL;
                }
                                                //Environmental
                else if(hasKeyword(input, "") && selectedProgram == "ปกติ"){
                    selectedMajor = "";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับ ครับ?");
                    currentState = SELECT_DETAIL;
                }
                                                //Mining & Petroleum
                else if(hasKeyword(input, "") && selectedProgram == "ปกติ"){
                    selectedMajor = "";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับ ครับ?");
                    currentState = SELECT_DETAIL;
                }
                                                //REAI (Robotics & AI)
                else if(hasKeyword(input, "") && selectedProgram == "ปกติ"){
                    selectedMajor = "";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับ ครับ?");
                    currentState = SELECT_DETAIL;
                }
                                                //Integrated
                else if(hasKeyword(input, "") && selectedProgram == "ปกติ"){
                    selectedMajor = "";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับ ครับ?");
                    currentState = SELECT_DETAIL;
                }

//                                                ภาคพิเศษ

                                                //Industrial
                else if(hasKeyword(input, "") && selectedProgram == "พิเศษ"){
                    selectedMajor = "";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับ ครับ?");
                    currentState = SELECT_DETAIL;
                }
                                                //Electrical
                else if(hasKeyword(input, "") && selectedProgram == "พิเศษ"){
                    selectedMajor = "";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับ ครับ?");
                    currentState = SELECT_DETAIL;
                }
                                                //Mechanical
                else if(hasKeyword(input, "") && selectedProgram == "พิเศษ"){
                    selectedMajor = "";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับ ครับ?");
                    currentState = SELECT_DETAIL;
                }

//                                                นานาชาติ

                                                //Mechanical
                else if(hasKeyword(input, "") && selectedProgram == "นานาชาติ"){
                    selectedMajor = "";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับ ครับ?");
                    currentState = SELECT_DETAIL;
                }
                                                //Integrated
                else if(hasKeyword(input, "") && selectedProgram == "นานาชาติ"){
                    selectedMajor = "";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับ ครับ?");
                    currentState = SELECT_DETAIL;
                }
                                                //Industrial
                else if(hasKeyword(input, "") && selectedProgram == "นานาชาติ"){
                    selectedMajor = "";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับ ครับ?");
                    currentState = SELECT_DETAIL;
                }
                                                //Civil
                else if(hasKeyword(input, "") && selectedProgram == "นานาชาติ"){
                    selectedMajor = "";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับ ครับ?");
                    currentState = SELECT_DETAIL;
                }
                                                //ISNE
                else if(hasKeyword(input, "") && selectedProgram == "นานาชาติ"){
                    selectedMajor = "";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับ ครับ?");
                    currentState = SELECT_DETAIL;
                }
                                                //Industrial
                else if(hasKeyword(input, "") && selectedProgram == "นานาชาติ"){
                    selectedMajor = "";
                    reply("ต้องการสอบถามเรื่องใดเกี่ยวกับ ครับ?");
                    currentState = SELECT_DETAIL;
                }

//=========================================================================================================================================

                else{
                    reply("ลองพิมพ์ชื่อสาขาใหม่ดูนะครับ (เช่น โยธา)");
                }
                break;

//=========================================================================================================================================

//                                                คำถาม

            case SELECT_DETAIL:
                if(hasKeyword(input, "ตัวอย่างคำถาม") || hasKeyword(input, "ตัวอย่างคำถาม")){
        
                    if(selectedMajor == "คอมพิวเตอร์"){
                    //แบบที่ 1
                        if(selectedProgram == "ปกติ"){
                        reply(" ");
                        }else if(selectedProgram == "พิเศษ"){
                            reply(" ");
                        }else if(selectedProgram == "นานาชาติ"){
                            reply(" ");
                        }
                    }else if(selectedMajor == "เครื่องกล"){
                        if(selectedProgram == "ปกติ"){
                            reply(" ");
                        }else{
                            reply(" ");
                        }
                    }
                }else if(hasKeyword(input, "ตัวอย่างคำถาม") || hasKeyword(input, "ตัวอย่างคำถาม")){
                    //แบบที่ 2
                    if(selectedProgram == "ปกติ"){
                        reply(" ");
                    }else if(selectedProgram == "พิเศษ"){
                        reply(" ");
                    }else if(selectedProgram == "นานาชาติ"){
                        reply(" ");
                    }
                }
                break;
        }
        return true;
    }
};