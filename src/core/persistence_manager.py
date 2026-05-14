import json
import os

class PersistenceManager:
    def __init__(self, save_dir="saves"):
        self.save_dir = save_dir
        if not os.path.exists(self.save_dir):
            os.makedirs(self.save_dir)

    def _get_path(self, player_id):
        return os.path.join(self.save_dir, f"{player_id}.json")

    def save_player(self, player_id, data):
        """
        Saves the complete player state including resources, 
        standing, divine favor, and codex progress.
        """
        path = self._get_path(player_id)
        try:
            with open(path, 'w') as f:
                json.dump(data, f, indent=4)
            return True
        except Exception as e:
            print(f"Error saving player {player_id}: {e}")
            return False

    def load_player(self, player_id):
        """
        Loads the player state from disk.
        """
        path = self._get_path(player_id)
        if not os.path.exists(path):
            return None
        try:
            with open(path, 'r') as f:
                return json.load(f)
        except Exception as e:
            print(f"Error loading player {player_id}: {e}")
            return None

    def delete_player(self, player_id):
        path = self._get_path(player_id)
        if os.path.exists(path):
            os.remove(path)
            return True
        return False