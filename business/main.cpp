#include <emscripten.h>
#include <iostream>
#include <string>

using namespace std;

extern "C" {
    EMSCRIPTEN_KEEPALIVE
        const char* get_personality_result(const char* answers) {
        int risk = 0, social = 0, logic = 0, action = 0;

        for (int i = 0; i < 20; i++) {
            int score = answers[i] - '0';
            if (i >= 0 && i < 5)   risk += score;
            if (i >= 5 && i < 10)  social += score;
            if (i >= 10 && i < 15) logic += (5 - score);
            if (i >= 15 && i < 20) action += score;
        }

        bool isHighRisk = (risk > 12);
        bool isHighSocial = (social > 12);
        bool isHighLogic = (logic > 12);
        bool isHighAction = (action > 12);

        if (isHighRisk && !isHighSocial && isHighLogic) {
            return "【孤狼型破局者】\n你不需要无效社交，一台电脑就是你的千军万马。你享受在规则边缘试探，用极高的效率和硬核实力单点突破。";
        }
        else if (!isHighRisk && !isHighSocial && isHighLogic) {
            return "【人间清醒的幕后军师】\n你永远能看到别人上头时的风险，是团队里的定海神针。你不追求聚光灯，但资金流向都由你暗中推演。";
        }
        else if (isHighRisk && isHighSocial && !isHighLogic) {
            return "【八面玲珑的资源大亨】\n天生的社交悍匪，朋友圈就是你的提款机。你能敏锐嗅到利益契合点，空手套白狼是你最擅长的艺术。";
        }
        else if (!isHighRisk && isHighSocial && !isHighLogic) {
            return "【降维打击的情绪收割机】\n你有着极其可怕的共情能力。你赚的不是辛苦钱，而是别人心甘情愿为你提供的情绪价值买单。";
        }
        else if (isHighRisk && !isHighSocial && !isHighLogic && isHighAction) {
            return "【敏捷的赛道狙击手】\n你永远在追逐风口。不管什么长期主义，只要看到利润，连夜跑通闭环，赚完一波红利立马撤退。";
        }
        else if (!isHighRisk && !isHighSocial && isHighLogic && isHighAction) {
            return "【冷酷无情的执行机器】\n你没有内耗，只有进度条。别人还在扯皮，你已经把活干完了。你是商业机器里最不可或缺的齿轮。";
        }
        else if (!isHighRisk && isHighSocial && isHighLogic) {
            return "【闷声发财的务实地主】\n你不相信一夜暴富，只相信复利的奇迹。你懂得利用规则和网络，慢慢把自己的资产雪球越滚越大。";
        }
        else {
            return "【自带势能的商业领袖】\n你不仅想赚钱，还想改变世界。你的直觉和个人魅力就是招牌，总能吸引一群人去打不可能赢的仗。";
        }
    }
}

int main() {
    printf("后端核心算法已启动，等待数据输入...\n");
    return 0;
}