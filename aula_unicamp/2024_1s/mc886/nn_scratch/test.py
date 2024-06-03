import matplotlib.pyplot as plt

# Sample data
data = [
    (1, 2, 0.0),
    (2, 3, 1.0),
    (3, 4, 0.0),
    (4, 5, 1.0),
    (5, 6, 0.0),
    (6, 7, 1.0)
]

# Separate the points based on z value
x_0 = [x for x, y, z in data if z == 0.0]
y_0 = [y for x, y, z in data if z == 0.0]
x_1 = [x for x, y, z in data if z == 1.0]
y_1 = [y for x, y, z in data if z == 1.0]

# Create the plot
plt.figure(figsize=(8, 6))

# Plot points with z = 0.0 as squares
plt.scatter(x_0, y_0, color='blue', edgecolor='black', marker='s', label='Class 0')

# Plot points with z = 1.0 as squares
plt.scatter(x_1, y_1, color='red', edgecolor='black', marker='s', label='Class 1')

# Add labels and legend
plt.xlabel('X')
plt.ylabel('Y')
plt.title('2D Scatter Plot Colored by Class with Square Markers')
plt.legend()

# Show the plot
plt.show()
