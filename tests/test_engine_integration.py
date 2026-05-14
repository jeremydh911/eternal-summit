import unittest
import json
import os
from src.core.engine import GameEngine

class TestEngineIntegration(unittest.TestCase):
    def setUp(self):
        self.config_path = "test_config.json"
        self.config_data = {
            "DivineSystem": {
                "EvilThresholdBase": 100,
                "EvilDecayPerDay": 15,
                "DisasterProbability": 0.0,  # Set to 0 to control outcomes
                "BlessingProbability": 1.0    # Set to 1 to force blessing
            }
        }
        with open(self.config_path, 'w') as f:
            json.dump(self.config_data, f)
        
        self.engine = GameEngine(self.config_path)

    def tearDown(self):
        if os.path.exists(self.config_path):
            os.remove(self.config_path)

    def test_blessing_triggers_codex_drop(self):
        """Test that a blessing event triggers a codex drop."""
        player_id = "player_1"
        # Perform a 'good' action (not in evil_actions list)
        # With BlessingProbability=1.0, this should trigger a blessing
        result = self.engine.process_player_turn(player_id, "prayer", 10)
        
        self.assertEqual(result["event_type"], "blessing")
        # Since we can't see codex_system.py, we check if codex_drop is not None 
        # assuming drop_page returns something when called.
        self.assertIsNotNone(result["codex_drop"])

    def test_evil_action_increases_score(self):
        """Test that evil actions increase the player's evil score."""
        player_id = "villain_1"
        self.engine.process_player_turn(player_id, "betrayal", 50)
        standing = self.engine.get_player_standing(player_id)
        self.assertEqual(standing["evil_score"], 50)
        self.assertEqual(standing["status"], "tainted")

if __name__ == "__main__":
    unittest.main()