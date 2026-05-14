import unittest
from src.core.engine import GameEngine

class TestDivineLoop(unittest.TestCase):
    def setUp(self):
        # Use the existing game_config.json
        self.engine = GameEngine("game_config.json")

    def test_evil_action_triggers_disaster(self):
        """Tests if high magnitude 'evil' actions increase disaster risk."""
        player_id = "tyrant_01"
        
        # Perform multiple high-magnitude evil actions
        for _ in range(10):
            self.engine.process_player_turn(player_id, "betrayal", 50)
        
        standing = self.engine.divine_system.get_player_standing(player_id)
        self.assertGreater(standing["evil_score"], 0)
        
        # In a real scenario, we'd mock random, but here we verify state
        # checking if the score is tracked correctly
        self.assertEqual(standing["evil_score"], 500)

    def test_codex_drop_on_blessing(self):
        """Tests if high-value 'good' actions can trigger codex drops."""
        player_id = "saint_01"
        
        # We attempt to trigger a blessing via high magnitude 'just_defense'
        # Note: Since check_divine_event uses random, this is a probabilistic test
        # In production, we would inject a deterministic seed/mock.
        found_drop = False
        for _ in range(100):
            result = self.engine.process_player_turn(player_id, "just_defense", 100)
            if result["codex_drop"] is not None:
                found_drop = True
                break
        
        # Given 8% blessing chance, 100 attempts should statistically yield a drop
        self.assertTrue(found_drop, "Codex drop did not trigger in 100 blessing attempts")

if __name__ == "__main__":
    unittest.main()