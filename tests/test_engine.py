import unittest
import json
import os
from src.core.engine import GameEngine

class TestGameEngine(unittest.TestCase):
    def setUp(self):
        self.config_path = "test_config.json"
        self.config_data = {
            "DivineSystem": {
                "threshold": 10,
                "blessing_chance": 0.5
            }
        }
        with open(self.config_path, 'w') as f:
            json.dump(self.config_data, f)
        
        self.engine = GameEngine(self.config_path)

    def tearDown(self):
        if os.path.exists(self.config_path):
            os.remove(self.config_path)

    def test_player_turn_flow(self):
        # Test a basic turn
        result = self.engine.process_player_turn("player1", "action", 15)
        
        self.assertIn("event_type", result)
        self.assertIn("event_message", result)
        self.assertIn("codex_drop", result)
        
        # Check if standing is recorded
        standing = self.engine.get_player_standing("player1")
        self.assertIsNotNone(standing)

if __name__ == "__main__":
    unittest.main()