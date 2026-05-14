import json
import os

class ConfigManager:
    _instance = None
    _config = {}

    def __new__(cls):
        if cls._instance is None:
            cls._instance = super(ConfigManager, cls).__new__(cls)
        return cls._instance

    def load_config(self, file_path):
        if not os.path.exists(file_path):
            raise FileNotFoundError(f"Configuration file not found: {file_path}")
        
        with open(file_path, 'r') as f:
            self._config = json.load(f)
        print(f"Successfully loaded configuration from {file_path}")

    def get(self, key_path, default=None):
        """
        Retrieve a value using a dot-notation path (e.g., 'DivineSystem.DisasterProbability')
        """
        keys = key_path.split('.')
        value = self._config
        try:
            for key in keys:
                value = value[key]
            return value
        except (KeyError, TypeError):
            return default

# Global instance for easy access
config = ConfigManager()