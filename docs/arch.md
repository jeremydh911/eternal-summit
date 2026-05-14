# 🏔️ ETERNAL SUMMIT: RISE OF THE ASCENDANTS — ARCHITECTURE SPECIFICATION (v1.3)

## 1. Executive Summary
**Eternal Summit** is a high-fidelity, top-grossing mobile multiplayer strategy experience. It fuses the competitive territorial conquest of **King of the Hill (KoTH)** with the economic depth of **Monopoly** and the creative progression of **SimCity**, all overseen by a dynamic **Divine System** and the mystery of the **Secret Codex**.

The architecture is built for massive scalability, mobile-first performance (60→30fps), and a "Juicy" aesthetic inspired by classic Mario-style triumphs.

---

## 2. Core Pillars & Bounded Contexts
The system is divided into five primary domains to ensure modularity and SOLID principles:

| Domain | Core Responsibility | Key Mechanic |
| :--- | :--- | :--- |
| **Ascendant Conquest** | Territorial control and match logic. | KoTH (Claiming Peaks) |
| **Economic Empire** | Resource management and trade. | Monopoly (Deeds/Trading) |
| **Celestial Architect** | Visual progression and guild building. | SimCity (Guild Structures) |
| **Divine Oversight** | Server-authoritative world events. | Divine/Evil Scoring & RNG |
| **The Secret Codex** | Deep progression and world mystery. | Codex of Ascendance Discovery |

---

## 3. Technical Stack & Standards

### **Engine & Platform**
- **Engine**: Unreal Engine 5.4+
- **Target Platforms**: Mobile-First (Android/iOS)
- **Performance Goal**: 60 FPS (High-end) $\rightarrow$ 30 FPS (Mid-range) via aggressive LOD/Nanite scaling and mobile profiling.

### **Core Systems & Mandatory Frameworks**
- **Logic Core**: **C++ (Server-Authoritative)**. All math, scoring, economic transactions, and combat logic must reside in C++ to prevent client-side cheating.
- **Hero Abilities**: **Gameplay Ability System (GAS)** is the mandatory standard for all character abilities.
- **Visual FX**: **Niagara** is required for all divine, celestial, and environmental effects.
- **Environment**: **ProceduralMeshComponent** for real-time, visible mountain sculpting and growth.
- **Audio**: **Dynamic Layered Audio**. Mario-inspired orchestral-chiptune hybrid that shifts layers based on game tension/state (Victory vs. Disaster).

### **Match & Social Constraints**
- **Match Lifecycle**: Sessions are strictly timed between **3 to 8 minutes**.
- **Player Scaling**: Supports **16 players per match**.
- **Guild Limits**: Maximum of **50 players per guild**.

### **Workspace Rules (v1.0)**
- **Class Prefixing**: All C++ classes MUST use the `ES_` prefix (e.g., `ES_DivineOverseerComponent`, `ES_HeroCharacter`).
- **Variable Naming**: Follow standard Unreal Engine C++ conventions (e.g., `bIsActive` for booleans, `MyVariable` for members).
- **Folder Structure**: 
    - `Source/EternalSummit/`: All C++ source files.
    - `Content/Data/`: All JSON-driven configuration files.
- **Documentation**: Every major class must include a "Why" comment block explicitly referencing one of the 5 Core Pillars.

---

## 4. Data-Driven Design
To enable rapid balancing and live-ops capability, the game logic is decoupled from hardcoded values.

**Data Strategy:**
- **Source**: All balance, event triggers, and unit stats reside in **JSON files**.
- **Runtime**: JSON $\rightarrow$ `UDataAsset` or `DataTable` via a centralized `ConfigManager`.
- **Key Data Schemas**:
    - `Heroes.json`: Ability stats, movement speeds, scaling.
    - `DivineEvents.json`: Trigger conditions (Evil vs. Good) and effects.
    - `GuildBuildTrees.json`: Structure costs and growth tiers.
    - `CodexPages.json`: Discovery requirements and lore.

---

## 5. Core Class Architecture (High-Level)

| Class Name | Type | Responsibility |
| :--- | :--- | :--- |
| `ES_GameMode` | C++ | Match lifecycle, 16-player session management, 3-8m timer. |
| `ES_DivineOverseer` | C++ | Managing the "Evil Score" and seeding Divine RNG. |
| `ES_MountainComponent` | C++ | Driving `ProceduralMeshComponent` for growth. |
| `ES_EconomicManager` | C++ | Monopoly-style deed ownership and resource math. |
| `ES_CodexManager` | C++ | Tracking world interaction for Codex discovery. |
| `ES_HeroCharacter` | C++ | Integration of GAS and player movement. |

---

## 6. Monetization Framework
To support the top-grossing mobile model, the architecture includes:
- **Seasonal Progression**: Battle Pass integration tied to the Codex and Guild progression.
- **Microtransactions**: Support for **Essence Packs** (Resource boosts) and **Divine Wards** (Cosmetic/Protective items).

---

## 7. Mobile Performance & Scalability Plan
1. **LOD & Nanite**: Aggressive Nanite usage for terrain with strict LOD fallback for mobile.
2. **VFX Culling**: Niagara emitters are distance-culled and particle counts are throttled based on device tier.
3. **Server-Authoritative Math**: Reduces client-side CPU load by offloading complex simulation math to the server.
4. **Profiling**: Mandatory mobile profiling before any merge to ensure the 30/60 FPS budget is maintained.

---

## 8. First Playable (Vertical Slice) Definition
The Vertical Slice must demonstrate the seamless loop of all 5 pillars:
1. **Conquest**: Player captures a mountain peak (KoTH).
2. **Growth**: Peak visibly expands via `ProceduralMeshComponent`.
3. **Economy**: Player acquires a deed/resource (Monopoly).
4. **Divine**: A triggered "Evil" event (e.g., Lightning Smite) occurs due to hoarding.
5. **Discovery**: Player unlocks a single entry in the `Codex of Ascendance`.

---

## 9. Workspace Alignment
This document adheres to **Eternal Summit Workspace Rules v1.0**, ensuring all development follows the Top-Grossing Mobile Strategy philosophy.