#include <emscripten.h>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

extern "C" {
    EMSCRIPTEN_KEEPALIVE
    const char* get_personality_result(const char* answers, const char* password) {
        
        // 🔒 密码锁
        if (strcmp(password, "828406") != 0 && strcmp(password, "mindmind") != 0) {
            return "【⚠️ 授权码无效或未输入】\n你已经完成了长达 80 题的人性推演，但你当前的授权码不正确。\n请联系主理人获取有效授权码，从首页重新进入测试！";
        }

        int emotion = 0, profit = 0, gray = 0, long_term = 0;

        for (int i = 0; i < 80; i++) {
            int score = answers[i] - '0'; 
            if (i >= 0 && i < 20)        emotion += score;     // 1-20题：情绪隐蔽
            else if (i >= 20 && i < 40)  profit += score;      // 21-40题：利益精算
            else if (i >= 40 && i < 60)  gray += score;        // 41-60题：灰度认知
            else if (i >= 60 && i < 80)  long_term += score;   // 61-80题：长线潜伏
        }

        bool isHighEmotion = (emotion > 50);
        bool isHighProfit = (profit > 50);
        bool isHighGray = (gray > 50);
        bool isHighLongTerm = (long_term > 50);

        if (isHighEmotion && isHighProfit && isHighGray && isHighLongTerm) 
            return "【深不可测的绝对执棋者】\n\n▶ 深度剖析：你的城府已经到了令人毛骨悚然的境界。你没有情绪的弱点，没有道德的洁癖，能够为了一个十年后的宏大目标，在今天对最讨厌的人笑脸相迎。在你的世界里，所有人都是棋子，包括你自己。\n\n▶ 核心武器：绝对冰冷的理智、降维打击的全局观、非人的隐忍力。\n\n▶ 破局建议：你已经脱离了普通人的范畴。不要在低维度的争斗中浪费天赋，去参与那些极其庞大的商业或权力游戏。但要警惕“高处不胜寒”，你极易陷入虚无主义。";
            
        else if (isHighEmotion && !isHighProfit && isHighLongTerm) 
            return "【隐世的扫地僧】\n\n▶ 深度剖析：你极其擅长隐藏自己，极具耐心，但你对短期的、粗暴的利益掠夺缺乏兴趣。你像一个冷眼旁观的幽灵，默默看透了一切规则，但往往选择独善其身，不到极其关键的时刻绝不出手。\n\n▶ 核心武器：完美的环境融合力、极其可怕的后发制人能力。\n\n▶ 破局建议：你的防御力点满了，但攻击力不足。你需要给自己设定一个极其渴望的“世俗目标”（比如搞大钱），强迫自己入局。一旦你决定掠夺，没有人能防得住你。";
            
        else if (!isHighEmotion && isHighProfit && isHighGray) 
            return "【锋芒毕露的嗜血狂徒】\n\n▶ 深度剖析：你极其聪明，深谙灰产和利益置换的规则。但你的城府不够深，所有的野心和算计都写在脸上。你极其追求短期暴利，甚至不惜游走在危险边缘。你能极快地赚到钱，但也极容易树敌。\n\n▶ 核心武器：极其敏锐的嗅觉、毫无底线的执行力、惊人的爆发力。\n\n▶ 破局建议：学会“藏拙”！木秀于林风必摧之，你现在的吃相太难看。立刻去学习如何把极其肮脏的利益交换，包装成极其高尚的情怀和共赢，否则你迟早会被人联手绞杀。";
            
        else if (isHighEmotion && isHighProfit && !isHighGray && !isHighLongTerm) 
            return "【精致的利己主义机器】\n\n▶ 深度剖析：你的算盘打得极精。在任何社交和职场环境中，你都能瞬间算出怎样做对自己最有利，并用极其完美的表情管理掩饰你的自私。你不碰灰产，也不做长远布局，只极其冷酷地收割眼前的每一分利润。\n\n▶ 核心武器：滴水不漏的伪装、极其高效的资源套现、绝对的精致利己。\n\n▶ 破局建议：你的战术极其完美，但战略极其短视。你赚不到真正跨越阶层的大钱，因为大钱往往藏在需要长时间潜伏的灰色迷雾中。试着牺牲一点短期利益，去下注一个未知的未来。";
            
        else if (isHighGray && isHighLongTerm && !isHighEmotion) 
            return "【被情绪拖累的毒士】\n\n▶ 深度剖析：你的大脑极其阴暗且深刻，能想出极其毒辣的奇谋，也能耐心地布局。但你极其致命的弱点是：你控制不住情绪。你往往在极其关键的时刻，因为极其微小的自尊心受挫或愤怒，亲手毁掉自己布了三年的局。\n\n▶ 核心武器：洞悉人性阴暗面、不择手段的计谋、极其顽强的韧性。\n\n▶ 破局建议：立刻寻找一个极其冷静、极其没有感情的合伙人/伴侣，把执行权交给他。你是极其优秀的谋士，但你绝不能亲自下场肉搏，你的情绪炸弹会炸死你自己。";
            
        else if (!isHighEmotion && !isHighProfit && !isHighGray && !isHighLongTerm) 
            return "【极其透明的待宰羔羊】\n\n▶ 深度剖析：你毫无城府可言。在这个弱肉强食的世界里，你就像一个极其天真、随时暴露在狼群面前的猎物。你极其容易被感动，极度遵守表面的道德规范，极其厌恶算计，别人可以一眼看穿你的底牌。\n\n▶ 核心武器：几乎没有，除了极其容易被利用的“善良”。\n\n▶ 破局建议：极度危险！立刻停止向任何人暴露你的真实想法。你必须强迫自己阅读心理学、博弈论，学习如何面无表情地撒谎。在拥有保护自己的獠牙之前，你的善良一文不值。";
            
        else 
            return "【潜行在暗处的变色龙】\n\n▶ 深度剖析：你的城府处于极其灵活的状态。你没有绝对的底线，也没有绝对的目标，你极其擅长根据环境的温度改变自己的颜色。你能在极度虚伪的圈子里如鱼得水，也能在极其残忍的博弈中咬下一块肉。\n\n▶ 核心武器：极其恐怖的环境适应力、见人说人话的顶级伪装、毫无道德包袱。\n\n▶ 破局建议：你极其容易活下来，但很难成为真正的王。你需要找到一个让你极其狂热的终极信仰（无论是极其庞大的财富还是权力），将你散落的城府凝聚成一把可以刺穿苍穹的利剑。";
    }
}

int main() {
    printf("城府深渊探测引擎已启动...\n");
    return 0;
}