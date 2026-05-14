class Player:
    def __init__(self, player_id, name):
        self.player_id = player_id
        self.name = name
        self.level = 1
        self.experience = 0
        self.is_active = True

    def gain_experience(self, amount):
        self.experience += amount
        if self.experience >= 100:
            self.level_up()

    def level_up(self):
        self.level += 1
        self.experience = 0
        print(f"Player {self.name} leveled up to {self.level}!")

    def __repr__(self):
        return f"Player(id={self.player_id}, name={self.name}, level={self.level})"

if __name__ == "__main__":
    print("--- Testing Player System ---")
    p = Player(1, "Hero_Alpha")
    print(f"Initial: {p}")
    p.gain_experience(50)
    print(f"After 50 XP: {p}")
    p.gain_experience(60)
    print(f"After 110 XP: {p}")