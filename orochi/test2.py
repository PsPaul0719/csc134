import pygame
import sys
import math

# Initialize Pygame
pygame.init()

# Set up the display
width, height = 600, 400
screen = pygame.display.set_mode((width, height))
pygame.display.set_caption("Pygame Test Window")

clock = pygame.time.Clock()

# --- Main Game Loop ---
running = True
x = width // 2
y = height // 2
radius = 50
ball_color = (200, 0, 150)

x_speed = 4
y_speed = 4

# Wormhole settings
wormhole_radius = 40
wormhole_color = (100, 50, 200)
left_wormhole_x = wormhole_radius + 10
left_wormhole_y = height // 2
right_wormhole_x = width - wormhole_radius - 10
right_wormhole_y = height // 2

# Teleport cooldown to prevent getting stuck
teleport_cooldown = 0

# Current shape (0=star, 1=circle, 2=square, 3=triangle)
current_shape = 0

# Function to create a star shape
def create_star(cx, cy, size):
    points = []
    num_points = 5
    outer_radius = size
    inner_radius = size * 0.4
    
    for i in range(num_points * 2):
        angle = math.pi / 2 + (i * math.pi / num_points)
        if i % 2 == 0:
            r = outer_radius
        else:
            r = inner_radius
        px = cx + r * math.cos(angle)
        py = cy - r * math.sin(angle)
        points.append((px, py))
    
    return points

# Function to check distance between two points
def distance(x1, y1, x2, y2):
    return math.sqrt((x2 - x1)**2 + (y2 - y1)**2)

# Function to create a circle shape
def create_circle(cx, cy, size):
    points = []
    num_points = 20
    for i in range(num_points):
        angle = 2 * math.pi * i / num_points
        px = cx + size * math.cos(angle)
        py = cy + size * math.sin(angle)
        points.append((px, py))
    return points

# Function to create a square shape
def create_square(cx, cy, size):
    half = size
    return [
        (cx - half, cy - half),
        (cx + half, cy - half),
        (cx + half, cy + half),
        (cx - half, cy + half)
    ]

# Function to create a triangle shape
def create_triangle(cx, cy, size):
    height = size * 1.5
    return [
        (cx, cy - height),
        (cx + size, cy + height * 0.5),
        (cx - size, cy + height * 0.5)
    ]

while running:
    # Check for events (like closing the window)
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # Move the star
    x = x + x_speed
    y = y + y_speed
    
    # Decrease cooldown timer
    if teleport_cooldown > 0:
        teleport_cooldown -= 1
    
    # Check if star enters left wormhole (only if cooldown is 0)
    if teleport_cooldown == 0 and distance(x, y, left_wormhole_x, left_wormhole_y) < wormhole_radius:
        x = right_wormhole_x
        y = right_wormhole_y
        teleport_cooldown = 30  # Wait 30 frames before teleporting again
        current_shape = (current_shape + 1) % 4  # Change to next shape (cycles 0->1->2->3->0)
    
    # Check if star enters right wormhole (only if cooldown is 0)
    elif teleport_cooldown == 0 and distance(x, y, right_wormhole_x, right_wormhole_y) < wormhole_radius:
        x = left_wormhole_x
        y = left_wormhole_y
        teleport_cooldown = 30  # Wait 30 frames before teleporting again
        current_shape = (current_shape + 1) % 4  # Change to next shape (cycles 0->1->2->3->0)
    
    # Bounce off top and bottom edges
    if y - radius <= 0 or y + radius >= height:
        y_speed = -y_speed
    
    # Bounce off left and right edges (safety net if star misses wormholes)
    if x - radius <= 0 or x + radius >= width:
        x_speed = -x_speed

    # Fill the screen with a color (black)
    screen.fill((0, 0, 0))

    # Draw the wormholes
    pygame.draw.circle(screen, wormhole_color, (left_wormhole_x, left_wormhole_y), wormhole_radius)
    pygame.draw.circle(screen, (50, 25, 100), (left_wormhole_x, left_wormhole_y), wormhole_radius - 10)
    
    pygame.draw.circle(screen, wormhole_color, (right_wormhole_x, right_wormhole_y), wormhole_radius)
    pygame.draw.circle(screen, (50, 25, 100), (right_wormhole_x, right_wormhole_y), wormhole_radius - 10)

    # Draw the star
    if current_shape == 0:
        shape_points = create_star(x, y, radius)
    elif current_shape == 1:
        shape_points = create_circle(x, y, radius)
    elif current_shape == 2:
        shape_points = create_square(x, y, radius)
    else:  # current_shape == 3
        shape_points = create_triangle(x, y, radius)
    
    pygame.draw.polygon(screen, ball_color, shape_points)
    
    # Update the display
    pygame.display.flip()
    
    # Control frame rate (60 FPS)
    clock.tick(60)

# Quit Pygame
pygame.quit()
sys.exit()