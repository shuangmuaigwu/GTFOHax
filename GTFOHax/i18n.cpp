#include "i18n.h"

#include <algorithm>
#include <cctype>
#include <string>
#include <unordered_map>

namespace
{
    struct TextEntry
    {
        const char* key;
        const char* zh;
        const char* en;
    };

    static const TextEntry kText[] = {
        {"tab.player", "玩家", "Player"},
        {"tab.esp", "透视", "ESP"},
        {"tab.aimbot", "自喵", "Aimbot"},
        {"tab.misc", "杂项", "Misc"},
        {"tab.config", "配置", "Config"},

        {"corner.top_left", "左上", "Top Left"},
        {"corner.top_right", "右上", "Top Right"},
        {"corner.bottom_left", "左下", "Bottom Left"},
        {"corner.bottom_right", "右下", "Bottom Right"},

        {"window.menu", "菜单", "Menu"},
        {"window.watermark", "水印", "Watermark"},

        {"common.enable", "启用", "Enable"},
        {"common.box", "方框", "Box"},
        {"common.box_2d", "2D方框", "2D Box"},
        {"common.health_bar", "血条", "Health Bar"},
        {"common.health_bar_thickness", "血条粗细", "Health Bar Thickness"},
        {"common.health_value", "血条数值", "Health Value"},
        {"common.health_value_full", "满血显示数值", "Show Value At Full Health"},
        {"common.enemy_info", "敌人信息", "Enemy Info"},
        {"common.name", "名称", "Name"},
        {"common.type", "类型", "Type"},
        {"common.health", "生命值", "Health"},
        {"common.distance", "距离", "Distance"},
        {"common.skeleton", "骨骼", "Skeleton"},
        {"common.render_distance", "显示距离", "Render Distance"},
        {"common.line_thickness", "线条粗细", "Line Thickness"},
        {"common.visible", "可见", "Visible"},
        {"common.not_visible", "不可见", "Not Visible"},
        {"common.position", "位置", "Position"},
        {"common.key", "按键", "Key"},
        {"common.language", "语言", "Language"},
        {"priority.health", "生命值", "Health"},
        {"priority.distance", "距离", "Distance"},
        {"priority.fov", "视野(FOV)", "FOV"},

        {"player.godmode", "上帝模式(Godmode)", "Godmode"},
        {"player.infinite_ammo", "无限弹药", "Infinite Ammo"},
        {"player.instant_glue", "胶枪无冷却", "No Glue Cooldown"},
        {"player.instant_hack", "秒破解", "Instant Hack"},
        {"player.full_auto", "全自动", "Full Auto"},
        {"player.no_recoil", "无后坐力", "No Recoil"},
        {"player.no_spread", "无散布", "No Spread"},
        {"player.no_shake", "无抖动", "No Shake"},
        {"player.no_fog", "去雾", "No Fog"},
        {"player.give_health", "加血", "Give Health"},
        {"player.give_disinfection", "消毒", "Disinfect"},
        {"player.give_ammo", "子弹", "Give Ammo"},

        {"esp.world_esp", "世界透视", "World ESP"},
        {"esp.enemy_esp", "敌人透视", "Enemy ESP"},
        {"esp.world", "世界", "World"},
        {"esp.enemy", "敌人", "Enemy"},

        {"esp.group.security", "门禁钥匙终端", "Security/Keys"},
        {"esp.group.objective", "任务物品", "Objective Items"},
        {"esp.group.consumable", "消耗品", "Consumables"},
        {"esp.group.other", "其他", "Other"},
        {"esp.group.collectible", "收集物", "Collectibles"},

        {"aimbot.enemy", "敌人自喵", "Enemy Aimbot"},
        {"aimbot.hold_only", "按住生效", "Hold To Aim"},
        {"aimbot.silent", "静默自喵", "Silent Aim"},
        {"aimbot.magic_bullet", "魔法子弹", "Magic Bullet"},
        {"aimbot.visible_only", "仅可见", "Visible Only"},
        {"aimbot.aim_armor", "优先护甲", "Aim Armor First"},
        {"aimbot.max_distance", "瞄准距离", "Aim Distance"},
        {"aimbot.smoothing", "平滑", "Smoothing"},
        {"aimbot.render_fov", "显示FOV", "Show FOV"},
        {"aimbot.priority", "目标优先级", "Target Priority"},

        {"misc.menu_key", "菜单开关键", "Menu Toggle Key"},
        {"misc.unload_menu", "卸载菜单", "Unload Menu"},
        {"misc.watermark", "水印", "Watermark"},
        {"misc.spawn_enemy", "生成敌人", "Spawn Enemy"},

        {"config.save", "保存", "Save"},
        {"config.load", "读取", "Load"},
        {"config.language", "语言", "Language"},

        {"label.health", "血量", "Health"},
        {"label.password", "密码", "Password"},
        {"unit.meter", "米", "m"},

        {"enemy.type.weakling", "弱小", "Weakling"},
        {"enemy.type.standard", "普通", "Standard"},
        {"enemy.type.special", "特殊", "Special"},
        {"enemy.type.miniboss", "小Boss", "Mini Boss"},
        {"enemy.type.boss", "Boss", "Boss"},

        {"error.prefix", "错误：", "Error: "},
        {"error.esp_item_missing_suffix", " 不存在于 espItemsMap 中，请反馈此问题。", " is missing from espItemsMap. Please report this issue."},

        // ESP item labels (keys are item codes)
        {"Terminal", "Terminal", "Terminal"},
        {"Ammo Pack", "弹药包", "Ammo Pack"},
        {"Bulkhead", "Bulkhead", "Bulkhead"},
        {"BULKHEAD_KEY", "BULKHEAD_KEY", "BULKHEAD_KEY"},
        {"KEYCARD", "Keycard", "KEYCARD"},
        {"Cargo Crate", "Cargo Crate", "Cargo Crate"},
        {"Cargo Crate High Security", "Cargo Crate High Security", "Cargo Crate High Security"},
        {"Collection Case", "Collection Case", "Collection Case"},
        {"Cryo Hardcase", "Cryo Hardcase", "Cryo Hardcase"},
        {"DATA_CUBE", "DATA_CUBE", "DATA_CUBE"},
        {"DATA SPHERE", "DATA SPHERE", "DATA SPHERE"},
        {"Fog Repeller Turbine", "Fog Repeller Turbine", "Fog Repeller Turbine"},
        {"GLP Hormone", "GLP Hormone", "GLP Hormone"},
        {"Hard drive", "Hard drive", "Hard drive"},
        {"HSU", "HSU", "HSU"},
        {"NEONATE_HSU", "NEONATE_HSU", "NEONATE_HSU"},
        {"MATTER_WAVE_PROJECTOR", "MATTER_WAVE_PROJECTOR", "MATTER_WAVE_PROJECTOR"},
        {"Micro Drive", "Micro Drive", "Micro Drive"},
        {"Partial Decoder", "Partial Decoder", "Partial Decoder"},
        {"Plant Sample", "Plant Sample", "Plant Sample"},
        {"Power Cell", "CELL", "Power Cell"},
        {"IMPRINTED NEONATE HSU", "打印HSU", "IMPRINTED NEONATE HSU"},
        {"Personnel ID", "人员ID", "Personnel ID"},
        {"MediPack", "医疗包", "MediPack"},
        {"Tool Refill Pack", "工具补给包", "Tool Refill Pack"},
        {"Disinfection Pack", "消毒包", "Disinfection Pack"},
        {"Explosive Trip Mine", "爆炸绊雷", "Explosive Trip Mine"},
        {"Fog Repeller", "驱雾器", "Fog Repeller"},
        {"Glow Stick", "荧光棒", "Glow Stick"},
        {"I2-LP Syringe", "I2-LP注射器", "I2-LP Syringe"},
        {"IIx Syringe", "IIx注射器", "IIx Syringe"},
        {"Lock Melter", "熔锁器", "Lock Melter"},
        {"Long Range Flashlight", "远程手电", "Long Range Flashlight"},
        {"OSIP Hormone", "OSIP激素", "OSIP Hormone"},
        {"C-Foam Grenade", "C-泡沫手雷(C-Foam Grenade)", "C-Foam Grenade"},
        {"C-Foam Tripmine", "C-泡沫绊雷(C-Foam Tripmine)", "C-Foam Tripmine"},
        {"artifact_muted", "红色激素", "artifact_muted"},
        {"artifact_bold", "紫色激素", "artifact_bold"},
        {"artifact_aggressive", "普通激素", "artifact_aggressive"},
    };

    static const I18n::LanguageOption kLanguages[] = {
        {I18n::Language::ZhCN, "zh-CN", "中文", "Chinese"},
        {I18n::Language::EnUS, "en", "英文", "English"},
    };

    static std::unordered_map<std::string, const TextEntry*> g_lookup;
    static I18n::Language g_language = I18n::Language::ZhCN;
    static bool g_initialized = false;

    void EnsureInit()
    {
        if (g_initialized)
            return;

        g_lookup.reserve(sizeof(kText) / sizeof(kText[0]));
        for (const auto& entry : kText)
            g_lookup.emplace(entry.key, &entry);

        g_initialized = true;
    }

    std::string ToLowerCopy(std::string value)
    {
        std::transform(value.begin(), value.end(), value.begin(), [](unsigned char ch) {
            return static_cast<char>(std::tolower(ch));
        });
        return value;
    }
}

namespace I18n
{
    void Init()
    {
        EnsureInit();
    }

    const char* Tr(const char* key)
    {
        EnsureInit();
        auto it = g_lookup.find(key);
        if (it == g_lookup.end())
            return key;
        return (g_language == Language::ZhCN) ? it->second->zh : it->second->en;
    }

    const char* Tr(const std::string& key)
    {
        return Tr(key.c_str());
    }

    Language GetLanguage()
    {
        return g_language;
    }

    void SetLanguage(Language lang)
    {
        g_language = lang;
    }

    int GetLanguageIndex()
    {
        return static_cast<int>(g_language);
    }

    void SetLanguageByIndex(int index)
    {
        if (index < 0 || index >= static_cast<int>(sizeof(kLanguages) / sizeof(kLanguages[0])))
            return;
        g_language = kLanguages[index].lang;
    }

    const char* const* GetLanguageLabels()
    {
        static const char* labelsZh[] = {kLanguages[0].labelZh, kLanguages[1].labelZh};
        static const char* labelsEn[] = {kLanguages[0].labelEn, kLanguages[1].labelEn};
        return (g_language == Language::ZhCN) ? labelsZh : labelsEn;
    }

    const LanguageOption* GetLanguageOptions(std::size_t& count)
    {
        count = sizeof(kLanguages) / sizeof(kLanguages[0]);
        return kLanguages;
    }

    const char* GetLanguageCode(Language lang)
    {
        for (const auto& option : kLanguages)
        {
            if (option.lang == lang)
                return option.code;
        }
        return "zh-CN";
    }

    Language LanguageFromCode(const std::string& code)
    {
        const std::string normalized = ToLowerCopy(code);
        if (normalized == "zh" || normalized == "zh-cn" || normalized == "zh_cn")
            return Language::ZhCN;
        if (normalized == "en" || normalized == "en-us" || normalized == "en_us")
            return Language::EnUS;
        return Language::ZhCN;
    }
}
