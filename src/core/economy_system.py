class EconomySystem:
    def __init__(self, initial_gold=100):
        self.player_gold = initial_gold
        self.transaction_history = []

    def add_gold(self, amount):
        if amount > 0:
            self.player_gold += amount
            self.transaction_history.append(f"Added {amount} gold. Balance: {self.player_gold}")
            return True
        return False

    def spend_gold(self, amount):
        """
        Attempts to deduct gold from the player balance.
        """
        if amount <= 0:
            return False, "Invalid amount"
        
        if self.player_gold >= amount:
            self.player_gold -= amount
            self.transaction_history.append(f"Spent {amount} gold. Balance: {self.player_gold}")
            return True, "Transaction successful"
        else:
            return False, "Insufficient funds"

    def get_balance(self):
        return self.player_gold

if __name__ == "__main__":
    # Mock testing for EconomySystem
    economy = EconomySystem(initial_gold=50)
    
    print(f"Initial Balance: {economy.get_balance()} gold")
    
    # Test 1: Successful addition
    print("\nTest 1: Adding 25 gold...")
    economy.add_gold(25)
    print(f"New Balance: {economy.get_balance()}")

    # Test 2: Successful purchase
    print("\nTest 2: Buying a potion (15 gold)...")
    success, message = economy.spend_gold(15)
    print(f"Result: {success}, Message: {message}. Balance: {economy.get_balance()}")

    # Test 3: Failed purchase (Insufficient funds)
    print("\nTest 3: Buying a legendary sword (100 gold)...")
    success, message = economy.spend_gold(100)
    print(f"Result: {success}, Message: {message}. Balance: {economy.get_balance()}")

    # Test 4: Negative amount attempt
    print("\nTest 4: Attempting to spend negative gold...")
    success, message = economy.spend_gold(-10)
    print(f"Result: {success}, Message: {message}")