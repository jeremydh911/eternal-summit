import json
from src.divine_system import DivineSystem
from src.blessing_system import BlessingSystem

class DivineManager:
    def __init__(self, config_path="game_config.json"):
        self.divine_system = DivineSystem(config_path)
        self.blessing_system = BlessingSystem(config_path)

    def process_game_tick(self):
        """
        Main update loop for the divine mechanics.
        Returns a list of triggered events.
        """
        events = []
        
        # 1. Check for Blessings
        blessing_event = self.blessing_system.check_for_blessing()
        if blessing_event:
            events.append(blessing_event)
            
        # 2. Update existing Blessing duration
        self.blessing_system.update()

        # 3. Check for Disasters based on internal DivineSystem score
        smite_event = self.divine_system.check_for_smite()
        if smite_event:
            events.append(smite_event)

        return events

    def add_evil(self, amount):
        # Delegate evil score management to the divine_system
        self.divine_system.add_evil_points(amount)

if __name__ == "__main__":
    manager = DivineManager()
    print("Testing DivineManager Integration...")
    # Simulate adding evil and checking for events
    manager.add_evil(160)
    events = manager.process_game_tick()
    print(f"Tick events: {events}")