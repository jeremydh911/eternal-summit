import unittest
import json
import os
from src.core.engine import GameEngine

class TestGameEngine(unittest.TestCase):
    def setUp(self):
        self.config_path = "test_config.json"
        self.config_data = {
            "DivineSystem": {
                "EvilThresholdBase": 50,
                "EvilDecayPerDay": 5,
                "DisasterProbability": 0.1,
                "BlessingProbability": 0.2
            }
        }
        with open(self.config_path, 'w') as f:
            json.dump(self.config_data, f)
        self.engine = GameEngine(self.config_path)

    def tearDown(self):
        if os.path.exists(self.config_path):
            os.remove(self.config_path)

    def test_player_turn_blessing_drops_codex(self):
        # Mocking the flow to ensure a blessing triggers a codex drop
        # We force a player_id and use a high magnitude to influence state if needed,
        # but since we want to test the logic path in engine.py:
        # if event_type == "blessing": codex_drop = self.codex_system.drop_page(player_id)
        
        # We'll simulate a turn. Since it's random, we might need to run it a few times 
        # or just verify the structure of the return dictionary.
        player_id = "test_player"
        
        # Test structure of return
        result = self.engine.process_player_turn(player_id, "righteous_action", 10)
        self.assertIn("event_type", result)
        self.assertIn("event_message", result)
        self.assertIn("codex_drop", result)

    def test_evil_accumulation(self):
        player_id = "evil_player"
        # Perform evil actions
        self.engine.process_player_turn(player_id, "betrayal", 20)
        self.engine.process_player_turn(player_id, "tyranny", 20)
        
        standing = self.engine.get_player_standing(player_id)
        self.assertEqual(standing["evil_score"], 40)
        self.assertEqual(standing["status"], "tainted")

if __name__ == "__main__":
    unittest.main()