#include <emscripten.h>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

extern "C" {
    EMSCRIPTEN_KEEPALIVE
    const char* get_personality_result(const char* answers, const char* password) {
        
        // 🔒 密码锁
        if (strcmp(password, "050129") != 0 && strcmp(password, "love120") != 0) {
            return "【⚠️ 授权码无效或未输入】\n你已经完成了长达 80 题的情感推演，但你当前的授权码不正确。\n请联系主理人获取有效授权码，从首页重新进入测试！";
        }

        int emotion = 0, reality = 0, boundary = 0, power = 0;

        for (int i = 0; i < 80; i++) {
            int score = answers[i] - '0'; 
            if (i >= 0 && i < 20)        emotion += score;   // 1-20题：情绪戒断
            else if (i >= 20 && i < 40)  reality += score;   // 21-40题：价值清醒
            else if (i >= 40 && i < 60)  boundary += score;  // 41-60题：底线防御
            else if (i >= 60 && i < 80)  power += score;     // 61-80题：权力博弈
        }

        bool isHighEmotion = (emotion > 50);
        bool isHighReality = (reality > 50);
        bool isHighBoundary = (boundary > 50);
        bool isHighPower = (power > 50);

        if (isHighEmotion && isHighReality && !isHighPower) 
            return "【极度清醒的边缘旁观者】\n\n▶ 深度剖析：你看透了爱情的本质不过是繁衍冲动和资源互换。你极其享受孤独，任何试图用情绪勒索你的人都会被你瞬间识破。你很难真正爱上谁，因为你的理智永远先于心动。\n\n▶ 致命弱点：过于防备，导致错失真正高价值的情感连接。\n\n▶ 破局建议：不要把亲密关系当成敌我矛盾。既然看透了规则，不妨试着在绝对安全的前提下“向下兼容”，把它当成一场有趣的体验游戏，而不是每天严防死守。";
            
        else if (!isHighEmotion && isHighPower && isHighReality) 
            return "【危险的情感猎手】\n\n▶ 深度剖析：你嘴上说着深情，但心里比谁都会算账。你非常享受征服的快感，深谙推拉、忽冷忽热等操控人心的技巧。你需要的不是爱情，而是一个极其耀眼的战利品来彰显你的价值。\n\n▶ 致命弱点：夜深人静时会感到极其空虚，容易在遇到段位比你高的人时翻车。\n\n▶ 破局建议：猎手最终都会死在打猎上。停止用廉价的套路去筛选猎物，试着提升自己最核心的硬价值。只有当你不屑于使用套路时，你才能遇到势均力敌的同路人。";
            
        else if (isHighBoundary && isHighEmotion && !isHighReality) 
            return "【宁缺毋滥的带刺玫瑰】\n\n▶ 深度剖析：你的底线极其清晰，眼里揉不得半点沙子。谁敢不尊重你、冷暴力你，你会像切除肿瘤一样瞬间斩断关系，哪怕自己痛得要死。你极其独立，但在潜意识里依然渴望那种毫无杂质的“纯爱”。\n\n▶ 致命弱点：水至清则无鱼，过于绝对化的标准会让你在现实中极其挫败。\n\n▶ 破局建议：世界不是非黑即白的。你需要明白人性的幽暗面，允许别人在不触碰核心底线的情况下有一点自私和软弱。把你的锋芒收起来两寸，你会活得更舒服。";
            
        else if (isHighReality && isHighPower && isHighBoundary && isHighEmotion) 
            return "【降维打击的绝对主导者】\n\n▶ 深度剖析：你是感情世界里极其可怕的“六边形战士”。你既能提供完美的情绪价值，又能随时抽离拔剑；你既看透了利益置换，又能把控全场节奏。任何试图PUA你的人，最终都会沦为你的提线木偶。\n\n▶ 核心优势：在任何关系中都立于不败之地，随时掌握“随时离开的权力”。\n\n▶ 破局建议：你已经通关了这场游戏。现在你需要警惕的是“无聊”。不要为了寻求刺激去招惹极其极端、有毁灭倾向的人。去找一个同样强大的事业合伙人，把你们在感情里的算计，全用到商业上搞钱去！";
            
        else if (!isHighReality && !isHighBoundary && !isHighPower) 
            return "【极易被吞噬的恋爱脑】\n\n▶ 深度剖析：你在感情中处于极其危险的食物链底端。你把爱情当成了全部的信仰，一谈恋爱就失去自我，毫无底线地妥协退让。你总是试图用讨好和感动来换取别人的爱，结果往往是被榨干后无情抛弃。\n\n▶ 致命弱点：毫无框架，极度渴望被拯救，容易吸引渣男/吸血鬼。\n\n▶ 破局建议：极其严厉的警告！立刻停止幻想！在你的个人存款达到某个安全阈值、且学会极其残忍地拒绝别人之前，绝对不要碰感情。你的善良在强者的眼里，就是挂着邀请牌的肥肉。";
            
        else if (isHighReality && isHighBoundary && !isHighEmotion) 
            return "【权衡利弊的清醒沉沦者】\n\n▶ 深度剖析：你脑子里极其清楚对方的缺点和这段关系的不堪，但你的情绪却像毒瘾一样戒不掉。你每天都在脑海里和对方分手八百次，但现实中对方勾勾手你又会心软。你是清醒地看着自己沉沦。\n\n▶ 致命弱点：极其严重的精神内耗，知行严重不合一。\n\n▶ 破局建议：切断一切物理联系！你的理智不足以对抗你的情绪惯性。把你的注意力极其功利地转移到赚钱、搞事业或者健身上。用硬核的现实反馈，强行冲散你那点可怜的荷尔蒙。";
            
        else 
            return "【深藏不露的情感博弈家】\n\n▶ 深度剖析：你极其擅长伪装。你表面上可能看起来很随和、甚至有点恋爱脑，但那只是你为了降低对方防备而展示的保护色。你极其懂得在关键时刻收网，不显山不露水地拿走你在感情中想要的所有核心利益。\n\n▶ 核心优势：扮猪吃老虎，用极低的成本撬动极高的情绪和物质回报。\n\n▶ 破局建议：保持你那令人恐惧的“松弛感”。但要注意，真正的最高级博弈是“双赢”。不要把伴侣当成彻底的假想敌，在你能绝对兜底的情况下，适度让渡一些掌控感，享受一下片刻的真实。";
    }
}

int main() {
    printf("情感维度解构算法已启动...\n");
    return 0;
}