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

while running:
    # Check for events (like closing the window)
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # Move the star
    x = x + x_speed
    y = y + y_speed
    
    # Check if star enters left wormhole
    if distance(x, y, left_wormhole_x, left_wormhole_y) < wormhole_radius:
        x = right_wormhole_x
        y = right_wormhole_y
    
    # Check if star enters right wormhole
    if distance(x, y, right_wormhole_x, right_wormhole_y) < wormhole_radius:
        x = left_wormhole_x
        y = left_wormhole_y
    
    # Bounce off top and bottom edges
    if y - radius <= 0 or y + radius >= height:
        y_speed = -y_speed

    # Fill the screen with a color (black)
    screen.fill((0, 0, 0))

    # Draw the wormholes
    pygame.draw.circle(screen, wormhole_color, (left_wormhole_x, left_wormhole_y), wormhole_radius)
    pygame.draw.circle(screen, (50, 25, 100), (left_wormhole_x, left_wormhole_y), wormhole_radius - 10)
    
    pygame.draw.circle(screen, wormhole_color, (right_wormhole_x, right_wormhole_y), wormhole_radius)
    pygame.draw.circle(screen, (50, 25, 100), (right_wormhole_x, right_wormhole_y), wormhole_radius - 10)

    # Draw the star
    star_points = create_star(x, y, radius)
    pygame.draw.polygon(screen, ball_color, star_points)
    
    # Update the display
    pygame.display.flip()
    
    # Control frame rate (60 FPS)
    clock.tick(60)

# Quit Pygame
pygame.quit()
sys.exit()