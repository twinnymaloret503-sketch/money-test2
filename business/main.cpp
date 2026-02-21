#include <emscripten.h>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

extern "C" {
    EMSCRIPTEN_KEEPALIVE
        const char* get_personality_result(const char* answers, const char* password) {

        // 🔒 密码锁：你可以随时在这里修改你的私域引流密码
        if (strcmp(password, "666888") != 0 && strcmp(password, "boss") != 0) {
            return "【⚠️ 授权码无效或未输入】\n你已经完成了长达 80 题的深度推演，但你当前的授权码不正确，无法解锁最终判定。\n请联系主理人获取有效授权码，从首页重新进入测试！";
        }

        // --- 80 题扩容版计分逻辑 ---
        int risk = 0, social = 0, logic = 0, action = 0;

        // 循环 80 次读取用户的 80 个答案
        for (int i = 0; i < 80; i++) {
            int score = answers[i] - '0';
            if (i >= 0 && i < 20)        risk += score;      // 第 1-20 题测风险偏好
            else if (i >= 20 && i < 40)  social += score;    // 第 21-40 题测社交手腕
            else if (i >= 40 && i < 60)  logic += score;     // 第 41-60 题测逻辑城府
            else if (i >= 60 && i < 80)  action += score;    // 第 61-80 题测行动力
        }

        // 20 道题，每题最高 4 分，满分 80 分。设定阈值为 50 分。
        bool isHighRisk = (risk > 50);
        bool isHighSocial = (social > 50);
        bool isHighLogic = (logic > 50);
        bool isHighAction = (action > 50);

        if (isHighRisk && !isHighSocial && isHighLogic) return "【孤狼型破局者】\n你不需要无效社交，一台电脑就是你的千军万马。你享受在规则边缘试探，用极高的效率和硬核实力单点突破。";
        else if (!isHighRisk && !isHighSocial && isHighLogic) return "【人间清醒的幕后军师】\n你永远能看到别人上头时的风险，是团队里的定海神针。你不追求聚光灯，但资金流向都由你暗中推演。";
        else if (isHighRisk && isHighSocial && !isHighLogic) return "【八面玲珑的资源大亨】\n天生的社交悍匪，朋友圈就是你的提款机。你能敏锐嗅到利益契合点，空手套白狼是你最擅长的艺术。";
        else if (!isHighRisk && isHighSocial && !isHighLogic) return "【降维打击的情绪收割机】\n你有着极其可怕的共情能力。你赚的不是辛苦钱，而是别人心甘情愿为你提供情绪价值买单。";
        else if (isHighRisk && !isHighSocial && !isHighLogic && isHighAction) return "【敏捷的赛道狙击手】\n你永远在追逐风口。不管什么长期主义，只要看到利润，连夜跑通闭环，赚完红利立马撤退。";
        else if (!isHighRisk && !isHighSocial && isHighLogic && isHighAction) return "【冷酷无情的执行机器】\n你没有内耗，只有进度条。别人还在扯皮，你已经把活干完了。你是商业机器里最不可或缺的齿轮。";
        else if (!isHighRisk && isHighSocial && isHighLogic) return "【闷声发财的务实地主】\n你不相信一夜暴富，只相信复利的奇迹。你懂得利用规则和网络，慢慢把自己的资产雪球越滚越大。";
        else return "【自带势能的商业领袖】\n你不仅想赚钱，还想改变世界。你的直觉和个人魅力就是招牌，总能吸引一群人去打不可能赢的仗。";
    }
}

int main() {
    printf("80题版加密后端算法已启动...\n");
    return 0;
}