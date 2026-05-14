# Eternal Summit: Rise of the Ascendants - Project Requirements

## 1. Core Gameplay Requirements
- **Genre**: Mobile-First Multiplayer (KoTH + Monopoly + SimCity elements).
- **Match Mechanics**: 16 players per match, 3-8 minute sessions.
- **Core Loop**: Claim mountain peaks (KoTH) $\rightarrow$ Guild building (SimCity) $\rightarrow$ Resource/Deed trading (Monopoly) $\rightarrow$ Divine interaction.
- **Progression**: Codex of Ascendance discovery via specific world interactions.

## 2. Technical Requirements
- **Engine**: Unreal Engine 5.4.
- **Platform**: Mobile (Android/iOS) with high performance scalability.
- **Target Performance**: 60 FPS / 30 FPS targets.
- **Architecture**: Server-authoritative (C++) for all math, scoring, and logic.
- **Key Systems**:
    - **Gameplay Ability System (GAS)** for hero abilities.
    - **Procedural Mesh Component** for real-time mountain growth.
    - **Niagara VFX** for divine/celestial effects.

## 3. Divine & Social Systems
- **Evil System**: Tracks "Evil Score" through betrayal, unprovoked raiding, and hoarding.
- **Divine Events**:
    - **Disaster (Evil-triggered)**: Lightning Smite, Earthquake, etc.
    - **Blessing (Contribution-triggered)**: Golden Rain, Celestial Bloom, etc.
- **Guild System**: Max 50 players per guild; focus on territory ownership and collective building.

## 4. Aesthetic & Audio Requirements
- **Visual Style**: High-quality mobile graphics with Nanite/LOD scaling.
- **Audio Style**: "Mario-inspired" (Adventure Orchestral + Chiptune).
- **Dynamic Audio**: Music layers must shift based on game state (Tension/Victory/Divine).

## 5. Monetization Framework
- **Battle Pass**: Seasonal progression.
- **Currency/Packs**: Essence Packs and Divine Wards.