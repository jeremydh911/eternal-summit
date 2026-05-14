# Eternal Summit: Workspace Rules v1.0

## 1. Naming Conventions
- **Class Prefixing**: All C++ classes MUST use the `ES_` prefix (e.g., `ES_DivineOverseerComponent`, `ES_HeroCharacter`).
- **Variable Naming**: Follow standard Unreal Engine C++ conventions (e.g., `bIsActive` for booleans, `MyVariable` for members).

## 2. Project Structure
- **C++ Core**: All source files must reside in `Source/EternalSummit/`.
- **Data Configuration**: All JSON-driven configuration files must reside in `Content/Data/`.

## 3. Documentation Standards
- **Mandatory Commenting**: Every major class must include a "Why" comment block that explicitly references one of the 5 Core Pillars:
    - Ascendant Conquest
    - Economic Empire
    - Celestial Architect
    - Divine Oversight
    - The Secret Codex

## 4. Architectural Principles
- **Server Authority**: All math, scoring, economic transactions, and combat logic must be implemented in C++ to ensure server-authoritative integrity.
- **Modular Systems**: Utilize the Gameplay Ability System (GAS) for all character abilities.
- **Data-Driven Design**: Decouple logic from values by using JSON files loaded via a centralized `ConfigManager` into `UDataAsset` or `DataTable`.
- **Performance First**: All visual and audio systems must adhere to the 60 FPS (High) / 30 FPS (Mid) mobile performance budget.