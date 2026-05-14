import time
import random
from divine_system import DivineSystem
from blessing_system import BlessingSystem

def run_game_loop():
    print("--- Starting King of the Hill MVP Simulation ---")
    divine = DivineSystem("game_config.json")
    blessing = BlessingSystem("game_config.json")
    
    # Simulate 10 game ticks
    for tick in range(1, 11):
        print(f"\n--- Tick {tick} ---")
        
        # 1. Simulate player actions generating "evil"
        evil_gain = random.randint(10, 40)
        divine.add_evil_points(evil_gain)
        
        # 2. Check Divine System (Smite)
        smite_event = divine.check_for_smite()
        if smite_event:
            print(f"!!! DIVINE EVENT: {smite_event['event']} !!!")
            print(f"    Effect: {smite_event['effect']}")
            print(f"    Visual: {smite_event['visual']}")
        
        # 3. Check Blessing System (Golden Rain)
        bless_event = blessing.check_for_blessing()
        if bless_event:
            print(f"*** BLESSING EVENT: {bless_event['event']} ***")
            print(f"    Effect: {bless_event['effect']}")
            print(f"    Visual: {bless_event['visual']}")
            
        blessing.update()
        time.sleep(0.5)

    print("\n--- Simulation Complete ---")

if __name__ == "__main__":
    run_game_loop()