import pandas as pd

# Load fleet log
fleet_data = pd.read_csv("fleet_log.csv")

print("=== Autonomous Fleet Analytics ===\n")

print(fleet_data)

# Average fuel remaining
average_fuel = fleet_data["Fuel"].mean()

print(f"\nAverage Fuel Level: {average_fuel:.2f}%")

# Count active trucks
active_trucks = fleet_data["Active"].sum()

print(f"Active Trucks: {active_trucks}")

# Detect low fuel trucks
low_fuel = fleet_data[fleet_data["Fuel"] < 30]

if not low_fuel.empty:
    print("\n[ALERT] Low Fuel Trucks Detected:")
    print(low_fuel[["ID", "Fuel"]])

# Simple productivity score
productivity_score = active_trucks * average_fuel

print(f"\nFleet Productivity Score: {productivity_score:.2f}")
