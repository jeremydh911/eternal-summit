# Eternal Summit: Core System Architecture Manifest

## Overview
The Eternal Summit core engine is built upon four interconnected pillars designed to create a dynamic, reactive world where environmental states and random events directly influence character progression and gameplay.

## The Four Pillars

### 1. Celestial Architect (Foundation)
* **Purpose:** Defines the structural hierarchy of the world and the base classes for all actors.
* **Key Components:** Base Actor classes, world composition logic, and foundational data structures.

### 2. Aetheric Atmosphere (Environmental State)
* **Purpose:** Manages the global 'mood' and systemic state of the world.
* **Key Components:** Global modifiers, environmental state machines, and atmospheric parameter controllers.

### 3. Mortal Ascent (Character Interaction)
* **Purpose:** Handles the player/NPC experience, focusing on movement, progression, and physical presence.
* **Key Components:** `AMortalAscentCharacter`, movement component overrides, and character-state management.

### 4. Echoes of Fate (Dynamic Events)
* **Purpose:** Bridges the Atmosphere and Ascent pillars by injecting unpredictable, gameplay-altering events into the world.
* **Key Components:** 
    * `AEventBase`: The interface for all dynamic events.
    * `ARadiantFlareEvent`: A concrete implementation modifying character speed.
    * `AEventOrchestrator`: The 'Conductor' that schedules and spawns events based on atmospheric cadence.

## Integration Flow

1. **Atmosphere** sets the stage (e.g., a 'High Energy' state).
2. **Orchestrator** detects the state and selects an appropriate **Echo** (Event).
3. **Event** is spawned at a location, affecting the **Ascent** (Character) via direct attribute modification (e.g., Speed, Gravity, Health).
4. **Character** responds to the event, completing the gameplay loop.

--- 
*End of Manifest - Build Cycle 1 Complete.*