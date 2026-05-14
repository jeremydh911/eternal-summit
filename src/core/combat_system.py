import random

class CombatSystem:
    def __init__(self, config_path):
        # In a real scenario, combat stats would be loaded from config
        self.base_damage_multiplier = 1.0

    def resolve_attack(self, attacker, defender):
        """
        Calculates damage from an attacker to a defender.
        """
        # Simple formula: (Attacker Power * Random Factor) - Defender Defense
        # For now, we assume attacker and defender have 'power' and 'defense' attributes
        
        attacker_power = getattr(attacker, 'power', 10)
        defender_defense = getattr(defender, 'defense', 5)
        
        damage_roll = random.uniform(0.8, 1.2)
        raw_damage = (attacker_power * damage_roll) - defender_defense
        
        # Ensure damage is at least 1 if an attack connects
        final_damage = max(1, int(raw_damage))
        
        # Update defender's health (assuming health attribute exists)
        if hasattr(defender, 'health'):
            defender.health -= final_damage
            
        return final_damage, defender.health

    def check_combat_status(self, player):
        """
        Checks if a player has been defeated.
        """
        if hasattr(player, 'health') and player.health <= 0:
            return True
        return False

if __name__ == "__main__":
    # Mock classes for testing
    class MockEntity:
        def __init__(self, name, health, power, defense):
            self.name = name
            self.health = health
            self.power = power
            self.defense = defense

    combat = CombatSystem(None)
    hero = MockEntity("Hero", 100, 15, 5)
    goblin = MockEntity("Goblin", 30, 5, 2)

    print(f"--- Combat Test: {hero.name} vs {goblin.name} ---")
    for i in range(3):
        damage, remaining_health = combat.resolve_attack(hero, goblin)
        print(f"Attack {i+1}: {hero.name} deals {damage} damage to {goblin.name}. {goblin.name} health: {remaining_health}")
        if combat.check_combat_status(goblin):
            print(f"{goblin.name} has been defeated!")
            break