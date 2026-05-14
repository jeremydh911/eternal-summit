import json
import random

class BlessingSystem:
    def __init__(self, config):
        """
        Initializes the BlessingSystem.
        :param config: A dictionary containing the game configuration.
        """
        # If a path is passed instead of a dict, load it (for backward compatibility)
        if isinstance(config, str):
            with open(config, 'r') as f:
                config = json.load(f)
        
        self.cfg = config.get("BlessingSystem", {})
        self.blessing_chance = self.cfg.get("BlessingChance", 0.05)
        self.events = self.cfg.get("Events", [])
        
        # State tracking for active blessings
        self.blessing_active = False
        self.blessing_duration = 0

    def check_for_blessing(self):
        # Simple check based on probability
        if random.random() < self.blessing_chance:
            if self.events:
                event = random.choice(self.events)
                self.blessing_active = True
                # Assume duration is passed in the event or defaulted
                self.blessing_duration = event.get("duration", 5)
                return event
        return None

    def update(self):
        """
        Decrements the duration of an active blessing.
        Returns True if a blessing is still active, False otherwise.
        """
        if self.blessing_active:
            self.blessing_duration -= 1
            if self.blessing_duration <= 0:
                self.blessing_active = False
                return False
            return True
        return False

if __name__ == "__main__":
    # Quick smoke test (requires a local game_config.json to run directly)
    try:
        bs = BlessingSystem({"BlessingSystem": {"BlessingChance": 0.5, "Events": [{"event": "SpeedBoost", "duration": 3}]}})
        # Force a check
        event = bs.check_for_blessing()
        if event:
            print(f"BLESSING TRIGGERED: {event.get('event', event)}")
        else:
            print("No blessing occurred.")
    except Exception as e:
        print(f"Smoke test failed: {e}")
