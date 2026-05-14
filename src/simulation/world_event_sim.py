import random
from src.core.player import Player

class DivineSystemSim:
    def __init__(self, evil_threshold_base=100, evil_decay_per_day=15, disaster_prob=0.12, blessing_prob=0.08):
        self.evil_threshold = evil_threshold_base
        self.evil_decay = evil_decay_per_day
        self.disaster_prob = disaster_prob
        self.blessing_prob = blessing_prob

    def player_action_evil(self, intensity):
        self.evil_threshold += intensity
        print(f"Action: Evil deed performed! Evil Threshold is now {self.evil_threshold}")

    def daily_decay(self):
        self.evil_threshold = max(0, self.evil_threshold - self.evil_decay)
        print(f"Day End: Evil decayed. Current Threshold: {self.evil_threshold}")

    def check_events(self):
        roll = random.random()
        if roll < self.disaster_prob:
            return "DISASTER"
        elif roll < (self.disaster_prob + self.blessing_prob):
            return "BLESSING"
        return "PEACE"

def run_simulation():
    print("--- Starting Divine System Integration Simulation ---")
    divine = DivineSystemSim()
    hero = Player(1, "Adventurer")

    # Simulate 3 "days"
    for day in range(1, 4):
        print(f"\n--- Day {day} ---")
        
        # Players do things
        if day == 1:
            hero.gain_experience(50)
            divine.player_action_evil(30)
        elif day == 2:
            hero.gain_experience(60)
            divine.player_action_evil(50)
        else:
            divine.player_action_evil(10)

        # Check for world events
        event = divine.check_events()
        print(f"World Event Status: {event}")

        # End of day decay
        divine.daily_decay()

if __name__ == "__main__":
    run_simulation()