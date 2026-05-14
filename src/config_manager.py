import json
import os

class ConfigManager:
    def __init__(self, config_path):
        self.config_path = config_path
        self.config = {}

    def load_config(self):
        if not os.path.exists(self.config_path):
            raise FileNotFoundError(f"Configuration file not found: {self.config_path}")
        
        with open(self.config_path, 'r') as f:
            self.config = json.load(f)
        return self.config

    def get(self, key, default=None):
        return self.config.get(key, default)

if __name__ == "__main__":
    # Example usage
    print("ConfigManager module initialized.")
