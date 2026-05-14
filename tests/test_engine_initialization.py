import sys
import os
import json
import pytest

# Add src to sys.path to allow importing core modules
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '../src')))

try:
    from core.engine import GameEngine
except ImportError as e:
    print(f"Import Error: {e}")
    GameEngine = None

def test_engine_data_loading():
    """
    Test if the GameEngine initializes correctly with the existing JSON configs.
    """
    if GameEngine is None:
        pytest.fail("Could not import GameEngine. Check sys.path or file location.")

    # Define the path to the configuration file
    config_path = os.path.abspath(os.path.join(os.path.dirname(__file__), '../EternalSummit_GameSettings.json'))

    if not os.path.exists(config_path):
        config_path = os.path.abspath(os.path.join(os.path.dirname(__file__), '../config.json'))
        if not os.path.exists(config_path):
            pytest.fail(f"Configuration file not found at {config_path}")

    try:
        # Attempt to initialize the engine with the config path
        engine = GameEngine(config_path=config_path)

        # Check if essential components are loaded
        assert engine is not None, "Engine failed to initialize."
        assert hasattr(engine, 'config'), "Engine should have a 'config' attribute."

        # Validate specific config values to ensure integrity
        # Note: The key in the JSON is 'Version', not 'GameVersion'
        assert engine.config.get("Version") == "0.1.0-MVP", "Version mismatch."
        assert engine.config.get("MaxPlayersPerMatch") == 16, "MaxPlayersPerMatch mismatch."

        print(f"\n✅ Engine initialization and data integrity check successful with config: {config_path}")
    except Exception as e:
        pytest.fail(f"\n❌ Engine initialization failed: {str(e)}")
