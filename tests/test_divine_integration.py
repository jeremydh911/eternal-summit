import unittest
import os
import json
from src.divine_manager import DivineManager

class TestDivineIntegration(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        # Create a temporary config file for testing purposes
        cls.test_config_path = "test_config.json"
        cls.test_config = {
            "DivineSystem": {
                "EvilThreshold": 50.0,
                "SmiteChance": 0.5
            },
            "BlessingSystem": {
                "BlessingChance": 0.2,
                "Events": [
                    {"event": "Golden Rain", "effect": "Gold multiplier x2"},
                    {"event": "Divine Shield", "effect": "Protection from damage"}
                ]
            }
        }
        with open(cls.test_config_path, 'w') as f:
            json.dump(cls.test_config, f)

    @classmethod
    def tearDownClass(cls):
        if os.path.exists(cls.test_config_path):
            os.remove(cls.test_config_path)

    def setUp(self):
        self.manager = DivineManager(config_path=self.test_config_path)

    def test_evil_accumulation_and_smite(self):
        """Verify that adding evil points eventually triggers a smite."""
        self.manager.reset_divine_state()
        # Add enough evil to cross the threshold (50.0)
        self.manager.add_evil(60.0)
        
        # We might need multiple ticks because SmiteChance is 0.5
        smite_triggered = False
        for _ in range(20):
            events = self.manager.process_game_tick()
            if any("Smite" in str(e) or "Disaster" in str(e) for e in events):
                smite_triggered = True
                break
        
        self.assertTrue(smite_triggered, "Smite should have triggered after crossing evil threshold.")

    def test_blessing_trigger(self):
        """Verify that blessings can be triggered."""
        # BlessingChance is 0.2
        blessing_triggered = False
        for _ in range(50):
            events = self.manager.process_game_tick()
            if any("event" in e for e in events if "event" in e):
                # The BlessingSystem returns the dict from the config
                blessing_triggered = True
                break
        
        self.assertTrue(blessing_triggered, "A blessing should have eventually triggered.")

    def test_no_events_on_clean_state(self):
        """Verify that no events trigger when evil is low and luck is not active."""
        # This is probabilistic, but we test for low evil first
        self.manager.reset_divine_state()
        # We check for a single tick. It might trigger a blessing, 
        # but it definitely shouldn't trigger a smite.
        events = self.manager.process_game_tick()
        for e in events:
            # Check if any event is a smite/disaster (assuming smite name contains 'Smite')
            self.assertNotIn("Smite", str(e))

if __name__ == "__main__":
    unittest.main()