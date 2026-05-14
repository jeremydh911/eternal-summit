from typing import Dict, List

class CodexSystem:
    def __init__(self):
        self._player_progress: Dict[str, List[str]] = {}

    def sync_player_progress(self, player_id: str, progress: List[str]):
        """Synchronizes the player's progress with the codex system."""
        self._player_progress[player_id] = progress

    def add_entry(self, player_id: str, entry: str):
        """Adds a new entry to the player's codex progress."""
        if player_id not in self._player_progress:
            self._player_progress[player_id] = []
        if entry not in self._player_progress[player_id]:
            self._player_progress[player_id].append(entry)

    def get_player_progress(self, player_id: str) -> List[str]:
        """Returns the current codex progress for a player."""
        return self._player_progress.get(player_id, [])

    def drop_page(self, player_id: str):
        """Removes the most recent entry from the player's codex progress."""
        if player_id in self._player_progress and self._player_progress[player_id]:
            self._player_progress[player_id].pop()