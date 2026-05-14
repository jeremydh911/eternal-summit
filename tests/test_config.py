import unittest
import sys
import os

# Add src to path so we can import ConfigManager
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))
from src.config_manager import ConfigManager

class TestConfigManager(unittest.TestCase):
    def setUp(self):
        self.config_path = 'config.json'
        self.manager = ConfigManager(self.config_path)
        self.manager.load_config()

    def test_load_config(self):
        config = self.manager.load_config()
        self.assertEqual(config["GameVersion"], "0.1.0-MVP")

    def test_get_value(self):
        self.assertEqual(self.manager.get("Platform"), "Mobile-First")
        self.assertEqual(self.manager.get("MaxPlayersPerMatch"), 16)

    def test_get_default(self):
        self.assertEqual(self.manager.get("NonExistentKey", "default_val"), "default_val")

if __name__ == "__main__":
    unittest.main()
