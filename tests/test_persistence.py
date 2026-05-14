import unittest
from src.core.game_engine import GameEngine

class TestPersistence(unittest.TestCase):
    def setUp(self):
        self.player_id = "test_hero_123"
        self.engine = GameEngine()

    def test_save_and_load_lifecycle(self):
        # 1. Register and perform action
        self.engine.register_player(self.player_id)
        
        # Perform 'build' action: resources +50, favor +5
        # Initial resources: 100 -> 150
        # Initial favor: 0 -> 5
        actions = list(self.engine.perform_action(self.player_id, "build"))
        
        # Verify in-memory state
        self.assertEqual(self.engine.players[self.player_id]["resources"], 150)
        self.assertEqual(self.engine.divine_system.get_favor(self.player_id), 5)

        # 2. Create a fresh engine to simulate a restart
        new_engine = GameEngine()
        new_engine.register_player(self.player_id)

        # 3. Verify loaded state matches the previous engine's state
        self.assertEqual(new_engine.players[self.player_id]["resources"], 150)
        self.assertEqual(new_engine.divine_system.get_favor(self.player_id), 5)

if __name__ == "__main__":
    unittest.main()