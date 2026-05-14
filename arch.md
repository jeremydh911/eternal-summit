# Eternal Summit: Rise of the Ascendants — Architectural Specification

## 1. Epic Architecture Overview
Eternal Summit is a high-performance, mobile-first multiplayer strategy experience. It merges the intensity of King of the Hill (KoTH), the economic tension of Monopoly, and the creative expansion of SimCity, all governed by a Divine Overseer and unlocked via the Secret Codex.

## 2. Bounded Contexts & Domains (The 5 Pillars)
The architecture is partitioned into five distinct functional domains:
| Domain | Pillar | Core Mechanics | Technical Focus |
| :--- | :--- | :--- | :--- |
| **Ascendant Conquest** | KoTH | Mountain peak claiming, territory control | Server-authoritative movement & scoring |
| **Economic Empire** | Monopoly | Resource/Deed trading, taxation, hoarding | Transactional integrity, C++ economic math |
| **Celestial Architect** | SimCity | Guild building, territory expansion | Procedural Mesh, real-time building logic |
| **Divine Oversight** | Divine | Evil scoring, disasters, blessings | Seeded RNG, Server-side event triggers |
| **The Secret Codex** | Codex | Progression, world interaction discovery | Data-driven discovery, state persistence |

## 3. Technical Stack & Implementation Standards
### 3.1 Core Engine & Systems
- **Engine**: Unreal Engine 5.4+
- **Programming Language**: C++ (Mandatory for all performance-critical and server-authoritative systems: Divine, Mountain, Guild, Codex, Economy).
- **Blueprints**: Restricted to UI, visual scripting, and rapid prototyping of designer-facing systems.
- **Ability System**: **Gameplay Ability System (GAS)** is the mandatory framework for all hero and divine abilities.
- **VFX/SFX**: **Niagara** for all celestial/divine effects; **Dynamic Audio Layering** (Orchestral + Chiptune) that shifts based on game state (Tension/Victory/Divine).

### 3.2 Specialized Components
- **Mountain Growth**: Real-time visible procedural mesh updates using `ProceduralMeshComponent` integrated with Niagara particle systems.
- **Server Authority**: 100% server-side math for all scoring, economic transactions, and combat validation.

## 4. Data-Driven Design (Single Source of Truth)
All game balance, event triggers, and build trees are decoupled from code.
- **Storage Format**: JSON.
- **Loading Strategy**: A centralized `ConfigManager` loads JSON files into Unreal `UDataAsset` or `UDataTable` structures at runtime.
- **Directory**: `Content/Data/` for all JSON configurations.

## 5. Mobile Performance & Scalability Plan
Targeting top-grossing mobile performance standards:
- **High-End Target**: 60 FPS.
- **Mid-Range Target**: 30 FPS.
- **Scalability**: Use of Nanite/LOD scaling and aggressive Niagara particle budgeting to ensure smooth gameplay on Android/iOS.

## 6. Core Class Architecture & Naming
### 6.1 Naming Convention
- **Prefix**: `ES_` (e.g., `ES_DivineOverseerComponent`, `ES_MountainProceduralManager`).
- **Variables**: Standard UE conventions (e.g., `bIsActive`).

### 6.2 Essential Classes
| Class Name | Responsibility | Pillar Reference |
| :--- | :--- | :--- |
| `ES_DivineOverseerComponent` | Tracks Evil Score, triggers disasters/blessings. | Divine Oversight |
| `ES_MountainProceduralManager` | Manages real-time mesh growth and sculpting. | Celestial Architect |
| `ES_CodexManager` | Handles progression logic and discovery state. | The Secret Codex |
| `ES_GuildTerritorySystem` | Manages territory ownership and guild builds. | Ascendant Conquest |

## 7. Vertical Slice Definition (First Playable)
A successful vertical slice must demonstrate the full loop:
`KoTH Conquest` $\rightarrow$ `Visible Guild Building` $\rightarrow$ `Divine Event Trigger` $\rightarrow$ `Codex Discovery`.

## 8. Workspace Rule Alignment
- **Philosophy**: Mobile-First, Data-Driven, Modular, SOLID.
- **Documentation**: Every major class MUST contain a "Why" comment referencing one of the 5 Pillars.
- **Structure**: `Source/EternalSummit/` for C++, `Content/Data/` for JSON.