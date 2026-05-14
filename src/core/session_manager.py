import time
import random

class SessionManager:
    def __init__(self, min_duration=180, max_duration=480):
        self.min_duration = min_duration
        self.max_duration = max_duration
        self.session_start_time = None
        self.target_duration = 0
        self.is_active = False

    def start_session(self):
        self.session_start_time = time.time()
        self.target_duration = random.randint(self.min_duration, self.max_duration)
        self.is_active = True
        print(f"Session started. Target duration: {self.target_duration} seconds.")

    def get_elapsed_time(self):
        if not self.is_active:
            return 0
        return time.time() - self.session_start_time

    def check_session_status(self):
        if not self.is_active:
            return "inactive"
        
        elapsed = self.get_elapsed_time()
        
        if elapsed >= self.target_duration:
            self.is_active = False
            print("Target duration reached. Ending session.")
            return "ended"
        
        if elapsed >= self.min_duration:
            return "eligible_to_end"
        
        return "running"

if __name__ == "__main__":
    # Mock testing for SessionManager
    # Using small durations for testing purposes
    sm = SessionManager(min_duration=2, max_duration=4)
    
    print("--- Testing Session Lifecycle ---")
    sm.start_session()
    
    # Check immediately
    print(f"Status immediately after start: {sm.check_session_status()}")
    assert sm.check_session_status() == "running"
    
    # Wait for min duration
    time.sleep(2.5)
    print(f"Status after 2.5s: {sm.check_session_status()}")
    assert sm.check_session_status() in ["eligible_to_end", "ended"]
    
    # Wait for max duration
    time.sleep(3)
    print(f"Status after waiting: {sm.check_session_status()}")
    
    # The first call that hits the limit returns "ended"
    # The next call returns "inactive" because is_active was set to False
    assert sm.check_session_status() == "inactive"
    print("\nVerification successful: Session lifecycle managed correctly.")