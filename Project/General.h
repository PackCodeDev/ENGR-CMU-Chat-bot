#pragma once
#include <iostream>
#include <string>
#include <vector>

// มีแค่สถานะเดียว เพราะถามมาก็ตอบไปเลย
enum GeneralQAState {
    QA_STATE_MAIN 
};

class GeneralQAHandler {
private:
    // ตัวแปรเก็บข้อมูลต่างๆ (ดึงมาจากโค้ดเดิมของคุณ)
    bool hasDoiSchedule = false;
    std::string doiDate = "15 พฤศจิกายน 2569";
    std::string openDate = "1 มิถุนายน 2569";
    std::string closeDate = "30 มีนาคม 2570";
    std::string dropTerm1 = "31 สิงหาคม 2569";
    std::string dropTerm2 = "15 มกราคม 2570";
    std::string newsLink = "https://eng.cmu.ac.th/?page_id=21937";
    std::string regLink = "https://reg.cmu.ac.th";

public:
    GeneralQAState currentState = QA_STATE_MAIN;

    // ฟังก์ชันเช็คคำคีย์เวิร์ด
    bool hasKeyword(std::string input, std::string keyword){
        return input.find(keyword) != std::string::npos;
    }

    // ฟังก์ชันหลักที่ main.cpp จะเรียกใช้งาน
    bool processQA(std::string input, std::vector<std::string>& chatHistory){
        
        auto reply = [&](std::string text) {
            chatHistory.push_back("Chatbot: " + text);
        };

        // ถ้าผู้ใช้ต้องการออก ให้ส่ง false กลับไปบอก main.cpp
        if (hasKeyword(input, "ออก") || hasKeyword(input, "กลับ") || hasKeyword(input, "เมนูหลัก")) {
            currentState = QA_STATE_MAIN;
            return false; 
        }

        // เช็คคำถามแล้วตอบ
        switch (currentState) {
            case QA_STATE_MAIN:
                if (hasKeyword(input, "ขึ้นดอย")) {
                    if (hasDoiSchedule) reply("วันขึ้นดอยคือ " + doiDate);
                    else reply("ยังไม่ประกาศวันแน่นอนครับ");
                }
                else if (hasKeyword(input, "เปิดเรียน") || hasKeyword(input, "ปิดเรียน")) {
                    reply("วันเปิดเรียน: " + openDate + "\nวันปิดเรียน: " + closeDate);
                }
                else if (hasKeyword(input, "ดรอป") || hasKeyword(input, "drop")) {
                    if (hasKeyword(input, "1")) reply("วันดรอปวิชา (ติด W) ภาคเรียนที่ 1: " + dropTerm1);
                    else if (hasKeyword(input, "2")) reply("วันดรอปวิชา (ติด W) ภาคเรียนที่ 2: " + dropTerm2);
                    else reply("วันดรอปวิชา (ติด W)\nภาคเรียนที่ 1: " + dropTerm1 + "\nภาคเรียนที่ 2: " + dropTerm2);
                }
                else if (hasKeyword(input, "ข่าว") || hasKeyword(input, "news")) {
                    reply("ติดตามข่าวสารได้ที่:\n" + newsLink);
                }
                else if (hasKeyword(input, "มกราคม") || hasKeyword(input, "มกรา")) {
                    reply("เดือนมกราคม: 1 ม.ค. วันขึ้นปีใหม่");
                }
                else if (hasKeyword(input, "กุมภาพันธ์") || hasKeyword(input, "กุมภา")) {
                    reply("เดือนกุมภาพันธ์: ไม่มีวันหยุดราชการ");
                }
                else if (hasKeyword(input, "มีนาคม") || hasKeyword(input, "มีนา")) {
                    reply("เดือนมีนาคม: ไม่มีวันหยุดราชการ");
                }
                else if (hasKeyword(input, "เมษายน") || hasKeyword(input, "เมษา")) {
                    reply("เดือนเมษายน:\n6 เม.ย. วันจักรี\n13-15 เม.ย. วันสงกรานต์");
                }
                else if (hasKeyword(input, "พฤษภาคม") || hasKeyword(input, "พฤษภา")) {
                    reply("เดือนพฤษภาคม:\n1 พ.ค. วันแรงงาน\n4 พ.ค. วันฉัตรมงคล");
                }
                else if (hasKeyword(input, "มิถุนายน") || hasKeyword(input, "มิถุนา")) {
                    reply("เดือนมิถุนายน: 3 มิ.ย. วันเฉลิมพระชนมพรรษาพระราชินี");
                }
                else if (hasKeyword(input, "กรกฎาคม") || hasKeyword(input, "กรกฎา")) {
                    reply("เดือนกรกฎาคม: 28 ก.ค. วันเฉลิมพระชนมพรรษา ร.10");
                }
                else if (hasKeyword(input, "สิงหาคม") || hasKeyword(input, "สิงหา")) {
                    reply("เดือนสิงหาคม: 12 ส.ค. วันแม่แห่งชาติ");
                }
                else if (hasKeyword(input, "กันยายน") || hasKeyword(input, "กันยา")) {
                    reply("เดือนกันยายน: ไม่มีวันหยุดราชการ");
                }
                else if (hasKeyword(input, "ตุลาคม") || hasKeyword(input, "ตุลา")) {
                    reply("เดือนตุลาคม:\n13 ต.ค. วันนวมินทรมหาราช\n23 ต.ค. วันปิยมหาราช");
                }
                else if (hasKeyword(input, "พฤศจิกายน") || hasKeyword(input, "พฤศจิกา")) {
                    reply("เดือนพฤศจิกายน: ไม่มีวันหยุดราชการ");
                }
                else if (hasKeyword(input, "ธันวาคม") || hasKeyword(input, "ธันวา")) {
                    reply("เดือนธันวาคม:\n5 ธ.ค. วันพ่อ\n10 ธ.ค. วันรัฐธรรมนูญ\n31 ธ.ค. วันสิ้นปี");
                }
                else if (hasKeyword(input, "คณะ") || hasKeyword(input, "ทะเบียน") || hasKeyword(input, "สำนัก")) {
                    reply("ติดต่อ งานทะเบียนคณะวิศวกรรมศาสตร์ มช.\nโทร: 053-944-000\nสถานที่: อาคารสำนักงานคณะวิศวกรรมศาสตร์ มหาวิทยาลัยเชียงใหม่\nเปิดทำการวันจันทร์ - ศุกร์ เวลา 08:30 - 16:30 น. (ปิดพักเที่ยงและวันหยุดนักขัตฤกษ์)");
                }
                else if (hasKeyword(input, "wifi") || hasKeyword(input, "WiFi") || hasKeyword(input, "ไวไฟ")) {
                    reply("Wi-Fi ของมหาวิทยาลัย: JumboNet\n1. เชื่อมต่อ Wi-Fi ชื่อ JumboNet\n2. ใช้ CMU Account ล็อกอิน\nUsername = รหัสนักศึกษา\nPassword = รหัสผ่าน CMU Account");
                }
                else if (hasKeyword(input, "reg") || hasKeyword(input, "ลงทะเบียน")) {
                    reply("ระบบลงทะเบียนเรียน REG CMU\n" + regLink);
                }
                else if (hasKeyword(input, "ฉุกเฉิน") || hasKeyword(input, "รปภ") || hasKeyword(input, "emergency")) {
                    reply("เบอร์โทรศัพท์แจ้งเหตุฉุกเฉิน มหาวิทยาลัยเชียงใหม่ ตลอด 24 ชั่วโมง\nเบอร์โทร 053-941-191");
                }
                else {
                    reply("ขออภัย ไม่พบข้อมูลครับ ลองถามเรื่องอื่นดูนะครับ เช่น 'ขึ้นดอย', 'ติดต่อ', 'wifi' หรือพิมพ์ 'ออก' เพื่อกลับเมนูหลัก");
                }
                break;
        }
        return true; 
    }
};