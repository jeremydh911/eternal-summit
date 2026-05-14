import unittest
from src.core.game_engine import GameEngine

class TestGameIntegration(unittest.TestCase):
    def setUp(self):
        self.engine = GameEngine()
        self.player_id = "test_player"
        self.engine.register_player(self.player_id)

    def test_build_increases_favor_and_resources(self):
        """Verify that building increases resources and divine favor."""
        initial_resources = self.engine.players[self.player_id]["resources"]
        initial_favor = self.engine.divine_system.get_favor(self.player_id)
        
        # Perform build action (yields resources)
        # Note: perform_action is a generator in the current implementation
        list(self.engine.perform_action(self.player_id, "build"))
        
        new_resources = self.engine.players[self.player_id]["resources"]
        new_favor = self.engine.divine_system.get_favor(self.player_id)
        
        self.assertGreater(new_resources, initial_resources)
        self.assertGreater(new_favor, initial_favor)

    def test_raid_decreases_favor(self):
        """Verify that raiding decreases divine favor."""
        # First, give player some favor
        self.engine.divine_system.update_favor(self.player_id, 10)
        initial_favor = self.engine.divine_system.get_favor(self.player_id)
        
        # Perform raid action
        list(self.engine.perform_action(self.player_id, "raid"))
        
        new_favor = self.engine.divine_system.get_favor(self.player_id)
        self.assertLess(new_favor, initial_favor)

    def test_blessing_impact(self):
        """Verify that high favor can trigger a blessing (probabilistic)."""
        # Force high favor to maximize blessing chance
        self.engine.divine_system.update_favor(self.player_id, 50)
        
        # We run multiple times to ensure we hit the probabilistic blessing
        blessing_triggered = False
        for _ in range(20):
            # We look for the codex_drop yielded by the generator
            results = list(self.engine.perform_action(self.player_id, "build"))
            # If a blessing occurs, the engine yields: [codex_drop, updated_resources]
            # Or if no blessing: [updated_resources]
            # Based on current engine: if blessing: yield codex_drop; yield player["resources"]
            if len(results) > 1:
                blessing_triggered = True
                break
        
        self.assertTrue(blessing_triggered, "A blessing should have been triggered with high favor.")

if __name__ == "__main__":
    unittest.main()