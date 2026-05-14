from src.config_manager import ConfigManager

def main():
    print("Initializing Game System...")
    config = ConfigManager('config.json')
    config.load_config()

    version = config.get("GameVersion")
    platform = config.get("Platform")
    players = config.get("MaxPlayersPerMatch")

    print(f"--- Game Info ---")
    print(f"Version: {version}")
    print(f"Platform: {platform}")
    print(f"Max Players: {players}")
    print(f"------------------")
    print("System Ready.")

if __name__ == "__main__":
    main()
