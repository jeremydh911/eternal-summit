from typing import Dict, List, Any
from src.core.divine_system import DivineSystem
from src.core.codex_system import CodexSystem

class GameEngine:
    def __init__(self, config: Dict[str, Any] = None):
        if config is None:
            config = {
                "EvilThresholdBase": 50.0,
                "GoodThresholdBase": 50.0,
                "SmiteChance": 0.5,
                "BlessingChance": 0.5
            }
        self.config = config
        self.players: Dict[str, Dict[str, Any]] = {}
        self.divine_system = DivineSystem(self.config)
        self.codex_system = CodexSystem()

    def add_player(self, player_id: str):
        if player_id not in self.players:
            self.players[player_id] = {"score": 0.0, "inventory": []}

    def record_action(self, player_id: str, action_type: str, magnitude: float):
        if player_id in self.players:
            self.players[player_id]["score"] += magnitude
            self.divine_system.record_action(player_id, action_type, magnitude)

    def step(self):
        event_type, message = self.divine_system.process_tick()
        return event_type, message