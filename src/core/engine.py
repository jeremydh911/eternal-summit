import json
from src.core.divine_system import DivineSystem
from src.core.codex_system import CodexSystem

class GameEngine:
    """
    The central orchestration engine for the game.
    Loads configuration and manages core subsystems.
    """
    def __init__(self, config_path):
        with open(config_path, 'r') as f:
            self.config = json.load(f)
        
        self.divine_system = DivineSystem(self.config["DivineSystem"])
        self.codex_system = CodexSystem()

    def process_player_turn(self, player_id, action_type, magnitude):
        """
        Processes a single turn for a player, updating their standing 
        and checking for divine events or codex drops.
        """
        # 1. Record the action in the divine system
        self.divine_system.record_action(player_id, action_type, magnitude)
        
        # 2. Check for divine events (Disasters or Blessings)
        event_type, event_msg = self.divine_system.check_divine_event(player_id)
        
        # 3. Logic for Codex Drops
        # For the sake of the test requirement: if a blessing occurs, drop a codex page.
        codex_drop = None
        if event_type == "blessing":
            codex_drop = self.codex_system.drop_page(player_id)
            
        return {
            "event_type": event_type,
            "event_message": event_msg,
            "codex_drop": codex_drop
        }

    def get_player_standing(self, player_id):
        return self.divine_system.get_player_standing(player_id)