#pragma once
#include "InputUtil.h"
#include "globals.h"
#include <map>
#include <array>
#include <vector>

namespace ESP
{
    static std::map<std::string, std::string> espItems = {
        { "Terminal", "Terminal" },
        { "Ammo Pack", "弹药包" },
        { "Bulkhead", "Bulkhead" },
        { "BULKHEAD_KEY", "BULKHEAD_KEY" },
        { "KEYCARD", "Keycard" },
        { "Cargo Crate", "Cargo Crate" },
        { "Cargo Crate High Security", "Cargo Crate High Security" },
        { "Collection Case", "Collection Case" },
        { "Cryo Hardcase", "Cryo Hardcase" },
        { "DATA_CUBE", "DATA_CUBE" },
        { "DATA SPHERE", "DATA SPHERE" },
        { "Fog Repeller Turbine", "Fog Repeller Turbine" },
        { "GLP Hormone", "GLP Hormone" },
        { "Hard drive", "Hard drive" },
        { "HSU", "HSU" },
        { "NEONATE_HSU", "NEONATE_HSU" },
        { "MATTER_WAVE_PROJECTOR", "MATTER_WAVE_PROJECTOR" },
        { "Micro Drive", "Micro Drive" },
        { "Partial Decoder", "Partial Decoder" },
        { "Plant Sample", "Plant Sample" },
        { "Power Cell", "CELL" },
        { "IMPRINTED NEONATE HSU", "打印HSU" },
        { "Personnel ID", "人员ID" },
        { "MediPack", "医疗包" },
        { "Tool Refill Pack", "工具补给包" },
        { "Disinfection Pack", "消毒包" },
        { "Explosive Trip Mine", "爆炸绊雷" },
        { "Fog Repeller", "驱雾器" },
        { "Glow Stick", "荧光棒" },
        { "I2-LP Syringe", "I2-LP注射器"},
        { "IIx Syringe", "IIx注射器"},
        { "Lock Melter", "熔锁器" },
        { "Long Range Flashlight", "远程手电" },
        { "OSIP Hormone", "OSIP激素" },
        { "C-Foam Grenade", "C-泡沫手雷(C-Foam Grenade)" },
        { "C-Foam Tripmine", "C-泡沫绊雷(C-Foam Tripmine)" },
        { "artifact_muted", "红色激素" },
        { "artifact_bold", "紫色激素" },
        { "artifact_aggressive", "普通激素" },

    };

    // Explicit render order for the ESP menu (std::map iteration is sorted by key).
    static const std::vector<std::string> espItemsOrder = {
        "Terminal",
        "Ammo Pack",
        "Bulkhead",
        "BULKHEAD_KEY",
        "KEYCARD",
        "Cargo Crate",
        "Cargo Crate High Security",
        "Collection Case",
        "Cryo Hardcase",
        "DATA_CUBE",
        "DATA SPHERE",
        "Fog Repeller Turbine",
        "GLP Hormone",
        "Hard drive",
        "HSU",
        "NEONATE_HSU",
        "IMPRINTED NEONATE HSU",
        "MATTER_WAVE_PROJECTOR",
        "Micro Drive",
        "Partial Decoder",
        "Personnel ID",
        "Plant Sample",
        "Power Cell",
        "MediPack",
        "Tool Refill Pack",
        "Disinfection Pack",
        "Explosive Trip Mine",
        "Fog Repeller",
        "Glow Stick",
        "I2-LP Syringe",
        "IIx Syringe",
        "Lock Melter",
        "Long Range Flashlight",
        "OSIP Hormone",
        "C-Foam Grenade",
        "C-Foam Tripmine",
        "artifact_muted",
        "artifact_bold",
        "artifact_aggressive",
    };

    // 1) 分组的显示顺序（菜单里折叠/标题的顺序）
    static const std::vector<std::string> espGroupsOrder = {
        "门禁钥匙终端",
        "任务物品",
        "消耗品",
        "其他",
        "收集物"
    };

    // 2) 每个 item key 属于哪个分组（key 必须和 espItems/espItemsOrder 里的完全一致）
    static const std::map<std::string, std::string> espItemToGroup = {
        {"Terminal", "门禁钥匙终端"},
        {"KEYCARD", "门禁钥匙终端"},
        { "BULKHEAD_KEY", "门禁钥匙终端" },
        { "Bulkhead", "门禁钥匙终端" },

        { "Collection Case", "任务物品" },
        { "Cryo Hardcase", "任务物品" },
        { "Cargo Crate", "任务物品" },
        { "Cargo Crate High Security", "任务物品" },
        {"HSU", "任务物品"},
        {"NEONATE_HSU", "任务物品"},
        {"IMPRINTED NEONATE HSU", "任务物品"},
        {"MATTER_WAVE_PROJECTOR", "任务物品"},
        {"Power Cell", "任务物品"},
        {"OSIP Hormone", "任务物品" },
        { "Plant Sample", "任务物品" },
        {"Fog Repeller Turbine", "任务物品"},
        { "Personnel ID", "任务物品" },
        { "Partial Decoder", "任务物品" },
        { "Micro Drive", "任务物品" },
        { "Hard drive", "任务物品" },
        { "GLP Hormone", "任务物品" },
        { "DATA_CUBE", "任务物品" },
        { "DATA SPHERE", "任务物品" },


        {"Ammo Pack", "消耗品"},
        {"MediPack", "消耗品"},
        {"Tool Refill Pack", "消耗品"},
        {"Disinfection Pack", "消耗品"},
        { "C-Foam Grenade", "消耗品" },
        { "C-Foam Tripmine", "消耗品" },
        { "Long Range Flashlight", "消耗品" },
        { "Lock Melter", "消耗品" },
        { "I2-LP Syringe", "消耗品"},
        { "IIx Syringe", "消耗品"},
        { "Glow Stick", "消耗品" },
        { "Fog Repeller", "消耗品" },
        { "Explosive Trip Mine", "消耗品" },

        {"artifact_muted", "收集物"},
        {"artifact_bold", "收集物"},
        {"artifact_aggressive", "收集物"},

    };
    // 3) 小工具：拿分组名（没配置就归到 Other）
    inline const std::string& EspGroupOf(const std::string& key)
    {
        static const std::string kOther = "Other";
        auto it = espItemToGroup.find(key);
        return (it == espItemToGroup.end()) ? kOther : it->second;
    }

    // 4) 小工具：按“分组 + 原始 espItemsOrder 顺序”遍历
    template <class Fn>
    inline void ForEachEspItemInGroup(const std::string& group, Fn&& fn)
    {
        for (const auto& key : espItemsOrder) {
            if (EspGroupOf(key) != group) continue;

            auto it = espItems.find(key);
            if (it == espItems.end()) continue; // 防御：order 里有但 map 里没有

            // fn(key, label)
            fn(key, it->second);
        }
    }


    struct WorldESPItem
    {
        bool enabled = false;
        int renderDistance = 250;
        ImVec4 renderColor = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
        ImVec4 outlineColor = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
    };

    struct WorldPickupItem
    {
        app::LG_PickupItem_Sync* pickupItem;
        app::pPickupItemState state;
        float distance;

        WorldPickupItem(app::LG_PickupItem_Sync* pickupItem, float distance = -1.0f)
        {
            this->pickupItem = pickupItem;
            this->distance = distance;
        }

        void update()
        {
            this->state = app::LG_PickupItem_Sync_GetCurrentState(this->pickupItem, NULL);
            this->distance = app::Vector3_Distance(this->state.placement.position, G::localPlayer->fields.m_goodPosition, NULL);
        }

        bool operator>(const WorldPickupItem& rhs) const
        {
            return this->distance > rhs.distance;
        }
    };

    struct WorldArtifactItem
    {
        app::ArtifactPickup_Core* artifactItem;
        app::LG_PickupItem_Sync* pickupItem;
        app::pPickupItemState state;
        float distance;

        WorldArtifactItem(app::ArtifactPickup_Core* artifactItem, float distance = -1.0f)
        {
            this->artifactItem = artifactItem;
            this->distance = distance;
        }

        void update()
        {
            this->pickupItem = reinterpret_cast<app::LG_PickupItem_Sync*>(artifactItem->fields.m_sync);
            this->state = app::LG_PickupItem_Sync_GetCurrentState(this->pickupItem, NULL);
            this->distance = app::Vector3_Distance(this->state.placement.position, G::localPlayer->fields.m_goodPosition, NULL);
        }

        bool operator>(const WorldArtifactItem& rhs) const
        {
            return this->distance > rhs.distance;
        }
    };

    struct WorldCarryItem
    {
        app::CarryItemPickup_Core* carryItem;
        app::LG_PickupItem_Sync* pickupItem;
        app::pPickupItemState state;
        float distance;

        WorldCarryItem(app::CarryItemPickup_Core* carryItem, float distance = -1.0f)
        {
            this->carryItem = carryItem;
            this->distance = distance;
        }

        void update()
        {
            this->pickupItem = reinterpret_cast<app::LG_PickupItem_Sync*>(carryItem->fields.m_sync);
            this->state = app::LG_PickupItem_Sync_GetCurrentState(this->pickupItem, NULL);
            this->distance = app::Vector3_Distance(this->state.placement.position, G::localPlayer->fields.m_goodPosition, NULL);
        }

        bool operator>(const WorldCarryItem& rhs) const
        {
            return this->distance > rhs.distance;
        }
    };

    struct WorldKeyItem
    {
        app::KeyItemPickup_Core* keyItem;
        app::LG_PickupItem_Sync* pickupItem;
        app::pPickupItemState state;
        float distance;

        WorldKeyItem(app::KeyItemPickup_Core* keyItem, float distance = -1.0f)
        {
            this->keyItem = keyItem;
            this->distance = distance;
        }
        
        void update()
        {
            this->pickupItem = reinterpret_cast<app::LG_PickupItem_Sync*>(keyItem->fields.m_sync);
            this->state = app::LG_PickupItem_Sync_GetCurrentState(this->pickupItem, NULL);
            this->distance = app::Vector3_Distance(this->state.placement.position, G::localPlayer->fields.m_goodPosition, NULL);
        }

        bool operator>(const WorldKeyItem& rhs) const
        {
            return this->distance > rhs.distance;
        }
    };

    struct WorldGenericItem
    {
        app::GenericSmallPickupItem_Core* genericItem;
        app::LG_PickupItem_Sync* pickupItem;
        app::pPickupItemState state;
        float distance;

        WorldGenericItem(app::GenericSmallPickupItem_Core* genericItem, float distance = -1.0f)
        {
            this->genericItem = genericItem;
            this->distance = distance;
        }
        
        void update()
        {
            this->pickupItem = reinterpret_cast<app::LG_PickupItem_Sync*>(genericItem->fields.m_sync);
            this->state = app::LG_PickupItem_Sync_GetCurrentState(this->pickupItem, NULL);
            this->distance = app::Vector3_Distance(this->state.placement.position, G::localPlayer->fields.m_goodPosition, NULL);
        }

        bool operator>(const WorldGenericItem& rhs) const
        {
            return this->distance > rhs.distance;
        }
    };

    struct WorldResourceItem
    {
        app::ResourcePackPickup* resourceItem;
        app::LG_PickupItem_Sync* pickupItem;
        app::pPickupItemState state;
        float distance;
        
        WorldResourceItem(app::ResourcePackPickup* resourceItem, float distance = -1.0f)
        {
            this->resourceItem = resourceItem;
            this->distance = distance;
        }
        
        void update()
        {
            this->pickupItem = reinterpret_cast<app::LG_PickupItem_Sync*>(resourceItem->fields.m_sync);
            this->state = app::LG_PickupItem_Sync_GetCurrentState(this->pickupItem, NULL);
            this->distance = app::Vector3_Distance(this->state.placement.position, G::localPlayer->fields.m_goodPosition, NULL);
        }

        bool operator>(const WorldResourceItem& rhs) const
        {
            return this->distance > rhs.distance;
        }
    };

    struct WorldTerminalItem
    {
        app::LG_ComputerTerminal* terminalItem;
        float distance;

        WorldTerminalItem(app::LG_ComputerTerminal* terminalItem, float distance = -1.0f)
        {
            this->terminalItem = terminalItem;
            this->distance = distance;
        }

        void update()
        {
            this->distance = app::Vector3_Distance(terminalItem->fields.m_position, G::localPlayer->fields.m_goodPosition, NULL);
        }

        bool operator>(const WorldTerminalItem& rhs) const
        {
            return this->distance > rhs.distance;
        }
    };

    struct WorldHSUItem
    {
        app::LG_HSU* hsuItem;
        app::LG_GenericTerminalItem* terminalItem;
        app::Vector3 position;
        float distance;

        WorldHSUItem(app::LG_HSU* hsuItem)
        {
            this->hsuItem = hsuItem;
        }

        void update()
        {
            this->terminalItem = reinterpret_cast<app::LG_GenericTerminalItem*>(hsuItem->fields.m_terminalItem);
            this->position = app::LG_GenericTerminalItem_get_LocatorBeaconPosition(this->terminalItem, NULL);
            this->distance = app::Vector3_Distance(this->position, G::localPlayer->fields.m_goodPosition, NULL);
        }

        bool operator>(const WorldHSUItem& rhs) const
        {
            return this->distance > rhs.distance;
        }
    };

    struct WorldBulkheadDC
    {
        app::LG_BulkheadDoorController_Core* bulkheadDC;
        app::LG_GenericTerminalItem* terminalItem;
        app::Vector3 position;
        float distance;

        WorldBulkheadDC(app::LG_BulkheadDoorController_Core* bulkheadDC)
        {
            this->bulkheadDC = bulkheadDC;
        }

        void update()
        {
            this->terminalItem = reinterpret_cast<app::LG_GenericTerminalItem*>(bulkheadDC->fields.m_terminalItem);
            this->position = app::LG_GenericTerminalItem_get_LocatorBeaconPosition(this->terminalItem, NULL);
            this->distance = app::Vector3_Distance(this->position, G::localPlayer->fields.m_goodPosition, NULL);
        }

        bool operator>(const WorldBulkheadDC& rhs) const
        {
            return this->distance > rhs.distance;
        }
    };

    struct AgentESPSection
    {
        std::string type;
        bool show = true;
        
        bool showBoxes = true;
        ImVec4 boxesColor = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
        ImVec4 boxesOutlineColor = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);

        bool showHealthBar = true;
        int healthBarThickness = 3;
        bool healthBarText = true;
        bool healthBarTextFull = true;
        ImVec4 healthBarTextColor = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
        ImVec4 healthBarTextOutlineColor = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
        
        bool showInfo = true;
        bool showName = true;
        bool showType = true;
        bool showHealth = true;
        bool showDistance = true;
        ImVec4 textColor = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
        ImVec4 textOutlineColor = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
        
        int renderDistance = 250;

        bool showSkeleton = true;
        ImVec4 skeletonColor = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
        int skeletonRenderDistance = 250;
        float skeletonThickness = 1.0f;

        AgentESPSection(std::string type)
        {
            this->type = type;
        }
    };

    struct AgentESP
    {
        KeyBindToggle toggleKey;
        AgentESPSection visibleSec = AgentESPSection("Visible");
        AgentESPSection nonVisibleSec = AgentESPSection("NonVisible");
    };

    extern std::map<std::string, WorldESPItem*> espItemsMap;

    extern KeyBindToggle worldESPToggleKey;
    extern AgentESP enemyESP;

    extern std::vector<WorldPickupItem> worldItems;
    extern std::vector<WorldArtifactItem> worldArtifacts;
    extern std::vector<WorldCarryItem> worldCarryItems;
    extern std::vector<WorldKeyItem> worldKeys;
    extern std::vector<WorldGenericItem> worldGenerics;
    extern std::vector<WorldResourceItem> worldResourcePacks;
    extern std::vector<WorldHSUItem> worldHSUItems;

    extern std::vector<WorldBulkheadDC> worldBulkheadDCs;
    extern std::vector<WorldTerminalItem> worldTerminals;

    void Init();
    void UpdateInput();
}
