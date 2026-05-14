import unittest
from src.blessing_system import BlessingSystem

class TestBlessingSystem(unittest.TestCase):
    def setUp(self):
        # Provide a valid config dictionary to satisfy the constructor
        self.config = {
            "BlessingSystem": {
                "BlessingChance": 0.5,
                "Events": [{"event": "SpeedBoost", "duration": 5}]
            }
        }
        self.bs = BlessingSystem(self.config)

    def test_blessing_activation_logic(self):
        # Manually set state to test the update cycle logic
        self.bs.blessing_active = True
        self.bs.blessing_duration = 1
        
        # Update should decrease duration and then deactivate
        is_active = self.bs.update()
        self.assertFalse(is_active)
        self.assertFalse(self.bs.blessing_active)

    def test_duration_countdown(self):
        self.bs.blessing_active = True
        self.bs.blessing_duration = 2
        
        # First update: duration 2 -> 1, still active
        self.bs.update()
        self.assertTrue(self.bs.blessing_active)
        self.assertEqual(self.bs.blessing_duration, 1)
        
        # Second update: duration 1 -> 0, becomes inactive
        self.bs.update()
        self.assertFalse(self.bs.blessing_active)

if __name__ == "__main__":
    unittest.main()
