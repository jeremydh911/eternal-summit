import json
from core.divine_system import DivineSystem
from blessing_system import BlessingSystem

class DivineManager:
    """
    Orchestrates the interaction between the DivineSystem (managing evil/smite)
    and the BlessingSystem (managing player luck/blessings).
    """
    def __init__(self, config_path="game_config.json"):
        self.config_path = config_path
        # Load the config once and share it
        with open(config_path, 'r') as f:
            self.config = json.load(f)
            
        self.divine_system = DivineSystem(self.config)
        self.blessing_system = BlessingSystem(self.config)

    def process_game_tick(self):
        """
        Main update loop for the divine mechanics.
        Returns a list of triggered events (e.g., 'Disaster', 'Blessing').
        """
        events = []
        
        # 1. Check for Blessings (Randomly triggered based on BlessingSystem config)
        blessing_event = self.blessing_system.check_for_blessing()
        if blessing_event:
            events.append(blessing_event)
            
        # 2. Update existing blessing durations or stateful blessing effects
        self.blessing_system.update()

        # 3. Check for Disasters/Smites (Triggered based on DivineSystem's internal evil score)
        # Note: DivineSystem uses process_tick() to return events
        smite_events = self.divine_system.process_tick()
        if smite_events:
            events.extend(smite_events)

        return events

    def add_evil(self, amount: float):
        """
        Increments the global evil score, which influences the likelihood 
        of divine punishment (Smites) via the DivineSystem.
        """
        self.divine_system.add_evil(amount)

    def reset_divine_state(self):
        """Resets the divine/evil tracking."""
        self.divine_system.reset_evil_score()

if __name__ == "__main__":
    # Integration Test
    try:
        manager = DivineManager()
        print("--- DivineManager Integration Test ---")
        
        # Scenario 1: Adding evil and checking for smites
        print("Simulating evil activity...")
        manager.add_evil(100.0)
        tick_events = manager.process_game_tick()
        print(f"Tick events after evil: {tick_events}")

        # Scenario 2: Checking for blessings
        print("\nSimulating game tick for random blessings...")
        # We loop a few times to increase the chance of seeing a blessing in console output
        for i in range(5):
            events = manager.process_game_tick()
            if events:
                print(f"Tick {i+1} events: {events}")
            else:
                print(f"Tick {i+1}: No events triggered.")

        print("\nTest completed successfully.")
    except Exception as e:
        print(f"Test failed with error: {e}")