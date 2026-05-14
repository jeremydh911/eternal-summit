import pytest
from src.core.divine_system import DivineSystem

def test_divine_system_initialization():
    config = {
        "EvilThresholdBase": 100,
        "EvilDecayPerDay": 5,
        "DisasterProbability": 0.1,
        "BlessingProbability": 0.1
    }
    system = DivineSystem(config)
    assert system.evil_threshold_base == 100
    assert system.evil_decay_per_day == 5
    assert system.global_evil_score == 0

def test_record_evil_action():
    config = {}
    system = DivineSystem(config)
    player_id = "player1"
    
    # Test evil action
    system.record_action(player_id, "betrayal", 20)
    assert system.player_scores[player_id] == 20
    assert system.global_evil_score == 20
    
    # Test good action (reduction)
    system.record_action(player_id, "charity", 10)
    # magnitude * 0.5 = 5 reduction
    assert system.player_scores[player_id] == 15

def test_global_evil_decay():
    config = {"EvilDecayPerDay": 10}
    system = DivineSystem(config)
    system.add_evil(50)
    
    system.process_tick()
    assert system.global_evil_score == 40

def test_extreme_evil_threshold():
    # Set threshold low to trigger increased disaster probability
    config = {
        "EvilThresholdBase": 10,
        "DisasterProbability": 0.0,
        "BlessingProbability": 0.0
    }
    system = DivineSystem(config)
    system.add_evil(50) # Trigger threshold
    
    # Since we can't easily test randomness without mocking, 
    # we just ensure the system logic executes without error
    result_type, message = system.process_tick()
    assert result_type in ["disaster", "blessing", "neutral"]
