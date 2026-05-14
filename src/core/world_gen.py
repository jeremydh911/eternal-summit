import random

class WorldGenerator:
    def __init__(self, mountain_count=15, max_players=16):
        self.mountain_count = mountain_count
        self.max_players = max_players
        self.terrain_features = []
        self.player_spawn_points = []

    def generate_world(self):
        print(f"Starting world generation: {self.mountain_count} mountains, {self.max_players} player slots.")
        
        # Generate Mountains
        for i in range(self.mountain_count):
            x = random.randint(0, 100)
            y = random.randint(0, 100)
            self.terrain_features.append({"type": "Mountain", "coords": (x, y)})
        
        # Generate Spawn Points
        for i in range(self.max_players):
            x = random.randint(0, 100)
            y = random.randint(0, 100)
            self.player_spawn_points.append({"id": i, "coords": (x, y)})
            
        print(f"Generation complete. {len(self.terrain_features)} features and {len(self.player_spawn_points)} spawns created.")
        return {"features": self.terrain_features, "spawns": self.player_spawn_points}

if __name__ == "__main__":
    # Mock testing for WorldGenerator
    gen = WorldGenerator(mountain_count=15, max_players=16)
    world = gen.generate_world()
    
    print("\n--- World Map Preview ---")
    print(f"First 3 Mountains: {world['features'][:3]}")
    print(f"First 3 Spawn Points: {world['spawns'][:3]}")
    
    # Verify counts
    assert len(world['features']) == 15
    assert len(world['spawns']) == 16
    print("\nVerification successful: World counts match configuration.")