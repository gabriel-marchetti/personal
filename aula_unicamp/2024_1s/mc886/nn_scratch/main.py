from dense import Dense
from tanh import Tanh
from losses import mse, mse_prime
from network import train, predict
import numpy as np
import matplotlib.pyplot as plt
from matplotlib import colors
from mpl_toolkits.mplot3d import Axes3D

'''
    Implementing the XOR gate since the boundary decision is not linear.
'''

X = np.reshape( [[0, 0], [0, 1], [1, 0], [1, 1]], (4, 2, 1) )
Y = np.reshape([[0], [1], [1], [0]], (4, 1, 1))

print("--- Truth Table ---")
print("X1\tX2\tS")
for x, y in zip(X, Y):
    print(f'{x[0][0]}\t{x[1][0]}\t{y[0][0]}')

network = [
    Dense(2, 3),
    Tanh(),
    Dense(3, 1),
    Tanh()
]

train(network, mse, mse_prime, X, Y, epochs=1000, learning_rate=0.1, verbose=False)

points = []
for x in np.linspace(0, 1, 20):
    for y in np.linspace(0, 1, 20):
        z = predict(network, [[x], [y]])
        points.append([x, y, z[0, 0]])

points = np.array(points)

print(f'Grid has {len(points)} points')
for point in points:
    print(f'x:{point[0]} y:{point[1]} z:{point[2]}')

x_points = points[:, 0]
y_points = points[:, 1]
z_points = points[:, 2]

fig, ax = plt.subplots(figsize=(8, 6))
scatter = ax.scatter(x_points, y_points, c=z_points, cmap='RdBu', marker='s')

# Adding a color bar
cbar = plt.colorbar(scatter)
cbar.set_label('Prediction Value')

ax.set_title('Decision Boundary for XOR Problem')
ax.set_xlabel('X1')
ax.set_ylabel('X2')
plt.show()

# fig = plt.figure()
# ax = fig.add_subplot(111, projection='3d')
# ax.scatter(points[:, 0], points[:, 1], points[:, 2], c=points[:, 2], cmap='winter')
# plt.show()
